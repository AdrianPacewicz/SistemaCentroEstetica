#include <iostream>
#include <cstring>
#include "Venta.h"
#include "rlutil.h"
#include "Funciones.h"

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

    int valor;
    float importe;
    string obs;
    interfaz.siguienteLinea();
    setFecha(cargarFecha(interfaz));
    /*
    do{}
    while(valor>);
    cout<<"Anio: ";
    cin>>valor;
    fecha.setAnio(valor);
    interfaz.siguienteLinea();

    // TODO: Validaciones



    cout<<"Mes: ";
    cin>>valor;
    fecha.setMes(valor);
    interfaz.siguienteLinea();
    cout<<"Dia: ";
    cin>>valor;
    fecha.setDia(valor);
    setFecha(fecha);
    */
    interfaz.siguienteLinea();
    cout<<"Empleado: ";
    cin>>valor;
    setEmpleado(valor);
    interfaz.siguienteLinea();
    cout<<"Servicio: ";
    cin>>valor;
    setServicio(valor);
    interfaz.siguienteLinea();
    cout<<"Cliente: ";
    cin>>valor;
    setCliente(valor);
    interfaz.siguienteLinea();
    cout<<"Importe: ";
    cin>>importe;
    setImporte(importe);
    interfaz.siguienteLinea();
    cout<<"Observacion: ";
    cin.ignore();
    getline(cin, obs);
    setObs(obs);
    interfaz.siguienteLinea();
    cout<<"Cargado con exito."<<endl;
    rlutil::anykey();
    return true;
}

string Venta::toString(){
    string venta;
    venta = fecha.toString() + " - Empleado: " + to_string(nEmpleado) + " - Servicio: " + to_string(nServicio) + " - $ " + to_string(importe);
    return venta;
}
