#ifndef CLIENTE_H
#define CLIENTE_H

#include "Persona.h"
using namespace std;

class Cliente: public Persona
{
    public:
        void cargar();
        string toString();
};

#endif // CLIENTE_H
