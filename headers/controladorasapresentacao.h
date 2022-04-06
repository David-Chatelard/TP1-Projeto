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
// Declaração da classe CntrApresentacaoControle e definição de métodos set

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
// Declaração da classe CntrApresentacaoAutenticacao e definição de métodos set

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
// Declaração da classe CntrApresentacaoContas e definição de métodos set

class CntrApresentacaoContas:public IApresentacaoContas{
    private:
        IServicoContas *cntrServicoContas;
        // IServicoExcursao *cntrServicoExcursao; //não sei se precisa
        // void consultarDadosPessoais(); //não sei se precisa
    public:
        void executar(Email);
        void cadastrar();
        void setCntrServicoContas(IServicoContas*);
        // void setCntrServicoExcursao(IServicoExcursao*); //não sei se precisa
};

inline void CntrApresentacaoContas::setCntrServicoContas(IServicoContas *cntr){
    this->cntrServicoContas = cntr;
}

// inline void CntrApresentacaoContas::setCntrServicoExcursao(IServicoExcursao *cntr){ //não sei se precisa
//     cntrServicoExcursao = cntr;
// }

//--------------------------------------------------------------------------------------------
// Declaração da classe CntrApresentacaoExcursao e definição de métodos set





















class CntrApresentacaoExcursao:public IApresentacaoExcursao{
    private:
        IServicoExcursao *cntrServicoExcursao;
        void detalheExcursao(Excursao); // para quando não ta logado e quer ver todas as excursoes
        void detalheExcursao2(Excursao); // para quando ta logado e quer ver todas as excursoes
        void detalheExcursao(Email, Excursao); // para quando ta logado e quer ver todas as suas excursoes
    public:
        void executar();
        void executar(Email);
        void listarExcursoes(); // para quando não ta logado e quer ver todas as excursoes
        void listarExcursoes2(); // para quando ta logado e quer ver todas as excursoes
        void listarExcursoes(Email); // para quando ta logado e quer ver todas as suas excursoes
        void listarSessoes(Excursao);
        void listarSessoes(Email, Excursao);
        void listarAvaliacoes(Excursao);
        void listarAvaliacoes(Email);
        void setCntrServicoExcursao(IServicoExcursao*);
};

inline void CntrApresentacaoExcursao::setCntrServicoExcursao(IServicoExcursao *cntr){
    this->cntrServicoExcursao = cntr;
}

#endif // CONTROLADORASAPRESENTACAO_H_INCLUDED