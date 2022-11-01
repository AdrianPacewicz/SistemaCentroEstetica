#include "PagosEmpleadosArchivo.h"

PagoEmpleado PagosEmpleadosArchivo::leer(int nroRegistro)
{
  PagoEmpleado pagoEmpleado;
  FILE* p;
  p = fopen("pagosEmpleados.dat", "rb");
  if (p == NULL)
  {
    return pagoEmpleado;
  }
  fseek(p, nroRegistro * sizeof(PagoEmpleado), SEEK_SET);
  fread(&pagoEmpleado, sizeof(PagoEmpleado), 1, p);
  fclose(p);
  return pagoEmpleado;
}

bool PagosEmpleadosArchivo::leerTodos(PagoEmpleado pagosEmpleados[], int cantidad)
{
  FILE* p;
  p = fopen("pagosEmpleados.dat", "rb");
  if (p == NULL)
  {
    return false;
  }
  fread(pagosEmpleados, sizeof(PagoEmpleado), cantidad, p);
  fclose(p);
  return true;
}

bool PagosEmpleadosArchivo::guardar(PagoEmpleado pagoEmpleado)
{
  FILE* p = fopen("pagosEmpleados.dat", "ab");
  if (p == NULL)
  {
    return false;
  }
  bool ok = fwrite(&pagoEmpleado, sizeof(PagoEmpleado), 1, p);
  fclose(p);
  return ok;
}

bool PagosEmpleadosArchivo::guardar(PagoEmpleado pagoEmpleado, int nroRegistro)
{
  FILE* p = fopen("pagosEmpleados.dat", "rb+");
  if (p == NULL)
  {
    return false;
  }
  fseek(p, nroRegistro * sizeof(PagoEmpleado), SEEK_SET);
  bool ok = fwrite(&pagoEmpleado, sizeof(PagoEmpleado), 1, p);
  fclose(p);
  return ok;
}

int PagosEmpleadosArchivo::getCantidad()
{
  FILE* p = fopen("pagosEmpleados.dat", "rb");
  if (p == NULL)
  {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof(PagoEmpleado);
  fclose(p);
  return cant;
}

int PagosEmpleadosArchivo::buscar(int id)
{
  int cant = getCantidad();
  PagoEmpleado pagoEmpleado;
  for (int i = 0; i < cant; i++)
  {
    pagoEmpleado = leer(i);
    if (pagoEmpleado.getId() == id)
    {
      return i;
    }
  }
  return -1;
}
