#ifndef GASTOGENERAL_H
#define GASTOGENERAL_H

#include <string>
#include "Transaccion.h"
#include "Interfaz.h"
using namespace std;

class GastoGeneral: public Transaccion
{
    private:
        char detalle[100];

    public:
        string getDetalle();
        void setDetalle(string _detalle);
        bool cargar(Interfaz &interfaz);
        string toString();
};

#endif // GASTOGENERAL_H
