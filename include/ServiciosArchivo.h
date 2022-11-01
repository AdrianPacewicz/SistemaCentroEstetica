#ifndef SERVICIOSARCHIVO_H
#define SERVICIOSARCHIVO_H
#include "Servicio.h"

class ServiciosArchivo
{
    Servicio leer(int nroRegistro);
    bool leerTodos(Servicio servicios[], int cantidad);
    bool guardar(Servicio servicio);
    bool guardar(Servicio servicio, int nroRegistro);
    int getCantidad();
    int buscar(int codigo);
};

#endif // SERVICIOSARCHIVO_H
