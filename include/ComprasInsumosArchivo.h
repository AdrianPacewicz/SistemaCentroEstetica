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
    int buscar(int id);
};

#endif // COMPRASINSUMOSARCHIVO_H
