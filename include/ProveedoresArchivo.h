#ifndef PROVEEDORESARCHIVO_H
#define PROVEEDORESARCHIVO_H
#include "Proveedor.h"

class ProveedoresArchivo
{
    Proveedor leer(int nroRegistro);
    bool leerTodos(Proveedor proveedores[], int cantidad);
    bool guardar(Proveedor proveedor);
    bool guardar(Proveedor proveedor, int nroRegistro);
    int getCantidad();
    int buscar(int cuil);
};

#endif // PROVEEDORESARCHIVO_H
