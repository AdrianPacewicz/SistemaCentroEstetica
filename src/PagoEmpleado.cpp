#include <iostream>
#include <cstring>
#include "PagoEmpleado.h"
#include "rlutil.h"
#include "EmpleadosArchivo.h"

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

bool PagoEmpleado::cargar(Interfaz &interfaz){
    string valor;
    int indice;
    bool existe = false;
    EmpleadosArchivo empleados;
    Empleado empleado;

    /*
    int id;
    Fecha fecha;
    double importe;
    bool estado;

    int idEmpleado;
    char detalle[100];
    */

    // Pedir DNI del empleado
    interfaz.siguienteLinea();
    interfaz.mostrar("Ingrese el DNI del empleado: ",interfaz.AMARILLO);
    getline(cin, valor);

    // Validación para verificar si el empleado existe
    indice = empleados.buscar(stoi(valor));
    if (indice >= 0){
        existe = true;
        empleado = empleados.leer(indice);
    }

    if(!existe){
        interfaz.siguienteLinea();
        interfaz.siguienteLinea();
        interfaz.mostrar("El empleado ingresado no existe.",interfaz.ROJO);
        return false;
    }
    setIdE(stoi(valor));

    interfaz.siguienteLinea();
    interfaz.mostrar("Fecha del pago (correspondiente al mes trabajado) ",interfaz.AMARILLO);
    // Pedir fecha
    setFecha(cargarFechaHoyOMenor(interfaz));

    double saldo = empleado.calcularSueldo(getFecha().getAnio(),getFecha().getMes());
    if (saldo == -1){
        interfaz.siguienteLinea();
        interfaz.mostrar("Error al procesar registros (No se pudo crear un vector).",interfaz.ROJO);
        return false;
    }
    else if (saldo <= 0.001){
        interfaz.siguienteLinea();
        interfaz.mostrar("No hay saldo a pagar para el empleado en el periodo cargado.",interfaz.ROJO);
        return false;
    }
    else {
        interfaz.siguienteLinea();
        interfaz.mostrar("Saldo a pagar del empleado: $ "+to_string_decimales(saldo),interfaz.AMARILLO);
        // Pedir detalle del pago
        interfaz.siguienteLinea();
        interfaz.mostrar("Ingrese un detalle del pago (opcional): ",interfaz.AMARILLO);
        getline(cin, valor);
        setDetalle(valor);

        interfaz.siguienteLinea();
        do {
           // Pedir el importe a pagar
            interfaz.borrarLineaActual(false);
            interfaz.mostrar("Ingrese el sueldo a pagar: ",interfaz.AMARILLO);
            cin>>valor;
            cin.ignore();
            if(stod(valor)>saldo){
                interfaz.cambiarMensaje("El sueldo no puede ser mayor al saldo a pagar.", interfaz.ROJO);
            }
        } while (stod(valor)>saldo);
        setImporte(stod(valor));
    }
    return true;
}

string PagoEmpleado::toString(){
    // acordarse de to_string_decimales
}
