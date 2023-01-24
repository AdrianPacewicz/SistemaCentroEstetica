#include "Menu.h"
#include "rlutil.h"

// Constructor con la interfaz que viene del main
Menu::Menu(Interfaz &interf){
    interfaz=interf;
}

void Menu::menuPrincipal(){
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
        // Según la opcion elegida llama al método correspondiente
        switch(opc)
        {
            case '1':
                nuevaTransaccion();
                break;
            case '2':
                cargaDeDatos();
                break;
            case '3':
                consultas();
                break;
            case '4':
                reportes();
                break;
            case '9':
                backupRestauracionDeArchivos();
                break;
            case '0':
                if(!salirDelSistema())
                {
                    opc=' ';
                }
                break;
        }
    }
    while(opc != '0');
}

    void Menu::nuevaTransaccion(){}
        void Menu::nuevaVenta(){}
        void Menu::nuevoGastoGeneral(){}
        void Menu::nuevaCompraInsumos(){}
        void Menu::nuevoPagoEmpleado(){}

    void Menu::cargaDeDatos(){}
        void Menu::menuCategorias(){}
            void Menu::nuevaCategoria(){}
            void Menu::cambiarEstadoCategoria(){}
            void Menu::modificarCategoria(){}
            void Menu::listarCategorias(){}
        void Menu::menuClientes(){}
            void Menu::listarClientes(){}
            void Menu::nuevoCliente(){}
            void Menu::cambiarEstadoCliente(){}
            void Menu::modificarCliente(){}
        void Menu::menuEmpleados(){}
        void Menu::menuProveedores(){}
        void Menu::menuServicios(){}
    void Menu::consultas(){}
    void Menu::reportes(){}
    void Menu::backupRestauracionDeArchivos(){}
        void Menu::menuImportarExportar(int opcon){}
            //void ExportarCategorias();
            //void ImportarCategorias();
    bool Menu::salirDelSistema(){}
