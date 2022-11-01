#include <iostream>
#include <cstring>
#include "PagoEmpleado.h"

int PagoEmpleado::getIdE(){
    return idEmpleado;
}

string PagoEmpleado::getDetalle(){
    string d = detalle;
    return d;
}

void PagoEmpleado::setIdE(int _idE){
    idEmpleado = _idE;
}

void PagoEmpleado::setDetalle(string _detalle){
    strcpy(detalle,_detalle.c_str());
}

void PagoEmpleado::cargar(){

}

string PagoEmpleado::toString(){

}
