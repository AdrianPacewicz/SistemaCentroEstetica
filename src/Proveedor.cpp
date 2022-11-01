#include <iostream>
#include <cstring>
#include "Proveedor.h"

int Proveedor::getCuil(){
    return cuil;
}

string Proveedor::getRazonS(){
    string r = razonSocial;
    return r;
}

int Proveedor::getCodCategoria(){
    return codCategoria;
}

int Proveedor::getTelefono(){
    return telefono;
}

string Proveedor::getEmail(){
    string e = email;
    return e;
}

bool Proveedor::getEstado(){
    return estado;
}

void Proveedor::setCuil(int _cuil){
    cuil = _cuil;
}

void Proveedor::setRazonSocial(string _razonSocial){
    strcpy(razonSocial,_razonSocial.c_str());
}

void Proveedor::setCodCategoria(int _codCategoria){
    codCategoria = _codCategoria;
}

void Proveedor::setTelefono(int _telefono){
    telefono = _telefono;
}

void Proveedor::setEmail(string _email){
    strcpy(email,_email.c_str());
}

void Proveedor::setEstado(bool _estado){
    estado = _estado;
}

void Proveedor::cargar(){

}

string Proveedor::toString(){

}
