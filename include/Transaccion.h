#ifndef TRANSACCION_H
#define TRANSACCION_H
#include "Fecha.h"

class Transaccion
{
    protected:
        int id;
        Fecha fecha;
        float importe;
        bool estado;

    public:
        int getId();
        Fecha getFecha();
        float getImporte();
        bool getEstado();
        void setId(int _id);
        void setFecha(Fecha _fecha);
        void setImporte(float _importe);
        void setEstado(bool _est);
        void cargar();
        string toString();
};

#endif // TRANSACCION_H
