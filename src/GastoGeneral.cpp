#include <iostream>
#include <cstring>
#include "GastoGeneral.h"
#include "rlutil.h"

string GastoGeneral::getDetalle(){
    string d = detalle;
    return d;
}

void GastoGeneral::setDetalle(string _detalle){
    strcpy(detalle,_detalle.c_str());
}

void GastoGeneral::cargar(){
    Fecha f;

    /*
    int id;
    Fecha fecha;
    float importe;
    bool estado;
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
    cout<<"  Importe: ";
    cin>>importe;
    setImporte(importe);
    cout<<"  Detalle: ";
    cin.ignore();
    getline(cin, det);
    setDetalle(det);
    cout<<"  Cargado con exito."<<endl;
    rlutil::anykey();
}

string GastoGeneral::toString(){

}
