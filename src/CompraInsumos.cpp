#include <iostream>
#include <cstring>
#include "CompraInsumos.h"

int CompraInsumos::getProv(){
    return cuilProveedor;
}

string CompraInsumos::getDetalle(){
    string d = detalle;
    return d;
}

int CompraInsumos::getCantidad(){
    return cantidad;
}

float CompraInsumos::getPrecioU(){
    return precioUnitario;
}

void CompraInsumos::setProv(int _prov){
    cuilProveedor = _prov;
}

void CompraInsumos::setDetalle(string _detalle){
    strcpy(detalle,_detalle.c_str());
}

void CompraInsumos::setCantidad(int _cant){
    cantidad = _cant;
}

void CompraInsumos::setPrecioU(float _precioU){
    precioUnitario = _precioU;
}

void CompraInsumos::cargar(){

}
string CompraInsumos::toString(){

}
