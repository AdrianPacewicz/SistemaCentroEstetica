#include <iostream>
#include <fstream>

using namespace std;

#include "rlutil.h"
#include "Menus.h"
#include "CategoriasArchivo.h"
#include "VentasArchivo.h"
#include "Funciones.h"
#include "GastosGeneralesArchivo.h"
#include "ComprasInsumosArchivo.h"
#include "PagosEmpleadosArchivo.h"
#include "ClientesArchivo.h"

// Funcion para el menu principal
void menuPrincipal(Interfaz &interfaz){
    char opc;
    do{
        system("cls");
        interfaz.dibujarMarco(rlutil::CYAN);
        interfaz.cambiarTitulo("FIRULI 3000 - MENU PRINCIPAL");
        interfaz.mostrarTextoCentrado("[1] - Nueva transaccion.",8);
        interfaz.mostrarTextoCentrado("[2] - Carga de datos maestros.",9);
        interfaz.mostrarTextoCentrado("[3] - Consultas.",10);
        interfaz.mostrarTextoCentrado("[4] - Reportes.",11);
        interfaz.mostrarTextoCentrado("[9] - Backup/Restauracion de archivos.",16);
        interfaz.dibujarLineaHorizontal(17, rlutil::CYAN);
        interfaz.mostrarTextoCentrado("[0] - SALIR",18);
        opc = interfaz.pedirOpcion();
        // Pregunta por la opcion elegida y se dirige a la funcion correspondiente
        switch(opc)
        {
            case '1':
                nuevaTransaccion(interfaz);
                break;
            case '2':
                cargaDeDatos(interfaz);
                break;
            case '3':
                consultas(interfaz);
                break;
            case '4':
                reportes(interfaz);
                break;
            case '9':
                backupRestauracionDeArchivos(interfaz);
                break;
            case '0':
                if(!salirDelSistema(interfaz))
                {
                    opc=' ';
                }
                break;
        }
    }
    while(opc != '0');
}

// Funcion para salir luego de pedir confirmacion
bool salirDelSistema(Interfaz &interfaz)
{
    char respuesta;
    int opc;
    interfaz.cambiarMensaje("Esta seguro/a de querer salir? (S/N)",ROJO);
    opc = rlutil::getkey();
    respuesta = char(opc);
    if (respuesta == 's' || respuesta == 'S')
    {
        return true;
    }
    else if (respuesta == 'n' || respuesta == 'N')
    {
        return false;
    }
    else {
        return salirDelSistema(interfaz);
    }
}

// Funcion para nueva transaccion
void nuevaTransaccion(Interfaz &interfaz){
    char opc;
    do{
        system("cls");
        interfaz.dibujarMarco(rlutil::CYAN);
        interfaz.cambiarTitulo("FIRULI 3000 - NUEVA TRANSACCION");
        rlutil::locate(5,8);
        cout<<"[1] - Venta";
        rlutil::locate(5,9);
        cout<<"[2] - Gasto general";
        rlutil::locate(5,10);
        cout<<"[3] - Compra insumos";
        rlutil::locate(5,11);
        cout<<"[4] - Pago empleado";
        rlutil::locate(5,13);
        cout<<"[0] - Volver";
        opc = interfaz.pedirOpcion();
        // Pregunta por la opcion elegida y se dirige a la funcion correspondiente
        switch(opc)
        {
            case '1':
                nuevaVenta(interfaz);
                break;
            case '2':
                nuevoGastoGeneral(interfaz);
                break;
            case '3':
                nuevaCompraInsumos(interfaz);
                break;
            case '4':
                nuevoPagoEmpleado(interfaz);
                break;
        }
    }
    while(opc != '0');
}

