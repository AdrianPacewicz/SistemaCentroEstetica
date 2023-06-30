using namespace std;
#include <clocale> // librería necesaria para poder hacer "setlocale" y que tome caracteres en español
#include "rlutil.h"
#include "Interfaz.h"
#include "Menu.h"

// TODO: cambiar caracteres usados para los marcos (se rompió al agregar setlocale para tomar tildes)

int main(){
    // seteo LC_ALL para que tome tildes y Ñ
    // setlocale(LC_ALL, "");
    // oculto el cursor
    rlutil::hidecursor();
    Interfaz interfaz;
    Menu _menu(interfaz);
    interfaz.maximizarVentana();
    _menu.menuPrincipal();
return 0;
}
