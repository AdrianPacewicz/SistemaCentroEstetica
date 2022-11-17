#ifndef VENTASARCHIVO_H
#define VENTASARCHIVO_H
#include "Venta.h"

class VentasArchivo
{
public:
    Venta leer(int nroRegistro);
    bool leerTodos(Venta ventas[], int cantidad);
    bool guardar(Venta venta);
    bool guardar(Venta venta, int nroRegistro);
    int getCantidad();
    int getCantidadActivos();
    int buscar(int id);

    bool importarCSV();
    bool exportarCSV();
    bool eliminarArchivoDAT();
};

#endif // VENTASARCHIVO_H
