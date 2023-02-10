#include <iostream>
#include <cstring>
#include "Servicio.h"
#include "CategoriasArchivo.h"
#include "rlutil.h"

int Servicio::getCodigo(){
    return codigo;
}

string Servicio::getNombre(){
    string n = nombre;
    return n;
}

float Servicio::getValor(){
    return valor;
}

int Servicio::getCodCategoria(){
    return codCategoria;
}

bool Servicio::getEstado(){
    return estado;
}

void Servicio::setCodigo(int _codigo){
    codigo= _codigo;
}

void Servicio::setNombre(string _nombre){
    strcpy(nombre,_nombre.c_str());
}

void Servicio::setValor(float _valor){
    valor= _valor;
}

void Servicio::setCodCategoria(int _codCateg){
    codCategoria = _codCateg;
}

void Servicio::setEstado(bool _estado){
    estado= _estado;
}

bool Servicio::cargar(){
    string cadena;
    CategoriasArchivo archivo;
    /*
    int codigo;
    char nombre[50];
    float valor;
    int codCategoria;
    bool estado;
    */
    do{
        cout<<"  Nombre: ";
        getline(cin, cadena);
    }while(cadena == "");
    setNombre(cadena);
    cout<<"  Valor servicio: ";
    getline(cin, cadena);
    setValor(stof(cadena));
    do
    {
        cout<<"  Codigo categoria: ";
        getline(cin, cadena);
    }
    while(cadena == "");
    if(archivo.buscar(stoi(cadena)) == -1)
    {
        cout<<"  ERROR: La categoria no existe.";
        rlutil::anykey();
        return false;
    }
    else
    {
        setCodCategoria(stoi(cadena));
    }
    cout<<"  Cargado con exito. (Codigo: "<<codigo<<")"<<endl;
    rlutil::anykey();
}

string Servicio::toString(){
    string servicio;
    servicio = to_string(codigo) + "\t|\t" + nombre + "\t|\t" + to_string(valor) + "\t|\t" + to_string(codCategoria);
    return servicio;
}
