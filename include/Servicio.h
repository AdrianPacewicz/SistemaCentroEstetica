#ifndef SERVICIO_H
#define SERVICIO_H

#include <string>
#include "Funciones.h"
using namespace std;

class Servicio
{
    private:
        int codigo;
        char nombre[50];
        double valor;
        int codCategoria;
        bool estado;

    public:
        int getCodigo();
        string getNombre();
        double getValor();
        int getCodCategoria();
        bool getEstado();
        void setCodigo(int _codigo);
        void setNombre(string _nombre);
        void setValor(double _valor);
        void setCodCategoria(int _codCateg);
        void setEstado(bool _estado);

        bool cargar();
        string toString();

};

#endif // SERVICIO_H
