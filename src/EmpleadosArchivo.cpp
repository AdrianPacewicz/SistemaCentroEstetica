#include "EmpleadosArchivo.h"
#include <iostream> // cout
#include <fstream>  // fstream importar CSV
#include <vector>   // vector importar CSV
#include <sstream>  // stringstream importar CSV
#include <stdio.h>  // remove .dat

Empleado EmpleadosArchivo::leer(int nroRegistro)
{
  Empleado empleado;
  FILE* p;
  p = fopen("empleados.dat", "rb");
  if (p == NULL)
  {
    return empleado;
  }
  fseek(p, nroRegistro * sizeof(Empleado), SEEK_SET);
  fread(&empleado, sizeof(Empleado), 1, p);
  fclose(p);
  return empleado;
}

bool EmpleadosArchivo::leerTodos(Empleado empleados[], int cantidad)
{
  FILE* p;
  p = fopen("empleados.dat", "rb");
  if (p == NULL)
  {
    return false;
  }
  fread(empleados, sizeof(Empleado), cantidad, p);
  fclose(p);
  return true;
}

bool EmpleadosArchivo::guardar(Empleado empleado)
{
  FILE* p = fopen("empleados.dat", "ab");
  if (p == NULL)
  {
    return false;
  }
  bool ok = fwrite(&empleado, sizeof(Empleado), 1, p);
  fclose(p);
  return ok;
}

bool EmpleadosArchivo::guardar(Empleado empleado, int nroRegistro)
{
  FILE* p = fopen("empleados.dat", "rb+");
  if (p == NULL)
  {
    return false;
  }
  fseek(p, nroRegistro * sizeof(Empleado), SEEK_SET);
  bool ok = fwrite(&empleado, sizeof(Empleado), 1, p);
  fclose(p);
  return ok;
}

int EmpleadosArchivo::getCantidad()
{
  FILE* p = fopen("empleados.dat", "rb");
  if (p == NULL)
  {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof(Empleado);
  fclose(p);
  return cant;
}

int EmpleadosArchivo::getCantidadActivos()
{
    Empleado obj;
    int cant = getCantidad();
    int cantActivos=0;
    for(int i=0; i<cant; i++){
        obj = leer(i);
        if(obj.getEstado())
            cantActivos++;
    }
    return cantActivos;
}

int EmpleadosArchivo::buscar(int dni)
{
  int cant = getCantidad();
  Empleado empleado;
  for (int i = 0; i < cant; i++)
  {
    empleado = leer(i);
    if (empleado.getDni() == dni)
    {
      return i;
    }
  }
  return -1;
}

bool EmpleadosArchivo::importarCSV(){
    system("cls");
    string nomArchivo = "empleados.csv";
    int cantRegistros=0, cantCampos=8;
    Empleado empleado;

    vector<vector<string>> contenido;
    vector<string> fila;
    string registro, campo;

    fstream file (nomArchivo, ios::in);
    if(file.is_open())
    {
        while(getline(file, registro))
        {
            fila.clear();
            stringstream str(registro);

            while(getline(str, campo, ';'))
                fila.push_back(campo);
            contenido.push_back(fila);
        }
    }
    else
    {
        cout<<"No se pudo abrir el archivo CSV."<<endl;
        return false;
    }


    cantRegistros = contenido.size();

    if (!eliminarArchivoDAT()){
        cout<<"Error al eliminar el archivo .DAT!"<<endl;
        return false;
    }

    for(int i=0;i<cantRegistros;i++)
    {
        if (i!=0){
            for(int j=0;j<cantCampos;j++)
            {
                switch(j)
                {
                    /*
                    int dni;
                    char nombre[50];
                    char apellido[50];
                    int telefono;
                    char email[50];
                    bool estado;

                    float PorcentajeComision;
                    float SueldoFijo;
                    */
                    case 0:
                        empleado.setDni(stoi(contenido[i][j]));
                        break;
                    case 1:
                        empleado.setNombre(contenido[i][j]);
                        break;
                    case 2:
                        empleado.setApellido(contenido[i][j]);
                        break;
                    case 3:
                        empleado.setTelefono(stoi(contenido[i][j]));
                        break;
                    case 4:
                        empleado.setEmail(contenido[i][j]);
                        break;
                    case 5:
                        empleado.setEstado(stoi(contenido[i][j]));
                        break;
                    case 6:
                        empleado.setPComision(stof(contenido[i][j]));
                        break;
                    case 7:
                        empleado.setSueldoF(stof(contenido[i][j]));
                        break;
                }
            }
            guardar(empleado);
        }
    }
    return true;
}

bool EmpleadosArchivo::exportarCSV(){
    system("cls");
    int cantRegistros = getCantidad();
    Empleado* vec = new Empleado[cantRegistros];
    ofstream archivoCSV;
    archivoCSV.open("empleados.csv");
    if(!archivoCSV.is_open()){
        cout<<"No se pudo abrir el archivo CSV."<<endl;
        delete vec;
        return false;
    }
    archivoCSV << "dni;nombre;apellido;telefono;email;estado;porcentajeComision;sueldoFijo" << endl;
    if(!leerTodos(vec, cantRegistros)){
        cout<<"No se pudo leer el archivo DAT."<<endl;
        archivoCSV.close();
        delete vec;
        return false;
    }
    for(int i=0; i<cantRegistros; i++){
        /*
        int dni;
        char nombre[50];
        char apellido[50];
        int telefono;
        char email[50];
        bool estado;

        float PorcentajeComision;
        float SueldoFijo;
        */
        archivoCSV  << vec[i].getDni() << ";"
                    << vec[i].getNombre() << ";"
                    << vec[i].getApellido() << ";"
                    << vec[i].getTelefono()  << ";"
                    << vec[i].getEmail() << ";"
                    << vec[i].getEstado() << ";"
                    << vec[i].getPComision() << ";"
                    << vec[i].getSueldoF() << endl;
    }
    archivoCSV.close();
    delete vec;
    return true;
}

bool EmpleadosArchivo::eliminarArchivoDAT(){
    int eliminado;
    eliminado = remove("empleados.dat");
    if(eliminado!=0)
        return false;
    return true;
}
