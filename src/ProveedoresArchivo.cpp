#include "ProveedoresArchivo.h"
#include <iostream> // cout
#include <fstream>  // fstream importar CSV
#include <vector>   // vector importar CSV
#include <sstream>  // stringstream importar CSV
#include <stdio.h>  // remove .dat
#include <sys/stat.h> // stat verificar que existe archivo antes de eliminar

Proveedor ProveedoresArchivo::leer(int nroRegistro)
{
  Proveedor proveedor;
  FILE* p;
  p = fopen("proveedores.dat", "rb");
  if (p == NULL)
  {
    return proveedor;
  }
  fseek(p, nroRegistro * sizeof(Proveedor), SEEK_SET);
  fread(&proveedor, sizeof(Proveedor), 1, p);
  fclose(p);
  return proveedor;
}

bool ProveedoresArchivo::leerTodos(Proveedor proveedores[], int cantidad)
{
  FILE* p;
  p = fopen("proveedores.dat", "rb");
  if (p == NULL)
  {
    return false;
  }
  fread(proveedores, sizeof(Proveedor), cantidad, p);
  fclose(p);
  return true;
}

bool ProveedoresArchivo::guardar(Proveedor proveedor)
{
  FILE* p = fopen("proveedores.dat", "ab");
  if (p == NULL)
  {
    return false;
  }
  bool ok = fwrite(&proveedor, sizeof(Proveedor), 1, p);
  fclose(p);
  return ok;
}

bool ProveedoresArchivo::guardar(Proveedor proveedor, int nroRegistro)
{
  FILE* p = fopen("proveedores.dat", "rb+");
  if (p == NULL)
  {
    return false;
  }
  fseek(p, nroRegistro * sizeof(Proveedor), SEEK_SET);
  bool ok = fwrite(&proveedor, sizeof(Proveedor), 1, p);
  fclose(p);
  return ok;
}

int ProveedoresArchivo::getCantidad()
{
  FILE* p = fopen("proveedores.dat", "rb");
  if (p == NULL)
  {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof(Proveedor);
  fclose(p);
  return cant;
}

int ProveedoresArchivo::getCantidadActivos()
{
    Proveedor obj;
    int cant = getCantidad();
    int cantActivos=0;
    for(int i=0; i<cant; i++){
        obj = leer(i);
        if(obj.getEstado())
            cantActivos++;
    }
    return cantActivos;
}

int ProveedoresArchivo::buscar(string cuil)
{
  int cant = getCantidad();
  Proveedor proveedor;
  for (int i = 0; i < cant; i++)
  {
    proveedor = leer(i);
    if (proveedor.getCuil() == cuil)
    {
      return i;
    }
  }
  return -1;
}

bool ProveedoresArchivo::importarCSV(){
    system("cls");
    string nomArchivo = "proveedores.csv";
    int cantRegistros=0, cantCampos=6;
    Proveedor proveedor;

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
                    int cuil;
                    char razonSocial[50];
                    int codCategoria;
                    char telefono[50];
                    char email[50];
                    bool estado;
                    */
                    case 0:
                        proveedor.setCuil(contenido[i][j]);
                        break;
                    case 1:
                        proveedor.setRazonSocial(contenido[i][j]);
                        break;
                    case 2:
                        proveedor.setCodCategoria(stoi(contenido[i][j]));
                        break;
                    case 3:
                        proveedor.setTelefono(contenido[i][j]);
                        break;
                    case 4:
                        proveedor.setEmail(contenido[i][j]);
                        break;
                    case 5:
                        proveedor.setEstado(stoi(contenido[i][j]));
                        break;
                }
            }
            guardar(proveedor);
        }
    }
    return true;
}

bool ProveedoresArchivo::exportarCSV(){
    system("cls");
    int cantRegistros = getCantidad();
    Proveedor* vec = new Proveedor[cantRegistros];
    ofstream archivoCSV;
    archivoCSV.open("proveedores.csv");
    if(!archivoCSV.is_open()){
        cout<<"No se pudo abrir el archivo CSV."<<endl;
        delete vec;
        return false;
    }
    archivoCSV << "cuil;razonSocial;codCategoria;telefono;email;estado" << endl;
    if(!leerTodos(vec, cantRegistros)){
        cout<<"No se pudo leer el archivo DAT."<<endl;
        archivoCSV.close();
        delete vec;
        return false;
    }
    for(int i=0; i<cantRegistros; i++){
        /*
        int cuil;
        char razonSocial[50];
        int codCategoria;
        char telefono[50];
        char email[50];
        bool estado;

        */
        archivoCSV  << vec[i].getCuil() << ";"
                    << vec[i].getRazonS() << ";"
                    << vec[i].getCodCategoria() << ";"
                    << vec[i].getTelefono()  << ";"
                    << vec[i].getEmail() << ";"
                    << vec[i].getEstado() << endl;
    }
    archivoCSV.close();
    delete vec;
    return true;
}

bool ProveedoresArchivo::eliminarArchivoDAT(){
    bool existe=false;
    int eliminado;
    struct stat buffer;
    existe = (stat ("proveedores.dat", &buffer) == 0);
    if (!existe)
        eliminado=0;
    else{
        eliminado = remove("proveedores.dat");
    }
    if(eliminado!=0)
        return false;
    return true;
}
