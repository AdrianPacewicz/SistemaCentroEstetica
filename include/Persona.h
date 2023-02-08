#ifndef PERSONA_H
#define PERSONA_H

#include <string>
using namespace std;

class Persona
{
    protected:
        int dni;
        char nombre[50];
        char apellido[50];
        char telefono[50];
        char email[50];
        bool estado;

    public:
        int getDni();
        string getNombre();
        string getApellido();
        string getTelefono();
        string getEmail();
        bool getEstado();

        void setDni(int _dni);
        void setNombre(string _nomb);
        void setApellido(string _apell);
        void setTelefono(string _tel);
        void setEmail(string _email);
        void setEstado(bool _est);

        void cargar();
        string toString();

};

#endif // PERSONA_H
