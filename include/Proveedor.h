#ifndef PROVEEDOR_H
#define PROVEEDOR_H

#include <string>
using namespace std;

class Proveedor
{
    private:
        char cuil[50];
        char razonSocial[50];
        int codCategoria;
        char telefono[50];
        char email[50];
        bool estado;

    public:
        string getCuil();
        string getRazonS();
        int getCodCategoria();
        string getTelefono();
        string getEmail();
        bool getEstado();

        void setCuil(string _cuil);
        void setRazonSocial(string _razonSocial);
        void setCodCategoria(int _codCategoria);
        void setTelefono(string _telefono);
        void setEmail(string _email);
        void setEstado(bool _estado);

        bool cargar();
        string toString();

};

#endif // PROVEEDOR_H
