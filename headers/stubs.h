#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include <string>
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"

using namespace std;

//--------------------------------------------------------------------------------------------
// Declarações da classe StubServicoAutenticacao.

class StubServicoAutenticacao:public IServicoAutenticacao {
    private:
        static const string INVALIDO;
    public:
        bool autenticar(Email, Senha);
};

//--------------------------------------------------------------------------------------------
// Declarações da classe StubServicoContas.

class StubServicoContas:public IServicoContas {
    private:
        static const string INVALIDO;
    public:
        bool cadastrar(Usuario);
        bool descadastrar(Email);
        bool editar(Usuario);
};

//--------------------------------------------------------------------------------------------
// Declarações da classe StubServicoExcursao.

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