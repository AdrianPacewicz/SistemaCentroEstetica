#include "EmpleadosArchivo.h"

Empleado EmpleadosArchivo::leer(int nroRegistro)
{
  Empleado empleado;
  FILE* p;
  p = fopen("empleados.dat", "rb");
  if (p == NULL)
  {
    return empleado;
  }
  fseek(p, nroRegistro * sizeof(Empleado), SEEK_SET);
  fread(&empleado, sizeof(Empleado), 1, p);
  fclose(p);
  return empleado;
}

bool EmpleadosArchivo::leerTodos(Empleado empleados[], int cantidad)
{
  FILE* p;
  p = fopen("empleados.dat", "rb");
  if (p == NULL)
  {
    return false;
  }
  fread(empleados, sizeof(Empleado), cantidad, p);
  fclose(p);
  return true;
}

bool EmpleadosArchivo::guardar(Empleado empleado)
{
  FILE* p = fopen("empleados.dat", "ab");
  if (p == NULL)
  {
    return false;
  }
  bool ok = fwrite(&empleado, sizeof(Empleado), 1, p);
  fclose(p);
  return ok;
}

bool EmpleadosArchivo::guardar(Empleado empleado, int nroRegistro)
{
  FILE* p = fopen("empleados.dat", "rb+");
  if (p == NULL)
  {
    return false;
  }
  fseek(p, nroRegistro * sizeof(Empleado), SEEK_SET);
  bool ok = fwrite(&empleado, sizeof(Empleado), 1, p);
  fclose(p);
  return ok;
}

int EmpleadosArchivo::getCantidad()
{
  FILE* p = fopen("empleados.dat", "rb");
  if (p == NULL)
  {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof(Empleado);
  fclose(p);
  return cant;
}

int EmpleadosArchivo::buscar(int dni)
{
  int cant = getCantidad();
  Empleado empleado;
  for (int i = 0; i < cant; i++)
  {
    empleado = leer(i);
    if (empleado.getDni() == dni)
    {
      return i;
    }
  }
  return -1;
}
