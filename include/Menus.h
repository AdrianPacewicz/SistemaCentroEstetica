#ifndef MENUS_H
#define MENUS_H
#include "Interfaz.h"

void maximizarVentana();
void VerMenu1();
bool SalirDelJuego();
void ExportarCategorias();
void ImportarCategorias();
void ListarCategorias();

void nuevaVenta(Interfaz &interfaz);
void nuevoGastoGeneral(Interfaz &interfaz);
void nuevaCompraInsumos(Interfaz &interfaz);
void nuevoPagoEmpleado(Interfaz &interfaz);

void nuevaTransaccion(Interfaz &interfaz);
void cargaDeDatos(Interfaz &interfaz);
void consultas(Interfaz &interfaz);
void reportes(Interfaz &interfaz);
void backupRestauracionDeArchivos(Interfaz &interfaz);

void menuPrincipal(Interfaz &interfaz);


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
