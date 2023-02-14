#include "Menu.h"
#include "rlutil.h"
#include "Funciones.h"

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

    void Menu::nuevaVenta(){
        bool continuarCargando=false;
        string msj = "";
        VentasArchivo archivo;
        Venta venta;
        venta.setEstado(true);
        do {
            venta.setId(archivo.getCantidad()+1);
            system("cls");
            interfaz.setFilaActual(8);
            interfaz.dibujarMarco(CIAN);
            interfaz.cambiarTitulo("FIRULI 3000 - NUEVA VENTA");
            interfaz.siguienteLinea();
            if(venta.cargar(interfaz)){
                archivo.guardar(venta);
                interfaz.siguienteLinea();
                interfaz.mostrar("Venta cargada con exito.",VERDECLARO);
            }
            else {
                interfaz.siguienteLinea();
                interfaz.mostrar("Error al cargar la venta.",ROJO);
            }
            interfaz.siguienteLinea();
            interfaz.mostrar("Desea cargar una nueva venta? [1] Si || [0] No",AMARILLO);
            int opc = 2;
            do{
                opc = interfaz.pedirOpcionNumerica();
            } while(opc!=1&&opc!=0);
            continuarCargando=opc;
        } while(continuarCargando);
    }

    void Menu::nuevoGastoGeneral(){
        bool continuarCargando=false;
        GastosGeneralesArchivo archivo;
        GastoGeneral gastogeneral;
        gastogeneral.setEstado(true);
        do {
            gastogeneral.setId(archivo.getCantidad()+1);
            system("cls");
            interfaz.setFilaActual(8);
            interfaz.dibujarMarco(CIAN);
            interfaz.cambiarTitulo("FIRULI 3000 - NUEVA GASTO GENERAL");
            interfaz.siguienteLinea();
            if(gastogeneral.cargar(interfaz)){
                archivo.guardar(gastogeneral);
                interfaz.siguienteLinea();
                interfaz.mostrar("Gasto cargado con exito.",VERDECLARO);
            }
            else {
                interfaz.siguienteLinea();
                interfaz.mostrar("Error al cargar el gasto.",ROJO);
            }
            interfaz.siguienteLinea();
            interfaz.mostrar("Desea cargar un nuevo gasto? [1] Si || [0] No",AMARILLO);
            int opc = 2;
            do{
                opc = interfaz.pedirOpcionNumerica();
            } while(opc!=1&&opc!=0);
            continuarCargando=opc;
        } while(continuarCargando);
    }

    void Menu::nuevaCompraInsumos(){
        bool continuarCargando=false;
        ComprasInsumosArchivo archivo;
        CompraInsumos compraInsumo;
        compraInsumo.setEstado(true);
        do {
            compraInsumo.setId(archivo.getCantidad()+1);
            system("cls");
            interfaz.setFilaActual(8);
            interfaz.dibujarMarco(CIAN);
            interfaz.cambiarTitulo("FIRULI 3000 - NUEVA COMPRA DE INSUMOS");
            interfaz.siguienteLinea();
            if(compraInsumo.cargar(interfaz)){
                archivo.guardar(compraInsumo);
                interfaz.siguienteLinea();
                interfaz.mostrar("Compra cargada con exito.",VERDECLARO);
            }
            else {
                interfaz.siguienteLinea();
                interfaz.mostrar("Error al cargar la compra.",ROJO);
            }
            interfaz.siguienteLinea();
            interfaz.mostrar("Desea cargar una nueva compra de insumos? [1] Si || [0] No",AMARILLO);
            int opc = 2;
            do{
                opc = interfaz.pedirOpcionNumerica();
            } while(opc!=1&&opc!=0);
            continuarCargando=opc;
        } while(continuarCargando);
    }

    void Menu::nuevoPagoEmpleado(){
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

    void Menu::cargaDeDatos(){
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
        void Menu::menuCategorias(){
            char opc;
            do{
                system("cls");
                interfaz.setFilaActual(7);
                interfaz.dibujarMarco(rlutil::CYAN);
                interfaz.cambiarTitulo("FIRULI 3000 - CATEGORIAS");
                interfaz.siguienteLinea();
                cout<<"[1] - Listar";
                interfaz.siguienteLinea();
                cout<<"[2] - Agregar";
                interfaz.siguienteLinea();
                cout<<"[0] - Volver";
                opc = interfaz.pedirOpcion();
                // Pregunta por la opcion elegida y se dirige al método correspondiente
                switch(opc)
                {
                    case '1':
                        listarCategorias();
                        break;
                    case '2':
                        nuevaCategoria();
                        break;
                }
            }
            while(opc != '0');
        }
            void Menu::listarCategorias(){
                CategoriasArchivo archivo;
                int cantidadRegistros = archivo.getCantidad();
                Categoria *vec = new Categoria[cantidadRegistros];
                if(vec==NULL) return;
                int cantidadPorPagina = 10;
                int totalPaginas = (cantidadRegistros + cantidadPorPagina - 1) / cantidadPorPagina;
                int paginaActual = 1;
                char opc;
                archivo.leerTodos(vec, cantidadRegistros);

                do {
                    system("cls");
                    interfaz.dibujarMarco(CIAN);
                    interfaz.setFilaActual(7);
                    interfaz.cambiarTitulo("FIRULI 3000 - LISTADO DE CATEGORIAS");
                    interfaz.siguienteLinea();
                    if (cantidadRegistros==0){
                        rlutil::setColor(ROJO);
                        cout<<"No hay registros a listar.";
                        interfaz.cambiarMensaje("Presione una tecla para continuar.",ROJO);
                        opc = '0';
                        rlutil::setColor(BLANCO);
                        rlutil::anykey();
                    }
                    else{
                        /*
                        Atributos de categoria:
                        int codigo;
                        char nombre[50];
                        bool estado;
                        */
                        int indiceInicial = (paginaActual - 1) * cantidadPorPagina;
                        int indiceFinal = min(paginaActual * cantidadPorPagina, cantidadRegistros);
                        cout<<"Pagina " << paginaActual << " de " << totalPaginas;
                        interfaz.siguienteLinea();
                        interfaz.siguienteLinea();
                        cout<<"Cod\t|\tNombre";
                        interfaz.siguienteLinea();
                        for (int i = indiceInicial; i < indiceFinal; i++) {
                            if(vec[i].getEstado()){
                                cout<< vec[i].toString();
                                interfaz.siguienteLinea();
                            }
                            else{
                                rlutil::setColor(ROJO);
                                cout<< vec[i].toString();
                                interfaz.siguienteLinea();
                                rlutil::setColor(BLANCO);
                            }
                        }
                        interfaz.siguienteLinea();
                        cout << " [1] Anterior || [2] Siguiente || [3] Activar/Desactivar || [4] Modificar || [0] Volver";
                        opc = interfaz.pedirOpcion();
                        switch (opc) {
                            case '1':
                                paginaActual = max(1, paginaActual - 1);
                                break;
                            case '2':
                                paginaActual = min(totalPaginas, paginaActual + 1);
                                break;
                            case '3':
                                cambiarEstadoCategoria();
                                archivo.leerTodos(vec, cantidadRegistros);
                                break;
                            case '4':
                                modificarCategoria();
                                archivo.leerTodos(vec, cantidadRegistros);
                                break;
                        }
                    }
                } while (opc != '0');
                delete []vec;
            }
            void Menu::nuevaCategoria(){
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
            void Menu::cambiarEstadoCategoria(){
                CategoriasArchivo archivo;
                Categoria obj;
                string id;
                interfaz.cambiarTitulo("FIRULI 3000 - BORRAR/REACTIVAR CATEGORIA");
                interfaz.siguienteLinea();
                int indice=-1;
                cout<<"Ingrese codigo de categoria a borrar/reactivar: ";
                getline(cin,id);
                indice = archivo.buscar(stoi(id));
                if(indice>=0){
                    obj = archivo.leer(indice);
                    obj.setEstado(!obj.getEstado());
                    archivo.guardar(obj,indice);
                    if(!obj.getEstado()){
                        interfaz.cambiarMensaje("Categoria borrada exitosamente. Presione una tecla para continuar.",VERDECLARO);
                    }
                    else{
                        interfaz.cambiarMensaje("Categoria reactivada exitosamente. Presione una tecla para continuar.",VERDECLARO);
                    }
                }
                else
                {
                    interfaz.cambiarMensaje("Codigo inexistente. Presione una tecla para continuar.",ROJO);
                }
                rlutil::anykey();
            }
            void Menu::modificarCategoria(){
                CategoriasArchivo archivo;
                Categoria obj;
                string id,nombre;
                interfaz.cambiarTitulo("FIRULI 3000 - MODIFICAR CATEGORIA");
                interfaz.siguienteLinea();
                int indice=-1;
                cout<<"Ingrese codigo de categoria a modificar: ";
                getline(cin,id);
                indice = archivo.buscar(stoi(id));
                if(indice>=0)
                {
                    obj = archivo.leer(indice);
                    interfaz.siguienteLinea();
                    cout<<"Ingrese los datos que desea modificar (deje en blanco los datos que desee mantener)";
                    interfaz.siguienteLinea();
                    interfaz.siguienteLinea();
                    cout<<"Nombre: ";
                    getline(cin,nombre);
                    if(nombre!=""){
                       obj.setNombre(nombre);
                    }
                    archivo.guardar(obj,indice);
                    interfaz.cambiarMensaje("Categoria modificada exitosamente. Presione una tecla para continuar.",VERDECLARO);
                }
                else {
                    interfaz.cambiarMensaje("Codigo inexistente. Presione una tecla para continuar.",ROJO);
                }
                rlutil::anykey();
            }
        void Menu::menuClientes(){
            char opc;
            do{
                system("cls");
                interfaz.setFilaActual(7);
                interfaz.dibujarMarco(rlutil::CYAN);
                interfaz.cambiarTitulo("FIRULI 3000 - CLIENTES");
                interfaz.siguienteLinea();
                cout<<"[1] - Listar";
                interfaz.siguienteLinea();
                cout<<"[2] - Agregar";
                interfaz.siguienteLinea();
                cout<<"[0] - Volver";
                opc = interfaz.pedirOpcion();
                // Pregunta por la opcion elegida y se dirige al método correspondiente
                switch(opc)
                {
                    case '1':
                        listarClientes();
                        break;
                    case '2':
                        nuevoCliente();
                        break;
                }
            }
            while(opc != '0');
        }
            void Menu::listarClientes(){
                ClientesArchivo archivo;
                int cantidadRegistros = archivo.getCantidad();
                Cliente *vec = new Cliente[cantidadRegistros];
                if(vec==NULL) return;
                int cantidadPorPagina = 10;
                int totalPaginas = (cantidadRegistros + cantidadPorPagina - 1) / cantidadPorPagina;
                int paginaActual = 1;
                char opc;
                archivo.leerTodos(vec, cantidadRegistros);

                do {
                    system("cls");
                    interfaz.dibujarMarco(CIAN);
                    interfaz.setFilaActual(7);
                    interfaz.cambiarTitulo("FIRULI 3000 - LISTADO DE CLIENTES");
                    interfaz.siguienteLinea();
                    if (cantidadRegistros==0){
                        rlutil::setColor(ROJO);
                        cout<<"No hay registros a listar.";
                        interfaz.cambiarMensaje("Presione una tecla para continuar.",ROJO);
                        opc = '0';
                        rlutil::setColor(BLANCO);
                        rlutil::anykey();
                    }
                    else{
                        /*
                        Atributos de cliente:
                        int dni;
                        char nombre[50];
                        char apellido[50];
                        int telefono;
                        char email[50];
                        bool estado;
                        */
                        int indiceInicial = (paginaActual - 1) * cantidadPorPagina;
                        int indiceFinal = min(paginaActual * cantidadPorPagina, cantidadRegistros);
                        cout<<"Pagina " << paginaActual << " de " << totalPaginas;
                        interfaz.siguienteLinea();
                        interfaz.siguienteLinea();
                        cout<<"DNI\t\t|\tNombre y Apellido\t|\tTelefono\t|\te-mail";
                        interfaz.siguienteLinea();
                        for (int i = indiceInicial; i < indiceFinal; i++) {
                            if(vec[i].getEstado()){
                                cout<< vec[i].toString();
                                interfaz.siguienteLinea();
                            }
                            else{
                                rlutil::setColor(ROJO);
                                cout<< vec[i].toString();
                                interfaz.siguienteLinea();
                                rlutil::setColor(BLANCO);
                            }
                        }
                        interfaz.siguienteLinea();
                        cout << " [1] Anterior || [2] Siguiente || [3] Activar/Desactivar || [4] Modificar || [0] Volver";
                        opc = interfaz.pedirOpcion();
                        switch (opc) {
                            case '1':
                                paginaActual = max(1, paginaActual - 1);
                                break;
                            case '2':
                                paginaActual = min(totalPaginas, paginaActual + 1);
                                break;
                            case '3':
                                cambiarEstadoCliente();
                                archivo.leerTodos(vec, cantidadRegistros);
                                break;
                            case '4':
                                modificarCliente();
                                archivo.leerTodos(vec, cantidadRegistros);
                                break;
                        }
                    }
                } while (opc != '0');
                delete []vec;
            }
            void Menu::nuevoCliente(){
                ClientesArchivo archivo;
                Cliente obj;
                obj.setEstado(true);
                system("cls");
                interfaz.setFilaActual(8);
                interfaz.dibujarRectangulo(2,2,2,interfaz.getAncho()-3,CIAN);
                interfaz.cambiarTitulo("FIRULI 3000 - NUEVO CLIENTE");
                rlutil::locate(1,interfaz.getFilaActual());
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
            void Menu::cambiarEstadoCliente(){
                ClientesArchivo archivo;
                Cliente obj;
                string id;
                interfaz.cambiarTitulo("FIRULI 3000 - BORRAR/REACTIVAR CLIENTE");
                interfaz.siguienteLinea();
                int indice=-1;
                cout<<"Ingrese DNI del cliente a borrar/reactivar: ";
                getline(cin,id);
                indice = archivo.buscar(stoi(id));
                if(indice>=0){
                    obj = archivo.leer(indice);
                    obj.setEstado(!obj.getEstado());
                    archivo.guardar(obj,indice);
                    if(!obj.getEstado()){
                        interfaz.cambiarMensaje("Cliente borrado exitosamente. Presione una tecla para continuar.",VERDECLARO);
                    }
                    else{
                        interfaz.cambiarMensaje("Cliente reactivado exitosamente. Presione una tecla para continuar.",VERDECLARO);
                    }
                }
                else
                {
                    interfaz.cambiarMensaje("DNI inexistente. Presione una tecla para continuar.",ROJO);
                }
                rlutil::anykey();
            }
            void Menu::modificarCliente(){
                ClientesArchivo archivo;
                Cliente obj;
                string id,cadena;
                interfaz.cambiarTitulo("FIRULI 3000 - MODIFICAR CLIENTE");
                interfaz.siguienteLinea();
                int indice=-1;
                cout<<"Ingrese DNI del cliente a modificar: ";
                getline(cin,id);
                indice = archivo.buscar(stoi(id));
                if(indice>=0)
                {
                    obj = archivo.leer(indice);
                    interfaz.siguienteLinea();
                    cout<<"Ingrese los datos que desea modificar (deje en blanco los datos que desee mantener)";
                    interfaz.siguienteLinea();
                    interfaz.siguienteLinea();

                    /*
                        int entero;
                        string cadena;
                        // TODO: Validaciones
                        cout<<"  Nombre: ";
                        getline(cin, cadena);
                        setNombre(cadena);
                        cout<<"  Apellido: ";
                        getline(cin, cadena);
                        setApellido(cadena);
                        cout<<"  Telefono: ";
                        cin>>entero;
                        setTelefono(entero);
                        cout<<"  Email: ";
                        cin.ignore();
                        getline(cin, cadena);
                        setEmail(cadena);
                    */


                    cout<<"Nombre: ";
                    getline(cin,cadena);
                    if(cadena!=""){
                       obj.setNombre(cadena);
                    }
                    interfaz.siguienteLinea();
                    cout<<"Apellido: ";
                    getline(cin,cadena);
                    if(cadena!=""){
                       obj.setApellido(cadena);
                    }
                    interfaz.siguienteLinea();
                    cout<<"Telefono: ";
                    getline(cin,cadena);
                    if(cadena!=""){
                       obj.setTelefono(cadena);
                    }
                    interfaz.siguienteLinea();
                    cout<<"Email: ";
                    getline(cin,cadena);
                    if(cadena!=""){
                       obj.setEmail(cadena);
                    }
                    archivo.guardar(obj,indice);
                    interfaz.cambiarMensaje("Cliente modificado exitosamente. Presione una tecla para continuar.",VERDECLARO);
                }
                else {
                    interfaz.cambiarMensaje("DNI inexistente. Presione una tecla para continuar.",ROJO);
                }
                rlutil::anykey();
            }
        void Menu::menuEmpleados(){
            char opc;
            do{
                system("cls");
                interfaz.setFilaActual(7);
                interfaz.dibujarMarco(rlutil::CYAN);
                interfaz.cambiarTitulo("FIRULI 3000 - EMPLEADOS");
                interfaz.siguienteLinea();
                cout<<"[1] - Listar";
                interfaz.siguienteLinea();
                cout<<"[2] - Agregar";
                interfaz.siguienteLinea();
                cout<<"[0] - Volver";
                opc = interfaz.pedirOpcion();
                // Pregunta por la opcion elegida y se dirige al método correspondiente
                switch(opc)
                {
                    case '1':
                        listarEmpleados();
                        break;
                    case '2':
                        nuevoEmpleado();
                        break;
                }
            }
            while(opc != '0');
        }
            void Menu::listarEmpleados(){
                EmpleadosArchivo archivo;
                int cantidadRegistros = archivo.getCantidad();
                Empleado *vec = new Empleado[cantidadRegistros];
                if(vec==NULL) return;
                int cantidadPorPagina = 10;
                int totalPaginas = (cantidadRegistros + cantidadPorPagina - 1) / cantidadPorPagina;
                int paginaActual = 1;
                char opc;
                archivo.leerTodos(vec, cantidadRegistros);

                do {
                    system("cls");
                    interfaz.dibujarMarco(CIAN);
                    interfaz.setFilaActual(7);
                    interfaz.cambiarTitulo("FIRULI 3000 - LISTADO DE EMPLEADOS");
                    interfaz.siguienteLinea();
                    if (cantidadRegistros==0){
                        rlutil::setColor(ROJO);
                        cout<<"No hay registros a listar.";
                        interfaz.cambiarMensaje("Presione una tecla para continuar.",ROJO);
                        opc = '0';
                        rlutil::setColor(BLANCO);
                        rlutil::anykey();
                    }
                    else {
                        /*
                        Atributos de persona:
                        int dni;
                        char nombre[50];
                        char apellido[50];
                        char telefono[50];
                        char email[50];
                        bool estado;

                        Atributos de empleado:
                        float PorcentajeComision;
                        float SueldoFijo;
                        */
                        int indiceInicial = (paginaActual - 1) * cantidadPorPagina;
                        int indiceFinal = min(paginaActual * cantidadPorPagina, cantidadRegistros);
                        cout<<"Pagina " << paginaActual << " de " << totalPaginas;
                        interfaz.siguienteLinea();
                        interfaz.siguienteLinea();
                        cout<<"DNI\t\t|\tNombre y Apellido\t|\tTelefono\t|\te-mail\t|\t% comision\t|\tSueldo";
                        interfaz.siguienteLinea();
                        for (int i = indiceInicial; i < indiceFinal; i++) {
                            if(vec[i].getEstado()){
                                cout<< vec[i].toString();
                                interfaz.siguienteLinea();
                            }
                            else{
                                rlutil::setColor(ROJO);
                                cout<< vec[i].toString();
                                interfaz.siguienteLinea();
                                rlutil::setColor(BLANCO);
                            }
                        }
                        interfaz.siguienteLinea();
                        cout << " [1] Anterior || [2] Siguiente || [3] Activar/Desactivar || [4] Modificar || [0] Volver";
                        opc = interfaz.pedirOpcion();
                        switch (opc) {
                            case '1':
                                paginaActual = max(1, paginaActual - 1);
                                break;
                            case '2':
                                paginaActual = min(totalPaginas, paginaActual + 1);
                                break;
                            case '3':
                                cambiarEstadoEmpleado();
                                archivo.leerTodos(vec, cantidadRegistros);
                                break;
                            case '4':
                                modificarEmpleado();
                                archivo.leerTodos(vec, cantidadRegistros);
                                break;
                        }
                    }
                } while (opc != '0');
                delete []vec;
            }
            void Menu::nuevoEmpleado(){
                EmpleadosArchivo archivo;
                Empleado obj;
                obj.setEstado(true);
                system("cls");
                interfaz.setFilaActual(8);
                interfaz.dibujarRectangulo(2,2,2,interfaz.getAncho()-3,CIAN);
                interfaz.cambiarTitulo("FIRULI 3000 - NUEVO EMPLEADO");
                rlutil::locate(1,interfaz.getFilaActual());
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
            void Menu::cambiarEstadoEmpleado(){
                EmpleadosArchivo archivo;
                Empleado obj;
                string id;
                interfaz.cambiarTitulo("FIRULI 3000 - BORRAR/REACTIVAR EMPLEADO");
                interfaz.siguienteLinea();
                int indice=-1;
                cout<<"Ingrese DNI de empleado a borrar/reactivar: ";
                getline(cin,id);
                indice = archivo.buscar(stoi(id));
                if(indice>=0){
                    obj = archivo.leer(indice);
                    obj.setEstado(!obj.getEstado());
                    archivo.guardar(obj,indice);
                    if(!obj.getEstado()){
                        interfaz.cambiarMensaje("Empleado borrado exitosamente. Presione una tecla para continuar.",VERDECLARO);
                    }
                    else{
                        interfaz.cambiarMensaje("Empleado reactivado exitosamente. Presione una tecla para continuar.",VERDECLARO);
                    }
                }
                else
                {
                    interfaz.cambiarMensaje("DNI inexistente. Presione una tecla para continuar.",ROJO);
                }
                rlutil::anykey();
            }
            void Menu::modificarEmpleado(){
                EmpleadosArchivo archivo;
                Empleado obj;
                string id,nombre;
                interfaz.cambiarTitulo("FIRULI 3000 - MODIFICAR EMPLEADO");
                interfaz.siguienteLinea();
                int indice=-1;
                cout<<"Ingrese DNI de empleado a modificar: ";
                getline(cin,id);
                indice = archivo.buscar(stoi(id));
                if(indice>=0)
                {
                    obj = archivo.leer(indice);
                    interfaz.siguienteLinea();
                    cout<<"Ingrese los datos que desea modificar (deje en blanco los datos que desee mantener)";
                    interfaz.siguienteLinea();
                    interfaz.siguienteLinea();
                    // TODO: datos de empleado
                    cout<<"Nombre: ";
                    getline(cin,nombre);
                    if(nombre!=""){
                       obj.setNombre(nombre);
                    }
                    archivo.guardar(obj,indice);
                    interfaz.cambiarMensaje("Empleado modificado exitosamente. Presione una tecla para continuar.",VERDECLARO);
                }
                else {
                    interfaz.cambiarMensaje("DNI inexistente. Presione una tecla para continuar.",ROJO);
                }
                rlutil::anykey();
            }
        void Menu::menuProveedores(){
            char opc;
            do{
                system("cls");
                interfaz.setFilaActual(7);
                interfaz.dibujarMarco(rlutil::CYAN);
                interfaz.cambiarTitulo("FIRULI 3000 - PROVEEDORES");
                interfaz.siguienteLinea();
                cout<<"[1] - Listar";
                interfaz.siguienteLinea();
                cout<<"[2] - Agregar";
                interfaz.siguienteLinea();
                cout<<"[0] - Volver";
                opc = interfaz.pedirOpcion();
                // Pregunta por la opcion elegida y se dirige al método correspondiente
                switch(opc)
                {
                    case '1':
                        listarProveedor();
                        break;
                    case '2':
                        nuevoProveedor();
                        break;
                }
            }
            while(opc != '0');
        }
            void Menu::listarProveedor(){
                ProveedoresArchivo archivo;
                int cantidadRegistros = archivo.getCantidad();
                Proveedor *vec = new Proveedor[cantidadRegistros];
                if(vec == NULL) return;
                int cantidadPorPagina = 10;
                int totalPaginas = (cantidadRegistros + cantidadPorPagina - 1) / cantidadPorPagina;
                int paginaActual = 1;
                char opc;
                archivo.leerTodos(vec, cantidadRegistros);

                do {
                    system("cls");
                    interfaz.dibujarMarco(CIAN);
                    interfaz.setFilaActual(7);
                    interfaz.cambiarTitulo("FIRULI 3000 - LISTADO DE PROVEEDORES");
                    interfaz.siguienteLinea();
                    if (cantidadRegistros==0){
                        rlutil::setColor(ROJO);
                        cout<<"No hay registros a listar.";
                        interfaz.cambiarMensaje("Presione una tecla para continuar.",ROJO);
                        opc = '0';
                        rlutil::setColor(BLANCO);
                        rlutil::anykey();
                    }
                    else{
                        /*
                        Atributos de proveedor:
                        int cuil;
                        char razonSocial[50];
                        int codCategoria;
                        char telefono[50];
                        char email[50];
                        bool estado;
                        */
                        int indiceInicial = (paginaActual - 1) * cantidadPorPagina;
                        int indiceFinal = min(paginaActual * cantidadPorPagina, cantidadRegistros);
                        cout<<"Pagina " << paginaActual << " de " << totalPaginas;
                        interfaz.siguienteLinea();
                        interfaz.siguienteLinea();
                        cout<<"Cuil\t|\tRazon Social\t|\tCod Categ\t|\tTel\t|\tEmail";
                        interfaz.siguienteLinea();
                        for (int i = indiceInicial; i < indiceFinal; i++) {
                            if(vec[i].getEstado()){
                                cout<< vec[i].toString();
                                interfaz.siguienteLinea();
                            }
                            else{
                                rlutil::setColor(ROJO);
                                cout<< vec[i].toString();
                                interfaz.siguienteLinea();
                                rlutil::setColor(BLANCO);
                            }
                        }
                        interfaz.siguienteLinea();
                        cout << " [1] Anterior || [2] Siguiente || [3] Activar/Desactivar || [4] Modificar || [0] Volver";
                        opc = interfaz.pedirOpcion();
                        switch (opc) {
                            case '1':
                                paginaActual = max(1, paginaActual - 1);
                                break;
                            case '2':
                                paginaActual = min(totalPaginas, paginaActual + 1);
                                break;
                            case '3':
                                cambiarEstadoProveedor();
                                archivo.leerTodos(vec, cantidadRegistros);
                                break;
                            case '4':
                                modificarProveedor();
                                archivo.leerTodos(vec, cantidadRegistros);
                                break;
                        }
                    }
                } while (opc != '0');
                delete []vec;
            }
            void Menu::nuevoProveedor(){
                ProveedoresArchivo archivo;
                Proveedor obj;
                obj.setEstado(true);
                system("cls");
                interfaz.setFilaActual(8);
                interfaz.dibujarRectangulo(2,2,2,interfaz.getAncho()-3,CIAN);
                interfaz.cambiarTitulo("FIRULI 3000 - NUEVO PROVEEDOR");
                rlutil::locate(1,interfaz.getFilaActual());
                string valor;
                cout<<"  CUIL: ";
                cin>>valor;
                cin.ignore();
                if (archivo.buscar(valor)==-1){
                    obj.setCuil(valor);
                    if(obj.cargar())
                    {
                        archivo.guardar(obj);
                    }
                }
                else{
                    cout<<"  ERROR: El proveedor ya existe.";
                }
                rlutil::anykey();
}
            void Menu::cambiarEstadoProveedor(){
                ProveedoresArchivo archivo;
                Proveedor obj;
                string id;
                interfaz.cambiarTitulo("FIRULI 3000 - BORRAR/REACTIVAR PROVEEDOR");
                interfaz.siguienteLinea();
                int indice=-1;
                cout<<"Ingrese CUIL de proveedor a borrar/reactivar: ";
                getline(cin,id);
                indice = archivo.buscar(id);
                if(indice>=0){
                    obj = archivo.leer(indice);
                    obj.setEstado(!obj.getEstado());
                    archivo.guardar(obj,indice);
                    if(!obj.getEstado()){
                        interfaz.cambiarMensaje("Proveedor borrado exitosamente. Presione una tecla para continuar.",VERDECLARO);
                    }
                    else{
                        interfaz.cambiarMensaje("Proveedor reactivado exitosamente. Presione una tecla para continuar.",VERDECLARO);
                    }
                }
                else
                {
                    interfaz.cambiarMensaje("CUIL inexistente. Presione una tecla para continuar.",ROJO);
                }
                rlutil::anykey();
            }
            void Menu::modificarProveedor(){
                ProveedoresArchivo archivo;
                CategoriasArchivo _categorias;
                Proveedor obj;
                string id,cadena;
                interfaz.cambiarTitulo("FIRULI 3000 - MODIFICAR PROVEEDOR");
                interfaz.siguienteLinea();
                int indice=-1;
                cout<<"Ingrese CUIL de proveedor a modificar: ";
                getline(cin,id);
                indice = archivo.buscar(id);
                if(indice>=0)
                {
                    obj = archivo.leer(indice);
                    interfaz.siguienteLinea();
                    cout<<"Ingrese los datos que desea modificar (deje en blanco los datos que desee mantener)";
                    interfaz.siguienteLinea();
                    interfaz.siguienteLinea();

                    // TODO: datos de proveedor
                    /*
                    char razonSocial[50];
                    int codCategoria;
                    char telefono[50];
                    char email[50];
                    bool estado;
                    */
                    cout<<"Razon social: ";
                    getline(cin, cadena);
                    if(cadena!=""){
                       obj.setRazonSocial(cadena);
                    }
                    interfaz.siguienteLinea();
                    cout<<"Codigo categoria: ";
                    getline(cin, cadena);
                    if(cadena!=""){
                        if(_categorias.buscar(stoi(cadena)) == -1)
                        {
                            interfaz.cambiarMensaje("La categoria no existe. Presione una tecla para continuar.",ROJO);
                            rlutil::anykey();
                            return;
                        }
                        else
                        {
                            obj.setCodCategoria(stoi(cadena));
                        }
                    }
                    interfaz.siguienteLinea();
                    cout<<"Telefono: ";
                    getline(cin,cadena);
                    if(cadena!=""){
                       obj.setTelefono(cadena);
                    }
                    interfaz.siguienteLinea();
                    cout<<"Email: ";
                    getline(cin,cadena);
                    if(cadena!=""){
                       obj.setEmail(cadena);
                    }
                    archivo.guardar(obj,indice);
                    interfaz.cambiarMensaje("Proveedor modificado exitosamente. Presione una tecla para continuar.",VERDECLARO);
                }
                else {
                    interfaz.cambiarMensaje("CUIL inexistente. Presione una tecla para continuar.",ROJO);
                }
                rlutil::anykey();
            }
        void Menu::menuServicios(){
             char opc;
            do{
                system("cls");
                interfaz.setFilaActual(7);
                interfaz.dibujarMarco(rlutil::CYAN);
                interfaz.cambiarTitulo("FIRULI 3000 - SERVICIOS");
                interfaz.siguienteLinea();
                cout<<"[1] - Listar";
                interfaz.siguienteLinea();
                cout<<"[2] - Agregar";
                interfaz.siguienteLinea();
                cout<<"[0] - Volver";
                opc = interfaz.pedirOpcion();
                // Pregunta por la opcion elegida y se dirige al método correspondiente
                switch(opc)
                {
                    case '1':
                        listarServicio();
                        break;
                    case '2':
                        nuevoServicio();
                        break;
                }
            }
            while(opc != '0');
        }
            void Menu::listarServicio(){
                ServiciosArchivo archivo;
                int cantidadRegistros = archivo.getCantidad();
                Servicio *vec = new Servicio[cantidadRegistros];
                if(vec == NULL) return;
                int cantidadPorPagina = 10;
                int totalPaginas = (cantidadRegistros + cantidadPorPagina - 1) / cantidadPorPagina;
                int paginaActual = 1;
                char opc;
                archivo.leerTodos(vec, cantidadRegistros);

                do {
                    system("cls");
                    interfaz.dibujarMarco(CIAN);
                    interfaz.setFilaActual(7);
                    interfaz.cambiarTitulo("FIRULI 3000 - LISTADO DE SERVICIOS");
                    interfaz.siguienteLinea();
                    if (cantidadRegistros==0){
                        rlutil::setColor(ROJO);
                        cout<<"No hay registros a listar.";
                        interfaz.cambiarMensaje("Presione una tecla para continuar.",ROJO);
                        opc = '0';
                        rlutil::setColor(BLANCO);
                        rlutil::anykey();
                    }
                    else{
                        /*
                        Atributos de servicio:
                        int codigo;
                        char nombre[50];
                        float valor;
                        int codCategoria;
                        bool estado;
                        */
                        int indiceInicial = (paginaActual - 1) * cantidadPorPagina;
                        int indiceFinal = min(paginaActual * cantidadPorPagina, cantidadRegistros);
                        cout<<"Pagina " << paginaActual << " de " << totalPaginas;
                        interfaz.siguienteLinea();
                        interfaz.siguienteLinea();
                        cout<<"Codigo\t|\tNombre\t|\tValor\t|\tCod. Categoria";
                        interfaz.siguienteLinea();
                        for (int i = indiceInicial; i < indiceFinal; i++) {
                            if(vec[i].getEstado()){
                                cout<< vec[i].toString();
                                interfaz.siguienteLinea();
                            }
                            else{
                                rlutil::setColor(ROJO);
                                cout<< vec[i].toString();
                                interfaz.siguienteLinea();
                                rlutil::setColor(BLANCO);
                            }
                        }
                        interfaz.siguienteLinea();
                        cout << " [1] Anterior || [2] Siguiente || [3] Activar/Desactivar || [4] Modificar || [0] Volver";
                        opc = interfaz.pedirOpcion();
                        switch (opc) {
                            case '1':
                                paginaActual = max(1, paginaActual - 1);
                                break;
                            case '2':
                                paginaActual = min(totalPaginas, paginaActual + 1);
                                break;
                            case '3':
                                cambiarEstadoServicio();
                                archivo.leerTodos(vec, cantidadRegistros);
                                break;
                            case '4':
                                modificarServicio();
                                archivo.leerTodos(vec, cantidadRegistros);
                                break;
                        }
                    }
                } while (opc != '0');
                delete []vec;
            }
            void Menu::nuevoServicio(){
                ServiciosArchivo archivo;
                Servicio obj;
                obj.setEstado(true);
                obj.setCodigo(archivo.getCantidad()+1);
                system("cls");
                interfaz.setFilaActual(8);
                interfaz.dibujarRectangulo(2,2,2,interfaz.getAncho()-3,CIAN);
                interfaz.cambiarTitulo("FIRULI 3000 - NUEVO SERVICIO");
                rlutil::locate(1,interfaz.getFilaActual());
                obj.cargar();
                archivo.guardar(obj);
            }
            void Menu::cambiarEstadoServicio(){
                ServiciosArchivo archivo;
                Servicio obj;
                string id;
                interfaz.cambiarTitulo("FIRULI 3000 - BORRAR/REACTIVAR SERVICIO");
                interfaz.siguienteLinea();
                int indice=-1;
                cout<<"Ingrese codigo de servicio a borrar/reactivar: ";
                getline(cin,id);
                indice = archivo.buscar(stoi(id));
                if(indice>=0){
                    obj = archivo.leer(indice);
                    obj.setEstado(!obj.getEstado());
                    archivo.guardar(obj,indice);
                    if(!obj.getEstado()){
                        interfaz.cambiarMensaje("Servicio borrado exitosamente. Presione una tecla para continuar.",VERDECLARO);
                    }
                    else{
                        interfaz.cambiarMensaje("Servicio reactivado exitosamente. Presione una tecla para continuar.",VERDECLARO);
                    }
                }
                else
                {
                    interfaz.cambiarMensaje("Codigo inexistente. Presione una tecla para continuar.",ROJO);
                }
                rlutil::anykey();
            }
            void Menu::modificarServicio(){
                ServiciosArchivo archivo;
                CategoriasArchivo _categorias;
                Servicio obj;
                string id,cadena;
                interfaz.cambiarTitulo("FIRULI 3000 - MODIFICAR SERVICIO");
                interfaz.siguienteLinea();
                int indice=-1;
                cout<<"Ingrese codigo de servicio a modificar: ";
                getline(cin,id);
                indice = archivo.buscar(stoi(id));
                if(indice>=0)
                {
                    obj = archivo.leer(indice);
                    interfaz.siguienteLinea();
                    cout<<"Ingrese los datos que desea modificar (deje en blanco los datos que desee mantener)";
                    interfaz.siguienteLinea();
                    interfaz.siguienteLinea();

                    // Atributos de servicio
                    /*
                    int codigo;
                    char nombre[50];
                    float valor;
                    int codCategoria;
                    bool estado;
                    */
                    cout<<"Nombre: ";
                    getline(cin, cadena);
                    if(cadena!=""){
                       obj.setNombre(cadena);
                    }
                    interfaz.siguienteLinea();
                    cout<<"Valor servicio: ";
                    getline(cin, cadena);
                    if(cadena!=""){
                       obj.setValor(stof(cadena));
                    }
                    interfaz.siguienteLinea();
                    cout<<"Codigo categoria: ";
                    getline(cin, cadena);
                    if(cadena!=""){
                        if(_categorias.buscar(stoi(cadena)) == -1)
                        {
                            interfaz.cambiarMensaje("La categoria no existe. Presione una tecla para continuar.",ROJO);
                            rlutil::anykey();
                            return;
                        }
                        else
                        {
                            obj.setCodCategoria(stoi(cadena));
                        }
                    }
                    archivo.guardar(obj,indice);
                    interfaz.cambiarMensaje("Servicio modificado exitosamente. Presione una tecla para continuar.",VERDECLARO);
                }
                else {
                    interfaz.cambiarMensaje("Codigo inexistente. Presione una tecla para continuar.",ROJO);
                }
                rlutil::anykey();
            }

    void Menu::consultas(){
        // TODO: Pensar consultas a agregar y programarlas
    }
        void Menu::nuevaConsEmpleado(){
            // TODO
        }
        void Menu::nuevaConsCliente(){
            // TODO
        }
    void Menu::reportes(){
        // TODO
    }
    void Menu::backupRestauracionDeArchivos(){
        char opc;
        do{
            system("cls");
            interfaz.dibujarMarco(rlutil::CYAN);
            interfaz.cambiarTitulo("FIRULI 3000 - BACKUP/RESTAURACION DE ARCHIVOS");
            interfaz.setFilaActual(7);
            interfaz.siguienteLinea();
            cout<<"[1] - Categorias";
            interfaz.siguienteLinea();
            cout<<"[2] - Clientes";
            interfaz.siguienteLinea();
            cout<<"[3] - CompraInsumos";
            interfaz.siguienteLinea();
            cout<<"[4] - Empleados";
            interfaz.siguienteLinea();
            cout<<"[5] - Gastos Generales";
            interfaz.siguienteLinea();
            cout<<"[6] - Pagos Empleados";
            interfaz.siguienteLinea();
            cout<<"[7] - Proveedores";
            interfaz.siguienteLinea();
            cout<<"[8] - Servicios";
            interfaz.siguienteLinea();
            cout<<"[9] - Ventas";
            interfaz.siguienteLinea();
            interfaz.siguienteLinea();
            cout<<"[0] - Volver";
            opc = interfaz.pedirOpcion();
            // Pregunta por la opcion elegida y se dirige al método correspondiente
            switch(opc)
            {
                case '1':
                    menuImportarExportar(1);
                    break;
                case '2':
                    menuImportarExportar(2);
                    break;
                case '3':
                    menuImportarExportar(3);
                    break;
                case '4':
                    menuImportarExportar(4);
                    break;
                case '5':
                    menuImportarExportar(5);
                    break;
                case '6':
                    menuImportarExportar(6);
                    break;
                case '7':
                    menuImportarExportar(7);
                    break;
                case '8':
                    menuImportarExportar(8);
                    break;
                case '9':
                    menuImportarExportar(9);
                    break;
            }
        }
        while(opc != '0');
    }
        void Menu::menuImportarExportar(int opcion){
            char opc;
            do{
                system("cls");
                interfaz.dibujarMarco(rlutil::CYAN);
                interfaz.cambiarTitulo("FIRULI 3000 - IMPORTAR O EXPORTAR CSV");
                interfaz.setFilaActual(7);
                interfaz.siguienteLinea();
                cout<<"[1] - Importar CSV";
                interfaz.siguienteLinea();
                cout<<"[2] - Exportar CSV";
                interfaz.siguienteLinea();
                interfaz.siguienteLinea();
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

    bool Menu::salirDelSistema(){
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
            return salirDelSistema();
        }
    }
