#include <iostream>
#include <fstream>

using namespace std;

#include "rlutil.h"
#include "Menus.h"
#include "CategoriasArchivo.h"
#include "Funciones.h"


void VerMenu1()
{
    int opc;

    do{
        system("cls");
        int centro = rlutil::tcols()/2;
        rlutil::locate(centro-7, 2);
        rlutil::setColor(CIAN);
        cout << "SISTEMA FIRULI3000";

        rlutil::locate(centro-10, 3);
        cout << "____________________";

        rlutil::locate(centro-8, 6);
        rlutil::setColor(BLANCO);
        cout << "1 - INGRESAR TRANSACCION";

        rlutil::locate(centro-8, 7);
        cout << "2 - INGRESAR/MODIFICAR DATOS";

        rlutil::locate(centro-8, 8);
        cout << "3 - ";

        rlutil::locate(centro-4, 10);
        rlutil::setColor(ROJO);
        cout << "0 - SALIR" << endl << endl;

        rlutil::setColor(BLANCO);

        cin >> opc;

        //--------------pregunta por la opcion elegida y se dirige a la funcion correspondiente---------------------------

    switch(opc)
    {
        case 1:
            system("cls");
            VerMenu1();
        break;

        case 2:
            system("cls");

        break;

        case 3:

        break;

        case 0:
            /*
            if(!salirDelSistema())
            {
                opc=' ';
            }
            */
        break;

        default: cout << "Ingrese una opcion disponible";
        break;
    }

    }while(opc != 0);
    /*int opc;

    cout << "SISTEMA FIRULI 3000" << endl;

    cout << "-----------------------------" << endl <<endl;

    cout << "1 - INGRESAR VENTA" << endl <<endl;
    cout << "2 - INGRESAR GASTO" << endl <<endl;

    cout << "0 - VOLVER AL MENU" << endl <<endl;

    switch(opc)
    {
        case 1:
            system("cls");
        break;

        case 2:
            system("cls");
        break;

        case 0:
            system("cls");
        break;

    }*/
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

void ExportarCategorias(){
    CategoriasArchivo ca;
    if (ca.exportarCSV())
    {
        cout<<"Categorias exportadas con exito."<<endl;
    }
    else
    {
        cout<<"Error al exportar categorias"<<endl;
    }
    system("pause");
}

void ImportarCategorias(){
    CategoriasArchivo ca;
    if (ca.importarCSV())
    {
        cout<<"Categorias importadas con exito."<<endl;
    }
    else
    {
        cout<<"Error al importar categorias"<<endl;
    }
    system("pause");
}

void ListarCategorias(){
    CategoriasArchivo ca;
    int cantCategorias = ca.getCantidad();
    Categoria *vCategorias = new Categoria[cantCategorias];
    system("cls");
    ca.leerTodos(vCategorias, cantCategorias);
    for(int i=0; i<cantCategorias; i++){
        if(vCategorias[i].getEstado()){
            cout<<vCategorias[i].toString()<<endl;
        }
    }
    cout<<endl;
    system("pause");
}

void nuevaVenta(Interfaz &interfaz){
    int opc;
    CategoriasArchivo categorias;
    interfaz.cambiarTitulo("FIRULI 3000 - NUEVA VENTA");
    interfaz.limpiarPantalla(5,0);
    rlutil::locate(5,8);
    cout << "Dia: ";
    rlutil::locate(10,8);
    cout << "Mes: ";
    rlutil::locate(15,8);
    cout << "Anio: ";
    rlutil::locate(5,10);
    cout << "Empleado: ";
    rlutil::locate(40,10);
    cout << "Servicio: ";
    rlutil::locate(5,12);
    cout << "Cliente: ";
    rlutil::locate(40,12);
    cout << "Importe: ";


    bool elegido=false;
    int pagActual=0;
    int cantPaginas = categorias.getCantidadActivos()/9;
    do {
        mostrarEmpleados(15,pagActual,cantPaginas);
        opc = interfaz.pedirOpcionNumerica();
        if(opc!=9){
            switch(opc){
            case 0:

                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;


            }
        }



    } while (!elegido);
    mostrarCategorias(15,pagActual,cantPaginas);
    //mostrarServicios();

    rlutil::locate(5,11);
    cout << "Importe: ";
    rlutil::locate(5,12);
    cout << "Anio: ";
    rlutil::locate(5,13);
    cout << "Anio: ";
    rlutil::locate(5,14);
    cout << "Anio: ";
    rlutil::locate(5,15);
    cout << "Anio: ";
    rlutil::locate(5,16);
    cout << "Anio: ";


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

void nuevoGastoGeneral(Interfaz &interfaz){

}

void nuevaCompraInsumos(Interfaz &interfaz){

}

void nuevoPagoEmpleado(Interfaz &interfaz){

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

void cargaDeDatos(Interfaz &interfaz){

}

void consultas(Interfaz &interfaz){

}

void reportes(Interfaz &interfaz){

}

void backupRestauracionDeArchivos(Interfaz &interfaz){

}
