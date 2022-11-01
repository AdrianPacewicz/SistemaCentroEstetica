#include "ServiciosArchivo.h"

Servicio ServiciosArchivo::leer(int nroRegistro)
{
  Servicio servicio;
  FILE* p;
  p = fopen("servicios.dat", "rb");
  if (p == NULL)
  {
    return servicio;
  }
  fseek(p, nroRegistro * sizeof(Servicio), SEEK_SET);
  fread(&servicio, sizeof(Servicio), 1, p);
  fclose(p);
  return servicio;
}

bool ServiciosArchivo::leerTodos(Servicio servicios[], int cantidad)
{
  FILE* p;
  p = fopen("servicios.dat", "rb");
  if (p == NULL)
  {
    return false;
  }
  fread(servicios, sizeof(Servicio), cantidad, p);
  fclose(p);
  return true;
}

bool ServiciosArchivo::guardar(Servicio servicio)
{
  FILE* p = fopen("servicios.dat", "ab");
  if (p == NULL)
  {
    return false;
  }
  bool ok = fwrite(&servicio, sizeof(Servicio), 1, p);
  fclose(p);
  return ok;
}

bool ServiciosArchivo::guardar(Servicio servicio, int nroRegistro)
{
  FILE* p = fopen("servicios.dat", "rb+");
  if (p == NULL)
  {
    return false;
  }
  fseek(p, nroRegistro * sizeof(Servicio), SEEK_SET);
  bool ok = fwrite(&servicio, sizeof(Servicio), 1, p);
  fclose(p);
  return ok;
}

int ServiciosArchivo::getCantidad()
{
  FILE* p = fopen("servicios.dat", "rb");
  if (p == NULL)
  {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof(Servicio);
  fclose(p);
  return cant;
}

int ServiciosArchivo::buscar(int codigo)
{
  int cant = getCantidad();
  Servicio servicio;
  for (int i = 0; i < cant; i++)
  {
    servicio = leer(i);
    if (servicio.getCodigo() == codigo)
    {
      return i;
    }
  }
  return -1;
}
