#include "PagosEmpleadosArchivo.h"
#include <iostream> // cout
#include <fstream>  // fstream importar CSV
#include <vector>   // vector importar CSV
#include <sstream>  // stringstream importar CSV
#include <stdio.h>  // remove .dat

PagoEmpleado PagosEmpleadosArchivo::leer(int nroRegistro)
{
  PagoEmpleado pagoEmpleado;
  FILE* p;
  p = fopen("pagosEmpleados.dat", "rb");
  if (p == NULL)
  {
    return pagoEmpleado;
  }
  fseek(p, nroRegistro * sizeof(PagoEmpleado), SEEK_SET);
  fread(&pagoEmpleado, sizeof(PagoEmpleado), 1, p);
  fclose(p);
  return pagoEmpleado;
}

bool PagosEmpleadosArchivo::leerTodos(PagoEmpleado pagosEmpleados[], int cantidad)
{
  FILE* p;
  p = fopen("pagosEmpleados.dat", "rb");
  if (p == NULL)
  {
    return false;
  }
  fread(pagosEmpleados, sizeof(PagoEmpleado), cantidad, p);
  fclose(p);
  return true;
}

bool PagosEmpleadosArchivo::guardar(PagoEmpleado pagoEmpleado)
{
  FILE* p = fopen("pagosEmpleados.dat", "ab");
  if (p == NULL)
  {
    return false;
  }
  bool ok = fwrite(&pagoEmpleado, sizeof(PagoEmpleado), 1, p);
  fclose(p);
  return ok;
}

bool PagosEmpleadosArchivo::guardar(PagoEmpleado pagoEmpleado, int nroRegistro)
{
  FILE* p = fopen("pagosEmpleados.dat", "rb+");
  if (p == NULL)
  {
    return false;
  }
  fseek(p, nroRegistro * sizeof(PagoEmpleado), SEEK_SET);
  bool ok = fwrite(&pagoEmpleado, sizeof(PagoEmpleado), 1, p);
  fclose(p);
  return ok;
}

int PagosEmpleadosArchivo::getCantidad()
{
  FILE* p = fopen("pagosEmpleados.dat", "rb");
  if (p == NULL)
  {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof(PagoEmpleado);
  fclose(p);
  return cant;
}

int PagosEmpleadosArchivo::getCantidadActivos()
{
    PagoEmpleado obj;
    int cant = getCantidad();
    int cantActivos=0;
    for(int i=0; i<cant; i++){
        obj = leer(i);
        if(obj.getEstado())
            cantActivos++;
    }
    return cantActivos;
}

int PagosEmpleadosArchivo::buscar(int id)
{
  int cant = getCantidad();
  PagoEmpleado pagoEmpleado;
  for (int i = 0; i < cant; i++)
  {
    pagoEmpleado = leer(i);
    if (pagoEmpleado.getId() == id)
    {
      return i;
    }
  }
  return -1;
}

bool PagosEmpleadosArchivo::importarCSV(){
    system("cls");
    string nomArchivo = "pagosEmpleados.csv";
    int cantRegistros=0, cantCampos=8;
    PagoEmpleado pagoEmpleado;

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
            Fecha f;
            for(int j=0;j<cantCampos;j++)
            {
                switch(j)
                {
                    /*
                    int id;
                    Fecha fecha;
                    float importe;
                    bool estado;

                    int idEmpleado;
                    char detalle[100];
                    */
                    case 0:
                        pagoEmpleado.setId(stoi(contenido[i][j]));
                        break;
                    case 1:
                        f.setAnio(stoi(contenido[i][j]));
                        break;
                    case 2:
                        f.setMes(stoi(contenido[i][j]));
                        break;
                    case 3:
                        f.setDia(stoi(contenido[i][j]));
                        pagoEmpleado.setFecha(f);
                        break;
                    case 4:
                        pagoEmpleado.setImporte(stof(contenido[i][j]));
                        break;
                    case 5:
                        pagoEmpleado.setEstado(stoi(contenido[i][j]));
                        break;
                    case 6:
                        pagoEmpleado.setIdE(stoi(contenido[i][j]));
                        break;
                    case 7:
                        pagoEmpleado.setDetalle(contenido[i][j]);
                        break;
                }
            }
            guardar(pagoEmpleado);
        }
    }
    return true;
}

bool PagosEmpleadosArchivo::exportarCSV(){
    system("cls");
    int cantRegistros = getCantidad();
    PagoEmpleado* vec = new PagoEmpleado[cantRegistros];
    ofstream archivoCSV;
    archivoCSV.open("pagosEmpleados.csv");
    if(!archivoCSV.is_open()){
        cout<<"No se pudo abrir el archivo CSV."<<endl;
        delete vec;
        return false;
    }
    archivoCSV << "id;anio;mes;dia;importe;estado;dniEmpleado;detalle" << endl;
    if(!leerTodos(vec, cantRegistros)){
        cout<<"No se pudo leer el archivo DAT."<<endl;
        archivoCSV.close();
        delete vec;
        return false;
    }
    for(int i=0; i<cantRegistros; i++){
        /*
        int id;
        Fecha fecha;
        float importe;
        bool estado;

        int idEmpleado;
        char detalle[100];
        */
        archivoCSV  << vec[i].getId() << ";"
                    << vec[i].getFecha().getAnio() << ";"
                    << vec[i].getFecha().getMes() << ";"
                    << vec[i].getFecha().getDia()  << ";"
                    << vec[i].getImporte() << ";"
                    << vec[i].getEstado() << ";"
                    << vec[i].getIdE() << ";"
                    << vec[i].getDetalle() << endl;
    }
    archivoCSV.close();
    delete vec;
    return true;
}

bool PagosEmpleadosArchivo::eliminarArchivoDAT(){
    int eliminado;
    eliminado = remove("pagosEmpleados.dat");
    if(eliminado!=0)
        return false;
    return true;
}
