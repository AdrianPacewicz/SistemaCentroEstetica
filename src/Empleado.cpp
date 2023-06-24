#include <iostream>
#include "Empleado.h"
#include "rlutil.h"
#include "VentasArchivo.h"
#include "PagosEmpleadosArchivo.h"

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

double Empleado::calcularSueldo(int anio, int mes){
    VentasArchivo ventasArchivo;
    int cantidadVentas = ventasArchivo.getCantidad();
    Venta *ventas = new Venta[cantidadVentas];
    if(ventas==NULL) return -1;
    ventasArchivo.leerTodos(ventas, cantidadVentas);

    PagosEmpleadosArchivo pagosArchivo;
    int cantidadPagos = pagosArchivo.getCantidad();
    PagoEmpleado *pagos = new PagoEmpleado[cantidadPagos];
    if(pagos==NULL) return -1;
    pagosArchivo.leerTodos(pagos, cantidadPagos);

    double sueldo = sueldoFijo;

    for (int i = 0; i<cantidadVentas; i++){
        if(ventas[i].getEstado()
        && ventas[i].getFecha().getAnio()==anio
        && ventas[i].getFecha().getMes()==mes
        && ventas[i].getEmpleado()==dni){
            sueldo += ventas[i].getImporte()*porcentajeComision/100;
        }
    }

    for (int i = 0; i<cantidadPagos; i++){
        if(pagos[i].getEstado()
        && pagos[i].getFecha().getAnio()==anio
        && pagos[i].getFecha().getMes()==mes
        && pagos[i].getIdE()==dni){
            sueldo -= pagos[i].getImporte();
        }
    }

    delete []ventas;
    delete []pagos;
    return sueldo;
}
