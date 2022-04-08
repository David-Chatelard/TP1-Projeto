#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED

#include <string.h>

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
#include "unidadepersistencia.h"
#include "../source/unidadepersistencia.cpp"

using namespace std;

class CntrServicoAutenticacao:public IServicoAutenticacao{
    public:
        bool autenticar(Email, Senha);
};

#endif