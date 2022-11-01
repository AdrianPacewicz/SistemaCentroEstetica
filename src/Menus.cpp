#include <iostream>
#include <fstream>

using namespace std;

#include "rlutil.h"
#include "Menus.h"
#include "CategoriasArchivo.h"

void VerMenu1()
{
    int opc;

    do{
        system("cls");
        int centro = rlutil::tcols()/2;
        rlutil::locate(centro-7, 2);
        rlutil::setColor(rlutil::CYAN);
        cout << "SISTEMA FIRULI3000";

        rlutil::locate(centro-10, 3);
        cout << "____________________";

        rlutil::locate(centro-8, 6);
        rlutil::setColor(rlutil::WHITE);
        cout << "1 - INGRESAR TRANSACCION";

        rlutil::locate(centro-8, 7);
        cout << "2 - INGRESAR/MODIFICAR DATOS";

        rlutil::locate(centro-8, 8);
        cout << "3 - ";

        rlutil::locate(centro-4, 10);
        rlutil::setColor(rlutil::RED);
        cout << "0 - SALIR" << endl << endl;

        rlutil::setColor(rlutil::WHITE);

        cin >> opc;

        //--------------pregunta por la opcion elegida y se dirige a la funcion correspondiente---------------------------

    switch(opc)
    {
        case 1:
            system("cls");
            VerMenu1();
        break;

        case 2:
            system("cls");

        break;

        case 3:

        break;

        case 0:
            if(!SalirDelJuego())
            {
                opc=-1;
            }
        break;

        default: cout << "Ingrese una opcion disponible";
        break;
    }

    }while(opc != 0);
    /*int opc;

    cout << "SISTEMA FIRULI 3000" << endl;

    cout << "-----------------------------" << endl <<endl;

    cout << "1 - INGRESAR VENTA" << endl <<endl;
    cout << "2 - INGRESAR GASTO" << endl <<endl;

    cout << "0 - VOLVER AL MENU" << endl <<endl;

    switch(opc)
    {
        case 1:
            system("cls");
        break;

        case 2:
            system("cls");
        break;

        case 0:
            system("cls");
        break;

    }*/
}


/*Funcion para salir del juego luego de pedir confirmacion*/
bool SalirDelJuego()
{
    char respuesta;

    cout << "Esta seguro/a de querer salir?" << endl << "S/N";

    cin >> respuesta;

    if(respuesta == 's' || respuesta == 'S')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void ExportarCategorias(){
    CategoriasArchivo ca;
    if (ca.exportarCSV())
    {
        cout<<"Categorias exportadas con exito."<<endl;
    }
    else
    {
        cout<<"Error al exportar categorias"<<endl;
    }
    system("pause");
}

void ImportarCategorias(){
    CategoriasArchivo ca;
    if (ca.importarCSV())
    {
        cout<<"Categorias importadas con exito."<<endl;
    }
    else
    {
        cout<<"Error al importar categorias"<<endl;
    }
    system("pause");
}

void ListarCategorias(){
    CategoriasArchivo ca;
    int cantCategorias = ca.getCantidad();
    Categoria *vCategorias = new Categoria[cantCategorias];
    system("cls");
    ca.leerTodos(vCategorias, cantCategorias);
    for(int i=0; i<cantCategorias; i++){
        if(vCategorias[i].getEstado()){
            cout<<vCategorias[i].toString()<<endl;
        }
    }
    cout<<endl;
    system("pause");
}
