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

    void Menu::nuevaTransaccion(){
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
                    nuevaVenta();
                    break;
                case '2':
                    nuevoGastoGeneral();
                    break;
                case '3':
                    nuevaCompraInsumos();
                    break;
                case '4':
                    nuevoPagoEmpleado();
                    break;
            }
        }
        while(opc != '0');
    }

        void Menu::nuevaVenta()
        {
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

        void Menu::nuevoGastoGeneral()
        {
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

        void Menu::nuevaCompraInsumos()
        {
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

        void Menu::nuevoPagoEmpleado()
        {
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
    void Menu::cargaDeDatos()
    {
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
                        menuCategorias();
                        break;
                    case '2':
                        menuClientes();
                        break;
                    case '3':
                        menuEmpleados();
                        break;
                    case '4':
                        menuProveedores();
                        break;
                    case '5':
                        menuServicios();
                        break;
                }
            }
            while(opc != '0');
    }
        void Menu::menuCategorias()
        {
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
                        listarCategorias();
                        break;
                    case '2':
                        nuevaCategoria();
                        break;
                    case '3':
                        cambiarEstadoCategoria();
                        break;
                    case '4':
                        modificarCategoria();
                        break;
                }
            }
            while(opc != '0');
        }
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
        void Menu::nuevaConsEmpleado(){}
        void Menu::nuevaConsCliente(){}
    void Menu::reportes(){}
    void Menu::backupRestauracionDeArchivos(){}
        void Menu::menuImportarExportar(int opcon){}
            //void ExportarCategorias();
            //void ImportarCategorias();
    bool Menu::salirDelSistema(){}
