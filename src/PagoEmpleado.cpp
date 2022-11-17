#include <iostream>
#include <cstring>
#include "PagoEmpleado.h"
#include "rlutil.h"

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

void PagoEmpleado::cargar(){
    Fecha f;

    /*
    int id;
    Fecha fecha;
    float importe;
    bool estado;

    int idEmpleado;
    char detalle[100];
    */

    int valor;
    float importe;
    string det;
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
    setIdE(valor);
    cout<<"  Detalle: ";
    cin.ignore();
    getline(cin, det);
    setDetalle(det);
    cout<<"  Importe: ";
    cin>>importe;
    setImporte(importe);
    cout<<"  Cargado con exito."<<endl;
    rlutil::anykey();
}

string PagoEmpleado::toString(){

}
