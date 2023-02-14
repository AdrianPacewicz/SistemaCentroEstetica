#include <iostream>
#include <cstring>
#include "Venta.h"
#include "rlutil.h"
#include "Funciones.h"
#include "EmpleadosArchivo.h"
#include "ClientesArchivo.h"
#include "ServiciosArchivo.h"
#include <iomanip>

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

bool Venta::cargar(Interfaz &interfaz){
    string valor;
    EmpleadosArchivo empleados;
    ClientesArchivo clientes;
    ServiciosArchivo servicios;
    int indice;
    bool existe = false;

    setFecha(cargarFecha(interfaz));

    interfaz.siguienteLinea();
    interfaz.mostrar("Ingrese el DNI del empleado: ",interfaz.AMARILLO);
    getline(cin, valor);

    // Validación para verificar si el empleado existe
    indice = empleados.buscar(stoi(valor));
    if (indice >= 0){
        existe = true;
    }

    if(!existe){
        interfaz.siguienteLinea();
        interfaz.siguienteLinea();
        interfaz.mostrar("El empleado ingresado no existe.",interfaz.ROJO);
        return false;
    }
    nEmpleado = stoi(valor);

    interfaz.siguienteLinea();
    existe = false;
    interfaz.mostrar("Ingrese el DNI del cliente (opcional): ",interfaz.AMARILLO);
    getline(cin, valor);

    // Validación para verificar si el cliente existe
    if (valor != ""){
        indice = clientes.buscar(stoi(valor));
        if (indice >= 0){
            existe = true;
        }

        if(!existe){
            interfaz.siguienteLinea();
            interfaz.siguienteLinea();
            interfaz.mostrar("El cliente ingresado no existe.",interfaz.ROJO);
            return false;
        }
        nCliente = stoi(valor);
    }
    else {
        nCliente = 0;
    }

    interfaz.siguienteLinea();
    existe = false;
    interfaz.mostrar("Ingrese el ID del servicio: ",interfaz.AMARILLO);
    getline(cin, valor);

    // Validación para verificar si el servicio existe
    indice = servicios.buscar(stoi(valor));
    if (indice >= 0){
        existe = true;
    }

    if(!existe){
        interfaz.siguienteLinea();
        interfaz.siguienteLinea();
        interfaz.mostrar("El servicio ingresado no existe.",interfaz.ROJO);
        return false;
    }
    nServicio = stoi(valor);

    // Pedir el monto de la venta
    interfaz.siguienteLinea();
    interfaz.mostrar("Ingrese el monto de la venta: ",interfaz.AMARILLO);
    getline(cin, valor);
    setImporte(stod(valor));

    // Pedir observacion de la venta
    interfaz.siguienteLinea();
    interfaz.mostrar("Ingrese una observacion (opcional): ",interfaz.AMARILLO);
    getline(cin, valor);
    setObs(valor);
    return true;
}

string Venta::toString(){
    string venta;
    venta = fecha.toString() + " - Empleado: " + to_string(nEmpleado) + " - Servicio: " + to_string(nServicio) + " - $ " + to_string_decimales(importe);
    return venta;
}
