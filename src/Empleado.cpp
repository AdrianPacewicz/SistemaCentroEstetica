#include <iostream>
#include "Empleado.h"

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
}

string Empleado::toString(){
    string empleado;
    empleado = Persona::toString()+"\t|\t"+to_string(porcentajeComision)+"%\t|\t"+to_string(sueldoFijo);
    return empleado;
}
