#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "Persona.h"
#include "Funciones.h"

class Empleado: public Persona
{
    private:
        double porcentajeComision;
        double sueldoFijo;

    public:
        double getPComision();
        double getSueldoF();
        void setPComision(double _PCom);
        void setSueldoF(double _SueldoF);
        void cargar();
        string toString();
};

#endif // EMPLEADO_H
