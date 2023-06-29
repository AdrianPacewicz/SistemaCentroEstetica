#include "Menu.h"
#include "rlutil.h"
#include "Funciones.h"
#include <iomanip>

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
        PagoEmpleado pagoEmpleado;
        pagoEmpleado.setEstado(true);
        do {
            pagoEmpleado.setId(archivo.getCantidad()+1);
            system("cls");
            interfaz.setFilaActual(8);
            interfaz.dibujarMarco(CIAN);
            interfaz.cambiarTitulo("FIRULI 3000 - NUEVO PAGO DE EMPLEADO");
            interfaz.siguienteLinea();
            if(pagoEmpleado.cargar(interfaz)){
                archivo.guardar(pagoEmpleado);
                interfaz.siguienteLinea();
                interfaz.mostrar("Pago cargado con exito.",VERDECLARO);
            }
            else {
                interfaz.siguienteLinea();
                interfaz.mostrar("Error al cargar el pago.",ROJO);
            }
            interfaz.siguienteLinea();
            interfaz.mostrar("Desea cargar un nuevo pago de empleado? [1] Si || [0] No",AMARILLO);
            int opc = 2;
            do{
                opc = interfaz.pedirOpcionNumerica();
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
            interfaz.dibujarMarco(CIAN);
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
                    cout << left << setw(14) << "Codigo";
                    cout << left << setw(30) << "Nombre";
                    interfaz.siguienteLinea();
                    for (int i = indiceInicial; i < indiceFinal; i++) {
                        if(vec[i].getEstado()){
                            cout << left << setw(14) << vec[i].getCodigo();
                            cout << left << setw(30) << vec[i].getNombre();
                            interfaz.siguienteLinea();
                        }
                        else{
                            rlutil::setColor(ROJO);
                            cout << left << setw(14) << vec[i].getCodigo();
                            cout << left << setw(30) << vec[i].getNombre();
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
            interfaz.dibujarMarco(CIAN);
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
                    cout << left << setw(14) << "DNI";
                    cout << left << setw(30) << "Nombre y Apellido";
                    cout << left << setw(15) << "Telefono";
                    cout << left << setw(25) << "e-mail";
                    interfaz.siguienteLinea();
                    for (int i = indiceInicial; i < indiceFinal; i++) {
                        if(vec[i].getEstado()){
                            cout << left << setw(14) << vec[i].getDni();
                            string n = vec[i].getNombre() + " " + vec[i].getApellido();
                            cout << left << setw(30) << n;
                            cout << left << setw(15) << vec[i].getTelefono();
                            cout << left << setw(25) << vec[i].getEmail();
                            interfaz.siguienteLinea();
                        }
                        else{
                            rlutil::setColor(ROJO);
                            cout << left << setw(14) << vec[i].getDni();
                            string n = vec[i].getNombre() + " " + vec[i].getApellido();
                            cout << left << setw(30) << n;
                            cout << left << setw(15) << vec[i].getTelefono();
                            cout << left << setw(25) << vec[i].getEmail();
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
            interfaz.dibujarMarco(CIAN);
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
                    double PorcentajeComision;
                    double SueldoFijo;
                    */
                    int indiceInicial = (paginaActual - 1) * cantidadPorPagina;
                    int indiceFinal = min(paginaActual * cantidadPorPagina, cantidadRegistros);
                    cout<<"Pagina " << paginaActual << " de " << totalPaginas;
                    interfaz.siguienteLinea();
                    interfaz.siguienteLinea();
                    cout << left << setw(14) << "DNI";
                    cout << left << setw(30) << "Nombre y Apellido";
                    cout << left << setw(15) << "Telefono";
                    cout << left << setw(25) << "e-mail";
                    cout << left << setw(15) << "% comision";
                    cout << left << setw(15) << "Sueldo";
                    interfaz.siguienteLinea();
                    for (int i = indiceInicial; i < indiceFinal; i++) {
                        if(vec[i].getEstado()){
                            cout << left << setw(14) << vec[i].getDni();
                            string n = vec[i].getNombre() + " " + vec[i].getApellido();
                            cout << left << setw(30) << n;
                            cout << left << setw(15) << vec[i].getTelefono();
                            cout << left << setw(25) << vec[i].getEmail();
                            cout << left << setw(15) << vec[i].getPComision();
                            cout << left << setw(15) << vec[i].getSueldoF();
                            interfaz.siguienteLinea();
                        }
                        else{
                            rlutil::setColor(ROJO);
                            cout << left << setw(14) << vec[i].getDni();
                            string n = vec[i].getNombre() + " " + vec[i].getApellido();
                            cout << left << setw(30) << n;
                            cout << left << setw(15) << vec[i].getTelefono();
                            cout << left << setw(25) << vec[i].getEmail();
                            cout << left << setw(15) << vec[i].getPComision();
                            cout << left << setw(15) << vec[i].getSueldoF();
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
            interfaz.dibujarMarco(CIAN);
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
                    cout << left << setw(14) << "Cuil";
                    cout << left << setw(30) << "Razon Social";
                    cout << left << setw(12) << "Cod. Categ";
                    cout << left << setw(15) << "Tel";
                    cout << left << setw(25) << "Email";
                    interfaz.siguienteLinea();
                    for (int i = indiceInicial; i < indiceFinal; i++) {
                        if(vec[i].getEstado()){
                            cout << left << setw(14) << vec[i].getCuil();
                            cout << left << setw(30) << vec[i].getRazonS();
                            cout << left << setw(12) << vec[i].getCodCategoria();
                            cout << left << setw(15) << vec[i].getTelefono();
                            cout << left << setw(25) << vec[i].getEmail();
                            interfaz.siguienteLinea();
                        }
                        else{
                            rlutil::setColor(ROJO);
                            cout << left << setw(14) << vec[i].getCuil();
                            cout << left << setw(30) << vec[i].getRazonS();
                            cout << left << setw(12) << vec[i].getCodCategoria();
                            cout << left << setw(15) << vec[i].getTelefono();
                            cout << left << setw(25) << vec[i].getEmail();
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
                rlutil::anykey();
            }

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
            interfaz.dibujarMarco(CIAN);
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
                    double valor;
                    int codCategoria;
                    bool estado;
                    */
                    int indiceInicial = (paginaActual - 1) * cantidadPorPagina;
                    int indiceFinal = min(paginaActual * cantidadPorPagina, cantidadRegistros);
                    cout<<"Pagina " << paginaActual << " de " << totalPaginas;
                    interfaz.siguienteLinea();
                    interfaz.siguienteLinea();
                    cout << left << setw(9) << "Codigo";
                    cout << left << setw(20) << "Nombre";
                    cout << left << setw(8) << "Valor";
                    cout << left << setw(15) << "Cod. Categoria";
                    interfaz.siguienteLinea();
                    for (int i = indiceInicial; i < indiceFinal; i++) {
                        if(vec[i].getEstado()){
                            cout << left << setw(9) << vec[i].getCodigo();
                            cout << left << setw(20) << vec[i].getNombre();
                            cout << left << setw(8) << vec[i].getValor();
                            cout << left << setw(15) << vec[i].getCodCategoria();
                            interfaz.siguienteLinea();
                        }
                        else{
                            rlutil::setColor(ROJO);
                            cout << left << setw(9) << vec[i].getCodigo();
                            cout << left << setw(20) << vec[i].getNombre();
                            cout << left << setw(8) << vec[i].getValor();
                            cout << left << setw(15) << vec[i].getCodCategoria();
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
                double valor;
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
                   obj.setValor(stod(cadena));
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
    char opc;
    do{
        system("cls");
        interfaz.dibujarMarco(rlutil::CYAN);
        interfaz.cambiarTitulo("FIRULI 3000 - NUEVA CONSULTA");
        rlutil::locate(5,8);
        cout<<"[1] - Consultar clientes";
        rlutil::locate(5,9);
        cout<<"[2] - Consultar ventas";
        rlutil::locate(5,10);
        cout<<"[3] - Consultar servicios";
        rlutil::locate(5,11);
        cout<<"[4] - Consultar empleados";
        rlutil::locate(5,12);
        cout<<"[5] - Consultar proveedor";
        rlutil::locate(5,14);
        cout<<"[0] - Volver";
        opc = interfaz.pedirOpcion();
        // Pregunta por la opcion elegida y se dirige a la funcion correspondiente
        switch(opc)
        {
            case '1':
                nuevaConsCliente();
                break;
            case '2':
                nuevaConsVenta();
                break;
            case '3':
                nuevaConsServicio();
                break;
            case '4':
                nuevaConsEmpleado();
                break;
            case '5':
                nuevaConsProveed();
                break;
        }
    }
    while(opc != '0');
}
    void Menu::nuevaConsCliente(){
        char opc;
        do{
            system("cls");
            interfaz.setFilaActual(7);
            interfaz.dibujarMarco(CIAN);
            interfaz.cambiarTitulo("FIRULI 3000 - CONSULTAS CLIENTE");
            interfaz.siguienteLinea();
            cout<<"[1] - Listado por apellido";
            interfaz.siguienteLinea();
            cout<<"[2] - Listado por nombre";
            interfaz.siguienteLinea();
            cout<<"[3] - Consultar por DNI";
            interfaz.siguienteLinea();
            cout<<"[4] - Consultar por telefono";
            interfaz.siguienteLinea();
            cout<<"[5] - Consultar por Apellido";
            interfaz.siguienteLinea();
            interfaz.siguienteLinea();
            cout<<"[0] - Volver";
            opc = interfaz.pedirOpcion();
            // Pregunta por la opcion elegida y se dirige a la funcion correspondiente
            switch(opc)
            {
                case '1':
                    listarClientesXApellido();
                    break;
                case '2':
                    listarClientesXNombre();
                    break;
                case '3':
                    consultaClientePorDNI();
                    break;
                case '4':
                    consultaClientePorTEL();
                    break;
                case '5':
                    consultaClientePorApellido();
                    break;
            }
        }
        while(opc != '0');
    }
        void Menu::listarClientesXApellido(){
            ClientesArchivo archivo;
            int cantidadRegistros = archivo.getCantidad();
            Cliente *vec = new Cliente[cantidadRegistros];
            Cliente clienteAux;
            if(vec==NULL) return;
            int cantidadPorPagina = 10;
            int totalPaginas = (cantidadRegistros + cantidadPorPagina - 1) / cantidadPorPagina;
            int paginaActual = 1;
            char opc;
            archivo.leerTodos(vec, cantidadRegistros);

            // Ordenamiento con método burbuja
            string cadena1, cadena2;
            if (cantidadRegistros>1){
                for (int i=0; i<cantidadRegistros; i++){
                    for (int j=0; j<cantidadRegistros - 1; j++){
                        cadena1 = vec[j].getApellido()+vec[j].getNombre();
                        cadena2 = vec[j+1].getApellido()+vec[j+1].getNombre();
                        if(cadena1 > cadena2){
                            clienteAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=clienteAux;
                        }
                    }
                }
            }

            do {
                system("cls");
                interfaz.dibujarMarco(CIAN);
                interfaz.setFilaActual(7);
                interfaz.cambiarTitulo("FIRULI 3000 - LISTADO DE CLIENTES POR APELLIDO");
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
                    int indiceInicial = (paginaActual - 1) * cantidadPorPagina;
                    int indiceFinal = min(paginaActual * cantidadPorPagina, cantidadRegistros);
                    cout<<"Pagina " << paginaActual << " de " << totalPaginas;
                    interfaz.siguienteLinea();
                    interfaz.siguienteLinea();
                    cout << left << setw(14) << "DNI";
                    cout << left << setw(30) << "Nombre y Apellido";
                    cout << left << setw(15) << "Telefono";
                    cout << left << setw(25) << "e-mail";
                    interfaz.siguienteLinea();
                    for (int i = indiceInicial; i < indiceFinal; i++) {
                        if(vec[i].getEstado()){
                            cout << left << setw(14) << vec[i].getDni();
                            string n = vec[i].getNombre() + " " + vec[i].getApellido();
                            cout << left << setw(30) << n;
                            cout << left << setw(15) << vec[i].getTelefono();
                            cout << left << setw(25) << vec[i].getEmail();
                            interfaz.siguienteLinea();
                        }
                        else{
                            rlutil::setColor(ROJO);
                            cout << left << setw(14) << vec[i].getDni();
                            string n = vec[i].getNombre() + " " + vec[i].getApellido();
                            cout << left << setw(30) << n;
                            cout << left << setw(15) << vec[i].getTelefono();
                            cout << left << setw(25) << vec[i].getEmail();
                            interfaz.siguienteLinea();
                            rlutil::setColor(BLANCO);
                        }
                    }
                    interfaz.siguienteLinea();
                    cout << " [1] Anterior || [2] Siguiente || [0] Volver";
                    opc = interfaz.pedirOpcion();
                    switch (opc) {
                        case '1':
                            paginaActual = max(1, paginaActual - 1);
                            break;
                        case '2':
                            paginaActual = min(totalPaginas, paginaActual + 1);
                            break;
                    }
                }
            } while (opc != '0');
            delete []vec;
        }
        void Menu::listarClientesXNombre(){
            ClientesArchivo archivo;
            int cantidadRegistros = archivo.getCantidad();
            Cliente *vec = new Cliente[cantidadRegistros];
            Cliente clienteAux;
            if(vec==NULL) return;
            int cantidadPorPagina = 10;
            int totalPaginas = (cantidadRegistros + cantidadPorPagina - 1) / cantidadPorPagina;
            int paginaActual = 1;
            char opc;
            archivo.leerTodos(vec, cantidadRegistros);

            // Ordenamiento con método burbuja
            string cadena1, cadena2;
            if (cantidadRegistros>1){
                for (int i=0; i<cantidadRegistros; i++){
                    for (int j=0; j<cantidadRegistros - 1; j++){
                        cadena1 = vec[j].getNombre()+vec[j].getApellido();
                        cadena2 = vec[j+1].getNombre()+vec[j+1].getApellido();
                        if(cadena1 > cadena2){
                            clienteAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=clienteAux;
                        }
                    }
                }
            }

            do {
                system("cls");
                interfaz.dibujarMarco(CIAN);
                interfaz.setFilaActual(7);
                interfaz.cambiarTitulo("FIRULI 3000 - LISTADO DE CLIENTES POR NOMBRE");
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
                    int indiceInicial = (paginaActual - 1) * cantidadPorPagina;
                    int indiceFinal = min(paginaActual * cantidadPorPagina, cantidadRegistros);
                    cout<<"Pagina " << paginaActual << " de " << totalPaginas;
                    interfaz.siguienteLinea();
                    interfaz.siguienteLinea();
                    cout << left << setw(14) << "DNI";
                    cout << left << setw(30) << "Nombre y Apellido";
                    cout << left << setw(15) << "Telefono";
                    cout << left << setw(25) << "e-mail";
                    interfaz.siguienteLinea();
                    for (int i = indiceInicial; i < indiceFinal; i++) {
                        if(vec[i].getEstado()){
                            cout << left << setw(14) << vec[i].getDni();
                            string n = vec[i].getNombre() + " " + vec[i].getApellido();
                            cout << left << setw(30) << n;
                            cout << left << setw(15) << vec[i].getTelefono();
                            cout << left << setw(25) << vec[i].getEmail();
                            interfaz.siguienteLinea();
                        }
                        else{
                            rlutil::setColor(ROJO);
                            cout << left << setw(14) << vec[i].getDni();
                            string n = vec[i].getNombre() + " " + vec[i].getApellido();
                            cout << left << setw(30) << n;
                            cout << left << setw(15) << vec[i].getTelefono();
                            cout << left << setw(25) << vec[i].getEmail();
                            interfaz.siguienteLinea();
                            rlutil::setColor(BLANCO);
                        }
                    }
                    interfaz.siguienteLinea();
                    cout << " [1] Anterior || [2] Siguiente || [0] Volver";
                    opc = interfaz.pedirOpcion();
                    switch (opc) {
                        case '1':
                            paginaActual = max(1, paginaActual - 1);
                            break;
                        case '2':
                            paginaActual = min(totalPaginas, paginaActual + 1);
                            break;
                    }
                }
            } while (opc != '0');
            delete []vec;
        }
        void Menu::consultaClientePorDNI(){
            ClientesArchivo archivo;
            int cantidadRegistros = archivo.getCantidad();
            Cliente *vec = new Cliente[cantidadRegistros];
            if(vec==NULL) return;
            int _dni, pos_dni;
            char opc;

            do {
                system("cls");
                interfaz.dibujarMarco(CIAN);
                interfaz.setFilaActual(7);
                interfaz.cambiarTitulo("FIRULI 3000 - BUSCAR CLIENTE POR DNI");
                interfaz.siguienteLinea();
                if (cantidadRegistros==0){
                    rlutil::setColor(ROJO);
                    cout<<"Aun no se registraron clientes para consultar.";
                    interfaz.cambiarMensaje("Presione una tecla para continuar.",ROJO);
                    opc = '0';
                    rlutil::setColor(BLANCO);
                    rlutil::anykey();
                }
                else
                {
                    cout << "Ingrese el DNI a consultar: ";
                    cin >> _dni;
                    cin.ignore();
                    pos_dni = archivo.buscar(_dni);
                    interfaz.siguienteLinea();

                    if(archivo.buscar(_dni) == -1){
                        interfaz.siguienteLinea();
                        interfaz.siguienteLinea();
                        cout<<"El DNI ingresado no se encuentra registrado";
                        interfaz.siguienteLinea();
                    }
                    else{
                        interfaz.siguienteLinea();
                        interfaz.siguienteLinea();
                        cout<<"Nombre\t|\tApellido|\tTelefono|\tEmail";
                        interfaz.siguienteLinea();
                        if(archivo.leer(pos_dni).getEstado()){
                            cout<< archivo.leer(pos_dni).getNombre() << "\t|";
                            cout<< archivo.leer(pos_dni).getApellido()<< "\t|";
                            cout<< archivo.leer(pos_dni).getTelefono()<< "\t|";
                            cout<< archivo.leer(pos_dni).getEmail();
                            interfaz.siguienteLinea();
                        }
                    }
                }

                interfaz.siguienteLinea();
                cout << "[0] Volver";
                opc = interfaz.pedirOpcion();


            } while (opc != '0');
            delete []vec;
        }
        void Menu::consultaClientePorTEL(){
        // TODO: Mejora: comparar pasando todo a mayus para que encuentre incluso si se escribe en mayus/minus
            ClientesArchivo archivo;
            int cantidadRegistros = archivo.getCantidad();
            Cliente *vec = new Cliente[cantidadRegistros];
            if(vec==NULL) return;
            archivo.leerTodos(vec, cantidadRegistros);
            string _tel;
            int _cantCoincidencias = 0;
            char opc;

            do {
                system("cls");
                interfaz.dibujarMarco(CIAN);
                interfaz.setFilaActual(7);
                interfaz.cambiarTitulo("FIRULI 3000 - BUSCAR CLIENTE POR TELEFONO");
                interfaz.siguienteLinea();
                if (cantidadRegistros==0){
                    rlutil::setColor(ROJO);
                    cout<<"Aun no se registraron clientes para consultar.";
                    interfaz.cambiarMensaje("Presione una tecla para continuar.",ROJO);
                    opc = '0';
                    rlutil::setColor(BLANCO);
                    rlutil::anykey();
                }
                else
                {
                    cout << "Ingrese el TELEFONO a consultar: ";
                    getline(cin, _tel);
                    interfaz.siguienteLinea();
                    _cantCoincidencias = 0;
                    for(int i=0; i<cantidadRegistros; i++){
                        if(vec[i].getEstado() && vec[i].getTelefono() == _tel)
                            _cantCoincidencias++;
                    }
                    if(_cantCoincidencias == 0){
                        interfaz.siguienteLinea();
                        interfaz.siguienteLinea();
                        cout << "El TELEFONO ingresado no se encuentra registrado";
                        interfaz.siguienteLinea();
                    }
                    else{
                        interfaz.siguienteLinea();
                        interfaz.siguienteLinea();
                        cout << "Cantidad de coincidencias: " << _cantCoincidencias;
                        interfaz.siguienteLinea();
                        interfaz.siguienteLinea();
                        cout << left << setw(14) << "DNI";
                        cout << left << setw(30) << "Nombre y Apellido";
                        cout << left << setw(15) << "Telefono";
                        cout << left << setw(25) << "e-mail";
                        interfaz.siguienteLinea();
                        for(int i=0; i<cantidadRegistros; i++){
                            if(vec[i].getEstado() && vec[i].getTelefono() == _tel){
                                cout << left << setw(14) << vec[i].getDni();
                                string n = vec[i].getNombre() + " " + vec[i].getApellido();
                                cout << left << setw(30) << n;
                                cout << left << setw(15) << vec[i].getTelefono();
                                cout << left << setw(25) << vec[i].getEmail();
                                interfaz.siguienteLinea();
                            }
                        }
                        interfaz.siguienteLinea();
                    }
                }

                interfaz.siguienteLinea();
                cout << "[0] Volver";
                opc = interfaz.pedirOpcion();


            } while (opc != '0');
            delete []vec;
        }
        void Menu::consultaClientePorApellido(){
            ClientesArchivo archivo;
            int cantidadRegistros = archivo.getCantidad();
            Cliente *vec = new Cliente[cantidadRegistros];
            if(vec==NULL) return;
            archivo.leerTodos(vec, cantidadRegistros);
            string _apellido;
            int _cantCoincidencias = 0;
            char opc;

            do {
                system("cls");
                interfaz.dibujarMarco(CIAN);
                interfaz.setFilaActual(7);
                interfaz.cambiarTitulo("FIRULI 3000 - BUSCAR CLIENTE POR APELLIDO");
                interfaz.siguienteLinea();
                if (cantidadRegistros==0){
                    rlutil::setColor(ROJO);
                    cout<<"Aun no se registraron clientes para consultar.";
                    interfaz.cambiarMensaje("Presione una tecla para continuar.",ROJO);
                    opc = '0';
                    rlutil::setColor(BLANCO);
                    rlutil::anykey();
                }
                else
                {
                    cout << "Ingrese el APELLIDO a consultar: ";
                    getline(cin, _apellido);
                    interfaz.siguienteLinea();
                    _cantCoincidencias = 0;
                    for(int i=0; i<cantidadRegistros; i++){
                        if(vec[i].getEstado() && vec[i].getApellido() == _apellido)
                            _cantCoincidencias++;
                    }
                    if(_cantCoincidencias == 0){
                        interfaz.siguienteLinea();
                        interfaz.siguienteLinea();
                        cout << "El APELLIDO ingresado no se encuentra registrado";
                        interfaz.siguienteLinea();
                    }
                    else{
                        interfaz.siguienteLinea();
                        interfaz.siguienteLinea();
                        cout << "Cantidad de coincidencias: " << _cantCoincidencias;
                        interfaz.siguienteLinea();
                        interfaz.siguienteLinea();
                        cout << left << setw(14) << "DNI";
                        cout << left << setw(30) << "Nombre y Apellido";
                        cout << left << setw(15) << "Telefono";
                        cout << left << setw(25) << "e-mail";
                        interfaz.siguienteLinea();
                        for(int i=0; i<cantidadRegistros; i++){
                            if(vec[i].getEstado() && vec[i].getApellido() == _apellido){
                                cout << left << setw(14) << vec[i].getDni();
                                string n = vec[i].getNombre() + " " + vec[i].getApellido();
                                cout << left << setw(30) << n;
                                cout << left << setw(15) << vec[i].getTelefono();
                                cout << left << setw(25) << vec[i].getEmail();
                                interfaz.siguienteLinea();
                            }
                        }
                        interfaz.siguienteLinea();
                    }
                }

                interfaz.siguienteLinea();
                cout << "[0] Volver";
                opc = interfaz.pedirOpcion();


            } while (opc != '0');
            delete []vec;
        }
    void Menu::nuevaConsVenta(){
        char opc;
        do{
            system("cls");
            interfaz.setFilaActual(7);
            interfaz.dibujarMarco(CIAN);
            interfaz.cambiarTitulo("FIRULI 3000 - CONSULTAS VENTAS");
            interfaz.siguienteLinea();
            cout<<"[1] - Listado por fecha";
            interfaz.siguienteLinea();
            cout<<"[2] - Listado por empleado";
            interfaz.siguienteLinea();
            cout<<"[3] - Listado por categoria";
            interfaz.siguienteLinea();
            cout<<"[4] - Consultar por rango de fechas";
            interfaz.siguienteLinea();
            cout<<"[5] - Consultar por Cliente";
            interfaz.siguienteLinea();
            cout<<"[6] - Consultar por Servicio";
            interfaz.siguienteLinea();
            cout<<"[7] - Consultar por Empleado";
            interfaz.siguienteLinea();
            interfaz.siguienteLinea();
            cout<<"[0] - Volver";
            opc = interfaz.pedirOpcion();
            // Pregunta por la opcion elegida y se dirige a la funcion correspondiente
            switch(opc)
            {
                case '1':
                    listarVentasXFecha();
                    break;
                case '2':
                    listarVentasXEmpleado();
                    break;
                case '3':
                    listarVentasXCategoria();
                    break;
                case '4':
                    consultaVentasPorRangoF();
                    break;
                case '5':
                    consultaVentasPorCliente();
                    break;
                case '6':
                    consultaVentasPorServicio();
                    break;
                case '7':
                    consultaVentasPorEmpleado();
                    break;
            }
        }
        while(opc != '0');
    }
        void Menu::listarVentasXFecha(){
            // Cargo vector de ventas
            VentasArchivo ventasArchivo;
            int cantidadVentas = ventasArchivo.getCantidad();
            Venta *vec = new Venta[cantidadVentas];
            if(vec==NULL) return;
            ventasArchivo.leerTodos(vec, cantidadVentas);

            // Cargo vector de servicios
            ServiciosArchivo serviciosArchivo;
            Servicio *vecServicios = new Servicio[serviciosArchivo.getCantidad()];
            if(vecServicios==NULL) return;
            serviciosArchivo.leerTodos(vecServicios,serviciosArchivo.getCantidad());

            // Variables de la consulta
            Venta ventaAux;
            int cantidadPorPagina = 10;
            int totalPaginas = (cantidadVentas + cantidadPorPagina - 1) / cantidadPorPagina;
            int paginaActual = 1;
            char opc;

            // Ordenamiento con método burbuja (por año/mes/dia/empleado/servicio)
            if (cantidadVentas>1){
                for (int i=0; i<cantidadVentas; i++){
                    for (int j=0; j<cantidadVentas - 1; j++){
                        if(vec[j+1].getFecha().getAnio() < vec[j].getFecha().getAnio()){
                            ventaAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=ventaAux;
                        }
                        else if(vec[j+1].getFecha().getAnio() == vec[j].getFecha().getAnio()
                                && vec[j+1].getFecha().getMes() < vec[j].getFecha().getMes()){
                            ventaAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=ventaAux;
                        }
                        else if(vec[j+1].getFecha().getAnio() == vec[j].getFecha().getAnio()
                                && vec[j+1].getFecha().getMes() == vec[j].getFecha().getMes()
                                && vec[j+1].getFecha().getDia() < vec[j].getFecha().getDia()){
                            ventaAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=ventaAux;
                        }
                        else if(vec[j+1].getFecha().getAnio() == vec[j].getFecha().getAnio()
                                && vec[j+1].getFecha().getMes() == vec[j].getFecha().getMes()
                                && vec[j+1].getFecha().getDia() == vec[j].getFecha().getDia()
                                && vec[j+1].getEmpleado() < vec[j].getEmpleado()){
                            ventaAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=ventaAux;
                        }
                        else if(vec[j+1].getFecha().getAnio() == vec[j].getFecha().getAnio()
                                && vec[j+1].getFecha().getMes() == vec[j].getFecha().getMes()
                                && vec[j+1].getFecha().getDia() == vec[j].getFecha().getDia()
                                && vec[j+1].getEmpleado() == vec[j].getEmpleado()
                                && vec[j+1].getServicio() < vec[j].getServicio()){
                            ventaAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=ventaAux;
                        }
                    }
                }
            }

            do {
                system("cls");
                interfaz.dibujarMarco(CIAN);
                interfaz.setFilaActual(7);
                interfaz.cambiarTitulo("FIRULI 3000 - LISTADO DE VENTAS POR FECHA");
                interfaz.siguienteLinea();
                if (cantidadVentas==0){
                    rlutil::setColor(ROJO);
                    cout<<"No hay registros a listar.";
                    interfaz.cambiarMensaje("Presione una tecla para continuar.",ROJO);
                    opc = '0';
                    rlutil::setColor(BLANCO);
                    rlutil::anykey();
                }
                else{
                    int indiceInicial = (paginaActual - 1) * cantidadPorPagina;
                    int indiceFinal = min(paginaActual * cantidadPorPagina, cantidadVentas);
                    cout<<"Pagina " << paginaActual << " de " << totalPaginas;
                    interfaz.siguienteLinea();
                    interfaz.siguienteLinea();
                    cout << left << setw(14) << "Fecha";
                    cout << left << setw(15) << "DNI Empleado";
                    cout << left << setw(25) << "Servicio";
                    cout << left << setw(15) << "DNI Cliente";
                    cout << right << setw(15) << "Importe";
                    cout << left << setw(100) << "   Observacion";
                    interfaz.siguienteLinea();
                    for (int i = indiceInicial; i < indiceFinal; i++) {
                        if(vec[i].getEstado()){
                            cout << left << setw(14) << vec[i].getFecha().toString();
                            cout << left << setw(15) << vec[i].getEmpleado();
                            cout << left << setw(25) << to_string(vec[i].getServicio()) + "-" + vecServicios[vec[i].getServicio()-1].getNombre();
                            cout << left << setw(15) << vec[i].getCliente();
                            cout << right << setw(15) << to_string_decimales(vec[i].getImporte());
                            cout << left << setw(100) << "   " + vec[i].getObs();
                            interfaz.siguienteLinea();
                        }
                        else{
                            rlutil::setColor(ROJO);
                            cout << left << setw(14) << vec[i].getFecha().toString();
                            cout << left << setw(15) << vec[i].getEmpleado();
                            cout << left << setw(25) << to_string(vec[i].getServicio()) + "-" + vecServicios[vec[i].getServicio()-1].getNombre();
                            cout << left << setw(15) << vec[i].getCliente();
                            cout << right << setw(15) << to_string_decimales(vec[i].getImporte());
                            cout << left << setw(100) << "   " + vec[i].getObs();
                            interfaz.siguienteLinea();
                            rlutil::setColor(BLANCO);
                        }
                    }
                    interfaz.siguienteLinea();
                    cout << " [1] Anterior || [2] Siguiente || [0] Volver";
                    opc = interfaz.pedirOpcion();
                    switch (opc) {
                        case '1':
                            paginaActual = max(1, paginaActual - 1);
                            break;
                        case '2':
                            paginaActual = min(totalPaginas, paginaActual + 1);
                            break;
                    }
                }
            } while (opc != '0');
            delete []vec;
            delete []vecServicios;
        }
        void Menu::listarVentasXEmpleado(){
            // Cargo vector de ventas
            VentasArchivo ventasArchivo;
            int cantidadVentas = ventasArchivo.getCantidad();
            Venta *vec = new Venta[cantidadVentas];
            if(vec==NULL) return;
            ventasArchivo.leerTodos(vec, cantidadVentas);

            // Cargo vector de servicios
            ServiciosArchivo serviciosArchivo;
            Servicio *vecServicios = new Servicio[serviciosArchivo.getCantidad()];
            if(vecServicios==NULL) return;
            serviciosArchivo.leerTodos(vecServicios,serviciosArchivo.getCantidad());

            // Variables de la consulta
            Venta ventaAux;
            int cantidadPorPagina = 10;
            int totalPaginas = (cantidadVentas + cantidadPorPagina - 1) / cantidadPorPagina;
            int paginaActual = 1;
            char opc;

            // Ordenamiento con método burbuja (por empleado/año/mes/dia)
            if (cantidadVentas>1){
                for (int i=0; i<cantidadVentas; i++){
                    for (int j=0; j<cantidadVentas - 1; j++){
                        if(vec[j+1].getEmpleado() < vec[j].getEmpleado()){
                            ventaAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=ventaAux;
                        }
                        else if(vec[j+1].getEmpleado() == vec[j].getEmpleado()
                                && vec[j+1].getFecha().getAnio() < vec[j].getFecha().getAnio()){
                            ventaAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=ventaAux;
                        }
                        else if(vec[j+1].getEmpleado() == vec[j].getEmpleado()
                                && vec[j+1].getFecha().getAnio() == vec[j].getFecha().getAnio()
                                && vec[j+1].getFecha().getMes() < vec[j].getFecha().getMes()){
                            ventaAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=ventaAux;
                        }
                        else if(vec[j+1].getEmpleado() == vec[j].getEmpleado()
                                && vec[j+1].getFecha().getAnio() == vec[j].getFecha().getAnio()
                                && vec[j+1].getFecha().getMes() == vec[j].getFecha().getMes()
                                && vec[j+1].getFecha().getDia() < vec[j].getFecha().getDia()){
                            ventaAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=ventaAux;
                        }
                    }
                }
            }

            do {
                system("cls");
                interfaz.dibujarMarco(CIAN);
                interfaz.setFilaActual(7);
                interfaz.cambiarTitulo("FIRULI 3000 - LISTADO DE VENTAS POR EMPLEADO");
                interfaz.siguienteLinea();
                if (cantidadVentas==0){
                    rlutil::setColor(ROJO);
                    cout<<"No hay registros a listar.";
                    interfaz.cambiarMensaje("Presione una tecla para continuar.",ROJO);
                    opc = '0';
                    rlutil::setColor(BLANCO);
                    rlutil::anykey();
                }
                else{
                    int indiceInicial = (paginaActual - 1) * cantidadPorPagina;
                    int indiceFinal = min(paginaActual * cantidadPorPagina, cantidadVentas);
                    cout<<"Pagina " << paginaActual << " de " << totalPaginas;
                    interfaz.siguienteLinea();
                    interfaz.siguienteLinea();
                    cout << left << setw(14) << "Fecha";
                    cout << left << setw(15) << "DNI Empleado";
                    cout << left << setw(25) << "Servicio";
                    cout << left << setw(15) << "DNI Cliente";
                    cout << right << setw(15) << "Importe";
                    cout << left << setw(100) << "   Observacion";
                    interfaz.siguienteLinea();
                    for (int i = indiceInicial; i < indiceFinal; i++) {
                        if(vec[i].getEstado()){
                            cout << left << setw(14) << vec[i].getFecha().toString();
                            cout << left << setw(15) << vec[i].getEmpleado();
                            cout << left << setw(25) << to_string(vec[i].getServicio()) + "-" + vecServicios[vec[i].getServicio()-1].getNombre();
                            cout << left << setw(15) << vec[i].getCliente();
                            cout << right << setw(15) << to_string_decimales(vec[i].getImporte());
                            cout << left << setw(100) << "   " + vec[i].getObs();
                            interfaz.siguienteLinea();
                        }
                        else{
                            rlutil::setColor(ROJO);
                            cout << left << setw(14) << vec[i].getFecha().toString();
                            cout << left << setw(15) << vec[i].getEmpleado();
                            cout << left << setw(25) << to_string(vec[i].getServicio()) + "-" + vecServicios[vec[i].getServicio()-1].getNombre();
                            cout << left << setw(15) << vec[i].getCliente();
                            cout << right << setw(15) << to_string_decimales(vec[i].getImporte());
                            cout << left << setw(100) << "   " + vec[i].getObs();
                            interfaz.siguienteLinea();
                            rlutil::setColor(BLANCO);
                        }
                    }
                    interfaz.siguienteLinea();
                    cout << " [1] Anterior || [2] Siguiente || [0] Volver";
                    opc = interfaz.pedirOpcion();
                    switch (opc) {
                        case '1':
                            paginaActual = max(1, paginaActual - 1);
                            break;
                        case '2':
                            paginaActual = min(totalPaginas, paginaActual + 1);
                            break;
                    }
                }
            } while (opc != '0');
            delete []vec;
            delete []vecServicios;
        }
        void Menu::listarVentasXCategoria(){
            // Cargo vector de ventas
            VentasArchivo ventasArchivo;
            int cantidadVentas = ventasArchivo.getCantidad();
            Venta *vec = new Venta[cantidadVentas];
            if(vec==NULL) return;
            ventasArchivo.leerTodos(vec, cantidadVentas);

            // Cargo vector de servicios
            ServiciosArchivo serviciosArchivo;
            Servicio *vecServicios = new Servicio[serviciosArchivo.getCantidad()];
            if(vecServicios==NULL) return;
            serviciosArchivo.leerTodos(vecServicios,serviciosArchivo.getCantidad());

            // Cargo vector de categorias
            CategoriasArchivo categoriasArchivo;
            Categoria *vecCategorias = new Categoria[categoriasArchivo.getCantidad()];;
            if(vecCategorias==NULL) return;
            categoriasArchivo.leerTodos(vecCategorias,categoriasArchivo.getCantidad());

            // Variables de la consulta
            Venta ventaAux;
            Servicio servicioSiguiente, servicioActual;
            int cantidadPorPagina = 10;
            int totalPaginas = (cantidadVentas + cantidadPorPagina - 1) / cantidadPorPagina;
            int paginaActual = 1;
            char opc;

            // Ordenamiento con método burbuja (por categoria/empleado/año/mes/dia)
            if (cantidadVentas>1){
                for (int i=0; i<cantidadVentas; i++){
                    for (int j=0; j<cantidadVentas - 1; j++){

                        // con el id_servicio busco el indice y con el indice traigo el servicio
                        servicioActual = vecServicios[vec[j].getServicio()-1];
                        servicioSiguiente = vecServicios[vec[j+1].getServicio()-1];

                        if(servicioSiguiente.getCodCategoria() < servicioActual.getCodCategoria()){
                            ventaAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=ventaAux;
                        }
                        else if(servicioSiguiente.getCodCategoria() == servicioActual.getCodCategoria()
                                && vec[j+1].getEmpleado() < vec[j].getEmpleado()){
                            ventaAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=ventaAux;
                        }
                        else if(servicioSiguiente.getCodCategoria() == servicioActual.getCodCategoria()
                                && vec[j+1].getEmpleado() == vec[j].getEmpleado()
                                && vec[j+1].getFecha().getAnio() < vec[j].getFecha().getAnio()){
                            ventaAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=ventaAux;
                        }
                        else if(servicioSiguiente.getCodCategoria() == servicioActual.getCodCategoria()
                                && vec[j+1].getEmpleado() == vec[j].getEmpleado()
                                && vec[j+1].getFecha().getAnio() == vec[j].getFecha().getAnio()
                                && vec[j+1].getFecha().getMes() < vec[j].getFecha().getMes()){
                            ventaAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=ventaAux;
                        }
                        else if(servicioSiguiente.getCodCategoria() == servicioActual.getCodCategoria()
                                && vec[j+1].getEmpleado() == vec[j].getEmpleado()
                                && vec[j+1].getFecha().getAnio() == vec[j].getFecha().getAnio()
                                && vec[j+1].getFecha().getMes() == vec[j].getFecha().getMes()
                                && vec[j+1].getFecha().getDia() < vec[j].getFecha().getDia()){
                            ventaAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=ventaAux;
                        }
                    }
                }
            }

            do {
                system("cls");
                interfaz.dibujarMarco(CIAN);
                interfaz.setFilaActual(7);
                interfaz.cambiarTitulo("FIRULI 3000 - LISTADO DE VENTAS POR CATEGORIA");
                interfaz.siguienteLinea();
                if (cantidadVentas==0){
                    rlutil::setColor(ROJO);
                    cout<<"No hay registros a listar.";
                    interfaz.cambiarMensaje("Presione una tecla para continuar.",ROJO);
                    opc = '0';
                    rlutil::setColor(BLANCO);
                    rlutil::anykey();
                }
                else{
                    int indiceInicial = (paginaActual - 1) * cantidadPorPagina;
                    int indiceFinal = min(paginaActual * cantidadPorPagina, cantidadVentas);
                    cout<<"Pagina " << paginaActual << " de " << totalPaginas;
                    interfaz.siguienteLinea();
                    interfaz.siguienteLinea();
                    cout << left << setw(14) << "Fecha";
                    cout << left << setw(20) << "Categoria";
                    cout << left << setw(15) << "DNI Empleado";
                    cout << left << setw(25) << "Servicio";
                    cout << left << setw(15) << "DNI Cliente";
                    cout << right << setw(15) << "Importe";
                    cout << left << setw(100) << "   Observacion";
                    interfaz.siguienteLinea();
                    for (int i = indiceInicial; i < indiceFinal; i++) {

                        if(vec[i].getEstado()){
                            cout << left << setw(14) << vec[i].getFecha().toString();
                            cout << left << setw(20) << to_string(vecServicios[vec[i].getServicio()-1].getCodCategoria()) + "-" + vecCategorias[vecServicios[vec[i].getServicio()-1].getCodCategoria()-1].getNombre();
                            cout << left << setw(15) << vec[i].getEmpleado();
                            cout << left << setw(25) << to_string(vec[i].getServicio()) + "-" + vecServicios[vec[i].getServicio()-1].getNombre();
                            cout << left << setw(15) << vec[i].getCliente();
                            cout << right << setw(15) << to_string_decimales(vec[i].getImporte());
                            cout << left << setw(100) << "   " + vec[i].getObs();
                            interfaz.siguienteLinea();
                        }
                        else{
                            rlutil::setColor(ROJO);
                            cout << left << setw(14) << vec[i].getFecha().toString();
                            cout << left << setw(20) << to_string(vecServicios[vec[i].getServicio()-1].getCodCategoria()) + "-" + vecCategorias[vecServicios[vec[i].getServicio()-1].getCodCategoria()-1].getNombre();
                            cout << left << setw(15) << vec[i].getEmpleado();
                            cout << left << setw(25) << to_string(vec[i].getServicio()) + "-" + vecServicios[vec[i].getServicio()-1].getNombre();
                            cout << left << setw(15) << vec[i].getCliente();
                            cout << right << setw(15) << to_string_decimales(vec[i].getImporte());
                            cout << left << setw(100) << "   " + vec[i].getObs();
                            interfaz.siguienteLinea();
                            rlutil::setColor(BLANCO);
                        }
                    }
                    interfaz.siguienteLinea();
                    cout << " [1] Anterior || [2] Siguiente || [0] Volver";
                    opc = interfaz.pedirOpcion();
                    switch (opc) {
                        case '1':
                            paginaActual = max(1, paginaActual - 1);
                            break;
                        case '2':
                            paginaActual = min(totalPaginas, paginaActual + 1);
                            break;
                    }
                }
            } while (opc != '0');
            delete []vec;
            delete []vecServicios;
            delete []vecCategorias;
        }
        void Menu::consultaVentasPorRangoF(){
            // Cargo vector de ventas
            VentasArchivo ventasArchivo;
            int cantidadVentas = ventasArchivo.getCantidad();
            Venta *vec = new Venta[cantidadVentas];
            if(vec==NULL) return;
            ventasArchivo.leerTodos(vec, cantidadVentas);

            // Cargo vector de servicios
            ServiciosArchivo serviciosArchivo;
            Servicio *vecServicios = new Servicio[serviciosArchivo.getCantidad()];
            if(vecServicios==NULL) return;
            serviciosArchivo.leerTodos(vecServicios,serviciosArchivo.getCantidad());

            // Variables de la consulta
            Venta ventaAux;
            char opc;
            Fecha fechaDesde, fechaHasta;
            int _cantCoincidencias = 0;

            // Ordenamiento con método burbuja (por año/mes/dia/empleado/servicio)
            if (cantidadVentas>1){
                for (int i=0; i<cantidadVentas; i++){
                    for (int j=0; j<cantidadVentas - 1; j++){
                        if(vec[j+1].getFecha().getAnio() < vec[j].getFecha().getAnio()){
                            ventaAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=ventaAux;
                        }
                        else if(vec[j+1].getFecha().getAnio() == vec[j].getFecha().getAnio()
                                && vec[j+1].getFecha().getMes() < vec[j].getFecha().getMes()){
                            ventaAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=ventaAux;
                        }
                        else if(vec[j+1].getFecha().getAnio() == vec[j].getFecha().getAnio()
                                && vec[j+1].getFecha().getMes() == vec[j].getFecha().getMes()
                                && vec[j+1].getFecha().getDia() < vec[j].getFecha().getDia()){
                            ventaAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=ventaAux;
                        }
                        else if(vec[j+1].getFecha().getAnio() == vec[j].getFecha().getAnio()
                                && vec[j+1].getFecha().getMes() == vec[j].getFecha().getMes()
                                && vec[j+1].getFecha().getDia() == vec[j].getFecha().getDia()
                                && vec[j+1].getEmpleado() < vec[j].getEmpleado()){
                            ventaAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=ventaAux;
                        }
                        else if(vec[j+1].getFecha().getAnio() == vec[j].getFecha().getAnio()
                                && vec[j+1].getFecha().getMes() == vec[j].getFecha().getMes()
                                && vec[j+1].getFecha().getDia() == vec[j].getFecha().getDia()
                                && vec[j+1].getEmpleado() == vec[j].getEmpleado()
                                && vec[j+1].getServicio() < vec[j].getServicio()){
                            ventaAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=ventaAux;
                        }
                    }
                }
            }

            do {
                system("cls");
                interfaz.dibujarMarco(CIAN);
                interfaz.setFilaActual(7);
                interfaz.cambiarTitulo("FIRULI 3000 - CONSULTA DE VENTAS POR RANGO DE FECHAS");
                interfaz.siguienteLinea();
                if (cantidadVentas==0){
                    rlutil::setColor(ROJO);
                    cout<<"Aun no se registraron ventas para consultar.";
                    interfaz.cambiarMensaje("Presione una tecla para continuar.",ROJO);
                    opc = '0';
                    rlutil::setColor(BLANCO);
                    rlutil::anykey();
                }
                else
                {
                    cout << "Ingrese la fecha DESDE a consultar: ";
                    fechaDesde = cargarFecha(interfaz);
                    interfaz.siguienteLinea();
                    cout << "Ingrese la fecha HASTA a consultar: ";
                    fechaHasta = cargarFecha(interfaz);
                    interfaz.siguienteLinea();
                    _cantCoincidencias = 0;
                    for(int i=0; i<cantidadVentas; i++){
                        if(vec[i].getEstado()
                        && vec[i].getFecha().esMayorOIgual(fechaDesde)
                        && vec[i].getFecha().esMenorOIgual(fechaHasta)){
                            _cantCoincidencias++;
                        }
                    }
                    if(_cantCoincidencias == 0){
                        interfaz.siguienteLinea();
                        interfaz.siguienteLinea();
                        cout << "No existen ventas en el rango de fechas ingresado";
                        interfaz.siguienteLinea();
                    }
                    else{
                        interfaz.siguienteLinea();
                        interfaz.siguienteLinea();
                        cout << "Cantidad de coincidencias: " << _cantCoincidencias;
                        interfaz.siguienteLinea();
                        interfaz.siguienteLinea();
                        cout << left << setw(14) << "Fecha";
                        cout << left << setw(15) << "DNI Empleado";
                        cout << left << setw(25) << "Servicio";
                        cout << left << setw(15) << "DNI Cliente";
                        cout << right << setw(15) << "Importe";
                        cout << left << setw(100) << "   Observacion";
                        interfaz.siguienteLinea();
                        for(int i=0; i<cantidadVentas; i++){
                            if(vec[i].getEstado()
                            && vec[i].getFecha().esMayorOIgual(fechaDesde)
                            && vec[i].getFecha().esMenorOIgual(fechaHasta)){
                                cout << left << setw(14) << vec[i].getFecha().toString();
                                cout << left << setw(15) << vec[i].getEmpleado();
                                cout << left << setw(25) << to_string(vec[i].getServicio()) + "-" + vecServicios[vec[i].getServicio()-1].getNombre();
                                cout << left << setw(15) << vec[i].getCliente();
                                cout << right << setw(15) << to_string_decimales(vec[i].getImporte());
                                cout << left << setw(100) << "   " + vec[i].getObs();
                                interfaz.siguienteLinea();
                            }
                        }
                        interfaz.siguienteLinea();
                    }
                }

                interfaz.siguienteLinea();
                cout << "[0] Volver";
                opc = interfaz.pedirOpcion();

            } while (opc != '0');
            delete []vec;
            delete []vecServicios;
        }
        void Menu::consultaVentasPorCliente(){
            // Cargo vector de ventas
            VentasArchivo ventasArchivo;
            int cantidadVentas = ventasArchivo.getCantidad();
            Venta *vec = new Venta[cantidadVentas];
            if(vec==NULL) return;
            ventasArchivo.leerTodos(vec, cantidadVentas);

            // Cargo vector de servicios
            ServiciosArchivo serviciosArchivo;
            Servicio *vecServicios = new Servicio[serviciosArchivo.getCantidad()];
            if(vecServicios==NULL) return;
            serviciosArchivo.leerTodos(vecServicios,serviciosArchivo.getCantidad());

            // Variables de la consulta
            Venta ventaAux;
            char opc;
            int _cantCoincidencias = 0;
            ClientesArchivo clientesArchivo;
            int _dni, pos_dni;

            // Ordenamiento con método burbuja (por año/mes/dia/empleado/servicio)
            if (cantidadVentas>1){
                for (int i=0; i<cantidadVentas; i++){
                    for (int j=0; j<cantidadVentas - 1; j++){
                        if(vec[j+1].getFecha().getAnio() < vec[j].getFecha().getAnio()){
                            ventaAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=ventaAux;
                        }
                        else if(vec[j+1].getFecha().getAnio() == vec[j].getFecha().getAnio()
                                && vec[j+1].getFecha().getMes() < vec[j].getFecha().getMes()){
                            ventaAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=ventaAux;
                        }
                        else if(vec[j+1].getFecha().getAnio() == vec[j].getFecha().getAnio()
                                && vec[j+1].getFecha().getMes() == vec[j].getFecha().getMes()
                                && vec[j+1].getFecha().getDia() < vec[j].getFecha().getDia()){
                            ventaAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=ventaAux;
                        }
                        else if(vec[j+1].getFecha().getAnio() == vec[j].getFecha().getAnio()
                                && vec[j+1].getFecha().getMes() == vec[j].getFecha().getMes()
                                && vec[j+1].getFecha().getDia() == vec[j].getFecha().getDia()
                                && vec[j+1].getEmpleado() < vec[j].getEmpleado()){
                            ventaAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=ventaAux;
                        }
                        else if(vec[j+1].getFecha().getAnio() == vec[j].getFecha().getAnio()
                                && vec[j+1].getFecha().getMes() == vec[j].getFecha().getMes()
                                && vec[j+1].getFecha().getDia() == vec[j].getFecha().getDia()
                                && vec[j+1].getEmpleado() == vec[j].getEmpleado()
                                && vec[j+1].getServicio() < vec[j].getServicio()){
                            ventaAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=ventaAux;
                        }
                    }
                }
            }

            do {
                system("cls");
                interfaz.dibujarMarco(CIAN);
                interfaz.setFilaActual(7);
                interfaz.cambiarTitulo("FIRULI 3000 - CONSULTA DE VENTAS POR CLIENTE");
                interfaz.siguienteLinea();
                if (cantidadVentas==0){
                    rlutil::setColor(ROJO);
                    cout<<"Aun no se registraron ventas para consultar.";
                    interfaz.cambiarMensaje("Presione una tecla para continuar.",ROJO);
                    opc = '0';
                    rlutil::setColor(BLANCO);
                    rlutil::anykey();
                }
                else
                {
                    cout << "Ingrese el DNI a consultar: ";
                    cin >> _dni;
                    cin.ignore();
                    pos_dni = clientesArchivo.buscar(_dni);
                    interfaz.siguienteLinea();

                    if(pos_dni == -1){
                        interfaz.siguienteLinea();
                        interfaz.siguienteLinea();
                        cout<<"El DNI ingresado no se encuentra registrado";
                        interfaz.siguienteLinea();
                    }
                    else{

                        _cantCoincidencias = 0;
                        for(int i=0; i<cantidadVentas; i++){
                            if(vec[i].getEstado()
                            && vec[i].getCliente() == _dni)
                                _cantCoincidencias++;
                        }
                        if(_cantCoincidencias == 0){
                            interfaz.siguienteLinea();
                            interfaz.siguienteLinea();
                            cout << "No existen ventas para el cliente ingresado.";
                            interfaz.siguienteLinea();
                        }
                        else{
                            interfaz.siguienteLinea();
                            interfaz.siguienteLinea();
                            cout << "Cantidad de coincidencias: " << _cantCoincidencias;
                            interfaz.siguienteLinea();
                            interfaz.siguienteLinea();
                            cout << left << setw(14) << "Fecha";
                            cout << left << setw(15) << "DNI Empleado";
                            cout << left << setw(25) << "Servicio";
                            cout << left << setw(15) << "DNI Cliente";
                            cout << right << setw(15) << "Importe";
                            cout << left << setw(100) << "   Observacion";
                            interfaz.siguienteLinea();
                            for(int i=0; i<cantidadVentas; i++){
                                if(vec[i].getEstado()
                                && vec[i].getCliente() == _dni){
                                    cout << left << setw(14) << vec[i].getFecha().toString();
                                    cout << left << setw(15) << vec[i].getEmpleado();
                                    cout << left << setw(25) << to_string(vec[i].getServicio()) + "-" + vecServicios[vec[i].getServicio()-1].getNombre();
                                    cout << left << setw(15) << vec[i].getCliente();
                                    cout << right << setw(15) << to_string_decimales(vec[i].getImporte());
                                    cout << left << setw(100) << "   " + vec[i].getObs();
                                    interfaz.siguienteLinea();
                                }
                            }
                            interfaz.siguienteLinea();
                        }
                    }
                }

                interfaz.siguienteLinea();
                cout << "[0] Volver";
                opc = interfaz.pedirOpcion();

            } while (opc != '0');
            delete []vec;
            delete []vecServicios;
        }
        void Menu::consultaVentasPorServicio(){
            // Cargo vector de ventas
            VentasArchivo ventasArchivo;
            int cantidadVentas = ventasArchivo.getCantidad();
            Venta *vec = new Venta[cantidadVentas];
            if(vec==NULL) return;
            ventasArchivo.leerTodos(vec, cantidadVentas);

            // Cargo vector de servicios
            ServiciosArchivo serviciosArchivo;
            Servicio *vecServicios = new Servicio[serviciosArchivo.getCantidad()];
            if(vecServicios==NULL) return;
            serviciosArchivo.leerTodos(vecServicios,serviciosArchivo.getCantidad());

            // Variables de la consulta
            Venta ventaAux;
            char opc;
            int _cantCoincidencias = 0;
            int _idServicio, pos_servicio;

            // Ordenamiento con método burbuja (por año/mes/dia/empleado)
            if (cantidadVentas>1){
                for (int i=0; i<cantidadVentas; i++){
                    for (int j=0; j<cantidadVentas - 1; j++){
                        if(vec[j+1].getFecha().getAnio() < vec[j].getFecha().getAnio()){
                            ventaAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=ventaAux;
                        }
                        else if(vec[j+1].getFecha().getAnio() == vec[j].getFecha().getAnio()
                                && vec[j+1].getFecha().getMes() < vec[j].getFecha().getMes()){
                            ventaAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=ventaAux;
                        }
                        else if(vec[j+1].getFecha().getAnio() == vec[j].getFecha().getAnio()
                                && vec[j+1].getFecha().getMes() == vec[j].getFecha().getMes()
                                && vec[j+1].getFecha().getDia() < vec[j].getFecha().getDia()){
                            ventaAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=ventaAux;
                        }
                        else if(vec[j+1].getFecha().getAnio() == vec[j].getFecha().getAnio()
                                && vec[j+1].getFecha().getMes() == vec[j].getFecha().getMes()
                                && vec[j+1].getFecha().getDia() == vec[j].getFecha().getDia()
                                && vec[j+1].getEmpleado() < vec[j].getEmpleado()){
                            ventaAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=ventaAux;
                        }
                    }
                }
            }

            do {
                system("cls");
                interfaz.dibujarMarco(CIAN);
                interfaz.setFilaActual(7);
                interfaz.cambiarTitulo("FIRULI 3000 - CONSULTA DE VENTAS POR SERVICIO");
                interfaz.siguienteLinea();
                if (cantidadVentas==0){
                    rlutil::setColor(ROJO);
                    cout<<"Aun no se registraron ventas para consultar.";
                    interfaz.cambiarMensaje("Presione una tecla para continuar.",ROJO);
                    opc = '0';
                    rlutil::setColor(BLANCO);
                    rlutil::anykey();
                }
                else
                {
                    cout << "Ingrese el Id del servicio a consultar: ";
                    cin >> _idServicio;
                    cin.ignore();
                    pos_servicio = serviciosArchivo.buscar(_idServicio);
                    interfaz.siguienteLinea();

                    if(pos_servicio == -1){
                        interfaz.siguienteLinea();
                        interfaz.siguienteLinea();
                        cout<<"El id ingresado es inexistente.";
                        interfaz.siguienteLinea();
                    }
                    else{

                        _cantCoincidencias = 0;
                        for(int i=0; i<cantidadVentas; i++){
                            if(vec[i].getEstado()
                            && vec[i].getServicio() == _idServicio)
                                _cantCoincidencias++;
                        }
                        if(_cantCoincidencias == 0){
                            interfaz.siguienteLinea();
                            interfaz.siguienteLinea();
                            cout << "No existen ventas para el servicio ingresado.";
                            interfaz.siguienteLinea();
                        }
                        else{
                            interfaz.siguienteLinea();
                            interfaz.siguienteLinea();
                            cout << "Cantidad de coincidencias: " << _cantCoincidencias;
                            interfaz.siguienteLinea();
                            interfaz.siguienteLinea();
                            cout << left << setw(14) << "Fecha";
                            cout << left << setw(15) << "DNI Empleado";
                            cout << left << setw(25) << "Servicio";
                            cout << left << setw(15) << "DNI Cliente";
                            cout << right << setw(15) << "Importe";
                            cout << left << setw(100) << "   Observacion";
                            interfaz.siguienteLinea();
                            for(int i=0; i<cantidadVentas; i++){
                                if(vec[i].getEstado()
                                && vec[i].getServicio() == _idServicio){
                                    cout << left << setw(14) << vec[i].getFecha().toString();
                                    cout << left << setw(15) << vec[i].getEmpleado();
                                    cout << left << setw(25) << to_string(vec[i].getServicio()) + "-" + vecServicios[vec[i].getServicio()-1].getNombre();
                                    cout << left << setw(15) << vec[i].getCliente();
                                    cout << right << setw(15) << to_string_decimales(vec[i].getImporte());
                                    cout << left << setw(100) << "   " + vec[i].getObs();
                                    interfaz.siguienteLinea();
                                }
                            }
                            interfaz.siguienteLinea();
                        }
                    }
                }

                interfaz.siguienteLinea();
                cout << "[0] Volver";
                opc = interfaz.pedirOpcion();

            } while (opc != '0');
            delete []vec;
            delete []vecServicios;
        }
        void Menu::consultaVentasPorEmpleado(){
            // Cargo vector de ventas
            VentasArchivo ventasArchivo;
            int cantidadVentas = ventasArchivo.getCantidad();
            Venta *vec = new Venta[cantidadVentas];
            if(vec==NULL) return;
            ventasArchivo.leerTodos(vec, cantidadVentas);

            // Cargo vector de servicios
            ServiciosArchivo serviciosArchivo;
            Servicio *vecServicios = new Servicio[serviciosArchivo.getCantidad()];
            if(vecServicios==NULL) return;
            serviciosArchivo.leerTodos(vecServicios,serviciosArchivo.getCantidad());

            // Variables de la consulta
            Venta ventaAux;
            EmpleadosArchivo empleadosArchivo;
            char opc;
            int _cantCoincidencias = 0;
            int _dniEmpleado, pos_empleado;

            // Ordenamiento con método burbuja (por año/mes/dia/servicio)
            if (cantidadVentas>1){
                for (int i=0; i<cantidadVentas; i++){
                    for (int j=0; j<cantidadVentas - 1; j++){
                        if(vec[j+1].getFecha().getAnio() < vec[j].getFecha().getAnio()){
                            ventaAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=ventaAux;
                        }
                        else if(vec[j+1].getFecha().getAnio() == vec[j].getFecha().getAnio()
                                && vec[j+1].getFecha().getMes() < vec[j].getFecha().getMes()){
                            ventaAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=ventaAux;
                        }
                        else if(vec[j+1].getFecha().getAnio() == vec[j].getFecha().getAnio()
                                && vec[j+1].getFecha().getMes() == vec[j].getFecha().getMes()
                                && vec[j+1].getFecha().getDia() < vec[j].getFecha().getDia()){
                            ventaAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=ventaAux;
                        }
                        else if(vec[j+1].getFecha().getAnio() == vec[j].getFecha().getAnio()
                                && vec[j+1].getFecha().getMes() == vec[j].getFecha().getMes()
                                && vec[j+1].getFecha().getDia() == vec[j].getFecha().getDia()
                                && vec[j+1].getServicio() < vec[j].getServicio()){
                            ventaAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=ventaAux;
                        }
                    }
                }
            }

            do {
                system("cls");
                interfaz.dibujarMarco(CIAN);
                interfaz.setFilaActual(7);
                interfaz.cambiarTitulo("FIRULI 3000 - CONSULTA DE VENTAS POR EMPLEADO");
                interfaz.siguienteLinea();
                if (cantidadVentas==0){
                    rlutil::setColor(ROJO);
                    cout<<"Aun no se registraron ventas para consultar.";
                    interfaz.cambiarMensaje("Presione una tecla para continuar.",ROJO);
                    opc = '0';
                    rlutil::setColor(BLANCO);
                    rlutil::anykey();
                }
                else
                {
                    cout << "Ingrese el DNI del empleado a consultar: ";
                    cin >> _dniEmpleado;
                    cin.ignore();
                    pos_empleado = empleadosArchivo.buscar(_dniEmpleado);
                    interfaz.siguienteLinea();

                    if(pos_empleado == -1){
                        interfaz.siguienteLinea();
                        interfaz.siguienteLinea();
                        cout<<"El empleado ingresado es inexistente.";
                        interfaz.siguienteLinea();
                    }
                    else{

                        _cantCoincidencias = 0;
                        for(int i=0; i<cantidadVentas; i++){
                            if(vec[i].getEstado()
                            && vec[i].getEmpleado() == _dniEmpleado)
                                _cantCoincidencias++;
                        }
                        if(_cantCoincidencias == 0){
                            interfaz.siguienteLinea();
                            interfaz.siguienteLinea();
                            cout << "No existen ventas para el empleado ingresado.";
                            interfaz.siguienteLinea();
                        }
                        else{
                            interfaz.siguienteLinea();
                            interfaz.siguienteLinea();
                            cout << "Cantidad de coincidencias: " << _cantCoincidencias;
                            interfaz.siguienteLinea();
                            interfaz.siguienteLinea();
                            cout << left << setw(14) << "Fecha";
                            cout << left << setw(15) << "DNI Empleado";
                            cout << left << setw(25) << "Servicio";
                            cout << left << setw(15) << "DNI Cliente";
                            cout << right << setw(15) << "Importe";
                            cout << left << setw(100) << "   Observacion";
                            interfaz.siguienteLinea();
                            for(int i=0; i<cantidadVentas; i++){
                                if(vec[i].getEstado()
                                && vec[i].getEmpleado() == _dniEmpleado){
                                    cout << left << setw(14) << vec[i].getFecha().toString();
                                    cout << left << setw(15) << vec[i].getEmpleado();
                                    cout << left << setw(25) << to_string(vec[i].getServicio()) + "-" + vecServicios[vec[i].getServicio()-1].getNombre();
                                    cout << left << setw(15) << vec[i].getCliente();
                                    cout << right << setw(15) << to_string_decimales(vec[i].getImporte());
                                    cout << left << setw(100) << "   " + vec[i].getObs();
                                    interfaz.siguienteLinea();
                                }
                            }
                            interfaz.siguienteLinea();
                        }
                    }
                }

                interfaz.siguienteLinea();
                cout << "[0] Volver";
                opc = interfaz.pedirOpcion();

            } while (opc != '0');
            delete []vec;
            delete []vecServicios;
        }
    void Menu::nuevaConsServicio(){
        char opc;
        do{
            system("cls");
            interfaz.setFilaActual(7);
            interfaz.dibujarMarco(CIAN);
            interfaz.cambiarTitulo("FIRULI 3000 - CONSULTAS SERVICIOS");
            interfaz.siguienteLinea();
            cout<<"[1] - Listado ordenado por categoria";
            interfaz.siguienteLinea();
            cout<<"[2] - Consultar por ID de categoria";
            interfaz.siguienteLinea();
            cout<<"[3] - Consultar por nombre del servicio";
            interfaz.siguienteLinea();
            cout<<"[4] - Consultar por codigo";
            interfaz.siguienteLinea();
            interfaz.siguienteLinea();
            cout<<"[0] - Volver";
            opc = interfaz.pedirOpcion();
            // Pregunta por la opcion elegida y se dirige a la funcion correspondiente
            switch(opc)
            {
                case '1':
                    listarServiciosXCategoria();
                    break;
                case '2':
                    consultaServiciosPorCategoria();
                    break;
                case '3':
                    consultaServiciosPorNombre();
                    break;
                case '4':
                    consultaServiciosPorCodigo();
                    break;
            }
        }
        while(opc != '0');
    }
        void Menu::listarServiciosXCategoria(){
            // Cargo vector de servicios
            ServiciosArchivo serviciosArchivo;
            int cantidadServicios = serviciosArchivo.getCantidad();
            Servicio *vec = new Servicio[cantidadServicios];
            if(vec==NULL) return;
            serviciosArchivo.leerTodos(vec,cantidadServicios);

            // Cargo vector de categorias
            CategoriasArchivo categoriasArchivo;
            int cantidadCategorias = categoriasArchivo.getCantidad();
            Categoria *vecCategorias = new Categoria[cantidadCategorias];
            if(vecCategorias==NULL) return;
            categoriasArchivo.leerTodos(vecCategorias,cantidadCategorias);

            // Variables de la consulta
            Servicio servicioAux;
            int cantidadPorPagina = 10;
            int totalPaginas = (cantidadServicios + cantidadPorPagina - 1) / cantidadPorPagina;
            int paginaActual = 1;
            char opc;

            // Ordenamiento con método burbuja (por categoria, codigo)
            if (cantidadServicios>1){
                for (int i=0; i<cantidadServicios; i++){
                    for (int j=0; j<cantidadServicios - 1; j++){
                        if(vec[j+1].getCodCategoria() < vec[j].getCodCategoria()){
                            servicioAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=servicioAux;
                        }
                        else if(vec[j+1].getCodCategoria() == vec[j].getCodCategoria()
                                && vec[j+1].getCodigo() < vec[j].getCodigo()){
                            servicioAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=servicioAux;
                        }
                    }
                }
            }

            do {
                system("cls");
                interfaz.dibujarMarco(CIAN);
                interfaz.setFilaActual(7);
                interfaz.cambiarTitulo("FIRULI 3000 - LISTADO DE SERVICIOS POR CATEGORIA");
                interfaz.siguienteLinea();
                if (cantidadServicios==0){
                    rlutil::setColor(ROJO);
                    cout<<"No hay registros a listar.";
                    interfaz.cambiarMensaje("Presione una tecla para continuar.",ROJO);
                    opc = '0';
                    rlutil::setColor(BLANCO);
                    rlutil::anykey();
                }
                else{
                    int indiceInicial = (paginaActual - 1) * cantidadPorPagina;
                    int indiceFinal = min(paginaActual * cantidadPorPagina, cantidadServicios);
                    cout<<"Pagina " << paginaActual << " de " << totalPaginas;
                    interfaz.siguienteLinea();
                    interfaz.siguienteLinea();
                    cout << left << setw(20) << "Categoria";
                    cout << left << setw(17) << "Codigo Servicio";
                    cout << left << setw(30) << "Nombre";
                    interfaz.siguienteLinea();
                    for (int i = indiceInicial; i < indiceFinal; i++) {
                        if(vec[i].getEstado()){
                            cout << left << setw(20) << to_string(vec[i].getCodCategoria()) + "-" + vecCategorias[vec[i].getCodCategoria()-1].getNombre();
                            cout << left << setw(17) << vec[i].getCodigo();
                            cout << left << setw(30) << vec[i].getNombre();
                            interfaz.siguienteLinea();
                        }
                        else{
                            rlutil::setColor(ROJO);
                            cout << left << setw(20) << to_string(vec[i].getCodCategoria()) + "-" + vecCategorias[vec[i].getCodCategoria()-1].getNombre();
                            cout << left << setw(17) << vec[i].getCodigo();
                            cout << left << setw(30) << vec[i].getNombre();
                            interfaz.siguienteLinea();
                            rlutil::setColor(BLANCO);
                        }
                    }
                    interfaz.siguienteLinea();
                    cout << " [1] Anterior || [2] Siguiente || [0] Volver";
                    opc = interfaz.pedirOpcion();
                    switch (opc) {
                        case '1':
                            paginaActual = max(1, paginaActual - 1);
                            break;
                        case '2':
                            paginaActual = min(totalPaginas, paginaActual + 1);
                            break;
                    }
                }
            } while (opc != '0');
            delete []vec;
            delete []vecCategorias;
        }
        void Menu::consultaServiciosPorCategoria(){
            // Cargo vector de servicios
            ServiciosArchivo serviciosArchivo;
            int cantidadServicios = serviciosArchivo.getCantidad();
            Servicio *vec = new Servicio[cantidadServicios];
            if(vec==NULL) return;
            serviciosArchivo.leerTodos(vec,cantidadServicios);

            // Cargo vector de categorias
            CategoriasArchivo categoriasArchivo;
            int cantidadCategorias = categoriasArchivo.getCantidad();
            Categoria *vecCategorias = new Categoria[cantidadCategorias];
            if(vecCategorias==NULL) return;
            categoriasArchivo.leerTodos(vecCategorias,cantidadCategorias);

            // Variables de la consulta
            char opc;
            int _cantCoincidencias = 0;
            int _idCategoria, pos_categoria;

            do {
                system("cls");
                interfaz.dibujarMarco(CIAN);
                interfaz.setFilaActual(7);
                interfaz.cambiarTitulo("FIRULI 3000 - CONSULTA DE SERVICIOS POR CATEGORIA");
                interfaz.siguienteLinea();
                if (cantidadServicios==0){
                    rlutil::setColor(ROJO);
                    cout<<"Aun no se registraron servicios para consultar.";
                    interfaz.cambiarMensaje("Presione una tecla para continuar.",ROJO);
                    opc = '0';
                    rlutil::setColor(BLANCO);
                    rlutil::anykey();
                }
                else
                {
                    cout << "Ingrese el ID de la categoria a consultar: ";
                    cin >> _idCategoria;
                    cin.ignore();
                    pos_categoria = categoriasArchivo.buscar(_idCategoria);
                    interfaz.siguienteLinea();

                    if(pos_categoria == -1){
                        interfaz.siguienteLinea();
                        interfaz.siguienteLinea();
                        cout<<"El ID ingresado es inexistente.";
                        interfaz.siguienteLinea();
                    }
                    else{

                        _cantCoincidencias = 0;
                        for(int i=0; i<cantidadServicios; i++){
                            if(vec[i].getEstado()
                            && vec[i].getCodCategoria() == _idCategoria)
                                _cantCoincidencias++;
                        }
                        if(_cantCoincidencias == 0){
                            interfaz.siguienteLinea();
                            interfaz.siguienteLinea();
                            cout << "No existen servicios para la categoria ingresada.";
                            interfaz.siguienteLinea();
                        }
                        else{
                            interfaz.siguienteLinea();
                            interfaz.siguienteLinea();
                            cout << "Cantidad de coincidencias: " << _cantCoincidencias;
                            interfaz.siguienteLinea();
                            interfaz.siguienteLinea();
                            cout << left << setw(20) << "Categoria";
                            cout << left << setw(17) << "Codigo Servicio";
                            cout << left << setw(30) << "Nombre";
                            interfaz.siguienteLinea();
                            for(int i=0; i<cantidadServicios; i++){
                                if(vec[i].getEstado()
                                && vec[i].getCodCategoria() == _idCategoria){
                                    cout << left << setw(20) << to_string(vec[i].getCodCategoria()) + "-" + vecCategorias[vec[i].getCodCategoria()-1].getNombre();
                                    cout << left << setw(17) << vec[i].getCodigo();
                                    cout << left << setw(30) << vec[i].getNombre();
                                    interfaz.siguienteLinea();
                                }
                            }
                            interfaz.siguienteLinea();
                        }
                    }
                }

                interfaz.siguienteLinea();
                cout << "[0] Volver";
                opc = interfaz.pedirOpcion();

            } while (opc != '0');
            delete []vec;
            delete []vecCategorias;
        }
        void Menu::consultaServiciosPorNombre(){
            // Cargo vector de servicios
            ServiciosArchivo serviciosArchivo;
            int cantidadServicios = serviciosArchivo.getCantidad();
            Servicio *vec = new Servicio[cantidadServicios];
            if(vec==NULL) return;
            serviciosArchivo.leerTodos(vec,cantidadServicios);

            // Cargo vector de categorias
            CategoriasArchivo categoriasArchivo;
            int cantidadCategorias = categoriasArchivo.getCantidad();
            Categoria *vecCategorias = new Categoria[cantidadCategorias];
            if(vecCategorias==NULL) return;
            categoriasArchivo.leerTodos(vecCategorias,cantidadCategorias);

            // Variables de la consulta
            char opc;
            int _cantCoincidencias = 0;
            string _nombre;

            do {
                system("cls");
                interfaz.dibujarMarco(CIAN);
                interfaz.setFilaActual(7);
                interfaz.cambiarTitulo("FIRULI 3000 - CONSULTA DE SERVICIOS POR NOMBRE");
                interfaz.siguienteLinea();
                if (cantidadServicios==0){
                    rlutil::setColor(ROJO);
                    cout<<"Aun no se registraron servicios para consultar.";
                    interfaz.cambiarMensaje("Presione una tecla para continuar.",ROJO);
                    opc = '0';
                    rlutil::setColor(BLANCO);
                    rlutil::anykey();
                }
                else
                {
                    cout << "Ingrese el nombre del servicio a consultar: ";
                    getline(cin, _nombre);

                    interfaz.siguienteLinea();

                    _cantCoincidencias = 0;
                    for(int i=0; i<cantidadServicios; i++){
                        if(vec[i].getEstado()
                        && vec[i].getNombre() == _nombre)
                            _cantCoincidencias++;
                    }
                    if(_cantCoincidencias == 0){
                        interfaz.siguienteLinea();
                        interfaz.siguienteLinea();
                        cout << "No existen servicios para el nombre ingresado.";
                        interfaz.siguienteLinea();
                    }
                    else{
                        interfaz.siguienteLinea();
                        interfaz.siguienteLinea();
                        cout << "Cantidad de coincidencias: " << _cantCoincidencias;
                        interfaz.siguienteLinea();
                        interfaz.siguienteLinea();
                        cout << left << setw(20) << "Categoria";
                        cout << left << setw(17) << "Codigo Servicio";
                        cout << left << setw(30) << "Nombre";
                        interfaz.siguienteLinea();
                        for(int i=0; i<cantidadServicios; i++){
                            if(vec[i].getEstado()
                            && vec[i].getNombre() == _nombre){
                                cout << left << setw(20) << to_string(vec[i].getCodCategoria()) + "-" + vecCategorias[vec[i].getCodCategoria()-1].getNombre();
                                cout << left << setw(17) << vec[i].getCodigo();
                                cout << left << setw(30) << vec[i].getNombre();
                                interfaz.siguienteLinea();
                            }
                        }
                        interfaz.siguienteLinea();
                    }
                }

                interfaz.siguienteLinea();
                cout << "[0] Volver";
                opc = interfaz.pedirOpcion();

            } while (opc != '0');
            delete []vec;
            delete []vecCategorias;
        }
        void Menu::consultaServiciosPorCodigo(){
            // Cargo vector de servicios
            ServiciosArchivo serviciosArchivo;
            int cantidadServicios = serviciosArchivo.getCantidad();
            Servicio *vec = new Servicio[cantidadServicios];
            if(vec==NULL) return;
            serviciosArchivo.leerTodos(vec,cantidadServicios);

            // Cargo vector de categorias
            CategoriasArchivo categoriasArchivo;
            int cantidadCategorias = categoriasArchivo.getCantidad();
            Categoria *vecCategorias = new Categoria[cantidadCategorias];
            if(vecCategorias==NULL) return;
            categoriasArchivo.leerTodos(vecCategorias,cantidadCategorias);

            // Variables de la consulta
            char opc;
            int _cantCoincidencias = 0;
            int _idServicio;

            do {
                system("cls");
                interfaz.dibujarMarco(CIAN);
                interfaz.setFilaActual(7);
                interfaz.cambiarTitulo("FIRULI 3000 - CONSULTA DE SERVICIOS POR CODIGO");
                interfaz.siguienteLinea();
                if (cantidadServicios==0){
                    rlutil::setColor(ROJO);
                    cout<<"Aun no se registraron servicios para consultar.";
                    interfaz.cambiarMensaje("Presione una tecla para continuar.",ROJO);
                    opc = '0';
                    rlutil::setColor(BLANCO);
                    rlutil::anykey();
                }
                else
                {
                    cout << "Ingrese el codigo del servicio a consultar: ";
                    cin >> _idServicio;
                    cin.ignore();
                    interfaz.siguienteLinea();

                    _cantCoincidencias = 0;
                    for(int i=0; i<cantidadServicios; i++){
                        if(vec[i].getEstado()
                        && vec[i].getCodigo() == _idServicio)
                            _cantCoincidencias++;
                    }
                    if(_cantCoincidencias == 0){
                        interfaz.siguienteLinea();
                        interfaz.siguienteLinea();
                        cout << "No existen servicios para el codigo ingresado.";
                        interfaz.siguienteLinea();
                    }
                    else{
                        interfaz.siguienteLinea();
                        interfaz.siguienteLinea();
                        cout << "Cantidad de coincidencias: " << _cantCoincidencias;
                        interfaz.siguienteLinea();
                        interfaz.siguienteLinea();
                        cout << left << setw(20) << "Categoria";
                        cout << left << setw(17) << "Codigo Servicio";
                        cout << left << setw(30) << "Nombre";
                        interfaz.siguienteLinea();
                        for(int i=0; i<cantidadServicios; i++){
                            if(vec[i].getEstado()
                            && vec[i].getCodigo() == _idServicio){
                                cout << left << setw(20) << to_string(vec[i].getCodCategoria()) + "-" + vecCategorias[vec[i].getCodCategoria()-1].getNombre();
                                cout << left << setw(17) << vec[i].getCodigo();
                                cout << left << setw(30) << vec[i].getNombre();
                                interfaz.siguienteLinea();
                            }
                        }
                        interfaz.siguienteLinea();
                    }
                }

                interfaz.siguienteLinea();
                cout << "[0] Volver";
                opc = interfaz.pedirOpcion();

            } while (opc != '0');
            delete []vec;
            delete []vecCategorias;
        }
    void Menu::nuevaConsEmpleado(){
        char opc;
        do{
            system("cls");
            interfaz.setFilaActual(7);
            interfaz.dibujarMarco(CIAN);
            interfaz.cambiarTitulo("FIRULI 3000 - CONSULTAS EMPLEADOS");
            interfaz.siguienteLinea();
            cout<<"[1] - Listado ordenado por DNI";
            interfaz.siguienteLinea();
            cout<<"[2] - Consultar por DNI de empleado";
            interfaz.siguienteLinea();
            cout<<"[3] - Consultar por apellido del empleado";
            interfaz.siguienteLinea();
            interfaz.siguienteLinea();
            cout<<"[0] - Volver";
            opc = interfaz.pedirOpcion();
            // Pregunta por la opcion elegida y se dirige a la funcion correspondiente
            switch(opc)
            {
                case '1':
                    listarEmpleadosXDNI();
                    break;
                case '2':
                    consultarEmpleadosXDNI();
                    break;
                case '3':
                    consultarEmpleadosXApellido();
                    break;
            }
        }
        while(opc != '0');
    }
        /// TODO
        void Menu::listarEmpleadosXDNI(){}
        void Menu::consultarEmpleadosXDNI(){}
        void Menu::consultarEmpleadosXApellido(){}
    void Menu::nuevaConsProveed(){
        char opc;
        do{
            system("cls");
            interfaz.setFilaActual(7);
            interfaz.dibujarMarco(CIAN);
            interfaz.cambiarTitulo("FIRULI 3000 - CONSULTAS PROVEEDORES");
            interfaz.siguienteLinea();
            cout<<"[1] - Listado ordenado por razon social";
            interfaz.siguienteLinea();
            cout<<"[2] - Listado ordenado por CUIL/CUIT";
            interfaz.siguienteLinea();
            cout<<"[3] - Consultar por razon social";
            interfaz.siguienteLinea();
            cout<<"[4] - Consultar por CUIL/CUIT";
            interfaz.siguienteLinea();
            interfaz.siguienteLinea();
            cout<<"[0] - Volver";
            opc = interfaz.pedirOpcion();
            // Pregunta por la opcion elegida y se dirige a la funcion correspondiente
            switch(opc)
            {
                case '1':
                    listarProveedoresXRazSoc();
                    break;
                case '2':
                    listarProveedoresXCUIL();
                    break;
                case '3':
                    consultarProveedoresXRazSoc();
                    break;
                case '4':
                    consultarProveedoresXCUIL();
                    break;
            }
        }
        while(opc != '0');
    }
        void Menu::listarProveedoresXRazSoc(){
            // Cargo vector de proveedores
            ProveedoresArchivo proveedoresArchivo;
            int cantidadProveedores = proveedoresArchivo.getCantidad();
            Proveedor *vec = new Proveedor[cantidadProveedores];
            if(vec==NULL) return;
            proveedoresArchivo.leerTodos(vec,cantidadProveedores);

            // Cargo vector de categorias
            CategoriasArchivo categoriasArchivo;
            int cantidadCategorias = categoriasArchivo.getCantidad();
            Categoria *vecCategorias = new Categoria[cantidadCategorias];
            if(vecCategorias==NULL) return;
            categoriasArchivo.leerTodos(vecCategorias,cantidadCategorias);

            // Variables de la consulta
            Proveedor proveedorAux;
            int cantidadPorPagina = 10;
            int totalPaginas = (cantidadProveedores + cantidadPorPagina - 1) / cantidadPorPagina;
            int paginaActual = 1;
            char opc;

            // Ordenamiento con método burbuja (por razon social)
            if (cantidadProveedores>1){
                for (int i=0; i<cantidadProveedores; i++){
                    for (int j=0; j<cantidadProveedores - 1; j++){
                        if(vec[j+1].getRazonS() < vec[j].getRazonS()){
                            proveedorAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=proveedorAux;
                        }
                    }
                }
            }

            do {
                system("cls");
                interfaz.dibujarMarco(CIAN);
                interfaz.setFilaActual(7);
                interfaz.cambiarTitulo("FIRULI 3000 - LISTADO DE PROVEEDORES POR RAZON SOCIAL");
                interfaz.siguienteLinea();
                if (cantidadProveedores==0){
                    rlutil::setColor(ROJO);
                    cout<<"No hay registros a listar.";
                    interfaz.cambiarMensaje("Presione una tecla para continuar.",ROJO);
                    opc = '0';
                    rlutil::setColor(BLANCO);
                    rlutil::anykey();
                }
                else{
                    int indiceInicial = (paginaActual - 1) * cantidadPorPagina;
                    int indiceFinal = min(paginaActual * cantidadPorPagina, cantidadProveedores);
                    cout<<"Pagina " << paginaActual << " de " << totalPaginas;
                    interfaz.siguienteLinea();
                    interfaz.siguienteLinea();
                    cout << left << setw(30) << "Razon Social";
                    cout << left << setw(17) << "CUIL/CUIT";
                    cout << left << setw(20) << "Categoria";
                    cout << left << setw(20) << "Telefono";
                    cout << left << setw(20) << "Email";
                    interfaz.siguienteLinea();
                    for (int i = indiceInicial; i < indiceFinal; i++) {
                        if(vec[i].getEstado()){
                            cout << left << setw(30) << vec[i].getRazonS();
                            cout << left << setw(17) << vec[i].getCuil();
                            cout << left << setw(20) << to_string(vec[i].getCodCategoria()) + "-" + vecCategorias[vec[i].getCodCategoria()-1].getNombre();
                            cout << left << setw(20) << vec[i].getTelefono();
                            cout << left << setw(20) << vec[i].getEmail();
                            interfaz.siguienteLinea();
                        }
                        else{
                            rlutil::setColor(ROJO);
                            cout << left << setw(30) << vec[i].getRazonS();
                            cout << left << setw(17) << vec[i].getCuil();
                            cout << left << setw(20) << to_string(vec[i].getCodCategoria()) + "-" + vecCategorias[vec[i].getCodCategoria()-1].getNombre();
                            cout << left << setw(20) << vec[i].getTelefono();
                            cout << left << setw(20) << vec[i].getEmail();
                            interfaz.siguienteLinea();
                            rlutil::setColor(BLANCO);
                        }
                    }
                    interfaz.siguienteLinea();
                    cout << " [1] Anterior || [2] Siguiente || [0] Volver";
                    opc = interfaz.pedirOpcion();
                    switch (opc) {
                        case '1':
                            paginaActual = max(1, paginaActual - 1);
                            break;
                        case '2':
                            paginaActual = min(totalPaginas, paginaActual + 1);
                            break;
                    }
                }
            } while (opc != '0');
            delete []vec;
            delete []vecCategorias;

        }
        void Menu::listarProveedoresXCUIL(){
            // Cargo vector de proveedores
            ProveedoresArchivo proveedoresArchivo;
            int cantidadProveedores = proveedoresArchivo.getCantidad();
            Proveedor *vec = new Proveedor[cantidadProveedores];
            if(vec==NULL) return;
            proveedoresArchivo.leerTodos(vec,cantidadProveedores);

            // Cargo vector de categorias
            CategoriasArchivo categoriasArchivo;
            int cantidadCategorias = categoriasArchivo.getCantidad();
            Categoria *vecCategorias = new Categoria[cantidadCategorias];
            if(vecCategorias==NULL) return;
            categoriasArchivo.leerTodos(vecCategorias,cantidadCategorias);

            // Variables de la consulta
            Proveedor proveedorAux;
            int cantidadPorPagina = 10;
            int totalPaginas = (cantidadProveedores + cantidadPorPagina - 1) / cantidadPorPagina;
            int paginaActual = 1;
            char opc;

            // Ordenamiento con método burbuja (por CUIL)
            if (cantidadProveedores>1){
                for (int i=0; i<cantidadProveedores; i++){
                    for (int j=0; j<cantidadProveedores - 1; j++){
                        if(vec[j+1].getCuil() < vec[j].getCuil()){
                            proveedorAux = vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=proveedorAux;
                        }
                    }
                }
            }

            do {
                system("cls");
                interfaz.dibujarMarco(CIAN);
                interfaz.setFilaActual(7);
                interfaz.cambiarTitulo("FIRULI 3000 - LISTADO DE PROVEEDORES POR CUIL/CUIT");
                interfaz.siguienteLinea();
                if (cantidadProveedores==0){
                    rlutil::setColor(ROJO);
                    cout<<"No hay registros a listar.";
                    interfaz.cambiarMensaje("Presione una tecla para continuar.",ROJO);
                    opc = '0';
                    rlutil::setColor(BLANCO);
                    rlutil::anykey();
                }
                else{
                    int indiceInicial = (paginaActual - 1) * cantidadPorPagina;
                    int indiceFinal = min(paginaActual * cantidadPorPagina, cantidadProveedores);
                    cout<<"Pagina " << paginaActual << " de " << totalPaginas;
                    interfaz.siguienteLinea();
                    interfaz.siguienteLinea();
                    cout << left << setw(17) << "CUIL/CUIT";
                    cout << left << setw(30) << "Razon Social";
                    cout << left << setw(20) << "Categoria";
                    cout << left << setw(20) << "Telefono";
                    cout << left << setw(20) << "Email";
                    interfaz.siguienteLinea();
                    for (int i = indiceInicial; i < indiceFinal; i++) {
                        if(vec[i].getEstado()){
                            cout << left << setw(17) << vec[i].getCuil();
                            cout << left << setw(30) << vec[i].getRazonS();
                            cout << left << setw(20) << to_string(vec[i].getCodCategoria()) + "-" + vecCategorias[vec[i].getCodCategoria()-1].getNombre();
                            cout << left << setw(20) << vec[i].getTelefono();
                            cout << left << setw(20) << vec[i].getEmail();
                            interfaz.siguienteLinea();
                        }
                        else{
                            rlutil::setColor(ROJO);
                            cout << left << setw(17) << vec[i].getCuil();
                            cout << left << setw(30) << vec[i].getRazonS();
                            cout << left << setw(20) << to_string(vec[i].getCodCategoria()) + "-" + vecCategorias[vec[i].getCodCategoria()-1].getNombre();
                            cout << left << setw(20) << vec[i].getTelefono();
                            cout << left << setw(20) << vec[i].getEmail();
                            interfaz.siguienteLinea();
                            rlutil::setColor(BLANCO);
                        }
                    }
                    interfaz.siguienteLinea();
                    cout << " [1] Anterior || [2] Siguiente || [0] Volver";
                    opc = interfaz.pedirOpcion();
                    switch (opc) {
                        case '1':
                            paginaActual = max(1, paginaActual - 1);
                            break;
                        case '2':
                            paginaActual = min(totalPaginas, paginaActual + 1);
                            break;
                    }
                }
            } while (opc != '0');
            delete []vec;
            delete []vecCategorias;
        }
        void Menu::consultarProveedoresXRazSoc(){
            // Cargo vector de proveedores
            ProveedoresArchivo proveedoresArchivo;
            int cantidadProveedores = proveedoresArchivo.getCantidad();
            Proveedor *vec = new Proveedor[cantidadProveedores];
            if(vec==NULL) return;
            proveedoresArchivo.leerTodos(vec,cantidadProveedores);

            // Cargo vector de categorias
            CategoriasArchivo categoriasArchivo;
            int cantidadCategorias = categoriasArchivo.getCantidad();
            Categoria *vecCategorias = new Categoria[cantidadCategorias];
            if(vecCategorias==NULL) return;
            categoriasArchivo.leerTodos(vecCategorias,cantidadCategorias);

            // Variables de la consulta
            char opc;
            int _cantCoincidencias = 0;
            string _razonsocial;

            do {
                system("cls");
                interfaz.dibujarMarco(CIAN);
                interfaz.setFilaActual(7);
                interfaz.cambiarTitulo("FIRULI 3000 - CONSULTA DE PROVEEDORES POR RAZON SOCIAL");
                interfaz.siguienteLinea();
                if (cantidadProveedores==0){
                    rlutil::setColor(ROJO);
                    cout<<"Aun no se registraron proveedores para consultar.";
                    interfaz.cambiarMensaje("Presione una tecla para continuar.",ROJO);
                    opc = '0';
                    rlutil::setColor(BLANCO);
                    rlutil::anykey();
                }
                else
                {
                    cout << "Ingrese la razon social del proveedor a consultar: ";
                    getline(cin, _razonsocial);

                    interfaz.siguienteLinea();

                    _cantCoincidencias = 0;
                    for(int i=0; i<cantidadProveedores; i++){
                        if(vec[i].getEstado()
                        && vec[i].getRazonS() == _razonsocial)
                            _cantCoincidencias++;
                    }
                    if(_cantCoincidencias == 0){
                        interfaz.siguienteLinea();
                        interfaz.siguienteLinea();
                        cout << "No existen proveedores para la razon social ingresada.";
                        interfaz.siguienteLinea();
                    }
                    else{
                        interfaz.siguienteLinea();
                        interfaz.siguienteLinea();
                        cout << "Cantidad de coincidencias: " << _cantCoincidencias;
                        interfaz.siguienteLinea();
                        interfaz.siguienteLinea();
                        cout << left << setw(17) << "CUIL/CUIT";
                        cout << left << setw(30) << "Razon Social";
                        cout << left << setw(20) << "Categoria";
                        cout << left << setw(20) << "Telefono";
                        cout << left << setw(20) << "Email";
                        interfaz.siguienteLinea();
                        for(int i=0; i<cantidadProveedores; i++){
                            if(vec[i].getEstado()
                            && vec[i].getRazonS() == _razonsocial){
                                cout << left << setw(17) << vec[i].getCuil();
                                cout << left << setw(30) << vec[i].getRazonS();
                                cout << left << setw(20) << to_string(vec[i].getCodCategoria()) + "-" + vecCategorias[vec[i].getCodCategoria()-1].getNombre();
                                cout << left << setw(20) << vec[i].getTelefono();
                                cout << left << setw(20) << vec[i].getEmail();
                                interfaz.siguienteLinea();
                            }
                        }
                        interfaz.siguienteLinea();
                    }
                }

                interfaz.siguienteLinea();
                cout << "[0] Volver";
                opc = interfaz.pedirOpcion();

            } while (opc != '0');
            delete []vec;
            delete []vecCategorias;
        }
        void Menu::consultarProveedoresXCUIL(){
            // Cargo vector de proveedores
            ProveedoresArchivo proveedoresArchivo;
            int cantidadProveedores = proveedoresArchivo.getCantidad();
            Proveedor *vec = new Proveedor[cantidadProveedores];
            if(vec==NULL) return;
            proveedoresArchivo.leerTodos(vec,cantidadProveedores);

            // Cargo vector de categorias
            CategoriasArchivo categoriasArchivo;
            int cantidadCategorias = categoriasArchivo.getCantidad();
            Categoria *vecCategorias = new Categoria[cantidadCategorias];
            if(vecCategorias==NULL) return;
            categoriasArchivo.leerTodos(vecCategorias,cantidadCategorias);

            // Variables de la consulta
            char opc;
            int _cantCoincidencias = 0;
            string _cuil;

            do {
                system("cls");
                interfaz.dibujarMarco(CIAN);
                interfaz.setFilaActual(7);
                interfaz.cambiarTitulo("FIRULI 3000 - CONSULTA DE PROVEEDORES POR CUIL/CUIT");
                interfaz.siguienteLinea();
                if (cantidadProveedores==0){
                    rlutil::setColor(ROJO);
                    cout<<"Aun no se registraron proveedores para consultar.";
                    interfaz.cambiarMensaje("Presione una tecla para continuar.",ROJO);
                    opc = '0';
                    rlutil::setColor(BLANCO);
                    rlutil::anykey();
                }
                else
                {
                    cout << "Ingrese el CUIL/CUIT del proveedor a consultar: ";
                    getline(cin, _cuil);

                    interfaz.siguienteLinea();

                    _cantCoincidencias = 0;
                    for(int i=0; i<cantidadProveedores; i++){
                        if(vec[i].getEstado()
                        && vec[i].getCuil() == _cuil)
                            _cantCoincidencias++;
                    }
                    if(_cantCoincidencias == 0){
                        interfaz.siguienteLinea();
                        interfaz.siguienteLinea();
                        cout << "No existen proveedores para el CUIL/CUIT ingresado.";
                        interfaz.siguienteLinea();
                    }
                    else{
                        interfaz.siguienteLinea();
                        interfaz.siguienteLinea();
                        cout << "Cantidad de coincidencias: " << _cantCoincidencias;
                        interfaz.siguienteLinea();
                        interfaz.siguienteLinea();
                        cout << left << setw(17) << "CUIL/CUIT";
                        cout << left << setw(30) << "Razon Social";
                        cout << left << setw(20) << "Categoria";
                        cout << left << setw(20) << "Telefono";
                        cout << left << setw(20) << "Email";
                        interfaz.siguienteLinea();
                        for(int i=0; i<cantidadProveedores; i++){
                            if(vec[i].getEstado()
                            && vec[i].getCuil() == _cuil){
                                cout << left << setw(17) << vec[i].getCuil();
                                cout << left << setw(30) << vec[i].getRazonS();
                                cout << left << setw(20) << to_string(vec[i].getCodCategoria()) + "-" + vecCategorias[vec[i].getCodCategoria()-1].getNombre();
                                cout << left << setw(20) << vec[i].getTelefono();
                                cout << left << setw(20) << vec[i].getEmail();
                                interfaz.siguienteLinea();
                            }
                        }
                        interfaz.siguienteLinea();
                    }
                }

                interfaz.siguienteLinea();
                cout << "[0] Volver";
                opc = interfaz.pedirOpcion();

            } while (opc != '0');
            delete []vec;
            delete []vecCategorias;
        }
    // TODO: Categorias
    // TODO: Compras de insumos
    // TODO: Pagos a empleados
    // TODO: Gastos generales

void Menu::reportes(){
    char opc;
    do{
        system("cls");
        interfaz.dibujarMarco(rlutil::CYAN);
        interfaz.cambiarTitulo("FIRULI 3000 - REPORTES");
        rlutil::locate(5,8);
        cout<<"[1] - Ver balance diario";
        rlutil::locate(5,9);
        cout<<"[2] - Ver balance mensual";
        rlutil::locate(5,10);
        cout<<"[3] - Ver balance Anual";
        rlutil::locate(5,11);
        cout<<"[4] - Recaudacion por empleado";
        rlutil::locate(5,12);
        cout<<"[5] - Recaudacion por categoria";
        rlutil::locate(5,13);
        cout<<"[6] - Sueldos a pagar";
        rlutil::locate(5,15);
        cout<<"[0] - Volver";
        opc = interfaz.pedirOpcion();
        // Pregunta por la opcion elegida y se dirige a la funcion correspondiente
        switch(opc)
        {
            case '1':
                balanceDiario();
                break;
            case '2':
                balanceMensual();
                break;
            case '3':
                balanceAnual();
                break;
            case '4':
                recaudacionPorEmpleado();
                break;
            case '5':
                recaudacionPorCategoria();
                break;
            case '6':
                sueldoAPagar();
                break;
        }
    }
    while(opc != '0');
}
    void Menu::balanceDiario(){

            VentasArchivo ventaArch;
            Venta _venta;
            CompraInsumos compraInsumos;
            GastoGeneral _gastoGral;
            GastosGeneralesArchivo gastosArch;
            ComprasInsumosArchivo compraInsumosArch;
            double recaudadoDia = 0, gastoGralDia = 0, gastoInsumos = 0, gananciaNeta = 0;
            int cantVentas = 0, cantGastos = 0, cantGastoProv = 0, anio, mes, dia ;
            Fecha fechaConsulta;
            char opc;


            do {
                system("cls");
                interfaz.dibujarMarco(CIAN);
                interfaz.setFilaActual(7);
                interfaz.cambiarTitulo("FIRULI 3000 - BALANCE DIARIO");
                interfaz.siguienteLinea();

                cout << "INGRESAR FECHA A CONSULTAR: ";
                fechaConsulta = cargarFecha(interfaz);
                anio = fechaConsulta.getAnio();
                mes = fechaConsulta.getMes();
                dia = fechaConsulta.getDia();


                interfaz.siguienteLinea();
                interfaz.siguienteLinea();


                cantVentas = ventaArch.getCantidad();

                for(int i=0; i < cantVentas; i++){
                    _venta = ventaArch.leer(i);
                        if(_venta.getEstado() &&
                           _venta.getFecha().getAnio() == anio &&
                           _venta.getFecha().getMes() == mes &&
                           _venta.getFecha().getDia() == dia){
                           recaudadoDia += _venta.getImporte();
                        }
                }

                cantGastos = gastosArch.getCantidad();

                for(int i=0; i < cantGastos; i++){
                     _gastoGral = gastosArch.leer(i);
                     if(_gastoGral.getEstado() &&
                        _gastoGral.getFecha().getAnio() == anio &&
                        _gastoGral.getFecha().getMes() == mes &&
                        _gastoGral.getFecha().getDia() == dia){
                            gastoGralDia += _gastoGral.getImporte();
                        }
                }

                cantGastoProv = compraInsumosArch.getCantidad();

                for(int i=0; i < cantGastoProv; i ++){
                    compraInsumos = compraInsumosArch.leer(i);
                    if(compraInsumos.getEstado() &&
                       compraInsumos.getFecha().getAnio() == anio &&
                       compraInsumos.getFecha().getMes() == mes &&
                       compraInsumos.getFecha().getDia() == dia){
                        gastoInsumos += compraInsumos.getImporte();
                       }
                }

                gananciaNeta = recaudadoDia - (gastoGralDia + gastoInsumos);

                cout << left << setw(14) << "FECHA";
                cout << left << setw(20) << "TOTAL RECAUDADO";
                cout << left << setw(20) << "GASTOS GRALES";
                cout << left << setw(20) << "PAGO A PROVEED";
                cout << left << setw(20) << "GANANCIA NETA";

                interfaz.siguienteLinea();

                cout << left << setw(14) << fechaConsulta.toString();

                if(recaudadoDia == 0){
                    cout << left << setw(20) << "-";
                }
                else{
                    cout << left << setw(20) << to_string_decimales(recaudadoDia);
                }
                cout << left << setw(20) << to_string_decimales(gastoGralDia);
                cout << left << setw(20) << to_string_decimales(gastoInsumos);

                if(gananciaNeta <= 0){
                     rlutil::setColor(ROJO);
                     cout << left << setw(20) << to_string_decimales(gananciaNeta);
                }
                else{
                    rlutil::setColor(VERDECLARO);
                    cout << left << setw(20) << to_string_decimales(gananciaNeta);
                }
                rlutil::setColor(BLANCO);

                recaudadoDia = 0;
                gastoGralDia = 0;
                gastoInsumos = 0;

                interfaz.siguienteLinea();
                interfaz.siguienteLinea();

                cout << "[0] Volver";
                opc = interfaz.pedirOpcion();

            } while (opc != '0');

    }
    void Menu::balanceMensual(){
            VentasArchivo ventaArch;
            Venta _venta;
            CompraInsumos compraInsumos;
            GastoGeneral _gastoGral;
            GastosGeneralesArchivo gastosArch;
            ComprasInsumosArchivo compraInsumosArch;
            PagoEmpleado _pagoEmp;
            PagosEmpleadosArchivo _pagoEmplArch;
            double recaudadoMes = 0, gastoGralDia = 0, gastoInsumos = 0, gananciaNeta = 0, sueldosMes = 0;
            int cantVentas = 0, cantGastos = 0, cantGastoProv = 0,cantSueldos= 0, anio, mes;
            Fecha fechaConsulta;
            char opc;

            do {
                system("cls");
                interfaz.dibujarMarco(CIAN);
                interfaz.setFilaActual(7);
                interfaz.cambiarTitulo("FIRULI 3000 - BALANCE MENSUAL");
                interfaz.siguienteLinea();

                cout << "Ingrese el mes a consultar: ";
                cin >> mes;
                interfaz.siguienteLinea();
                cout << "Ingrese el anio a consultar: ";
                cin >> anio;

                cin.ignore();

                interfaz.siguienteLinea();
                interfaz.siguienteLinea();

                cantVentas = ventaArch.getCantidad();

                for(int i=0; i < cantVentas; i++){
                    _venta = ventaArch.leer(i);
                    if(_venta.getEstado() &&
                       _venta.getFecha().getAnio() == anio &&
                       _venta.getFecha().getMes() == mes){
                       recaudadoMes += _venta.getImporte();
                    }
                }

                cantGastos = gastosArch.getCantidad();

                for(int i=0; i < cantGastos; i++){
                     _gastoGral = gastosArch.leer(i);
                     if(_gastoGral.getEstado() &&
                        _gastoGral.getFecha().getAnio() == anio &&
                        _gastoGral.getFecha().getMes() == mes){
                            gastoGralDia += _gastoGral.getImporte();
                        }
                }

                cantGastoProv = compraInsumosArch.getCantidad();

                for(int i=0; i < cantGastoProv; i ++){
                    compraInsumos = compraInsumosArch.leer(i);
                    if(compraInsumos.getEstado() &&
                       compraInsumos.getFecha().getAnio() == anio &&
                       compraInsumos.getFecha().getMes() == mes){
                        gastoInsumos += compraInsumos.getImporte();
                       }
                }

                cantSueldos = _pagoEmplArch.getCantidad();

                for(int i =0; i < cantSueldos; i++){
                    _pagoEmp = _pagoEmplArch.leer(i);
                    if(_pagoEmp.getEstado() &&
                       _pagoEmp.getFecha().getAnio() == anio &&
                       _pagoEmp.getFecha().getMes() == mes){
                        sueldosMes += _pagoEmp.getImporte();
                    }
                }

                gananciaNeta = recaudadoMes - (gastoGralDia + gastoInsumos + sueldosMes);

                cout << left << setw(14) << "MES";
                cout << left << setw(20) << "TOTAL RECAUDADO";
                cout << left << setw(22) << "GASTOS GRALES";
                cout << left << setw(22) << "PAGO A PROVEED";
                cout << left << setw(22) << "SUELDOS";
                cout << left << setw(22) << "GANANCIA NETA";

                interfaz.siguienteLinea();

                cout << left << setw(14) << mes;
                cout << left << setw(20) << to_string_decimales(recaudadoMes);
                cout << left << setw(22) << to_string_decimales(gastoGralDia);
                cout << left << setw(22) << to_string_decimales(gastoInsumos);
                cout << left << setw(22) << to_string_decimales(sueldosMes);
                cout << left << setw(22) << to_string_decimales(gananciaNeta);

                recaudadoMes = 0;
                gastoGralDia = 0;
                gastoInsumos = 0;
                sueldosMes = 0;

                interfaz.siguienteLinea();
                interfaz.siguienteLinea();
                cout << "[0] Volver";
                opc = interfaz.pedirOpcion();

            } while (opc != '0');
    }
    void Menu::balanceAnual(){

        VentasArchivo ventaArch;
        Venta _venta;
        CompraInsumos compraInsumos;
        GastoGeneral _gastoGral;
        GastosGeneralesArchivo gastosArch;
        ComprasInsumosArchivo compraInsumosArch;
        PagoEmpleado _pagoEmp;
        PagosEmpleadosArchivo _pagoEmplArch;
        double recaudadoAnio = 0, gastoGralAnio = 0, gastoInsumos = 0, gananciaNeta = 0, sueldosAnio = 0;
        int cantVentas = 0, cantGastos = 0, cantGastoProv = 0,cantSueldos = 0, anio;
        Fecha fechaConsulta;
        char opc;

        do {
            system("cls");
            interfaz.dibujarMarco(CIAN);
            interfaz.setFilaActual(7);
            interfaz.cambiarTitulo("FIRULI 3000 - BALANCE ANUAL");
            interfaz.siguienteLinea();

            cout << "Ingrese el anio a consultar: ";
            cin >> anio;

            cin.ignore();

            interfaz.siguienteLinea();
            interfaz.siguienteLinea();

            cantVentas = ventaArch.getCantidad();

            for(int i=0; i < cantVentas; i++){
                _venta = ventaArch.leer(i);
                if(_venta.getEstado() && _venta.getFecha().getAnio() == anio){
                   recaudadoAnio += _venta.getImporte();
                }
            }

            cantGastos = gastosArch.getCantidad();

            for(int i=0; i < cantGastos; i++){
                _gastoGral = gastosArch.leer(i);
                if(_gastoGral.getEstado() &&  _gastoGral.getFecha().getAnio() == anio){
                    gastoGralAnio += _gastoGral.getImporte();
                }
            }

            cantGastoProv = compraInsumosArch.getCantidad();

            for(int i=0; i < cantGastoProv; i ++){
                compraInsumos = compraInsumosArch.leer(i);
                if(compraInsumos.getEstado() && compraInsumos.getFecha().getAnio() == anio){
                    gastoInsumos += compraInsumos.getImporte();
                }
            }

            cantSueldos = _pagoEmplArch.getCantidad();

            for(int i =0; i < cantSueldos; i++){
                _pagoEmp = _pagoEmplArch.leer(i);
                if(_pagoEmp.getEstado() && _pagoEmp.getFecha().getAnio() == anio){
                    sueldosAnio += _pagoEmp.getImporte();
                }
            }

            gananciaNeta = recaudadoAnio - (gastoGralAnio + gastoInsumos + sueldosAnio);

            cout << left << setw(14) << "ANIO";
            cout << left << setw(20) << "TOTAL RECAUDADO";
            cout << left << setw(22) << "GASTOS GRALES";
            cout << left << setw(22) << "PAGO A PROVEED";
            cout << left << setw(22) << "SUELDOS";
            cout << left << setw(22) << "GANANCIA NETA";

            interfaz.siguienteLinea();

            cout << left << setw(14) << anio;
            cout << left << setw(20) << to_string_decimales(recaudadoAnio);
            cout << left << setw(22) << to_string_decimales(gastoGralAnio);
            cout << left << setw(22) << to_string_decimales(gastoInsumos);
            cout << left << setw(22) << to_string_decimales(sueldosAnio);
            cout << left << setw(22) << to_string_decimales(gananciaNeta);

            recaudadoAnio = 0;
            gastoGralAnio = 0;
            gastoInsumos = 0;
            sueldosAnio = 0;

            interfaz.siguienteLinea();
            cout << "[0] Volver";
            opc = interfaz.pedirOpcion();

        } while (opc != '0');
    }
    void Menu::recaudacionPorEmpleado(){
        VentasArchivo archivoVentas;
        int cantidadRegistros = archivoVentas.getCantidad(), cantidadEmpleados;
        Venta *vecVentas = new Venta[cantidadRegistros];
        if(vecVentas==NULL) return;
        archivoVentas.leerTodos(vecVentas, cantidadRegistros);

        EmpleadosArchivo empleadoArch;
        cantidadEmpleados = empleadoArch.getCantidad();
        Empleado *vecEmpleado = new Empleado[cantidadEmpleados];
        if(vecEmpleado == NULL) return;
        empleadoArch.leerTodos(vecEmpleado, cantidadEmpleados);

        Fecha fechaDesde, fechaHasta;
        double recaudadoEmpleado=0;
        char opc;


        do {
            system("cls");
            interfaz.dibujarMarco(CIAN);
            interfaz.setFilaActual(7);
            interfaz.cambiarTitulo("FIRULI 3000 - RECAUDACION POR EMPLEADO");
            interfaz.siguienteLinea();

            cout << "Ingrese la fecha DESDE a consultar: ";
            fechaDesde = cargarFecha(interfaz);
            interfaz.siguienteLinea();
            cout << "Ingrese la fecha HASTA a consultar: ";
            fechaHasta = cargarFecha(interfaz);
            interfaz.siguienteLinea();
            interfaz.siguienteLinea();


            cout << left << setw(14) << "APELLIDO";
            cout << left << setw(14) << "NOMBRE";
            cout << left << setw(20) << "TOTAL RECAUDADO";
            interfaz.siguienteLinea();

            //recorro vector de empleados
            for(int i = 0; i < cantidadEmpleados; i++){
                //verifico que el empleado este activo
                if(vecEmpleado[i].getEstado()){
                    //recorro vector ventas para encontrar ventas de empleados
                    for(int x= 0; x < cantidadRegistros; x++){
                        if(vecVentas[x].getEmpleado() == vecEmpleado[i].getDni() &&
                           vecVentas[x].getEstado()){
                            if(vecVentas[x].getFecha().esMayorOIgual(fechaDesde) &&
                                vecVentas[x].getFecha().esMenorOIgual(fechaHasta)){
                                    recaudadoEmpleado += vecVentas[x].getImporte();
                            }
                        }
                    }

                    cout << left << setw(15) << vecEmpleado[i].getApellido();
                    cout << left << setw(15) << vecEmpleado[i].getNombre();
                    cout << left << setw(25) << to_string_decimales(recaudadoEmpleado);

                    interfaz.siguienteLinea();
                    recaudadoEmpleado=0;
                }
            }

            interfaz.siguienteLinea();
            interfaz.siguienteLinea();

            cout << "[0] Volver";
            opc = interfaz.pedirOpcion();

        } while (opc != '0');

        delete []vecEmpleado;
        delete []vecVentas;

    }
    void Menu::recaudacionPorCategoria(){
        VentasArchivo archivoVentas;
        int cantidadRegistros = archivoVentas.getCantidad(), cantidadCategorias, cantidadServicios;
        Venta *vecVentas = new Venta[cantidadRegistros];
        if(vecVentas==NULL) return;
        archivoVentas.leerTodos(vecVentas, cantidadRegistros);

        CategoriasArchivo categoriaArchivo;
        cantidadCategorias = categoriaArchivo.getCantidad();
        Categoria *vecCategoria = new Categoria[cantidadCategorias];
        if(vecCategoria == NULL) return;
        categoriaArchivo.leerTodos(vecCategoria, cantidadCategorias);

        ServiciosArchivo servicioArchivo;
        cantidadServicios = servicioArchivo.getCantidad();
        Servicio *vecServicio = new Servicio[cantidadServicios];
        if(vecServicio == NULL) return;
        servicioArchivo.leerTodos(vecServicio, cantidadServicios);

        Fecha fechaDesde, fechaHasta;
        double recaudadoCategoria=0;
        char opc;


         do {
            system("cls");
            interfaz.dibujarMarco(CIAN);
            interfaz.setFilaActual(7);
            interfaz.cambiarTitulo("FIRULI 3000 - RECAUDACION POR CATEGORIA");
            interfaz.siguienteLinea();

            cout << "Ingrese la fecha DESDE a consultar: ";
            fechaDesde = cargarFecha(interfaz);
            interfaz.siguienteLinea();
            cout << "Ingrese la fecha HASTA a consultar: ";
            fechaHasta = cargarFecha(interfaz);
            interfaz.siguienteLinea(); interfaz.siguienteLinea();


            cout << left << setw(14) << "CATEGORIA";
            cout << left << setw(20) << "TOTAL RECAUDADO";
            interfaz.siguienteLinea();


            for(int i = 0; i < cantidadCategorias; i++){
                //verifico que la categoria este activa
                if(vecCategoria[i].getEstado()){
                    //recorro las ventas
                    for(int x= 0; x < cantidadRegistros; x++){
                        // verifico que la venta este activa y que la categoria de su servicio coincida
                        if(vecVentas[x].getEstado() &&
                           vecServicio[vecVentas[x].getServicio()-1].getCodCategoria() == vecCategoria[i].getCodigo()){
                            if(vecVentas[x].getFecha().esMayorOIgual(fechaDesde) &&
                                vecVentas[x].getFecha().esMenorOIgual(fechaHasta)){
                                    recaudadoCategoria += vecVentas[x].getImporte();
                            }
                        }

                    }
                }

                cout << left << setw(15) << vecCategoria[i].getNombre();
                cout << left << setw(25) << to_string_decimales(recaudadoCategoria);

                interfaz.siguienteLinea();
                recaudadoCategoria=0;
            }

            interfaz.siguienteLinea();
            interfaz.siguienteLinea();

            cout << "[0] Volver";
            opc = interfaz.pedirOpcion();

        } while (opc != '0');

        delete []vecCategoria;
        delete []vecVentas;
        delete []vecServicio;
    }
    void Menu::sueldoAPagar(){
        VentasArchivo archivoVentas;
        int cantidadRegistros = archivoVentas.getCantidad(), cantidadEmpleados, cantPagos, anio,mes;
        Venta *vecVentas = new Venta[cantidadRegistros];
        if(vecVentas==NULL) return;
        archivoVentas.leerTodos(vecVentas, cantidadRegistros);

        EmpleadosArchivo empleadoArch;
        cantidadEmpleados = empleadoArch.getCantidad();
        Empleado *vecEmpleado = new Empleado[cantidadEmpleados];
        if(vecEmpleado == NULL) return;
        empleadoArch.leerTodos(vecEmpleado, cantidadEmpleados);

        PagoEmpleado _pagoEmpleado;
        PagosEmpleadosArchivo _pagoEmpleadoArch;
        cantPagos = _pagoEmpleadoArch.getCantidad();
        PagoEmpleado *vecPagos = new PagoEmpleado[cantPagos];
        if(vecPagos==NULL) return;
        _pagoEmpleadoArch.leerTodos(vecPagos, cantPagos);

        Fecha fechaActual;
        double sueldoEmpleado=0, recaudadoEmpleado=0;
        char opc;
        bool mesPagado=false;


         do {
            system("cls");
            interfaz.dibujarMarco(CIAN);
            interfaz.setFilaActual(7);
            interfaz.cambiarTitulo("FIRULI 3000 - SUELDOS A PAGAR");
            interfaz.siguienteLinea();

            cout << "Ingrese el anio a consultar: ";
            cin >> anio;
            interfaz.siguienteLinea();

            cout << "Ingrese el mes a consultar: ";
            cin >> mes;

            cin.ignore();

            interfaz.siguienteLinea();
            interfaz.siguienteLinea();


            cout << left << setw(14) << "APELLIDO";
            cout << left << setw(14) << "NOMBRE";
            cout << left << setw(20) << "SUELDO FIJO";
            cout << left << setw(20) << "RECAUDADO DEL MES";
            cout << left << setw(20) << "PORCENTAJE";
            cout << left << setw(20) << "TOTAL A PAGAR";

            interfaz.siguienteLinea();

            for(int i = 0; i < cantidadEmpleados; i++){
                for(int x= 0; x < cantidadRegistros; x++){
                    if(vecVentas[x].getEmpleado() == vecEmpleado[i].getDni() &&
                        vecVentas[x].getEstado()){
                        if(vecVentas[x].getFecha().getAnio() == anio &&
                           vecVentas[x].getFecha().getMes() == mes){
                                recaudadoEmpleado += vecVentas[x].getImporte();
                        }
                    }
                }

                sueldoEmpleado = ((recaudadoEmpleado * vecEmpleado[i].getPComision()) / 100) + vecEmpleado[i].getSueldoF() ;


                for(int z =0; z < cantPagos; z++){
                    if(vecPagos[z].getIdE() == vecEmpleado[i].getDni() &&
                       vecPagos[z].getEstado() &&
                       vecPagos[z].getFecha().getAnio() == anio &&
                       vecPagos[z].getFecha().getMes() == mes){
                        sueldoEmpleado = sueldoEmpleado - vecPagos[z].getImporte();
                        mesPagado = true;
                       }
                }


                cout << left << setw(15) << vecEmpleado[i].getApellido();
                cout << left << setw(15) << vecEmpleado[i].getNombre();
                cout << left << setw(20) << to_string_decimales(vecEmpleado[i].getSueldoF());
                cout << left << setw(20) << to_string_decimales(recaudadoEmpleado);
                cout << left << setw(20) << vecEmpleado[i].getPComision();
                if(sueldoEmpleado <= 0.001 && mesPagado){
                    cout << left << setw(20) << to_string_decimales(sueldoEmpleado) << " (pagado)";
                }
                else{
                    cout << left << setw(20) << to_string_decimales(sueldoEmpleado);
                }

                interfaz.siguienteLinea();
                sueldoEmpleado=0;
                recaudadoEmpleado=0;
                mesPagado = false;
            }

            interfaz.siguienteLinea();
            interfaz.siguienteLinea();

            cout << "[0] Volver";
            opc = interfaz.pedirOpcion();

        } while (opc != '0');

        delete []vecEmpleado;
        delete []vecVentas;
        delete []vecPagos;
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
