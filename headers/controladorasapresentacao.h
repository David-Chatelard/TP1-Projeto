#ifndef CONTROLADORASAPRESENTACAO_H_INCLUDED
#define CONTROLADORASAPRESENTACAO_H_INCLUDED

#include <conio.h>
#include <iostream>
#include <string.h>

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"

#define CLR_SCR system("cls");

using namespace std;

//--------------------------------------------------------------------------------------------
// Declaração das controladoras e definição de métodos set

class CntrApresentacaoControle{
    private:
        Email email;
        IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
        IApresentacaoContas *cntrApresentacaoContas;
        IApresentacaoExcursao *cntrApresentacaoExcursao;
    public:
        void executar();
        void setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao*);
        void setCntrApresentacaoContas(IApresentacaoContas*);
        void setCntrApresentacaoExcursao(IApresentacaoExcursao*);
};

inline void CntrApresentacaoControle::setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao *cntr){
    cntrApresentacaoAutenticacao = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoContas(IApresentacaoContas *cntr){
    cntrApresentacaoContas = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoExcursao(IApresentacaoExcursao *cntr){
    cntrApresentacaoExcursao = cntr;
}

//--------------------------------------------------------------------------------------------

class CntrApresentacaoAutenticacao:public IApresentacaoAutenticacao{
    private:
        IServicoAutenticacao *cntr;
    public:
        bool autenticar(Email*);
        void setCntrServicoAutenticacao(IServicoAutenticacao*);
};

inline void CntrApresentacaoAutenticacao::setCntrServicoAutenticacao(IServicoAutenticacao *cntr){
    this->cntr = cntr;
}

//--------------------------------------------------------------------------------------------

class CntrApresentacaoContas:public IApresentacaoContas{
    private:
        IServicoContas *cntrServicoContas;
        // IServicoExcursao *cntrServicoExcursao;
        // void consultarDadosPessoais();
    public:
        void executar(Email);
        void cadastrar();
        void setCntrServicoContas(IServicoContas*);
        // void setCntrServicoExcursao(IServicoExcursao*);
};

inline void CntrApresentacaoContas::setCntrServicoContas(IServicoContas *cntr){
    cntrServicoContas = cntr;
}

// inline void CntrApresentacaoContas::setCntrServicoExcursao(IServicoExcursao *cntr){
//     cntrServicoExcursao = cntr;
// }

//--------------------------------------------------------------------------------------------

class CntrApresentacaoExcursao:public IApresentacaoExcursao{
    private:
        IServicoExcursao *cntr;
        void consultarConta();
        void cadastrarProdutoInvestimento();
        void descadastrarProdutoInvestimento();
        void consultarProdutoInvestimento();
        void realizarAplicacao();
        void listarAplicacoes();
    public:
        void executar();
        void executar(Email);
        void setCntrServicoExcursao(IServicoExcursao*);
};

inline void CntrApresentacaoExcursao::setCntrServicoExcursao(IServicoExcursao *cntr){
    this->cntr = cntr;
}


#endif // CONTROLADORASAPRESENTACAO_H_INCLUDED