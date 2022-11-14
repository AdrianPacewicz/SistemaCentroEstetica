using namespace std;

#include "rlutil.h"
#include "Menus.h"
#include "Interfaz.h"

int main(){
    rlutil::hidecursor();
    Interfaz interfaz;
    interfaz.maximizarVentana();
    menuPrincipal(interfaz);
return 0;
}
