#ifndef COMPRASINSUMOSARCHIVO_H
#define COMPRASINSUMOSARCHIVO_H
#include "CompraInsumos.h"

class ComprasInsumosArchivo
{
    CompraInsumos leer(int nroRegistro);
    bool leerTodos(CompraInsumos comprasInsumos[], int cantidad);
    bool guardar(CompraInsumos compraInsumos);
    bool guardar(CompraInsumos compraInsumos, int nroRegistro);
    int getCantidad();
    int getCantidadActivos();
    int buscar(int id);

    bool importarCSV();
    bool exportarCSV();
    bool eliminarArchivoDAT();
};

#endif // COMPRASINSUMOSARCHIVO_H
