#include "ClientesArchivo.h"

Cliente ClientesArchivo::leer(int nroRegistro)
{
  Cliente cliente;
  FILE* p;
  p = fopen("clientes.dat", "rb");
  if (p == NULL)
  {
    return cliente;
  }
  fseek(p, nroRegistro * sizeof(Cliente), SEEK_SET);
  fread(&cliente, sizeof(Cliente), 1, p);
  fclose(p);
  return cliente;
}

bool ClientesArchivo::leerTodos(Cliente clientes[], int cantidad)
{
  FILE* p;
  p = fopen("clientes.dat", "rb");
  if (p == NULL)
  {
    return false;
  }
  fread(clientes, sizeof(Cliente), cantidad, p);
  fclose(p);
  return true;
}

bool ClientesArchivo::guardar(Cliente cliente)
{
  FILE* p = fopen("clientes.dat", "ab");
  if (p == NULL)
  {
    return false;
  }
  bool ok = fwrite(&cliente, sizeof(Cliente), 1, p);
  fclose(p);
  return ok;
}

bool ClientesArchivo::guardar(Cliente cliente, int nroRegistro)
{
  FILE* p = fopen("clientes.dat", "rb+");
  if (p == NULL)
  {
    return false;
  }
  fseek(p, nroRegistro * sizeof(Cliente), SEEK_SET);
  bool ok = fwrite(&cliente, sizeof(Cliente), 1, p);
  fclose(p);
  return ok;
}

int ClientesArchivo::getCantidad()
{
  FILE* p = fopen("clientes.dat", "rb");
  if (p == NULL)
  {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof(Cliente);
  fclose(p);
  return cant;
}

int ClientesArchivo::buscar(int dni)
{
  int cant = getCantidad();
  Cliente cliente;
  for (int i = 0; i < cant; i++)
  {
    cliente = leer(i);
    if (cliente.getDni() == dni)
    {
      return i;
    }
  }
  return -1;
}
