#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <string>

using namespace std;

class Interfaz {
private:
    int alto, ancho, filaActual=1;
public:
    int getAlto();
    int getAncho();
    int getFilaActual();
    void setAlto(int a);
    void setAncho(int a);
    void setFilaActual(int f);


    void maximizarVentana();
    void dibujarRectangulo(int x, int y, int alto, int ancho, int color);
    void dibujarRectangulo(int color);
    void dibujarLineaHorizontal(int y, int color);
    void dibujarLineaHorizontal(int y, int color, int desde, int hasta);
    void dibujarLineaVertical(int x, int color);
    void dibujarLineaVertical(int x, int color, int desde, int hasta);
    void dibujarMarco(int color);
    void borrarLinea(int y, bool bordes);
    void borrarLineaActual(bool bordes);
    void limpiarPantalla(int desde, int hasta, bool bordes);
    void cambiarTitulo(std::string texto);
    void mostrarTextoCentrado(std::string texto, int y);
    void cambiarMensaje(std::string texto, int color);
    char pedirOpcion();
    int pedirOpcionNumerica();
    void siguienteLinea();
    void siguienteLinea(int col);
};

#endif // INTERFAZ_H
