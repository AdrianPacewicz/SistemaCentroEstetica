#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "Persona.h"

class Empleado: public Persona
{
    private:
        float PorcentajeComision;
        float SueldoFijo;

    public:
        float getPComision();
        float getSueldoF();
        void setPComision(float _PCom);
        void setSueldoF(float _SueldoF);
        void cargar();
        string toString();
};

#endif // EMPLEADO_H
