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

        /*
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
        */
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
                    /*
                    LISTAR SOLO ACTIVOS
                    int contador = 0;
                    contador = 0;
                    for (int i = 0; i < cantidadRegistros; i++) {
                        if (vec[i].getEstado()) {
                            contador++;
                            if (contador > (paginaActual - 1) * cantidadPorPagina && contador <= paginaActual * cantidadPorPagina) {
                                cout << vec[i].toString();
                                interfaz.siguienteLinea();
                            }
                        }
                    }
                    */
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
        /*
        • Listado de clientes
            o Ordenados por apellido
            o Ordenados por nombre
        */
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
        // TODO
        /*
        o Ordenadas por fechas
        o Ordenadas por empleado que lo realizó
        o Ordenadas por categoría
        o Por rango de fechas
        o Por cliente
        o Por servicio
        o Por empleado
        */
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
            VentasArchivo archivo;
            int cantidadRegistros = archivo.getCantidad();
            Venta *vec = new Venta[cantidadRegistros];
            Venta ventaAux;
            if(vec==NULL) return;
            int cantidadPorPagina = 10;
            int totalPaginas = (cantidadRegistros + cantidadPorPagina - 1) / cantidadPorPagina;
            int paginaActual = 1;
            char opc;
            archivo.leerTodos(vec, cantidadRegistros);

            // Ordenamiento con método burbuja (por año/mes/dia/empleado/servicio)
            if (cantidadRegistros>1){
                for (int i=0; i<cantidadRegistros; i++){
                    for (int j=0; j<cantidadRegistros - 1; j++){
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
                    cout << left << setw(14) << "Fecha";
                    cout << left << setw(15) << "Id Empleado";
                    cout << left << setw(15) << "Id Servicio";
                    cout << left << setw(15) << "Cliente";
                    cout << right << setw(15) << "Importe";
                    interfaz.siguienteLinea();
                    for (int i = indiceInicial; i < indiceFinal; i++) {
                        if(vec[i].getEstado()){
                            cout << left << setw(14) << vec[i].getFecha().toString();
                            cout << left << setw(15) << vec[i].getEmpleado();
                            cout << left << setw(15) << vec[i].getServicio();
                            cout << left << setw(15) << vec[i].getCliente();
                            cout << right << setw(15) << to_string_decimales(vec[i].getImporte());
                            interfaz.siguienteLinea();
                        }
                        else{
                            rlutil::setColor(ROJO);
                            cout << left << setw(14) << vec[i].getFecha().toString();
                            cout << left << setw(15) << vec[i].getEmpleado();
                            cout << left << setw(15) << vec[i].getServicio();
                            cout << left << setw(15) << vec[i].getCliente();
                            cout << right << setw(15) << to_string_decimales(vec[i].getImporte());
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
        void Menu::listarVentasXEmpleado(){
            VentasArchivo archivo;
            int cantidadRegistros = archivo.getCantidad();
            Venta *vec = new Venta[cantidadRegistros];
            Venta ventaAux;
            if(vec==NULL) return;
            int cantidadPorPagina = 10;
            int totalPaginas = (cantidadRegistros + cantidadPorPagina - 1) / cantidadPorPagina;
            int paginaActual = 1;
            char opc;
            archivo.leerTodos(vec, cantidadRegistros);

            // Ordenamiento con método burbuja (por empleado/año/mes/dia)
            if (cantidadRegistros>1){
                for (int i=0; i<cantidadRegistros; i++){
                    for (int j=0; j<cantidadRegistros - 1; j++){
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
                    cout << left << setw(14) << "Fecha";
                    cout << left << setw(15) << "Id Empleado";
                    cout << left << setw(15) << "Id Servicio";
                    cout << right << setw(15) << "Importe";
                    interfaz.siguienteLinea();
                    for (int i = indiceInicial; i < indiceFinal; i++) {
                        if(vec[i].getEstado()){
                            cout << left << setw(14) << vec[i].getFecha().toString();
                            cout << left << setw(15) << vec[i].getEmpleado();
                            cout << left << setw(15) << vec[i].getServicio();
                            cout << right << setw(15) << to_string_decimales(vec[i].getImporte());
                            interfaz.siguienteLinea();
                        }
                        else{
                            rlutil::setColor(ROJO);
                            cout << left << setw(14) << vec[i].getFecha().toString();
                            cout << left << setw(15) << vec[i].getEmpleado();
                            cout << left << setw(15) << vec[i].getServicio();
                            cout << right << setw(15) << to_string_decimales(vec[i].getImporte());
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
        void Menu::listarVentasXCategoria(){
            ServiciosArchivo serviciosArchivo;
            Servicio servicioSiguiente, servicioActual;
            CategoriasArchivo categoriasArchivo;
            Categoria categoria;
            int idCategoriaAnterior=-1;

            VentasArchivo archivo;
            int cantidadRegistros = archivo.getCantidad();
            Venta *vec = new Venta[cantidadRegistros];
            Venta ventaAux;
            if(vec==NULL) return;
            int cantidadPorPagina = 10;
            int totalPaginas = (cantidadRegistros + cantidadPorPagina - 1) / cantidadPorPagina;
            int paginaActual = 1;
            char opc;
            archivo.leerTodos(vec, cantidadRegistros);

            // Ordenamiento con método burbuja (por categoria/empleado/año/mes/dia)
            if (cantidadRegistros>1){
                for (int i=0; i<cantidadRegistros; i++){
                    for (int j=0; j<cantidadRegistros - 1; j++){

                        // con el id_servicio busco el indice y con el indice traigo el servicio
                        servicioActual = serviciosArchivo.leer(serviciosArchivo.buscar(vec[j].getServicio()));
                        servicioSiguiente = serviciosArchivo.leer(serviciosArchivo.buscar(vec[j+1].getServicio()));

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
                    cout << left << setw(14) << "Fecha";
                    cout << left << setw(20) << "Categoria";
                    cout << left << setw(15) << "Id Empleado";
                    cout << left << setw(15) << "Id Servicio";
                    cout << right << setw(15) << "Importe";
                    interfaz.siguienteLinea();
                    for (int i = indiceInicial; i < indiceFinal; i++) {
                        // Leo el servicio para buscar su categoria
                        servicioActual = serviciosArchivo.leer(serviciosArchivo.buscar(vec[i].getServicio()));
                        // Si la categoria es diferente a la que tenía de antes leo la categoria nueva
                        if(idCategoriaAnterior!=servicioActual.getCodCategoria()){
                            categoria = categoriasArchivo.leer(categoriasArchivo.buscar(servicioActual.getCodCategoria()));
                            idCategoriaAnterior = categoria.getCodigo();
                        }

                        if(vec[i].getEstado()){
                            cout << left << setw(14) << vec[i].getFecha().toString();
                            cout << left << setw(20) << categoria.getNombre();
                            cout << left << setw(15) << vec[i].getEmpleado();
                            cout << left << setw(15) << vec[i].getServicio();
                            cout << right << setw(15) << to_string_decimales(vec[i].getImporte());
                            interfaz.siguienteLinea();
                        }
                        else{
                            rlutil::setColor(ROJO);
                            cout << left << setw(14) << vec[i].getFecha().toString();
                            cout << left << setw(20) << categoria.getNombre();
                            cout << left << setw(15) << vec[i].getEmpleado();
                            cout << left << setw(15) << vec[i].getServicio();
                            cout << right << setw(15) << to_string_decimales(vec[i].getImporte());
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
        void Menu::consultaVentasPorRangoF(){
            VentasArchivo archivo;
            int cantidadRegistros = archivo.getCantidad();
            Venta *vec = new Venta[cantidadRegistros];
            if(vec==NULL) return;
            archivo.leerTodos(vec, cantidadRegistros);
            Venta ventaAux;
            Fecha fechaDesde, fechaHasta;
            int _cantCoincidencias = 0;
            char opc;

            // Ordenamiento con método burbuja (por año/mes/dia/empleado/servicio)
            if (cantidadRegistros>1){
                for (int i=0; i<cantidadRegistros; i++){
                    for (int j=0; j<cantidadRegistros - 1; j++){
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
                if (cantidadRegistros==0){
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
                    for(int i=0; i<cantidadRegistros; i++){
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
                        cout << left << setw(15) << "Id Empleado";
                        cout << left << setw(15) << "Id Servicio";
                        cout << right << setw(15) << "Importe";
                        interfaz.siguienteLinea();
                        for(int i=0; i<cantidadRegistros; i++){
                            if(vec[i].getEstado()
                            && vec[i].getFecha().esMayorOIgual(fechaDesde)
                            && vec[i].getFecha().esMenorOIgual(fechaHasta)){
                                cout << left << setw(14) << vec[i].getFecha().toString();
                                cout << left << setw(15) << vec[i].getEmpleado();
                                cout << left << setw(15) << vec[i].getServicio();
                                cout << right << setw(15) << to_string_decimales(vec[i].getImporte());
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
        void Menu::consultaVentasPorCliente(){
            VentasArchivo archivo;
            int cantidadRegistros = archivo.getCantidad();
            ClientesArchivo clientesArchivo;
            Venta *vec = new Venta[cantidadRegistros];
            if(vec==NULL) return;
            archivo.leerTodos(vec, cantidadRegistros);
            Venta ventaAux;
            int _dni, pos_dni;
            int _cantCoincidencias = 0;
            char opc;

            // Ordenamiento con método burbuja (por año/mes/dia/empleado/servicio)
            if (cantidadRegistros>1){
                for (int i=0; i<cantidadRegistros; i++){
                    for (int j=0; j<cantidadRegistros - 1; j++){
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
                if (cantidadRegistros==0){
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
                        for(int i=0; i<cantidadRegistros; i++){
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
                            cout << left << setw(15) << "Id Empleado";
                            cout << left << setw(15) << "Id Servicio";
                            cout << left << setw(15) << "Cliente";
                            cout << right << setw(15) << "Importe";
                            interfaz.siguienteLinea();
                            for(int i=0; i<cantidadRegistros; i++){
                                if(vec[i].getEstado()
                                && vec[i].getCliente() == _dni){
                                    cout << left << setw(14) << vec[i].getFecha().toString();
                                    cout << left << setw(15) << vec[i].getEmpleado();
                                    cout << left << setw(15) << vec[i].getServicio();
                                    cout << left << setw(15) << vec[i].getCliente();
                                    cout << right << setw(15) << to_string_decimales(vec[i].getImporte());
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
        }
        void Menu::consultaVentasPorServicio(){}
        void Menu::consultaVentasPorEmpleado(){}
    void Menu::nuevaConsServicio(){
        // TODO
        /*
        o Por categoría
        o Por nombre
        o Por código
        */
    }
    void Menu::nuevaConsEmpleado(){
        // TODO
        /*
        o Por DNI
        o Por Apellido
        */
    }
    void Menu::nuevaConsProveed(){
        // TODO
        /*
        o Por razón social
        o Por CUIT/CUIL
        */
    }

void Menu::reportes(){
    // TODO
    /*
    • Balance diario.
    • Balance mensual
    • Balance anual
    • Recaudación por empleado
    • Recaudación por categoría
    • Sueldos a pagar
    */
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
