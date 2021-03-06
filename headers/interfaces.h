#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include <vector>

using namespace std;

// Declarações das interfaces da camada de servico

class IServicoAutenticacao {
    public:
        virtual bool autenticar(Email, Senha) = 0;
        virtual ~IServicoAutenticacao(){}
};

class IServicoContas {
    public:
        virtual bool descadastrar(Email) = 0;
        virtual bool editar(Usuario) = 0;
        virtual bool cadastrar(Usuario) = 0;
        virtual ~IServicoContas(){}
};

class IServicoExcursao {
    public:
        

        // TODAS AS FUNCIONALIDADES A SEREM IMPLEMENTADAS

        virtual vector<Excursao> listarExcursoes() = 0;
        virtual vector<Excursao> listarExcursoes(Email) = 0;
        virtual bool editarExcursao(Excursao) = 0;
        virtual bool descadastrarExcursao(Excursao) = 0;
        virtual bool cadastrarExcursao(Excursao, Email) = 0;
        virtual void atualizarNotaExcursao(Excursao) = 0;
        
        virtual vector<Sessao> listarSessoes(Codigo) = 0;
        virtual bool editarSessao(Sessao) = 0;
        virtual bool descadastrarSessao(Sessao) = 0;
        virtual bool cadastrarSessao(Sessao, Excursao) = 0;

        virtual vector<Avaliacao> listarAvaliacoes(Codigo) = 0;
        virtual vector<Avaliacao> listarAvaliacoes(Email) = 0; //para listar as avaliações que ele escreveu, para poder editar e excluir
        virtual bool editarAvaliacao(Avaliacao) = 0;
        virtual bool descadastrarAvaliacao(Avaliacao) = 0;
        virtual bool cadastrarAvaliacao(Avaliacao, Excursao, Email) = 0;



        // virtual bool consultarExcursao(Excursao*) = 0;
        // virtual bool consultarSessao(Sessao*) = 0;
        // virtual bool consultarAvaliacao(Avaliacao*) = 0;
        // virtual ~IServicoExcursao(){}
};


// Declarações das interfaces da camada de apresentação

class IApresentacaoAutenticacao {
    public:
        virtual bool autenticar(Email*) = 0;
        virtual void setCntrServicoAutenticacao(IServicoAutenticacao*) = 0;
        virtual ~IApresentacaoAutenticacao(){}
};

class IApresentacaoContas {
    public:
        virtual void executar(Email, bool*) = 0;
        virtual void cadastrar() = 0;
        virtual void setCntrServicoContas(IServicoContas*) = 0;
        virtual ~IApresentacaoContas(){}
};

class IApresentacaoExcursao {
    public:
        virtual void executar() = 0;
        virtual void executar(Email) = 0;
        virtual void listarExcursoes() = 0;
        virtual void listarExcursoes2(Email) = 0;
        virtual void listarExcursoes(Email) = 0;
        virtual void listarAvaliacoes(Excursao) = 0;
        virtual void listarAvaliacoes(Email) = 0;
        virtual void listarSessoes(Excursao) = 0;
        virtual void listarSessoes(Email, Excursao) = 0;
        virtual void setCntrServicoExcursao(IServicoExcursao*) = 0;
        virtual ~IApresentacaoExcursao(){}
};

#endif
