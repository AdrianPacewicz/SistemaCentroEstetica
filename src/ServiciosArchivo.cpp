#include "ServiciosArchivo.h"
#include <iostream> // cout
#include <fstream>  // fstream importar CSV
#include <vector>   // vector importar CSV
#include <sstream>  // stringstream importar CSV
#include <stdio.h>  // remove .dat
#include <sys/stat.h> // stat verificar que existe archivo antes de eliminar
#include <iomanip>

Servicio ServiciosArchivo::leer(int nroRegistro)
{
  Servicio servicio;
  FILE* p;
  p = fopen("servicios.dat", "rb");
  if (p == NULL)
  {
    return servicio;
  }
  fseek(p, nroRegistro * sizeof(Servicio), SEEK_SET);
  fread(&servicio, sizeof(Servicio), 1, p);
  fclose(p);
  return servicio;
}

bool ServiciosArchivo::leerTodos(Servicio servicios[], int cantidad)
{
  FILE* p;
  p = fopen("servicios.dat", "rb");
  if (p == NULL)
  {
    return false;
  }
  fread(servicios, sizeof(Servicio), cantidad, p);
  fclose(p);
  return true;
}

bool ServiciosArchivo::guardar(Servicio servicio)
{
  FILE* p = fopen("servicios.dat", "ab");
  if (p == NULL)
  {
    return false;
  }
  bool ok = fwrite(&servicio, sizeof(Servicio), 1, p);
  fclose(p);
  return ok;
}

bool ServiciosArchivo::guardar(Servicio servicio, int nroRegistro)
{
  FILE* p = fopen("servicios.dat", "rb+");
  if (p == NULL)
  {
    return false;
  }
  fseek(p, nroRegistro * sizeof(Servicio), SEEK_SET);
  bool ok = fwrite(&servicio, sizeof(Servicio), 1, p);
  fclose(p);
  return ok;
}

int ServiciosArchivo::getCantidad()
{
  FILE* p = fopen("servicios.dat", "rb");
  if (p == NULL)
  {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof(Servicio);
  fclose(p);
  return cant;
}

int ServiciosArchivo::getCantidadActivos()
{
    Servicio obj;
    int cant = getCantidad();
    int cantActivos=0;
    for(int i=0; i<cant; i++){
        obj = leer(i);
        if(obj.getEstado())
            cantActivos++;
    }
    return cantActivos;
}

int ServiciosArchivo::buscar(int codigo)
{
  int cant = getCantidad();
  Servicio servicio;
  for (int i = 0; i < cant; i++)
  {
    servicio = leer(i);
    if (servicio.getCodigo() == codigo)
    {
      return i;
    }
  }
  return -1;
}

bool ServiciosArchivo::importarCSV(){
    system("cls");
    string nomArchivo = "servicios.csv";
    int cantRegistros=0, cantCampos=5;
    Servicio servicio;

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
                    int codigo;
                    char nombre[50];
                    double valor;
                    int codCategoria;
                    bool estado;
                    */
                    case 0:
                        servicio.setCodigo(stoi(contenido[i][j]));
                        break;
                    case 1:
                        servicio.setNombre(contenido[i][j]);
                        break;
                    case 2:
                        servicio.setValor(stod(contenido[i][j]));
                        break;
                    case 3:
                        servicio.setCodCategoria(stoi(contenido[i][j]));
                        break;
                    case 4:
                        servicio.setEstado(stoi(contenido[i][j]));
                        break;
                }
            }
            guardar(servicio);
        }
    }
    return true;
}

bool ServiciosArchivo::exportarCSV(){
    system("cls");
    int cantRegistros = getCantidad();
    Servicio* vec = new Servicio[cantRegistros];
    ofstream archivoCSV;
    archivoCSV.open("servicios.csv");
    if(!archivoCSV.is_open()){
        cout<<"No se pudo abrir el archivo CSV."<<endl;
        delete vec;
        return false;
    }
    archivoCSV << "codigo;nombre;valor;codCategoria;estado" << endl;
    if(!leerTodos(vec, cantRegistros)){
        cout<<"No se pudo leer el archivo DAT."<<endl;
        archivoCSV.close();
        delete vec;
        return false;
    }
    for(int i=0; i<cantRegistros; i++){
        /*
        int codigo;
        char nombre[50];
        double valor;
        int codCategoria;
        bool estado;
        */
        archivoCSV  << vec[i].getCodigo() << ";"
                    << vec[i].getNombre() << ";"
                    << fixed << setprecision(2) << vec[i].getValor() << ";"
                    << vec[i].getCodCategoria()  << ";"
                    << vec[i].getEstado() << endl;
    }
    archivoCSV.close();
    delete vec;
    return true;
}

bool ServiciosArchivo::eliminarArchivoDAT(){
    bool existe=false;
    int eliminado;
    struct stat buffer;
    existe = (stat ("servicios.dat", &buffer) == 0);
    if (!existe)
        eliminado=0;
    else{
        eliminado = remove("servicios.dat");
    }
    if(eliminado!=0)
        return false;
    return true;
}
