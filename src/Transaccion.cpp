#include <iostream>
#include "Transaccion.h"

int Transaccion::getId(){
    return id;
}

Fecha Transaccion::getFecha(){
    return fecha;
}

float Transaccion::getImporte(){
    return importe;
}

bool Transaccion::getEstado(){
    return estado;
}

void Transaccion::setId(int _id){
    id = _id;
}

void Transaccion::setFecha(Fecha _fecha){
    fecha=_fecha;
}

void Transaccion::setImporte(float _importe){
    importe = _importe;
}

void Transaccion::setEstado(bool _est){
    estado = _est;
}

void Transaccion::cargar(){

}

string Transaccion::toString(){

}
