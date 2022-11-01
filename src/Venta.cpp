#include <iostream>
#include <cstring>
#include "Venta.h"

int Venta::getEmpleado(){
    return nEmpleado;
}

int Venta::getCliente(){
    return nCliente;
}

int Venta::getServicio(){
    return nServicio;
}

string Venta::getObs(){
    string o = observacion;
    return o;
}

void Venta::setEmpleado(int empleado){
    nEmpleado = empleado;
}

void Venta::setCliente(int cliente){
    nCliente = cliente;
}

void Venta::setServicio(int servicio){
    nServicio = servicio;
}

void Venta::setObs(string _observacion){
    strcpy(observacion,_observacion.c_str());
}

void Venta::cargar(){

}

string Venta::toString(){

}
