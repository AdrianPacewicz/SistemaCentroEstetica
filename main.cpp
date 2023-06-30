using namespace std;
#include <clocale> // librer�a necesaria para poder hacer "setlocale" y que tome caracteres en espa�ol
#include "rlutil.h"
#include "Interfaz.h"
#include "Menu.h"

// TODO: cambiar caracteres usados para los marcos (se rompi� al agregar setlocale para tomar tildes)

int main(){
    // seteo LC_ALL para que tome tildes y �
    // setlocale(LC_ALL, "");
    // oculto el cursor
    rlutil::hidecursor();
    Interfaz interfaz;
    Menu _menu(interfaz);
    interfaz.maximizarVentana();
    _menu.menuPrincipal();
return 0;
}
