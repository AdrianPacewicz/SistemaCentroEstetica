#ifndef EMPLEADOSARCHIVO_H
#define EMPLEADOSARCHIVO_H
#include "Empleado.h"

class EmpleadosArchivo
{
public:
    Empleado leer(int nroRegistro);
    bool leerTodos(Empleado empleados[], int cantidad);
    bool guardar(Empleado empleado);
    bool guardar(Empleado empleado, int nroRegistro);
    int getCantidad();
    int getCantidadActivos();
    int buscar(int dni);

    bool importarCSV();
    bool exportarCSV();
    bool eliminarArchivoDAT();
};

#endif // EMPLEADOSARCHIVO_H
