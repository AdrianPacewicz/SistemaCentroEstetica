#ifndef PROVEEDOR_H
#define PROVEEDOR_H

#include <string>
using namespace std;

class Proveedor
{
    private:
        int cuil;
        char razonSocial[50];
        int codCategoria;
        int telefono;
        char email[50];
        bool estado;

    public:
        int getCuil();
        string getRazonS();
        int getCodCategoria();
        int getTelefono();
        string getEmail();
        bool getEstado();

        void setCuil(int _cuil);
        void setRazonSocial(string _razonSocial);
        void setCodCategoria(int _codCategoria);
        void setTelefono(int _telefono);
        void setEmail(string _email);
        void setEstado(bool _estado);

        void cargar();
        string toString();

};

#endif // PROVEEDOR_H
