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
        void menuProveedores();
        void menuServicios();
    void consultas();
        void nuevaConsEmpleado();
        void nuevaConsCliente();

    void reportes();
    void backupRestauracionDeArchivos();
        void menuImportarExportar(int opcion);
            //void ExportarCategorias();
            //void ImportarCategorias();
    bool salirDelSistema();

};


#endif // MENU_H
