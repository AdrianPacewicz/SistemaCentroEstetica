#ifndef COMPRAINSUMOS_H
#define COMPRAINSUMOS_H

#include <string>
#include "Transaccion.h"
#include "Interfaz.h"
#include "Funciones.h"

using namespace std;

class CompraInsumos: public Transaccion
{
    private:
        int cuilProveedor;
        char detalle[100];
        int cantidad;
        double precioUnitario;

    public:
        int getProv();
        string getDetalle();
        int getCantidad();
        double getPrecioU();
        void setProv(int _prov);
        void setDetalle(string _detalle);
        void setCantidad(int _cant);
        void setPrecioU(double _precioU);
        bool cargar(Interfaz &interfaz);
        string toString();
};

#endif // COMPRAINSUMOS_H
