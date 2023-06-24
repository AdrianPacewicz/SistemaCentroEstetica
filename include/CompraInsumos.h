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
        char cuilProveedor[50];
        char detalle[100];
        int cantidad;
        double precioUnitario;

    public:
        string getProv();
        string getDetalle();
        int getCantidad();
        double getPrecioU();
        void setProv(string _prov);
        void setDetalle(string _detalle);
        void setCantidad(int _cant);
        void setPrecioU(double _precioU);
        bool cargar(Interfaz &interfaz);
        string toString();
};

#endif // COMPRAINSUMOS_H
