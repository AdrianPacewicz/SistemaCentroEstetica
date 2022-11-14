#include "GastosGeneralesArchivo.h"
#include <iostream> // cout
#include <fstream>  // fstream importar CSV
#include <vector>   // vector importar CSV
#include <sstream>  // stringstream importar CSV
#include <stdio.h>  // remove .dat

GastoGeneral GastosGeneralesArchivo::leer(int nroRegistro)
{
  GastoGeneral gastoGeneral;
  FILE* p;
  p = fopen("gastosGenerales.dat", "rb");
  if (p == NULL)
  {
    return gastoGeneral;
  }
  fseek(p, nroRegistro * sizeof(GastoGeneral), SEEK_SET);
  fread(&gastoGeneral, sizeof(GastoGeneral), 1, p);
  fclose(p);
  return gastoGeneral;
}

bool GastosGeneralesArchivo::leerTodos(GastoGeneral gastosGenerales[], int cantidad)
{
  FILE* p;
  p = fopen("gastosGenerales.dat", "rb");
  if (p == NULL)
  {
    return false;
  }
  fread(gastosGenerales, sizeof(GastoGeneral), cantidad, p);
  fclose(p);
  return true;
}

bool GastosGeneralesArchivo::guardar(GastoGeneral gastoGeneral)
{
  FILE* p = fopen("gastosGenerales.dat", "ab");
  if (p == NULL)
  {
    return false;
  }
  bool ok = fwrite(&gastoGeneral, sizeof(GastoGeneral), 1, p);
  fclose(p);
  return ok;
}

bool GastosGeneralesArchivo::guardar(GastoGeneral gastoGeneral, int nroRegistro)
{
  FILE* p = fopen("gastosGenerales.dat", "rb+");
  if (p == NULL)
  {
    return false;
  }
  fseek(p, nroRegistro * sizeof(GastoGeneral), SEEK_SET);
  bool ok = fwrite(&gastoGeneral, sizeof(GastoGeneral), 1, p);
  fclose(p);
  return ok;
}

int GastosGeneralesArchivo::getCantidad()
{
  FILE* p = fopen("gastosGenerales.dat", "rb");
  if (p == NULL)
  {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof(GastoGeneral);
  fclose(p);
  return cant;
}

int GastosGeneralesArchivo::getCantidadActivos()
{
    GastoGeneral obj;
    int cant = getCantidad();
    int cantActivos=0;
    for(int i=0; i<cant; i++){
        obj = leer(i);
        if(obj.getEstado())
            cantActivos++;
    }
    return cantActivos;
}

int GastosGeneralesArchivo::buscar(int id)
{
  int cant = getCantidad();
  GastoGeneral gastoGeneral;
  for (int i = 0; i < cant; i++)
  {
    gastoGeneral = leer(i);
    if (gastoGeneral.getId() == id)
    {
      return i;
    }
  }
  return -1;
}

bool GastosGeneralesArchivo::importarCSV(){
    system("cls");
    string nomArchivo = "gastosGenerales.csv";
    int cantRegistros=0, cantCampos=7;
    GastoGeneral gastoGeneral;

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

                    char detalle[100];
                    */
                    case 0:
                        gastoGeneral.setId(stoi(contenido[i][j]));
                        break;
                    case 1:
                        f.setAnio(stoi(contenido[i][j]));
                        break;
                    case 2:
                        f.setMes(stoi(contenido[i][j]));
                        break;
                    case 3:
                        f.setDia(stoi(contenido[i][j]));
                        gastoGeneral.setFecha(f);
                        break;
                    case 4:
                        gastoGeneral.setImporte(stof(contenido[i][j]));
                        break;
                    case 5:
                        gastoGeneral.setEstado(stoi(contenido[i][j]));
                        break;
                    case 6:
                        gastoGeneral.setDetalle(contenido[i][j]);
                        break;
                }
            }
            guardar(gastoGeneral);
        }
    }
    return true;
}

bool GastosGeneralesArchivo::exportarCSV(){
    system("cls");
    int cantRegistros = getCantidad();
    GastoGeneral* vec = new GastoGeneral[cantRegistros];
    ofstream archivoCSV;
    archivoCSV.open("gastosGenerales.csv");
    if(!archivoCSV.is_open()){
        cout<<"No se pudo abrir el archivo CSV."<<endl;
        delete vec;
        return false;
    }
    archivoCSV << "id;anio;mes;dia;importe;estado;detalle" << endl;
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

        char detalle[100];
        */
        archivoCSV  << vec[i].getId() << ";"
                    << vec[i].getFecha().getAnio() << ";"
                    << vec[i].getFecha().getMes() << ";"
                    << vec[i].getFecha().getDia()  << ";"
                    << vec[i].getImporte() << ";"
                    << vec[i].getEstado() << ";"
                    << vec[i].getDetalle() << endl;
    }
    archivoCSV.close();
    delete vec;
    return true;
}

bool GastosGeneralesArchivo::eliminarArchivoDAT(){
    int eliminado;
    eliminado = remove("gastosGenerales.dat");
    if(eliminado!=0)
        return false;
    return true;
}
