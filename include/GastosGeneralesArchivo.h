#ifndef GASTOSGENERALESARCHIVO_H
#define GASTOSGENERALESARCHIVO_H
#include "GastoGeneral.h"

class GastosGeneralesArchivo
{
    GastoGeneral leer(int nroRegistro);
    bool leerTodos(GastoGeneral gastosGenerales[], int cantidad);
    bool guardar(GastoGeneral gastoGeneral);
    bool guardar(GastoGeneral gastoGeneral, int nroRegistro);
    int getCantidad();
    int buscar(int id);
};

#endif // GASTOSGENERALESARCHIVO_H
