#include "Funciones.h"
#include "rlutil.h"
#include "CategoriasArchivo.h"
#include "ClientesArchivo.h"
#include "ComprasInsumosArchivo.h"
#include "EmpleadosArchivo.h"
#include "GastosGeneralesArchivo.h"
#include "PagosEmpleadosArchivo.h"
#include "ProveedoresArchivo.h"
#include "ServiciosArchivo.h"
#include "VentasArchivo.h"

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

void importar(int opcion){
    CategoriasArchivo cA;
    ClientesArchivo clA;
    ComprasInsumosArchivo ciA;
    EmpleadosArchivo eA;
    GastosGeneralesArchivo ggA;
    PagosEmpleadosArchivo peA;
    ProveedoresArchivo pA;
    ServiciosArchivo sA;
    VentasArchivo vA;
    switch(opcion){
    case 1:
        if (cA.importarCSV())
            cout<<"Categorias importadas con exito."<<endl;
        else
            cout<<"Error al importar categorias."<<endl;
        break;
    case 2:
        if (clA.importarCSV())
            cout<<"Clientes importadas con exito."<<endl;
        else
            cout<<"Error al importar clientes."<<endl;
        break;
    case 3:
        if (ciA.importarCSV())
            cout<<"Compras de insumos importadas con exito."<<endl;
        else
            cout<<"Error al importar compras de insumos."<<endl;
        break;
    case 4:
        if (eA.importarCSV())
            cout<<"Empleados importados con exito."<<endl;
        else
            cout<<"Error al importar empleados."<<endl;
        break;
    case 5:
        if (ggA.importarCSV())
            cout<<"Gastos generales importados con exito."<<endl;
        else
            cout<<"Error al importar gastos generales."<<endl;
        break;
    case 6:
        if (peA.importarCSV())
            cout<<"Pagos de empleados importados con exito."<<endl;
        else
            cout<<"Error al importar pagos de empleados."<<endl;
        break;
    case 7:
        if (pA.importarCSV())
            cout<<"Proveedores importados con exito."<<endl;
        else
            cout<<"Error al importar proveedores."<<endl;
        break;
    case 8:
        if (sA.importarCSV())
            cout<<"Servicios importados con exito."<<endl;
        else
            cout<<"Error al importar servicios."<<endl;
        break;
    case 9:
        if (vA.importarCSV())
            cout<<"Ventas importadas con exito."<<endl;
        else
            cout<<"Error al importar ventas."<<endl;
        break;
    }
    rlutil::anykey();
}

void exportar(int opcion){
    CategoriasArchivo cA;
    ClientesArchivo clA;
    ComprasInsumosArchivo ciA;
    EmpleadosArchivo eA;
    GastosGeneralesArchivo ggA;
    PagosEmpleadosArchivo peA;
    ProveedoresArchivo pA;
    ServiciosArchivo sA;
    VentasArchivo vA;
    switch(opcion){
    case 1:
        if (cA.exportarCSV())
            cout<<"Categorias exportadas con exito."<<endl;
        else
            cout<<"Error al exportar categorias."<<endl;
        break;
    case 2:
        if (clA.exportarCSV())
            cout<<"Clientes exportadas con exito."<<endl;
        else
            cout<<"Error al exportar clientes."<<endl;
        break;
    case 3:
        if (ciA.exportarCSV())
            cout<<"Compras de insumos exportadas con exito."<<endl;
        else
            cout<<"Error al exportar compras de insumos."<<endl;
        break;
    case 4:
        if (eA.exportarCSV())
            cout<<"Empleados exportados con exito."<<endl;
        else
            cout<<"Error al exportar empleados."<<endl;
        break;
    case 5:
        if (ggA.exportarCSV())
            cout<<"Gastos generales exportados con exito."<<endl;
        else
            cout<<"Error al exportar gastos generales."<<endl;
        break;
    case 6:
        if (peA.exportarCSV())
            cout<<"Pagos de empleados exportados con exito."<<endl;
        else
            cout<<"Error al exportar pagos de empleados."<<endl;
        break;
    case 7:
        if (pA.exportarCSV())
            cout<<"Proveedores exportados con exito."<<endl;
        else
            cout<<"Error al exportar proveedores."<<endl;
        break;
    case 8:
        if (sA.exportarCSV())
            cout<<"Servicios exportados con exito."<<endl;
        else
            cout<<"Error al exportar servicios."<<endl;
        break;
    case 9:
        if (vA.exportarCSV())
            cout<<"Ventas exportadas con exito."<<endl;
        else
            cout<<"Error al exportar ventas."<<endl;
        break;
    }
    rlutil::anykey();
}



