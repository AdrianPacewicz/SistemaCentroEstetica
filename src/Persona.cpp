#include <iostream>
#include <cstring>
#include "Persona.h"

int Persona::getDni(){
    return dni;
}

string Persona::getNombre(){
    string n = nombre;
    return n;
}

string Persona::getApellido(){
    string a = apellido;
    return a;
}

string Persona::getTelefono(){
    string t = telefono;
    return t;
}

string Persona::getEmail(){
    string e = email;
    return e;
}

bool Persona::getEstado(){
    return estado;
}

void Persona::setDni(int _dni){
    dni=_dni;
}

void Persona::setNombre(string _nomb){
    strcpy(nombre,_nomb.c_str());
}

void Persona::setApellido(string _apell){
    strcpy(apellido,_apell.c_str());
}

void Persona::setTelefono(string _tel){
    strcpy(telefono,_tel.c_str());
}

void Persona::setEmail(string _email){
    strcpy(email,_email.c_str());
}

void Persona::setEstado(bool _est){
    estado = _est;
}

void Persona::cargar(){
    string cadena;
    // TODO: Validaciones
    cout<<"  Nombre: ";
    getline(cin, cadena);
    setNombre(cadena);
    cout<<"  Apellido: ";
    getline(cin, cadena);
    setApellido(cadena);
    cout<<"  Telefono: ";
    getline(cin, cadena);
    setTelefono(cadena);
    cout<<"  Email: ";
    getline(cin, cadena);
    setEmail(cadena);
}

string Persona::toString(){
    string persona;
    persona = to_string(dni) + "\t|\t" + nombre + " " + apellido + "\t|\t" + telefono + "\t|\t" + email;
    return persona;
}
