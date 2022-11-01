#include "ProveedoresArchivo.h"

Proveedor ProveedoresArchivo::leer(int nroRegistro)
{
  Proveedor proveedor;
  FILE* p;
  p = fopen("proveedores.dat", "rb");
  if (p == NULL)
  {
    return proveedor;
  }
  fseek(p, nroRegistro * sizeof(Proveedor), SEEK_SET);
  fread(&proveedor, sizeof(Proveedor), 1, p);
  fclose(p);
  return proveedor;
}

bool ProveedoresArchivo::leerTodos(Proveedor proveedores[], int cantidad)
{
  FILE* p;
  p = fopen("proveedores.dat", "rb");
  if (p == NULL)
  {
    return false;
  }
  fread(proveedores, sizeof(Proveedor), cantidad, p);
  fclose(p);
  return true;
}

bool ProveedoresArchivo::guardar(Proveedor proveedor)
{
  FILE* p = fopen("proveedores.dat", "ab");
  if (p == NULL)
  {
    return false;
  }
  bool ok = fwrite(&proveedor, sizeof(Proveedor), 1, p);
  fclose(p);
  return ok;
}

bool ProveedoresArchivo::guardar(Proveedor proveedor, int nroRegistro)
{
  FILE* p = fopen("proveedores.dat", "rb+");
  if (p == NULL)
  {
    return false;
  }
  fseek(p, nroRegistro * sizeof(Proveedor), SEEK_SET);
  bool ok = fwrite(&proveedor, sizeof(Proveedor), 1, p);
  fclose(p);
  return ok;
}

int ProveedoresArchivo::getCantidad()
{
  FILE* p = fopen("proveedores.dat", "rb");
  if (p == NULL)
  {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof(Proveedor);
  fclose(p);
  return cant;
}

int ProveedoresArchivo::buscar(int cuil)
{
  int cant = getCantidad();
  Proveedor proveedor;
  for (int i = 0; i < cant; i++)
  {
    proveedor = leer(i);
    if (proveedor.getCuil() == cuil)
    {
      return i;
    }
  }
  return -1;
}
