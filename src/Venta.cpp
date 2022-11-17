#include <iostream>
#include <cstring>
#include "Venta.h"
#include <ctime>
#include "rlutil.h"

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

void Venta::cargar(){
    Fecha f;
    time_t rawtime;
    struct tm timeinfo;
    time (&rawtime);
    timeinfo = *(localtime (&rawtime));
    int diaActual = timeinfo.tm_mday;
    int mesActual = timeinfo.tm_mon + 1;
    int anioActual = timeinfo.tm_year + 1900;

    int valor;
    float importe;
    string obs;
    // TODO: Validaciones
    cout<<"  Anio: ";
    cin>>valor;
    f.setAnio(valor);
    cout<<"  Mes: ";
    cin>>valor;
    f.setMes(valor);
    cout<<"  Dia: ";
    cin>>valor;
    f.setDia(valor);
    setFecha(f);
    cout<<"  Empleado: ";
    cin>>valor;
    setEmpleado(valor);
    cout<<"  Servicio: ";
    cin>>valor;
    setServicio(valor);
    cout<<"  Cliente: ";
    cin>>valor;
    setCliente(valor);
    cout<<"  Importe: ";
    cin>>importe;
    setImporte(importe);
    cout<<"  Observacion: ";
    cin.ignore();
    getline(cin, obs);
    setObs(obs);
    cout<<"  Cargado con exito."<<endl;
    rlutil::anykey();
}

string Venta::toString(){
    string venta;
    venta = fecha.toString() + " - Empleado: " + to_string(nEmpleado) + " - Servicio: " + to_string(nServicio) + " - $ " + to_string(importe);
    return venta;
}
