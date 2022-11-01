#ifndef VENTA_H
#define VENTA_H

#include "Transaccion.h"
#include <string>
using namespace std;

class Venta: public Transaccion
{
    private:
        int nEmpleado;
        int nCliente;
        int nServicio;
        char observacion[100];

    public:
        int getEmpleado();
        int getCliente();
        int getServicio();
        string getObs();

        void setEmpleado(int empleado);
        void setCliente(int cliente);
        void setServicio(int servicio);
        void setObs(string _observacion);
        void cargar();
        string toString();
};

#endif // VENTA_H
