#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Fecha.h"
#include "Interfaz.h"

void mostrarEmpleados(int y, int pag, int cantPag);
void mostrarCategorias(int y, int pag, int cantPag);
void mostrarServicios(int y, int pag, int cantPag);
Fecha cargarFecha(Interfaz &interfaz);
void importar(int opcion);
void exportar(int opcion);

#endif // FUNCIONES_H
