#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <string>


class Interfaz {
private:
    int alto, ancho;
public:
    int getAlto();
    int getAncho();
    void setAlto(int a);
    void setAncho(int a);

    void maximizarVentana();
    void dibujarRectangulo(int x, int y, int alto, int ancho, int color);
    void dibujarRectangulo(int color);
    void dibujarLineaHorizontal(int y, int color);
    void dibujarLineaHorizontal(int y, int color, int desde, int hasta);
    void dibujarLineaVertical(int x, int color);
    void dibujarLineaVertical(int x, int color, int desde, int hasta);
    void dibujarMarco(int color);
    void borrarLinea(int y);
    void limpiarPantalla(int desde, int hasta);
    void cambiarTitulo(std::string texto);
    void mostrarTextoCentrado(std::string texto, int y);
    void cambiarMensaje(std::string texto, int color);
    char pedirOpcion();
    int pedirOpcionNumerica();
};

#endif // INTERFAZ_H
