#include <iostream>
#include "Empleado.h"
#include "rlutil.h"

double Empleado::getPComision(){
    return porcentajeComision;
}

double Empleado::getSueldoF(){
    return sueldoFijo;
}

void Empleado::setPComision(double _PCom){
    porcentajeComision=_PCom;
}

void Empleado::setSueldoF(double _SueldoF){
    sueldoFijo=_SueldoF;
}

void Empleado::cargar(){
    string cadena;
    Persona::cargar ();
    /*
        double porcentajeComision;
        double sueldoFijo;
    */
    // TODO: Validaciones
    cout<<"  Porcentaje Comision: ";
    getline(cin, cadena);
    setPComision(stod(cadena));
    cout<<"  Sueldo fijo: ";
    getline(cin, cadena);
    setSueldoF(stod(cadena));

    cout<<"  Cargado con exito."<<endl;
    rlutil::anykey();
}

string Empleado::toString(){
    string empleado;
    empleado = Persona::toString()+"\t|\t"+to_string_decimales(porcentajeComision)+"%\t|\t"+to_string_decimales(sueldoFijo);
    return empleado;
}