void nuevaVenta(Interfaz &interfaz){
    bool continuarCargando=false;
    VentasArchivo archivo;
    Venta venta;
    venta.setEstado(true);
    do {
        venta.setId(archivo.getCantidad()+1);
        system("cls");
        interfaz.setFilaActual(8);
        interfaz.dibujarRectangulo(2,2,2,interfaz.getAncho()-3,CIAN);

        interfaz.cambiarTitulo("FIRULI 3000 - NUEVA VENTA");
        rlutil::locate(1,interfaz.getFilaActual());
        venta.cargar();
        archivo.guardar(venta);
        int opc=2;
        do{
            cout<<"  Desea cargar una nueva venta? (1=SI - 0=NO): ";
            cin>>opc;
        } while(opc!=1&&opc!=0);
        continuarCargando=opc;
    } while(continuarCargando);
}

void nuevoGastoGeneral(Interfaz &interfaz){
    bool continuarCargando=false;
    GastosGeneralesArchivo archivo;
    GastoGeneral obj;
    obj.setEstado(true);
    do {
        obj.setId(archivo.getCantidad()+1);
        system("cls");
        interfaz.setFilaActual(8);
        interfaz.dibujarRectangulo(2,2,2,interfaz.getAncho()-3,CIAN);

        interfaz.cambiarTitulo("FIRULI 3000 - NUEVO GASTO GENERAL");
        rlutil::locate(1,interfaz.getFilaActual());
        obj.cargar();
        archivo.guardar(obj);
        int opc=2;
        do{
            cout<<"  Desea cargar un nuevo gasto? (1=SI - 0=NO): ";
            cin>>opc;
        } while(opc!=1&&opc!=0);
        continuarCargando=opc;
    } while(continuarCargando);
}

void nuevaCompraInsumos(Interfaz &interfaz){
    bool continuarCargando=false;
    ComprasInsumosArchivo archivo;
    CompraInsumos obj;
    obj.setEstado(true);
    do {
        obj.setId(archivo.getCantidad()+1);
        system("cls");
        interfaz.setFilaActual(8);
        interfaz.dibujarRectangulo(2,2,2,interfaz.getAncho()-3,CIAN);

        interfaz.cambiarTitulo("FIRULI 3000 - NUEVA COMPRA DE INSUMOS");
        rlutil::locate(1,interfaz.getFilaActual());
        obj.cargar();
        archivo.guardar(obj);
        int opc=2;
        do{
            cout<<"  Desea cargar una nueva compra de insumos? (1=SI - 0=NO): ";
            cin>>opc;
        } while(opc!=1&&opc!=0);
        continuarCargando=opc;
    } while(continuarCargando);
}

void nuevoPagoEmpleado(Interfaz &interfaz){
    bool continuarCargando=false;
    PagosEmpleadosArchivo archivo;
    PagoEmpleado obj;
    obj.setEstado(true);
    do {
        obj.setId(archivo.getCantidad()+1);
        system("cls");
        interfaz.setFilaActual(8);
        interfaz.dibujarRectangulo(2,2,2,interfaz.getAncho()-3,CIAN);

        interfaz.cambiarTitulo("FIRULI 3000 - NUEVO PAGO EMPLEADO");
        rlutil::locate(1,interfaz.getFilaActual());
        obj.cargar();
        archivo.guardar(obj);
        int opc=2;
        do{
            cout<<"  Desea cargar un nuevo pago a empleado? (1=SI - 0=NO): ";
            cin>>opc;
        } while(opc!=1&&opc!=0);
        continuarCargando=opc;
    } while(continuarCargando);
}

// Funcion para mostrar menu de carga de datos
void cargaDeDatos(Interfaz &interfaz){
    char opc;
    do{
        system("cls");
        interfaz.dibujarMarco(rlutil::CYAN);
        interfaz.cambiarTitulo("FIRULI 3000 - CARGA DE DATOS");
        rlutil::locate(5,8);
        cout<<"[1] - Categorias";
        rlutil::locate(5,9);
        cout<<"[2] - Clientes";
        rlutil::locate(5,10);
        cout<<"[3] - Empleados";
        rlutil::locate(5,11);
        cout<<"[4] - Proveedores";
        rlutil::locate(5,12);
        cout<<"[5] - Servicios";
        rlutil::locate(5,14);
        cout<<"[0] - Volver";
        opc = interfaz.pedirOpcion();
        // Pregunta por la opcion elegida y se dirige a la funcion correspondiente
        switch(opc)
        {
            case '1':
                menuCategorias(interfaz);
                break;
            case '2':
                menuClientes(interfaz);
                break;
            case '3':
                menuEmpleados(interfaz);
                break;
            case '4':
                menuProveedores(interfaz);
                break;
            case '5':
                menuServicios(interfaz);
                break;
        }
    }
    while(opc != '0');
}

