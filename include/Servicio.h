#ifndef SERVICIO_H
#define SERVICIO_H

#include <string>
using namespace std;

class Servicio
{
    private:
        int codigo;
        char nombre[50];
        float valor;
        int codCategoria;
        bool estado;

    public:
        int getCodigo();
        string getNombre();
        float getValor();
        int getCodCategoria();
        bool getEstado();
        void setCodigo(int _codigo);
        void setNombre(string _nombre);
        void setValor(float _valor);
        void setCodCategoria(int _codCateg);
        void setEstado(bool _estado);

        bool cargar();
        string toString();

};

#endif // SERVICIO_H
