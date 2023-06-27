#include <iostream>
#include <fstream>

using namespace std;

#ifndef MENU_H
#define MENU_H
#include "Interfaz.h"
#include "rlutil.h"
#include "Funciones.h"
#include "CategoriasArchivo.h"
#include "VentasArchivo.h"
#include "GastosGeneralesArchivo.h"
#include "ComprasInsumosArchivo.h"
#include "PagosEmpleadosArchivo.h"
#include "ClientesArchivo.h"
#include "EmpleadosArchivo.h"
#include "ProveedoresArchivo.h"
#include "ServiciosArchivo.h"

class Menu
{
private:
    Interfaz interfaz;

public:
    Menu(Interfaz &interf);

    enum {
	NEGRO,
	AZULOSCURO,
	VERDEOSCURO,
	CIAN,
	ROJOOSCURO,
	FUCSIAOSCURO,
	MARRON,
	GRISCLARO,
	GRISOSCURO,
	AZUL,
	VERDECLARO,
	CELESTE,
	ROJO,
	FUCSIA,
	AMARILLO,
	BLANCO
    };

    void menuPrincipal();

    void nuevaTransaccion();
        void nuevaVenta();
        void nuevoGastoGeneral();
        void nuevaCompraInsumos();
        void nuevoPagoEmpleado();

    void cargaDeDatos();
        void menuCategorias();
            void nuevaCategoria();
            void cambiarEstadoCategoria();
            void modificarCategoria();
            void listarCategorias();
        void menuClientes();
            void listarClientes();
            void nuevoCliente();
            void cambiarEstadoCliente();
            void modificarCliente();
        void menuEmpleados();
            void listarEmpleados();
            void nuevoEmpleado();
            void cambiarEstadoEmpleado();
            void modificarEmpleado();
        void menuProveedores();
            void listarProveedor();
            void nuevoProveedor();
            void cambiarEstadoProveedor();
            void modificarProveedor();
        void menuServicios();
            void listarServicio();
            void nuevoServicio();
            void cambiarEstadoServicio();
            void modificarServicio();
    void consultas();
        void nuevaConsCliente();
            void listarClientesXApellido();
            void listarClientesXNombre();
            void consultaClientePorDNI();
            void consultaClientePorTEL();
            void consultaClientePorApellido();
        void nuevaConsVenta();
            void listarVentasXFecha();
            void listarVentasXEmpleado();
            void listarVentasXCategoria();
            void consultaVentasPorRangoF();
            void consultaVentasPorCliente();
            void consultaVentasPorServicio();
            void consultaVentasPorEmpleado();
        void nuevaConsServicio();
        void nuevaConsEmpleado();
        void nuevaConsProveed();

    void reportes();
    void backupRestauracionDeArchivos();
        void menuImportarExportar(int opcion);
            //void ExportarCategorias();
            //void ImportarCategorias();
    bool salirDelSistema();

};


#endif // MENU_H
