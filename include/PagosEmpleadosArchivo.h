#ifndef PAGOSEMPLEADOSARCHIVO_H
#define PAGOSEMPLEADOSARCHIVO_H
#include "PagoEmpleado.h"
#include <string>
using namespace std;

class PagosEmpleadosArchivo
{
    PagoEmpleado leer(int nroRegistro);
    bool leerTodos(PagoEmpleado pagosEmpleados[], int cantidad);
    bool guardar(PagoEmpleado pagoEmpleado);
    bool guardar(PagoEmpleado pagoEmpleado, int nroRegistro);
    int getCantidad();
    int buscar(int id);
};

#endif // PAGOSEMPLEADOSARCHIVO_H
