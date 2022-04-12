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
class CntrServicoExcursao:public IServicoExcursao{
    public:
        vector<Excursao> listarExcursoes(Email);
        vector<Excursao> listarExcursoes2(Email); //acho que pode tirar e usar só a listarExcursoes()
        vector<Excursao> listarExcursoes();
        vector<Avaliacao> listarAvaliacoes(Email);
        vector<Avaliacao> listarAvaliacoes(Codigo);
        vector<Sessao> listarSessoes(Codigo);
        // bool cadastrarExcursao(Excursao excursao);
        // bool cadastrarAvaliacao(Avaliacao avaliacao);
        // bool cadastrarSessao(Sessao sessao);
        // bool editarExcursao(Excursao excursao);
        // bool editarAvaliacao(Avaliacao avaliacao);
        // bool editarSessao(Sessao sessao);
        // bool descadastrarExcursao(Excursao excursao);
        // bool descadastrarAvaliacao(Avaliacao avaliacao);
        // bool descadastrarSessao(Sessao sessao);
};

#endif