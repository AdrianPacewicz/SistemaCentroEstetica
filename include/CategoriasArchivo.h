#ifndef CATEGORIASARCHIVO_H
#define CATEGORIASARCHIVO_H
#include "Categoria.h"

class CategoriasArchivo
{
public:
    Categoria leer(int nroRegistro);
    bool leerTodos(Categoria categorias[], int cantidad);
    bool guardar(Categoria categoria);
    bool guardar(Categoria categoria, int nroRegistro);
    int getCantidad();
    int buscar(int codigo);

    bool importarCSV();
    bool exportarCSV();
    bool eliminarCategoriasArchivo();
};

#endif // CATEGORIASARCHIVO_H
