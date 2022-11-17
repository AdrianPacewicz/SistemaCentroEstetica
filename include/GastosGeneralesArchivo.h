#ifndef GASTOSGENERALESARCHIVO_H
#define GASTOSGENERALESARCHIVO_H
#include "GastoGeneral.h"

class GastosGeneralesArchivo
{
public:
    GastoGeneral leer(int nroRegistro);
    bool leerTodos(GastoGeneral gastosGenerales[], int cantidad);
    bool guardar(GastoGeneral gastoGeneral);
    bool guardar(GastoGeneral gastoGeneral, int nroRegistro);
    int getCantidad();
    int getCantidadActivos();
    int buscar(int id);

    bool importarCSV();
    bool exportarCSV();
    bool eliminarArchivoDAT();
};

#endif // GASTOSGENERALESARCHIVO_H
