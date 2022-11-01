#include <iostream>
#include <cstring>
#include "Categoria.h"

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
    // ToDo
}

string Categoria::toString(){
    string categoria;
    categoria = to_string(codigo) + ": " + nombre;
    return categoria;
}
