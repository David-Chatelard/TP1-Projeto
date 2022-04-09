#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED

#include <string.h>

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
#include "unidadepersistencia.h"
#include "../source/unidadepersistencia.cpp"

using namespace std;

//--------------------------------------------------------------------------------------------
// Declaração da classe CntrServicoAutenticacao
class CntrServicoAutenticacao:public IServicoAutenticacao{
    public:
        bool autenticar(Email, Senha);
};

//--------------------------------------------------------------------------------------------
// Declaração da classe CntrServicoContas
class CntrServicoContas:public IServicoContas{
    public:
        bool descadastrar(Email);
        bool editar(Usuario);
        bool cadastrar(Usuario);
};

//--------------------------------------------------------------------------------------------
// Declaração da classe CntrServicoExcursao
// class CntrServicoExcursao:public IServicoExcursao{
//     public:

// };

#endif