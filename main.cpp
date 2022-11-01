#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "rlutil.h"
#include "Menus.h"


int main(){
    srand(time(NULL));
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
        cout << "3 - Importar Categorias";

        rlutil::locate(centro-8, 9);
        cout << "4 - Exportar Categorias";

        rlutil::locate(centro-8, 10);
        cout << "5 - Listar Categorias";

        rlutil::locate(centro-4, 15);
        rlutil::setColor(rlutil::RED);
        cout << "0 - SALIR" << endl << endl;

        rlutil::setColor(rlutil::WHITE);

        cin >> opc;

        //--------------pregunta por la opcion elegida y se dirige a la funcion correspondiente---------------------------

    switch(opc)
    {
        case 1:
            system("cls");
            //VerMenu1();
            break;
        case 2:
            system("cls");

            break;
        case 3:
            ImportarCategorias();
            break;
        case 4:
            ExportarCategorias();
            break;
        case 5:
            ListarCategorias();
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


return 0;
}
