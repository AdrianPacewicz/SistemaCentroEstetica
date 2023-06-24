#include "ComprasInsumosArchivo.h"
#include <iostream> // cout
#include <fstream>  // fstream importar CSV
#include <vector>   // vector importar CSV
#include <sstream>  // stringstream importar CSV
#include <stdio.h>  // remove .dat
#include <sys/stat.h> // stat verificar que existe archivo antes de eliminar
#include <iomanip>

CompraInsumos ComprasInsumosArchivo::leer(int nroRegistro)
{
    CompraInsumos compraInsumos;
    FILE* p;
    p = fopen("compraInsumos.dat", "rb");
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
    p = fopen("compraInsumos.dat", "rb");
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
    FILE* p = fopen("compraInsumos.dat", "ab");
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
    FILE* p = fopen("compraInsumos.dat", "rb+");
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
    FILE* p = fopen("compraInsumos.dat", "rb");
    if (p == NULL)
    {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int cant = ftell(p) / sizeof(CompraInsumos);
    fclose(p);
    return cant;
}

int ComprasInsumosArchivo::getCantidadActivos()
{
    CompraInsumos obj;
    int cant = getCantidad();
    int cantActivos=0;
    for(int i=0; i<cant; i++){
        obj = leer(i);
        if(obj.getEstado())
            cantActivos++;
    }
    return cantActivos;
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

bool ComprasInsumosArchivo::importarCSV(){
    system("cls");
    string nomArchivo = "compraInsumos.csv";
    int cantRegistros=0, cantCampos=10;
    CompraInsumos compraInsumos;

    vector<vector<string>> contenido;
    vector<string> fila;
    string registro, campo;

    fstream file (nomArchivo, ios::in);
    if(file.is_open())
    {
        while(getline(file, registro))
        {
            fila.clear();
            stringstream str(registro);

            while(getline(str, campo, ';'))
                fila.push_back(campo);
            contenido.push_back(fila);
        }
    }
    else
    {
        cout<<"No se pudo abrir el archivo CSV."<<endl;
        return false;
    }


    cantRegistros = contenido.size();

    if (!eliminarArchivoDAT()){
        cout<<"Error al eliminar el archivo .DAT!"<<endl;
        return false;
    }

    for(int i=0;i<cantRegistros;i++)
    {
        if (i!=0){
            Fecha f;
            for(int j=0;j<cantCampos;j++)
            {
                switch(j)
                {
                    /*
                    int id;
                    Fecha fecha;
                        anio
                        mes
                        dia
                    double importe;
                    bool estado;
                    char cuilProveedor[50];
                    char detalle[100];
                    int cantidad;
                    double precioUnitario;
                    */
                    case 0:
                        compraInsumos.setId(stoi(contenido[i][j]));
                        break;
                    case 1:
                        f.setAnio(stoi(contenido[i][j]));
                        break;
                    case 2:
                        f.setMes(stoi(contenido[i][j]));
                        break;
                    case 3:
                        f.setDia(stoi(contenido[i][j]));
                        compraInsumos.setFecha(f);
                        break;
                    case 4:
                        compraInsumos.setImporte(stod(contenido[i][j]));
                        break;
                    case 5:
                        compraInsumos.setEstado(stoi(contenido[i][j]));
                        break;
                    case 6:
                        compraInsumos.setProv(contenido[i][j]);
                        break;
                    case 7:
                        compraInsumos.setDetalle(contenido[i][j]);
                        break;
                    case 8:
                        compraInsumos.setCantidad(stoi(contenido[i][j]));
                        break;
                    case 9:
                        compraInsumos.setPrecioU(stod(contenido[i][j]));
                        break;
                }
            }
            guardar(compraInsumos);
        }
    }
    return true;
}

bool ComprasInsumosArchivo::exportarCSV(){
    system("cls");
    int cantidadCompraInsumos = getCantidad();
    CompraInsumos* vecCompraInsumos = new CompraInsumos[cantidadCompraInsumos];
    ofstream archivoCSV;
    archivoCSV.open("compraInsumos.csv");
    if(!archivoCSV.is_open()){
        cout<<"No se pudo abrir el archivo CSV."<<endl;
        delete vecCompraInsumos;
        return false;
    }
    archivoCSV << "id;anio;mes;dia;importe;estado;cuilProv;detalle;cantidad;precioUni" << endl;
    if(!leerTodos(vecCompraInsumos, cantidadCompraInsumos)){
        cout<<"No se pudo leer el archivo DAT."<<endl;
        archivoCSV.close();
        delete vecCompraInsumos;
        return false;
    }
    for(int i=0; i<cantidadCompraInsumos; i++){
        archivoCSV  << vecCompraInsumos[i].getId() << ";"
                    << vecCompraInsumos[i].getFecha().getAnio() << ";"
                    << vecCompraInsumos[i].getFecha().getMes() << ";"
                    << vecCompraInsumos[i].getFecha().getDia()  << ";"
                    << fixed << setprecision(2) << vecCompraInsumos[i].getImporte() << ";"
                    << vecCompraInsumos[i].getEstado() << ";"
                    << vecCompraInsumos[i].getProv() << ";"
                    << vecCompraInsumos[i].getDetalle() << ";"
                    << vecCompraInsumos[i].getCantidad() << ";"
                    << vecCompraInsumos[i].getPrecioU() << endl;
    }
    archivoCSV.close();
    delete vecCompraInsumos;
    return true;
}

bool ComprasInsumosArchivo::eliminarArchivoDAT(){
        bool existe=false;
    int eliminado;
    struct stat buffer;
    existe = (stat ("compraInsumos.dat", &buffer) == 0);
    if (!existe)
        eliminado=0;
    else{
        eliminado = remove("compraInsumos.dat");
    }
    if(eliminado!=0)
        return false;
    return true;
}
