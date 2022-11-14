#include "Funciones.h"
#include "rlutil.h"
#include "CategoriasArchivo.h"
#include "EmpleadosArchivo.h"

void mostrarEmpleados(int y=8, int pag=0, int cantPag=0){
    EmpleadosArchivo archivo;
    int opc=0;
    int cantidadRegistros = archivo.getCantidad();
    Empleado *vec = new Empleado[cantidadRegistros];
    if (vec==NULL){
        return;
    }
    archivo.leerTodos(vec,cantidadRegistros);
    for(int i=0; i<cantidadRegistros; i++){
        if(vec[i].getEstado()){
            rlutil::locate(5,y+opc);
            cout<<"["<<opc<<"]/t"<<vec[i].getNombre()<<" "<<vec[i].getApellido();
            opc++;
        }
    }
    if(pag<cantPag){
        rlutil::locate(5,y+opc+1);
        cout<< "[9] Ver mas >>";
    }
    delete []vec;
}

void mostrarCategorias(int y=8, int pag=0, int cantPag=0){
    CategoriasArchivo archivo;
    int opc=0;
    int cantidadRegistros = archivo.getCantidad();
    Categoria *vec = new Categoria[cantidadRegistros];
    if (vec==NULL){
        return;
    }
    archivo.leerTodos(vec,cantidadRegistros);
    for(int i=0; i<cantidadRegistros; i++){
        if(vec[i].getEstado()){
            rlutil::locate(5,y+opc);
            cout<<"["<<opc<<"]/t"<<vec[i].getNombre();
            opc++;
        }
    }
    if(pag<cantPag){
        rlutil::locate(5,y+opc+1);
        cout<< "[9] Ver mas >>";
    }
    delete []vec;
}

void mostrarServicios(int y=8){

}

