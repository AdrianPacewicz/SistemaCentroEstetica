#include "Fecha.h"
#include <ctime>
using namespace std;

int  Fecha::getDia(){
    return _dia;
}

int  Fecha::getMes(){
    return _mes;
}

int  Fecha::getAnio(){
    return _anio;
}

void Fecha::setDia(int dia){
    _dia = dia;
}

void Fecha::setMes(int mes){
    _mes = mes;
}

void Fecha::setAnio(int anio){
    _anio = anio;
}

Fecha::Fecha(int dia, int mes, int anio){
    _dia = dia;
    _mes = mes;
    _anio = anio;
}

Fecha::Fecha(){
    time_t rawtime;
    struct tm timeinfo;

    time (&rawtime);
    timeinfo = *(localtime (&rawtime));

    _dia = timeinfo.tm_mday;
    _mes = timeinfo.tm_mon + 1;
    _anio = timeinfo.tm_year + 1900;
}

bool Fecha::esMayorOIgual(Fecha f){
    bool mayorOIgual = false;
    if(getAnio() > f.getAnio())
        mayorOIgual = true;
    else if (getAnio() == f.getAnio()){
        if(getMes() > f.getMes())
            mayorOIgual = true;
        else if (getMes() == f.getMes()){
            if(getDia() >= f.getDia())
                mayorOIgual = true;
        }
    }
    return mayorOIgual;
}

bool Fecha::esMenorOIgual(Fecha f){
    bool menorOIgual = false;
    if(getAnio() < f.getAnio())
        menorOIgual = true;
    else if (getAnio() == f.getAnio()){
        if(getMes() < f.getMes())
            menorOIgual = true;
        else if (getMes() == f.getMes()){
            if(getDia() <= f.getDia())
                menorOIgual = true;
        }
    }
    return menorOIgual;
}

string Fecha::toString(){
    string fecha;
    fecha = to_string(_dia) + "/" + to_string(_mes) + "/" + to_string(_anio);
    return fecha;
}
