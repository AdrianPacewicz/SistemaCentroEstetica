#include <iostream>
#include <cstring>
#include "GastoGeneral.h"
#include "rlutil.h"
#include "Funciones.h"

string GastoGeneral::getDetalle(){
    string d = detalle;
    return d;
}

void GastoGeneral::setDetalle(string _detalle){
    strcpy(detalle,_detalle.c_str());
}

bool GastoGeneral::cargar(Interfaz &interfaz){
    /*
    int id;
    Fecha fecha;
    double importe;
    bool estado;
    char detalle[100];
    */
    string valor;

    setFecha(cargarFechaHoyOMenor(interfaz));

    // Pedir el importe del gasto
    interfaz.siguienteLinea();
    interfaz.mostrar("Ingrese el importe del gasto: ",interfaz.AMARILLO);
    getline(cin, valor);
    setImporte(stod(valor));

    // Pedir detalle (obligatorio) del gasto
    interfaz.siguienteLinea();
    do {
        interfaz.borrarLineaActual(false);
        interfaz.mostrar("Ingrese un detalle: ",interfaz.AMARILLO);
        getline(cin, valor);
    } while (valor == "");
    setDetalle(valor);
    return true;
}

string GastoGeneral::toString(){
    string gasto;
    gasto = fecha.toString() + " - $ " + to_string_decimales(importe) + " - " + detalle;
    return gasto;
}
