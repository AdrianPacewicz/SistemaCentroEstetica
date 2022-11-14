#include "VentasArchivo.h"
#include <iostream> // cout
#include <fstream>  // fstream importar CSV
#include <vector>   // vector importar CSV
#include <sstream>  // stringstream importar CSV
#include <stdio.h>  // remove .dat

Venta VentasArchivo::leer(int nroRegistro)
{
  Venta venta;
  FILE* p;
  p = fopen("ventas.dat", "rb");
  if (p == NULL)
  {
    return venta;
  }
  fseek(p, nroRegistro * sizeof(Venta), SEEK_SET);
  fread(&venta, sizeof(Venta), 1, p);
  fclose(p);
  return venta;
}

bool VentasArchivo::leerTodos(Venta ventas[], int cantidad)
{
  FILE* p;
  p = fopen("ventas.dat", "rb");
  if (p == NULL)
  {
    return false;
  }
  fread(ventas, sizeof(Venta), cantidad, p);
  fclose(p);
  return true;
}

bool VentasArchivo::guardar(Venta venta)
{
  FILE* p = fopen("ventas.dat", "ab");
  if (p == NULL)
  {
    return false;
  }
  bool ok = fwrite(&venta, sizeof(Venta), 1, p);
  fclose(p);
  return ok;
}

bool VentasArchivo::guardar(Venta venta, int nroRegistro)
{
  FILE* p = fopen("ventas.dat", "rb+");
  if (p == NULL)
  {
    return false;
  }
  fseek(p, nroRegistro * sizeof(Venta), SEEK_SET);
  bool ok = fwrite(&venta, sizeof(Venta), 1, p);
  fclose(p);
  return ok;
}

int VentasArchivo::getCantidad()
{
  FILE* p = fopen("ventas.dat", "rb");
  if (p == NULL)
  {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof(Venta);
  fclose(p);
  return cant;
}

int VentasArchivo::getCantidadActivos()
{
    Venta obj;
    int cant = getCantidad();
    int cantActivos=0;
    for(int i=0; i<cant; i++){
        obj = leer(i);
        if(obj.getEstado())
            cantActivos++;
    }
    return cantActivos;
}

int VentasArchivo::buscar(int id)
{
  int cant = getCantidad();
  Venta venta;
  for (int i = 0; i < cant; i++)
  {
    venta = leer(i);
    if (venta.getId() == id)
    {
      return i;
    }
  }
  return -1;
}

bool VentasArchivo::importarCSV(){
    system("cls");
    string nomArchivo = "ventas.csv";
    int cantRegistros=0, cantCampos=10;
    Venta venta;

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

                    int nEmpleado;
                    int nCliente;
                    int nServicio;
                    char observacion[100];
                    */
                    case 0:
                        venta.setId(stoi(contenido[i][j]));
                        break;
                    case 1:
                        f.setAnio(stoi(contenido[i][j]));
                        break;
                    case 2:
                        f.setMes(stoi(contenido[i][j]));
                        break;
                    case 3:
                        f.setDia(stoi(contenido[i][j]));
                        venta.setFecha(f);
                        break;
                    case 4:
                        venta.setImporte(stof(contenido[i][j]));
                        break;
                    case 5:
                        venta.setEstado(stoi(contenido[i][j]));
                        break;
                    case 6:
                        venta.setEmpleado(stoi(contenido[i][j]));
                        break;
                    case 7:
                        venta.setCliente(stoi(contenido[i][j]));
                        break;
                    case 8:
                        venta.setServicio(stoi(contenido[i][j]));
                        break;
                    case 9:
                        venta.setObs(contenido[i][j]);
                        break;
                }
            }
            guardar(venta);
        }
    }
    return true;
}

bool VentasArchivo::exportarCSV(){
    system("cls");
    int cantRegistros = getCantidad();
    Venta* vec = new Venta[cantRegistros];
    ofstream archivoCSV;
    archivoCSV.open("ventas.csv");
    if(!archivoCSV.is_open()){
        cout<<"No se pudo abrir el archivo CSV."<<endl;
        delete vec;
        return false;
    }
    archivoCSV << "id;anio;mes;dia;importe;estado;dniEmpleado;dniCliente;idServicio;observacion" << endl;
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

        int nEmpleado;
        int nCliente;
        int nServicio;
        char observacion[100];
        */
        archivoCSV  << vec[i].getId() << ";"
                    << vec[i].getFecha().getAnio() << ";"
                    << vec[i].getFecha().getMes() << ";"
                    << vec[i].getFecha().getDia()  << ";"
                    << vec[i].getImporte() << ";"
                    << vec[i].getEstado() << ";"
                    << vec[i].getEmpleado() << ";"
                    << vec[i].getCliente() << ";"
                    << vec[i].getServicio() << ";"
                    << vec[i].getObs() << endl;
    }
    archivoCSV.close();
    delete vec;
    return true;
}

bool VentasArchivo::eliminarArchivoDAT(){
    int eliminado;
    eliminado = remove("ventas.dat");
    if(eliminado!=0)
        return false;
    return true;
}
