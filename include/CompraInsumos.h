#ifndef COMPRAINSUMOS_H
#define COMPRAINSUMOS_H

#include <string>
#include "Transaccion.h"
#include "Interfaz.h"
using namespace std;

class CompraInsumos: public Transaccion
{
    private:
        int cuilProveedor;
        char detalle[100];
        int cantidad;
        float precioUnitario;

    public:
        int getProv();
        string getDetalle();
        int getCantidad();
        float getPrecioU();
        void setProv(int _prov);
        void setDetalle(string _detalle);
        void setCantidad(int _cant);
        void setPrecioU(float _precioU);
        bool cargar(Interfaz &interfaz);
        string toString();
};

#endif // COMPRAINSUMOS_H
