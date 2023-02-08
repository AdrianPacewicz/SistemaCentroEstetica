#include <iostream>
#include <cstring>
#include "Categoria.h"
#include "rlutil.h"

int Categoria::getCodigo(){
    return codigo;
}

string Categoria::getNombre(){
    string n = nombre;
    return n;
}

bool Categoria::getEstado(){
    return estado;
}

void Categoria::setCodigo(int _codigo){
    codigo= _codigo;
}

void Categoria::setNombre(string _nombre){
    strcpy(nombre,_nombre.c_str());
}

void Categoria::setEstado(bool _estado){
    estado= _estado;
}

void Categoria::cargar(){
    /*
    --int codigo;
    char nombre[50];
    bool estado;
    */

    string nombre;
    // TODO: Validaciones
    cout<<"  Nombre de categoria: ";
    getline(cin, nombre);
    setNombre(nombre);
    cout<<"  Cargado con exito. (Codigo: "<<codigo<<")"<<endl;
    rlutil::anykey();
}

string Categoria::toString(){
    string categoria;
    categoria = to_string(codigo) + "\t| " + nombre;
    return categoria;
}
