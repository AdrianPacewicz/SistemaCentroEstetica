#include "Interfaz.h"
#include <iostream>
#include "rlutil.h"
#include "Windows.h"



int Interfaz::getAlto(){
    setAlto(rlutil::trows());
    return alto;
    }
int Interfaz::getAncho(){
    setAncho(rlutil::tcols());
    return ancho;
    }
int Interfaz::getFilaActual(){return filaActual;}
void Interfaz::setAlto(int a){alto=a;}
void Interfaz::setAncho(int a){ancho=a;}
void Interfaz::setFilaActual(int f){filaActual=f;}

void Interfaz::maximizarVentana(){
    ShowWindow( GetConsoleWindow() , SW_MAXIMIZE);
}

void Interfaz::dibujarRectangulo(int x, int y, int alto, int ancho, int color){
    rlutil::setColor(color);
    for (int i=x; i<=x+ancho; i++){
        rlutil::locate(i,y);
        cout << char(220);
        rlutil::locate(i,y+alto);
        cout << char(223);
    }
    for (int i=y+1; i<y+alto; i++){
        rlutil::locate(x,i);
        cout << char(219);
        rlutil::locate(x+ancho,i);
        cout << char(219);
    }
}

void Interfaz::dibujarRectangulo(int color){
    rlutil::setColor(color);
    int ancho,alto;
    ancho = rlutil::tcols();
    alto = rlutil::trows();
    for (int i=2; i<ancho; i++){
        rlutil::locate(i,2);
        cout << char(220);
        rlutil::locate(i,alto-1);
        cout << char(223);
    }
    for (int i=3; i<alto-1; i++){
        rlutil::locate(2,i);
        cout << char(219);
        rlutil::locate(ancho-1,i);
        cout << char(219);
    }
}

void Interfaz::dibujarLineaHorizontal(int y, int color){
    int ancho;
    ancho = rlutil::tcols()-1;
    rlutil::locate(2,y);
    rlutil::setColor(color);
    cout<<char(219);
    for(int i=3; i<ancho; i++){
        cout<<char(223);
    }
    cout<<char(219);
    rlutil::setColor(rlutil::WHITE);
}

void Interfaz::dibujarLineaHorizontal(int y, int color, int desde, int hasta){
    rlutil::locate(2,desde);
    rlutil::setColor(color);
    cout<<char(219);
    for(int i=desde+1; i<hasta; i++){
        cout<<char(223);
    }
    cout<<char(219);
    rlutil::setColor(rlutil::WHITE);
}

void Interfaz::dibujarLineaVertical(int x, int color){
    int alto;
    alto=rlutil::trows()-1;
    rlutil::setColor(color);
    for(int i=2; i<=alto; i++){
        rlutil::locate(x,i);
        cout<<char(219);
    }
    rlutil::setColor(rlutil::WHITE);
}

void Interfaz::dibujarLineaVertical(int x, int color, int desde, int hasta){
    rlutil::setColor(color);
    for(int i=desde; i<=hasta; i++){
        rlutil::locate(x,i);
        cout<<char(219);
    }
    rlutil::setColor(rlutil::WHITE);
}

void Interfaz::dibujarMarco(int color=1){
    int alto=rlutil::trows();
    dibujarRectangulo(color);
    dibujarLineaHorizontal(4,color);
    dibujarLineaHorizontal(alto-3,color);
}

// Metodo que borra el texto de toda una linea en la pantalla
void Interfaz::borrarLinea(int y, bool bordes=false){
    int ancho;
    ancho = rlutil::tcols();
    if(!bordes){
        rlutil::locate(3,y);
        for(int i = 3; i < ancho-1; i++){
            cout << " ";
        }
    }
    else{
        rlutil::locate(1,y);
        for(int i = 1; i <= ancho; i++){
            cout << " ";
        }
    }
}

// Metodo que borra el texto de toda la linea actual en la pantalla y posiciona el cursor al principio de la misma
void Interfaz::borrarLineaActual(bool bordes=false){
    int ancho;
    ancho = rlutil::tcols();
    if(!bordes){
        rlutil::locate(3,filaActual);
        for(int i = 3; i < ancho-1; i++){
            cout << " ";
        }
        rlutil::locate(5,filaActual);
    }
    else{
        rlutil::locate(1,filaActual);
        for(int i = 1; i <= ancho; i++){
            cout << " ";
        }
        rlutil::locate(5,filaActual);
    }
}

// Metodo que recibe dos filas (opcionales) y borra todas las filas intermedias
void Interfaz::limpiarPantalla(int desde=5, int hasta=0, bool bordes=false){
    if (hasta==0){
        if(bordes)
            hasta=rlutil::trows()-4;
        else
            hasta=rlutil::trows();
    }
    for(int i=desde; i<=hasta; i++){
        borrarLinea(i,bordes);
    }
}

// Metodo que cambia la cabecera del marco
void Interfaz::cambiarTitulo(string texto){
    int ancho, centro;
    borrarLinea(3);
    ancho = rlutil::tcols();
    centro = ancho/2 - texto.size()/2;
    rlutil::locate(centro,3);
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    cout << texto;
    rlutil::setColor(rlutil::WHITE);
}

// Metodo que recibe texto y la fila y lo muestra centrado
void Interfaz::mostrarTextoCentrado(string texto, int y){
    int ancho, centro;
    borrarLinea(y);
    ancho = rlutil::tcols();
    centro = ancho/2 - texto.size()/2;
    rlutil::locate(centro,y);
    cout << texto;
}

// Metodo que recibe texto+color y cambia el mensaje inferior de la pantalla con su color
void Interfaz::cambiarMensaje(string texto, int color){
    int yMensaje = rlutil::trows() -2;
    borrarLinea(yMensaje);
    rlutil::locate(4,yMensaje);
    rlutil::setColor(color);
    cout << texto;
    rlutil::setColor(rlutil::WHITE);
}

// Metodo que pide una opcion y devuelve el char correspondiente
char Interfaz::pedirOpcion(){
    int op;
    cambiarMensaje("Seleccione una opcion", rlutil::YELLOW);
    op = rlutil::getkey();
    return char(op);
}

int Interfaz::pedirOpcionNumerica(){
    int op;
    cambiarMensaje("Seleccione una opcion", rlutil::YELLOW);
    op = rlutil::getkey();
    if (op>=48 && op<=57){
        return op-48;
    }
    else
        return pedirOpcionNumerica();
}

void Interfaz::siguienteLinea(){
    filaActual++;
    rlutil::locate(5,filaActual);
}

void Interfaz::siguienteLinea(int col){
    filaActual++;
    rlutil::locate(col,filaActual);
}