void menuCategorias(Interfaz &interfaz){
    char opc;
    do{
        system("cls");
        interfaz.dibujarMarco(rlutil::CYAN);
        interfaz.cambiarTitulo("FIRULI 3000 - CATEGORIAS");
        rlutil::locate(5,8);
        cout<<"[1] - Listar";
        rlutil::locate(5,9);
        cout<<"[2] - Agregar";
        rlutil::locate(5,10);
        cout<<"[3] - Borrar/Reactivar";
        rlutil::locate(5,11);
        cout<<"[4] - Modificar";
        rlutil::locate(5,13);
        cout<<"[0] - Volver";
        opc = interfaz.pedirOpcion();
        // Pregunta por la opcion elegida y se dirige a la funcion correspondiente
        switch(opc)
        {
            case '1':
                listarCategorias(interfaz);
                break;
            case '2':
                nuevaCategoria(interfaz);
                break;
            case '3':
                cambiarEstadoCategoria(interfaz);
                break;
            case '4':
                modificarCategoria(interfaz);
                break;
        }
    }
    while(opc != '0');
}

void listarCategorias(Interfaz &interfaz){
    CategoriasArchivo archivo;
    int cantRegistros = archivo.getCantidad();
    Categoria *vec = new Categoria[cantRegistros];
    system("cls");
    interfaz.setFilaActual(8);
    interfaz.dibujarRectangulo(2,2,2,interfaz.getAncho()-3,CIAN);
    interfaz.cambiarTitulo("FIRULI 3000 - LISTADO DE CATEGORIAS");
    rlutil::locate(1,interfaz.getFilaActual());
    archivo.leerTodos(vec, cantRegistros);
    /*
    Atributos de categoria:
    int codigo;
    char nombre[50];
    bool estado;
    */
    cout<<"Codigo\t|\tNombre"<<endl;
    for(int i=0; i<cantRegistros; i++){
        if(vec[i].getEstado()){
            cout<<vec[i].toString()<<endl;
        }
    }
    cout<<endl;
    cout<<"Presione una tecla para continuar."<<endl;
    rlutil::anykey();
}

void nuevaCategoria(Interfaz &interfaz){
    CategoriasArchivo archivo;
    Categoria obj;
    obj.setEstado(true);
    obj.setCodigo(archivo.getCantidad()+1);
    system("cls");
    interfaz.setFilaActual(8);
    interfaz.dibujarRectangulo(2,2,2,interfaz.getAncho()-3,CIAN);
    interfaz.cambiarTitulo("FIRULI 3000 - NUEVA CATEGORIA");
    rlutil::locate(1,interfaz.getFilaActual());
    obj.cargar();
    archivo.guardar(obj);
}

void cambiarEstadoCategoria(Interfaz &interfaz){
    CategoriasArchivo archivo;
    Categoria obj;
    string id;
    system("cls");
    interfaz.setFilaActual(8);
    interfaz.dibujarRectangulo(2,2,2,interfaz.getAncho()-3,CIAN);
    interfaz.cambiarTitulo("FIRULI 3000 - BORRAR/REACTIVAR CATEGORIA");
    rlutil::locate(1,interfaz.getFilaActual());
    bool existe=false;
    int indice=-1;
    while(!existe){
        cout<<"Ingrese codigo de categoria a borrar/reactivar: ";
        getline(cin,id);
        indice = archivo.buscar(stoi(id));
        if(indice>=0) existe = true;
        else {
            cout<<"Codigo inexistente. Presione una tecla para continuar."<<endl;
            rlutil::anykey();
        }
    }
    obj = archivo.leer(indice);
    obj.setEstado(!obj.getEstado());
    archivo.guardar(obj,indice);
    if(!obj.getEstado()){
        cout<<"Categoria borrada exitosamente."<<endl;
    }
    else{
        cout<<"Categoria reactivada exitosamente."<<endl;
    }
    rlutil::anykey();
}

