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
#include <ctime>

/*
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
*/

Fecha cargarFecha(Interfaz &interfaz){
    Fecha fecha;
    time_t rawtime;
    struct tm timeinfo;
    time (&rawtime);
    timeinfo = *(localtime (&rawtime));
    int diaActual = timeinfo.tm_mday;
    int mesActual = timeinfo.tm_mon + 1;
    int anioActual = timeinfo.tm_year + 1900;
    int valor;
    bool fechaValida;
    // TODO
    interfaz.siguienteLinea();
    do{
        interfaz.borrarLineaActual(false);
        cout<<"Anio: ";
        cin>>valor;
    }while(valor>=1900&&valor<=anioActual);
    fecha.setAnio(valor);
    interfaz.siguienteLinea();
    do{
        fechaValida = false;
        interfaz.borrarLineaActual(false);
        cout<<"Mes: ";
        cin>>valor;
        if(anioActual==fecha.getAnio()){
            if(valor>=1&&valor<=mesActual){
                fechaValida=true;
            }
        }
        else{
            if(valor>=1&&valor<=12){
                fechaValida=true;
            }
        }
    }while(!fechaValida);
    fecha.setMes(valor);

    ////////
    interfaz.siguienteLinea();
    do{
        fechaValida = false;
        interfaz.borrarLineaActual(false);
        cout<<"Dia: ";
        cin>>valor;
        // Si el año y el mes son los actuales valida contra la fecha de hoy
        if(anioActual==fecha.getAnio()&&mesActual==fecha.getMes()){
            if(valor>=1&&valor<=diaActual){
                fechaValida=true;
            }
        }
        // Sino valida por mes y calcula el bisiesto en caso de ser necesario
        else{
            switch(fecha.getMes()){
                // Meses de 31 dias
                case 1:
                    if(valor>=1&&valor<=31){
                        fechaValida=true;
                    }
                    break;
                case 3:
                    if(valor>=1&&valor<=31){
                        fechaValida=true;
                    }
                    break;
                case 5:
                    if(valor>=1&&valor<=31){
                        fechaValida=true;
                    }
                    break;
                case 7:
                    if(valor>=1&&valor<=31){
                        fechaValida=true;
                    }
                    break;
                case 8:
                    if(valor>=1&&valor<=31){
                        fechaValida=true;
                    }
                    break;
                case 10:
                    if(valor>=1&&valor<=31){
                        fechaValida=true;
                    }
                    break;
                case 12:
                    if(valor>=1&&valor<=31){
                        fechaValida=true;
                    }
                    break;
                // Meses de 30 dias
                case 4:
                    if(valor>=1&&valor<=30){
                        fechaValida=true;
                    }
                    break;
                case 6:
                    if(valor>=1&&valor<=30){
                        fechaValida=true;
                    }
                    break;
                case 9:
                    if(valor>=1&&valor<=30){
                        fechaValida=true;
                    }
                    break;
                case 11:
                    if(valor>=1&&valor<=30){
                        fechaValida=true;
                    }
                    break;
                // Febrero
                case 2:
                    if((fecha.getAnio()%4==0&&fecha.getAnio()%100!=0)||fecha.getAnio()%400==0){ // es bisiesto
                        if(valor>=1&&valor<=29){
                            fechaValida=true;
                        }
                    }
                    else{
                        if(valor>=1&&valor<=28){ // NO es bisiesto
                            fechaValida=true;
                        }
                    }
                    break;
            }
        }
    }while(!fechaValida);
    fecha.setDia(valor);
    return fecha;
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



