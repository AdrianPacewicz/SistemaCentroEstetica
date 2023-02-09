#include <iostream>
#include "Empleado.h"
#include "rlutil.h"

float Empleado::getPComision(){
    return porcentajeComision;
}

float Empleado::getSueldoF(){
    return sueldoFijo;
}

void Empleado::setPComision(float _PCom){
    porcentajeComision=_PCom;
}

void Empleado::setSueldoF(float _SueldoF){
    sueldoFijo=_SueldoF;
}

void Empleado::cargar(){
    string cadena;
    Persona::cargar ();
    /*
        float porcentajeComision;
        float sueldoFijo;
    */
    // TODO: Validaciones
    cout<<"  Porcentaje Comision: ";
    getline(cin, cadena);
    setPComision(stof(cadena));
    cout<<"  Sueldo fijo: ";
    getline(cin, cadena);
    setSueldoF(stof(cadena));

    cout<<"  Cargado con exito."<<endl;
    rlutil::anykey();
}

string Empleado::toString(){
    string empleado;
    empleado = Persona::toString()+"\t|\t"+to_string(porcentajeComision)+"%\t|\t"+to_string(sueldoFijo);
    return empleado;
}
