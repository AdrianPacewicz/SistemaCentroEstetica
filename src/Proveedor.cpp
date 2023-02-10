#include <iostream>
#include <cstring>
#include "Proveedor.h"
#include "CategoriasArchivo.h"
#include "rlutil.h"

string Proveedor::getCuil(){
    string _cuil = cuil;
    return _cuil;
}

string Proveedor::getRazonS(){
    string r = razonSocial;
    return r;
}

int Proveedor::getCodCategoria(){
    return codCategoria;
}

string Proveedor::getTelefono(){
    string t = telefono;
    return t;
}

string Proveedor::getEmail(){
    string e = email;
    return e;
}

bool Proveedor::getEstado(){
    return estado;
}

void Proveedor::setCuil(string _cuil){
    strcpy(cuil,_cuil.c_str());
}

void Proveedor::setRazonSocial(string _razonSocial){
    strcpy(razonSocial,_razonSocial.c_str());
}

void Proveedor::setCodCategoria(int _codCategoria){
    codCategoria = _codCategoria;
}

void Proveedor::setTelefono(string _telefono){
    strcpy(telefono,_telefono.c_str());
}

void Proveedor::setEmail(string _email){
    strcpy(email,_email.c_str());
}

void Proveedor::setEstado(bool _estado){
    estado = _estado;
}

bool Proveedor::cargar(){
    string cadena;
    int valor;
    CategoriasArchivo archivo;

    do{
        cout<<"  Razon social: ";
        getline(cin, cadena);
    }while(cadena == "");
    setRazonSocial(cadena);

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

    cout<<"  Telefono: ";
    getline(cin, cadena);
    setTelefono(cadena);
    cout<<"  Email: ";
    getline(cin, cadena);
    setEmail(cadena);
    cout<<"  Cargado con exito. (Codigo(CUIL): "<<cuil<<")"<<endl;
    rlutil::anykey();
}

string Proveedor::toString(){
    string proveedor;
    proveedor = getCuil() + "\t| " + razonSocial + "\t| " + to_string(codCategoria) + "\t| " + telefono + "\t| " + email;
    //proveedor = "";
    return proveedor;
}
