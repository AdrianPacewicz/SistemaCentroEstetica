#ifndef CATEGORIA_H
#define CATEGORIA_H
#include <string>

using namespace std;

class Categoria
{
    private:
        int codigo;
        char nombre[50];
        bool estado;

    public:
        int getCodigo();
        string getNombre();
        bool getEstado();
        void setCodigo(int _codigo);
        void setNombre(string _nombre);
        void setEstado(bool _estado);
        void cargar();
        string toString();
};

#endif // CATEGORIA_H
