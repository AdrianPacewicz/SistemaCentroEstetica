using namespace std;

#include "rlutil.h"
#include "Menus.h"
#include "Interfaz.h"
#include "Menu.h"

int main(){
    rlutil::hidecursor();
    Interfaz interfaz;
    Menu _menu(interfaz);
    interfaz.maximizarVentana();
    _menu.menuPrincipal();
    //menuPrincipal(interfaz);

return 0;
}
