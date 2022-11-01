#ifndef VENTASARCHIVO_H
#define VENTASARCHIVO_H
#include "Venta.h"

class VentasArchivo
{
    Venta leer(int nroRegistro);
    bool leerTodos(Venta ventas[], int cantidad);
    bool guardar(Venta venta);
    bool guardar(Venta venta, int nroRegistro);
    int getCantidad();
    int buscar(int id);
};

#endif // VENTASARCHIVO_H
