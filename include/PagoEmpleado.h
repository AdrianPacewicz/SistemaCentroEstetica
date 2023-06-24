#ifndef PAGOEMPLEADO_H
#define PAGOEMPLEADO_H

#include <string>
#include "Transaccion.h"
#include "Interfaz.h"
#include "Funciones.h"
using namespace std;

class PagoEmpleado: public Transaccion
{
    private:
        int idEmpleado;
        char detalle[100];

    public:
        int getIdE();
        string getDetalle();
        void setIdE(int _idE);
        void setDetalle(string _detalle);
        bool cargar(Interfaz &interfaz);
        string toString();
};

#endif // PAGOEMPLEADO_H
