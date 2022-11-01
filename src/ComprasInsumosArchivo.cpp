#include "ComprasInsumosArchivo.h"

CompraInsumos ComprasInsumosArchivo::leer(int nroRegistro)
{
  CompraInsumos compraInsumos;
  FILE* p;
  p = fopen("compraInsumoss.dat", "rb");
  if (p == NULL)
  {
    return compraInsumos;
  }
  fseek(p, nroRegistro * sizeof(CompraInsumos), SEEK_SET);
  fread(&compraInsumos, sizeof(CompraInsumos), 1, p);
  fclose(p);
  return compraInsumos;
}

bool ComprasInsumosArchivo::leerTodos(CompraInsumos compraInsumoss[], int cantidad)
{
  FILE* p;
  p = fopen("compraInsumoss.dat", "rb");
  if (p == NULL)
  {
    return false;
  }
  fread(compraInsumoss, sizeof(CompraInsumos), cantidad, p);
  fclose(p);
  return true;
}

bool ComprasInsumosArchivo::guardar(CompraInsumos compraInsumos)
{
  FILE* p = fopen("compraInsumoss.dat", "ab");
  if (p == NULL)
  {
    return false;
  }
  bool ok = fwrite(&compraInsumos, sizeof(CompraInsumos), 1, p);
  fclose(p);
  return ok;
}

bool ComprasInsumosArchivo::guardar(CompraInsumos compraInsumos, int nroRegistro)
{
  FILE* p = fopen("compraInsumoss.dat", "rb+");
  if (p == NULL)
  {
    return false;
  }
  fseek(p, nroRegistro * sizeof(CompraInsumos), SEEK_SET);
  bool ok = fwrite(&compraInsumos, sizeof(CompraInsumos), 1, p);
  fclose(p);
  return ok;
}

int ComprasInsumosArchivo::getCantidad()
{
  FILE* p = fopen("compraInsumoss.dat", "rb");
  if (p == NULL)
  {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof(CompraInsumos);
  fclose(p);
  return cant;
}

int ComprasInsumosArchivo::buscar(int id)
{
  int cant = getCantidad();
  CompraInsumos compraInsumos;
  for (int i = 0; i < cant; i++)
  {
    compraInsumos = leer(i);
    if (compraInsumos.getId() == id)
    {
      return i;
    }
  }
  return -1;
}

