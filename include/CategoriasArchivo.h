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
    int getCantidadActivos();
    int buscar(int codigo);

    bool importarCSV();
    bool exportarCSV();
    bool eliminarArchivoDAT();
};

#endif // CATEGORIASARCHIVO_H
