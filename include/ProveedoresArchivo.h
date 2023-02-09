#ifndef PROVEEDORESARCHIVO_H
#define PROVEEDORESARCHIVO_H
#include "Proveedor.h"

class ProveedoresArchivo
{
public:
    Proveedor leer(int nroRegistro);
    bool leerTodos(Proveedor proveedores[], int cantidad);
    bool guardar(Proveedor proveedor);
    bool guardar(Proveedor proveedor, int nroRegistro);
    int getCantidad();
    int getCantidadActivos();
    int buscar(string cuil);

    bool importarCSV();
    bool exportarCSV();
    bool eliminarArchivoDAT();
};

#endif // PROVEEDORESARCHIVO_H
