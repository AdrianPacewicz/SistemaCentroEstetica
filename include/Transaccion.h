#ifndef TRANSACCION_H
#define TRANSACCION_H
#include "Fecha.h"

class Transaccion
{
    protected:
        int id;
        Fecha fecha;
        double importe;
        bool estado;

    public:
        int getId();
        Fecha getFecha();
        double getImporte();
        bool getEstado();
        void setId(int _id);
        void setFecha(Fecha _fecha);
        void setImporte(double _importe);
        void setEstado(bool _est);
        void cargar();
        string toString();
};

#endif // TRANSACCION_H
