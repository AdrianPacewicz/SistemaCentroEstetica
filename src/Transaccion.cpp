#include <iostream>
#include "Transaccion.h"

int Transaccion::getId(){
    return id;
}

Fecha Transaccion::getFecha(){
    return fecha;
}

double Transaccion::getImporte(){
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

void Transaccion::setImporte(double _importe){
    importe = _importe;
}

void Transaccion::setEstado(bool _est){
    estado = _est;
}

void Transaccion::cargar(){

}

string Transaccion::toString(){
    string transaccion;
    transaccion = to_string(id) + "\t" + fecha.toString() + " - " + to_string(importe);
    return transaccion;
}
