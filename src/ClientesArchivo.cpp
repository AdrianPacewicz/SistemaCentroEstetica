#include "ClientesArchivo.h"
#include <iostream> // cout
#include <fstream>  // fstream importar CSV
#include <vector>   // vector importar CSV
#include <sstream>  // stringstream importar CSV
#include <stdio.h>  // remove .dat
#include <sys/stat.h> // stat verificar que existe archivo antes de eliminar

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

int ClientesArchivo::getCantidadActivos()
{
    Cliente obj;
    int cant = getCantidad();
    int cantActivos=0;
    for(int i=0; i<cant; i++){
        obj = leer(i);
        if(obj.getEstado())
            cantActivos++;
    }
    return cantActivos;
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

bool ClientesArchivo::importarCSV(){
    system("cls");
    string nomArchivo = "clientes.csv";
    int cantRegistros=0, cantCampos=6;
    Cliente cliente;

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
            for(int j=0;j<cantCampos;j++)
            {
                switch(j)
                {
                    case 0:
                        cliente.setDni(stoi(contenido[i][j]));
                        break;
                    case 1:
                        cliente.setNombre(contenido[i][j]);
                        break;
                    case 2:
                        cliente.setApellido(contenido[i][j]);
                        break;
                    case 3:
                        cliente.setTelefono(stoi(contenido[i][j]));
                        break;
                    case 4:
                        cliente.setEmail(contenido[i][j]);
                        break;
                    case 5:
                        cliente.setEstado(stoi(contenido[i][j]));
                        break;
                }
            }
            guardar(cliente);
        }
    }
    return true;
}

bool ClientesArchivo::exportarCSV(){
    system("cls");
    int cantidadClientes = getCantidad();
    Cliente* vecClientes = new Cliente[cantidadClientes];
    ofstream archivoCSV;
    archivoCSV.open("clientes.csv");
    if(!archivoCSV.is_open()){
        cout<<"No se pudo abrir el archivo CSV."<<endl;
        delete vecClientes;
        return false;
    }
    archivoCSV << "dni;nombre;apellido;telefono;email;estado" << endl;
    if(!leerTodos(vecClientes, cantidadClientes)){
        cout<<"No se pudo leer el archivo DAT."<<endl;
        archivoCSV.close();
        delete vecClientes;
        return false;
    }
    for(int i=0; i<cantidadClientes; i++){
        archivoCSV  << vecClientes[i].getDni() << ";"
                    << vecClientes[i].getNombre() << ";"
                    << vecClientes[i].getApellido() << ";"
                    << vecClientes[i].getTelefono() << ";"
                    << vecClientes[i].getEmail() << ";"
                    << vecClientes[i].getEstado() << endl;
    }
    archivoCSV.close();
    delete vecClientes;
    return true;
}

bool ClientesArchivo::eliminarArchivoDAT(){
    bool existe=false;
    int eliminado;
    struct stat buffer;
    existe = (stat ("clientes.dat", &buffer) == 0);
    if (!existe)
        eliminado=0;
    else{
        eliminado = remove("clientes.dat");
    }
    if(eliminado!=0)
        return false;
    return true;
}

