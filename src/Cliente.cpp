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
    Persona::cargar ();
    cout<<"  Cargado con exito."<<endl;
    rlutil::anykey();
}

string Cliente::toString(){
    string cliente;
    cliente = Persona::toString();
    return cliente;
}

