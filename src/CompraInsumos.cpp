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

double CompraInsumos::getPrecioU(){
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

void CompraInsumos::setPrecioU(double _precioU){
    precioUnitario = _precioU;
}

bool CompraInsumos::cargar(Interfaz &interfaz){
    /*
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
    cin>>valor;
    setImporte(stod(valor));
    cin.ignore();

    // Pedir observacion de la venta
    interfaz.siguienteLinea();
    interfaz.mostrar("Ingrese una observacion (opcional): ",interfaz.AMARILLO);
    getline(cin, valor);
    setObs(valor);
    return true;
*/



    Fecha f;

    /*
    int id;
    Fecha fecha;
    double importe;
    bool estado;

    int cuilProveedor;
    char detalle[100];
    int cantidad;
    double precioUnitario;
    */

    int valor;
    double importe;
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
    compraInsumos = to_string(id) + "\t" + fecha.toString() + " " + to_string(cuilProveedor) + "\t - " + detalle + "\t- " + to_string(cantidad) + "\t $ " + to_string_decimales(precioUnitario) + "\t $ " + to_string_decimales(importe);
    return compraInsumos;
}
