#include <iostream>
#include "Empleado.h"

float Empleado::getPComision(){
    return PorcentajeComision;
}

float Empleado::getSueldoF(){
    return SueldoFijo;
}

void Empleado::setPComision(float _PCom){
    PorcentajeComision=_PCom;
}

void Empleado::setSueldoF(float _SueldoF){
    SueldoFijo=_SueldoF;
}

void Empleado::cargar(){
}

string Empleado::toString(){

}
