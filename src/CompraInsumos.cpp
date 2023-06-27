#include <iostream>
#include <cstring>
#include "CompraInsumos.h"
#include "rlutil.h"
#include "ProveedoresArchivo.h"

string CompraInsumos::getProv(){
    return cuilProveedor;
}

string CompraInsumos::getDetalle(){
    string d = detalle;
    return d;
}

int CompraInsumos::getCantidad(){
    return cantidad;
}

double CompraInsumos::getPrecioU(){
    return precioUnitario;
}

void CompraInsumos::setProv(string _prov){
    strcpy(cuilProveedor,_prov.c_str());
}

void CompraInsumos::setDetalle(string _detalle){
    strcpy(detalle,_detalle.c_str());
}

void CompraInsumos::setCantidad(int _cant){
    cantidad = _cant;
}

void CompraInsumos::setPrecioU(double _precioU){
    precioUnitario = _precioU;
}

bool CompraInsumos::cargar(Interfaz &interfaz){
    /*
    int id;
    Fecha fecha;
    double importe;
    bool estado;

    char cuilProveedor[50];
    char detalle[100];
    int cantidad;
    double precioUnitario;
    */
    string valor;
    ProveedoresArchivo proveedores;
    int indice;
    bool existe = false;

    // Pedir fecha
    setFecha(cargarFechaHoyOMenor(interfaz));

    // Pedir cuil del proveedor
    interfaz.siguienteLinea();
    interfaz.mostrar("Ingrese el CUIL del proveedor: ",interfaz.AMARILLO);
    getline(cin, valor);

    // Validación para verificar si el proveedor existe
    indice = proveedores.buscar(valor);
    if (indice >= 0){
        existe = true;
    }

    if(!existe){
        interfaz.siguienteLinea();
        interfaz.siguienteLinea();
        interfaz.mostrar("El proveedor ingresado no existe.",interfaz.ROJO);
        return false;
    }
    setProv(valor);

    // Pedir detalle (obligatorio) de la compra
    interfaz.siguienteLinea();
    do {
        interfaz.borrarLineaActual(false);
        interfaz.mostrar("Ingrese un detalle: ",interfaz.AMARILLO);
        getline(cin, valor);
    } while (valor == "");
    setDetalle(valor);

    // Pedir la cantidad comprada
    interfaz.siguienteLinea();
    interfaz.mostrar("Ingrese la cantidad de articulos: ",interfaz.AMARILLO);
    cin>>valor;
    setCantidad(stoi(valor));

    // Pedir el precio unitario
    interfaz.siguienteLinea();
    interfaz.mostrar("Ingrese el precio unitario: ",interfaz.AMARILLO);
    cin>>valor;
    cin.ignore();
    setPrecioU(stod(valor));

    // Calculo del importe
    setImporte(precioUnitario*cantidad);
    return true;
}

string CompraInsumos::toString(){
    string compraInsumos;
    compraInsumos = to_string(id) + "\t" + fecha.toString() + " " + cuilProveedor + "\t - " + detalle + "\t- " + to_string(cantidad) + "\t $ " + to_string_decimales(precioUnitario) + "\t $ " + to_string_decimales(importe);
    return compraInsumos;
}
