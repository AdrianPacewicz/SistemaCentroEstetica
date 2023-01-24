#ifndef MENUS_H
#define MENUS_H
#include "Interfaz.h"

bool salirDelSistema(Interfaz &interfaz);//
void ExportarCategorias();//
void ImportarCategorias();//


    void nuevaVenta(Interfaz &interfaz);//
    void nuevoGastoGeneral(Interfaz &interfaz);//
    void nuevaCompraInsumos(Interfaz &interfaz);//
    void nuevoPagoEmpleado(Interfaz &interfaz);//
void nuevaTransaccion(Interfaz &interfaz);//

        void nuevaCategoria(Interfaz &interfaz);//
        void cambiarEstadoCategoria(Interfaz &interfaz);//
        void modificarCategoria(Interfaz &interfaz);//
        void listarCategorias(Interfaz &interfaz);//
    void menuCategorias(Interfaz &interfaz);//

        void listarClientes(Interfaz &interfaz);//
        void nuevoCliente(Interfaz &interfaz);//
        void cambiarEstadoCliente(Interfaz &interfaz);//
        void modificarCliente(Interfaz &interfaz);//
    void menuClientes(Interfaz &interfaz);//

    void menuEmpleados(Interfaz &interfaz);//

    void menuProveedores(Interfaz &interfaz);//

    void menuServicios(Interfaz &interfaz);//
void cargaDeDatos(Interfaz &interfaz);//

void consultas(Interfaz &interfaz);//

void reportes(Interfaz &interfaz);//

    void menuImportarExportar(Interfaz &interfaz, int opcion);//
void backupRestauracionDeArchivos(Interfaz &interfaz);//

void menuPrincipal(Interfaz &interfaz);//


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

#endif // MENUS_H
