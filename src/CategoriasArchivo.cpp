#include "CategoriasArchivo.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdio.h>

Categoria CategoriasArchivo::leer(int nroRegistro)
{
  Categoria categoria;
  FILE* p;
  p = fopen("categorias.dat", "rb");
  if (p == NULL)
  {
    return categoria;
  }
  fseek(p, nroRegistro * sizeof(Categoria), SEEK_SET);
  fread(&categoria, sizeof(Categoria), 1, p);
  fclose(p);
  return categoria;
}

bool CategoriasArchivo::leerTodos(Categoria categorias[], int cantidad)
{
  FILE* p;
  p = fopen("categorias.dat", "rb");
  if (p == NULL)
  {
    return false;
  }
  fread(categorias, sizeof(Categoria), cantidad, p);
  fclose(p);
  return true;
}

bool CategoriasArchivo::guardar(Categoria categoria)
{
  FILE* p = fopen("categorias.dat", "ab");
  if (p == NULL)
  {
    return false;
  }
  bool ok = fwrite(&categoria, sizeof(Categoria), 1, p);
  fclose(p);
  return ok;
}

bool CategoriasArchivo::guardar(Categoria categoria, int nroRegistro)
{
  FILE* p = fopen("categorias.dat", "rb+");
  if (p == NULL)
  {
    return false;
  }
  fseek(p, nroRegistro * sizeof(Categoria), SEEK_SET);
  bool ok = fwrite(&categoria, sizeof(Categoria), 1, p);
  fclose(p);
  return ok;
}

int CategoriasArchivo::getCantidad()
{
  FILE* p = fopen("categorias.dat", "rb");
  if (p == NULL)
  {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof(Categoria);
  fclose(p);
  return cant;
}

int CategoriasArchivo::buscar(int codigo)
{
  int cant = getCantidad();
  Categoria categoria;
  for (int i = 0; i < cant; i++)
  {
    categoria = leer(i);
    if (categoria.getCodigo() == codigo)
    {
      return i;
    }
  }
  return -1;
}

bool CategoriasArchivo::importarCSV(){
    system("cls");
    string nomArchivo = "Categorias.csv";
    int cantRegistros=0, cantCampos=3;
    Categoria categoria;

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

    if (!eliminarCategoriasArchivo()){
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
                    case 0:
                        categoria.setCodigo(stoi(contenido[i][j]));
                        break;
                    case 1:
                        categoria.setNombre(contenido[i][j]);
                        break;
                    case 2:
                        categoria.setEstado(stoi(contenido[i][j]));
                        break;
                }
            }
            guardar(categoria);
        }
    }
    return true;
}

bool CategoriasArchivo::exportarCSV(){
    system("cls");
    int cantidadCategorias = getCantidad();
    Categoria* vecCategorias = new Categoria[cantidadCategorias];
    ofstream archivoCSV;
    archivoCSV.open("Categorias.csv");
    if(!archivoCSV.is_open()){
        cout<<"No se pudo abrir el archivo CSV."<<endl;
        delete vecCategorias;
        return false;
    }
    archivoCSV << "codigo;nombre;estado" << endl;
    if(!leerTodos(vecCategorias, cantidadCategorias)){
        cout<<"No se pudo leer el archivo DAT."<<endl;
        archivoCSV.close();
        delete vecCategorias;
        return false;
    }
    for(int i=0; i<cantidadCategorias; i++){
        archivoCSV << vecCategorias[i].getCodigo() << ";" << vecCategorias[i].getNombre() << ";" << vecCategorias[i].getEstado() << endl;
    }
    archivoCSV.close();
    delete vecCategorias;
    return true;
}

bool CategoriasArchivo::eliminarCategoriasArchivo(){
    int eliminado;
    eliminado = remove("categorias.dat");
    if(eliminado!=0)
        return false;
    return true;
}

