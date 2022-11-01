#include "GastosGeneralesArchivo.h"

GastoGeneral GastosGeneralesArchivo::leer(int nroRegistro)
{
  GastoGeneral gastoGeneral;
  FILE* p;
  p = fopen("gastosGenerales.dat", "rb");
  if (p == NULL)
  {
    return gastoGeneral;
  }
  fseek(p, nroRegistro * sizeof(GastoGeneral), SEEK_SET);
  fread(&gastoGeneral, sizeof(GastoGeneral), 1, p);
  fclose(p);
  return gastoGeneral;
}

bool GastosGeneralesArchivo::leerTodos(GastoGeneral gastosGenerales[], int cantidad)
{
  FILE* p;
  p = fopen("gastosGenerales.dat", "rb");
  if (p == NULL)
  {
    return false;
  }
  fread(gastosGenerales, sizeof(GastoGeneral), cantidad, p);
  fclose(p);
  return true;
}

bool GastosGeneralesArchivo::guardar(GastoGeneral gastoGeneral)
{
  FILE* p = fopen("gastosGenerales.dat", "ab");
  if (p == NULL)
  {
    return false;
  }
  bool ok = fwrite(&gastoGeneral, sizeof(GastoGeneral), 1, p);
  fclose(p);
  return ok;
}

bool GastosGeneralesArchivo::guardar(GastoGeneral gastoGeneral, int nroRegistro)
{
  FILE* p = fopen("gastosGenerales.dat", "rb+");
  if (p == NULL)
  {
    return false;
  }
  fseek(p, nroRegistro * sizeof(GastoGeneral), SEEK_SET);
  bool ok = fwrite(&gastoGeneral, sizeof(GastoGeneral), 1, p);
  fclose(p);
  return ok;
}

int GastosGeneralesArchivo::getCantidad()
{
  FILE* p = fopen("gastosGenerales.dat", "rb");
  if (p == NULL)
  {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof(GastoGeneral);
  fclose(p);
  return cant;
}

int GastosGeneralesArchivo::buscar(int id)
{
  int cant = getCantidad();
  GastoGeneral gastoGeneral;
  for (int i = 0; i < cant; i++)
  {
    gastoGeneral = leer(i);
    if (gastoGeneral.getId() == id)
    {
      return i;
    }
  }
  return -1;
}
