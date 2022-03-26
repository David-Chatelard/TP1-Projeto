#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include <string>
#include "dominios.h"
#include "interfaces.h"

using namespace std;

//--------------------------------------------------------------------------------------------
// Declarações de classes stub.

class StubServicoAutenticacao:public IServicoAutenticacao {
    private:
        static const string INVALIDO;
    public:
        bool autenticar(Email, Senha);
};

//--------------------------------------------------------------------------------------------

class StubServicoContas:public IServicoContas {
    private:
        static const string INVALIDO;
    public:
        bool cadastrar(Usuario);
        bool descadastrar(Email);
        bool editar(Usuario);
};

//--------------------------------------------------------------------------------------------

class StubServicoExcursao:public IServicoExcursao {
    private:
        static const string INVALIDO;
    public:
        // bool cadastrarConta(Conta);
        // bool consultarConta(Conta*);
        // bool cadastrarProdutoInvestimento(Produto);
        // bool descadastrarProdutoInvestimento(Codigo);
        // bool realizarAplicacao(Aplicacao);
        // bool recuperarAplicacao(Aplicacao*);                        // Adaptar assinatura.
        bool cadastrarExcursao(Excursao);
        bool consultarExcursao(Excursao*);
        bool descadastrarExcursao(Excursao);
        bool cadastrarSessao(Sessao);
        bool consultarSessao(Sessao*);
        bool descadastrarSessao(Sessao);
        bool cadastrarAvaliacao(Avaliacao);
        bool consultarAvaliacao(Avaliacao*);
        bool descadastrarAvaliacao(Avaliacao);
};

#endif // STUBS_H_INCLUDED