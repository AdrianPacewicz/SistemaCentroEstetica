#include <iostream>
#include "Cliente.h"
#include "rlutil.h"

void Cliente::cargar(){
    /*
    int dni;
    char nombre[50];
    char apellido[50];
    int telefono;
    char email[50];
    bool estado;
    */
    int entero;
    string cadena;
    // TODO: Validaciones
    cout<<"  Nombre: ";
    getline(cin, cadena);
    setNombre(cadena);
    cout<<"  Apellido: ";
    getline(cin, cadena);
    setApellido(cadena);
    cout<<"  Telefono: ";
    cin>>entero;
    setTelefono(entero);
    cout<<"  Email: ";
    cin.ignore();
    getline(cin, cadena);
    setEmail(cadena);
    cout<<"  Cargado con exito."<<endl;
    rlutil::anykey();
}

string Cliente::toString(){
    string cliente;
    cliente = Persona::toString();
    return cliente;
}