void modificarCategoria(Interfaz &interfaz){
    CategoriasArchivo archivo;
    Categoria obj;
    string id,nombre;
    system("cls");
    interfaz.setFilaActual(8);
    interfaz.dibujarRectangulo(2,2,2,interfaz.getAncho()-3,CIAN);
    interfaz.cambiarTitulo("FIRULI 3000 - MODIFICAR CATEGORIA");
    rlutil::locate(1,interfaz.getFilaActual());
    bool existe=false;
    int indice=-1;
    while(!existe){
        cout<<"Ingrese codigo de categoria a modificar: ";
        getline(cin,id);
        indice = archivo.buscar(stoi(id));
        if(indice>=0) existe = true;
        else {
            cout<<"Codigo inexistente. Presione una tecla para continuar."<<endl;
            rlutil::anykey();
        }
    }
    obj = archivo.leer(indice);
    cout<<"Ingrese los datos que desea modificar (deje en blanco los datos que desee mantener)"<<endl<<endl;
    cout<<"Nombre: ";
    getline(cin,nombre);
    if(nombre!=""){
       obj.setNombre(nombre);
    }
    archivo.guardar(obj,indice);
    cout<<"Categoria modificada exitosamente."<<endl;
    rlutil::anykey();
}

void menuClientes(Interfaz &interfaz){
    char opc;
    do{
        system("cls");
        interfaz.dibujarMarco(rlutil::CYAN);
        interfaz.cambiarTitulo("FIRULI 3000 - CLIENTES");
        rlutil::locate(5,8);
        cout<<"[1] - Listar";
        rlutil::locate(5,9);
        cout<<"[2] - Agregar";
        rlutil::locate(5,10);
        cout<<"[3] - Borrar/Reactivar";
        rlutil::locate(5,11);
        cout<<"[4] - Modificar";
        rlutil::locate(5,13);
        cout<<"[0] - Volver";
        opc = interfaz.pedirOpcion();
        // Pregunta por la opcion elegida y se dirige a la funcion correspondiente
        switch(opc)
        {
            case '1':
                listarClientes(interfaz);
                break;
            case '2':
                nuevoCliente(interfaz);
                break;
            case '3':
                cambiarEstadoCliente(interfaz);
                break;
            case '4':
                modificarCliente(interfaz);
                break;
        }
    }
    while(opc != '0');
}

void listarClientes(Interfaz &interfaz){
    ClientesArchivo archivo;
    int cantRegistros = archivo.getCantidad();
    Cliente *vec = new Cliente[cantRegistros];
    system("cls");
    interfaz.setFilaActual(8);
    interfaz.dibujarRectangulo(2,2,2,interfaz.getAncho()-3,CIAN);
    interfaz.cambiarTitulo("FIRULI 3000 - LISTADO DE CLIENTES");
    rlutil::locate(1,interfaz.getFilaActual());
    archivo.leerTodos(vec, cantRegistros);
    /*
    Atributos de cliente(persona):
    int dni;
    char nombre[50];
    char apellido[50];
    int telefono;
    char email[50];
    bool estado;
    */
    cout<<"DNI\t\t|\tNombre y apellido\t|\tTelefono\t|\tEmail"<<endl;
    for(int i=0; i<cantRegistros; i++){
        if(vec[i].getEstado()){
            cout<<vec[i].toString()<<endl;
        }
    }
    cout<<endl;
    cout<<"Presione una tecla para continuar."<<endl;
    rlutil::anykey();
}

