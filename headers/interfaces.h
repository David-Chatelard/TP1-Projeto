#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

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
        // void listarTodasExcursoes(); //DEPOIS ACESSAR OS DADOS DE CADA UMA
        // void listarMinhasExcursoes(); //Talvez não precise
        // void cadastrarExcursao();
        // void descadastrarExcursao();
        // void editarExcursao();
        
        // void listarSessoes();
        // void cadastrarSessao(); // Fazer o mesmo para as sessões
        // void descadastrarSessao();
        // void editarSessao();

        // void listarAvaliacoes();
        // void cadastrarAvaliacao();
        // void descadastrarAvaliacao();
        // void editarAvaliacao();



        virtual bool cadastrarExcursao(Excursao) = 0;
        virtual bool consultarExcursao(Excursao*) = 0;
        virtual bool descadastrarExcursao(Excursao) = 0;
        virtual bool cadastrarSessao(Sessao) = 0;
        virtual bool consultarSessao(Sessao*) = 0;
        virtual bool descadastrarSessao(Sessao) = 0;
        virtual bool cadastrarAvaliacao(Avaliacao) = 0;
        virtual bool consultarAvaliacao(Avaliacao*) = 0;
        virtual bool descadastrarAvaliacao(Avaliacao) = 0;
        virtual ~IServicoExcursao(){}
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
        virtual void executar(Email) = 0;
        virtual void cadastrar() = 0;
        virtual void setCntrServicoContas(IServicoContas*) = 0;
        virtual ~IApresentacaoContas(){}
};

class IApresentacaoExcursao {
    public:
        virtual void executar() = 0;
        virtual void executar(Email) = 0;
        virtual void setCntrServicoExcursao(IServicoExcursao*) = 0;
        virtual ~IApresentacaoExcursao(){}
};

#endif
