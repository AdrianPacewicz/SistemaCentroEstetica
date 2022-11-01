#include "VentasArchivo.h"

Venta VentasArchivo::leer(int nroRegistro)
{
  Venta venta;
  FILE* p;
  p = fopen("ventas.dat", "rb");
  if (p == NULL)
  {
    return venta;
  }
  fseek(p, nroRegistro * sizeof(Venta), SEEK_SET);
  fread(&venta, sizeof(Venta), 1, p);
  fclose(p);
  return venta;
}

bool VentasArchivo::leerTodos(Venta ventas[], int cantidad)
{
  FILE* p;
  p = fopen("ventas.dat", "rb");
  if (p == NULL)
  {
    return false;
  }
  fread(ventas, sizeof(Venta), cantidad, p);
  fclose(p);
  return true;
}

bool VentasArchivo::guardar(Venta venta)
{
  FILE* p = fopen("ventas.dat", "ab");
  if (p == NULL)
  {
    return false;
  }
  bool ok = fwrite(&venta, sizeof(Venta), 1, p);
  fclose(p);
  return ok;
}

bool VentasArchivo::guardar(Venta venta, int nroRegistro)
{
  FILE* p = fopen("ventas.dat", "rb+");
  if (p == NULL)
  {
    return false;
  }
  fseek(p, nroRegistro * sizeof(Venta), SEEK_SET);
  bool ok = fwrite(&venta, sizeof(Venta), 1, p);
  fclose(p);
  return ok;
}

int VentasArchivo::getCantidad()
{
  FILE* p = fopen("ventas.dat", "rb");
  if (p == NULL)
  {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof(Venta);
  fclose(p);
  return cant;
}

int VentasArchivo::buscar(int id)
{
  int cant = getCantidad();
  Venta venta;
  for (int i = 0; i < cant; i++)
  {
    venta = leer(i);
    if (venta.getId() == id)
    {
      return i;
    }
  }
  return -1;
}
