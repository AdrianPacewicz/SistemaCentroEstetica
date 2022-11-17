#include <iostream>
#include <cstring>
#include "CompraInsumos.h"
#include "rlutil.h"

int CompraInsumos::getProv(){
    return cuilProveedor;
}

string CompraInsumos::getDetalle(){
    string d = detalle;
    return d;
}

int CompraInsumos::getCantidad(){
    return cantidad;
}

float CompraInsumos::getPrecioU(){
    return precioUnitario;
}

void CompraInsumos::setProv(int _prov){
    cuilProveedor = _prov;
}

void CompraInsumos::setDetalle(string _detalle){
    strcpy(detalle,_detalle.c_str());
}

void CompraInsumos::setCantidad(int _cant){
    cantidad = _cant;
}

void CompraInsumos::setPrecioU(float _precioU){
    precioUnitario = _precioU;
}

void CompraInsumos::cargar(){
    Fecha f;

    /*
    int id;
    Fecha fecha;
    float importe;
    bool estado;

    int cuilProveedor;
    char detalle[100];
    int cantidad;
    float precioUnitario;
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
    cout<<"  CUIL/CUIT Proveedor: ";
    cin>>valor;
    setProv(valor);
    cout<<"  Detalle: ";
    cin.ignore();
    getline(cin, det);
    setDetalle(det);
    cout<<"  Cantidad: ";
    cin>>valor;
    setCantidad(valor);
    cout<<"  Precio unitario: ";
    cin>>importe;
    setPrecioU(importe);
    importe=getPrecioU()*getCantidad();
    setImporte(importe);
    cout<<"  Cargado con exito."<<endl;
    rlutil::anykey();
}
string CompraInsumos::toString(){
    string compraInsumos;
    compraInsumos = to_string(id) + "\t" + fecha.toString() + " " + to_string(cuilProveedor) + "\t - " + detalle + "\t- " + to_string(cantidad) + "\t" + to_string(precioUnitario) + "\t" + to_string(importe);
    return compraInsumos;
}
