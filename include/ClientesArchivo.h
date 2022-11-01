#ifndef CLIENTESARCHIVO_H
#define CLIENTESARCHIVO_H
#include "Cliente.h"

class ClientesArchivo
{
public:
    Cliente leer(int nroRegistro);
    bool leerTodos(Cliente clientes[], int cantidad);
    bool guardar(Cliente cliente);
    bool guardar(Cliente cliente, int nroRegistro);
    int getCantidad();
    int buscar(int dni);
};

#endif // CLIENTESARCHIVO_H
