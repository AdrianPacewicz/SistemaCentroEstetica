#include <iostream>
#include <cstring>
#include "Servicio.h"

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

void Servicio::cargar(){

}

string Servicio::toString(){

}
