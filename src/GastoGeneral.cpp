#include <iostream>
#include <cstring>
#include "GastoGeneral.h"

string GastoGeneral::getDetalle(){
    string d = detalle;
    return d;
}

void GastoGeneral::setDetalle(string _detalle){
    strcpy(detalle,_detalle.c_str());
}

void GastoGeneral::cargar(){

}

string GastoGeneral::toString(){

}