void nuevoCliente(Interfaz &interfaz){
    ClientesArchivo archivo;
    Cliente obj;
    obj.setEstado(true);
    system("cls");
    interfaz.setFilaActual(8);
    interfaz.dibujarRectangulo(2,2,2,interfaz.getAncho()-3,CIAN);
    interfaz.cambiarTitulo("FIRULI 3000 - NUEVO CLIENTE");
    rlutil::locate(1,interfaz.getFilaActual());
    int existe;
    int valor;
    cout<<"  DNI: ";
    cin>>valor;
    cin.ignore();
    if (archivo.buscar(valor)==-1){
        obj.setDni(valor);
        obj.cargar();
        archivo.guardar(obj);
    }
    else{
        cout<<"  ERROR: El registro ya existe.";
        rlutil::anykey();
    }
}

void cambiarEstadoCliente(Interfaz &interfaz){

}

void modificarCliente(Interfaz &interfaz){

}


void menuEmpleados(Interfaz &interfaz){

}

void menuProveedores(Interfaz &interfaz){

}

void menuServicios(Interfaz &interfaz){

}

void backupRestauracionDeArchivos(Interfaz &interfaz){
    char opc;
    do{
        system("cls");
        interfaz.dibujarMarco(rlutil::CYAN);
        interfaz.cambiarTitulo("FIRULI 3000 - BACKUP/RESTAURACION DE ARCHIVOS");
        rlutil::locate(5,8);
        cout<<"[1] - Categorias";
        rlutil::locate(5,9);
        cout<<"[2] - Clientes";
        rlutil::locate(5,10);
        cout<<"[3] - CompraInsumos";
        rlutil::locate(5,11);
        cout<<"[4] - Empleados";
        rlutil::locate(5,12);
        cout<<"[5] - Gastos Generales";
        rlutil::locate(5,13);
        cout<<"[6] - Pagos Empleados";
        rlutil::locate(5,14);
        cout<<"[7] - Proveedores";
        rlutil::locate(5,15);
        cout<<"[8] - Servicios";
        rlutil::locate(5,16);
        cout<<"[9] - Ventas";
        rlutil::locate(5,18);
        cout<<"[0] - Volver";
        opc = interfaz.pedirOpcion();
        // Pregunta por la opcion elegida y se dirige a la funcion correspondiente
        switch(opc)
        {
            case '1':
                menuImportarExportar(interfaz,1);
                break;
            case '2':
                menuImportarExportar(interfaz,2);
                break;
            case '3':
                menuImportarExportar(interfaz,3);
                break;
            case '4':
                menuImportarExportar(interfaz,4);
                break;
            case '5':
                menuImportarExportar(interfaz,5);
                break;
            case '6':
                menuImportarExportar(interfaz,6);
                break;
            case '7':
                menuImportarExportar(interfaz,7);
                break;
            case '8':
                menuImportarExportar(interfaz,8);
                break;
            case '9':
                menuImportarExportar(interfaz,9);
                break;
        }
    }
    while(opc != '0');
}

void menuImportarExportar(Interfaz &interfaz, int opcion){
    char opc;
    do{
        system("cls");
        interfaz.dibujarMarco(rlutil::CYAN);
        interfaz.cambiarTitulo("FIRULI 3000 - IMPORTAR O EXPORTAR CSV");
        rlutil::locate(5,8);
        cout<<"[1] - Importar CSV";
        rlutil::locate(5,9);
        cout<<"[2] - Exportar CSV";
        rlutil::locate(5,11);
        cout<<"[0] - Volver";
        opc = interfaz.pedirOpcion();
        rlutil::locate(5,13);
        // Pregunta por la opcion elegida y se dirige a la funcion correspondiente
        switch(opc)
        {
            case '1':
                importar(opcion);
                break;
            case '2':
                exportar(opcion);
                break;
        }
    }
    while(opc != '0');
}

void consultas(Interfaz &interfaz){

}

void reportes(Interfaz &interfaz){

}


