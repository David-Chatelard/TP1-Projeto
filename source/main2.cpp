#include <string.h>
#include <stdexcept>
#include <iostream>
#include <ctime>

#include "../headers/dominios.h"
#include "dominios.cpp"

#include "../headers/entidades.h"
#include "entidades.cpp"

#include "../headers/controladorasapresentacao.h"
#include "controladorasapresentacao.cpp"

#include "../headers/controladorasservico.h"
#include "controladorasservico.cpp"

#include "../headers/stubs.h"
#include "stubs.cpp"

#include "../sqlite-amalgamation-3380200/sqlite3.h"            // Incluir cabeçalho da biblioteca SQLite.

using namespace std;

int main() {
    srand(time(0));
    // Declarar poteiros e instanciar controladoras.

    CntrApresentacaoControle *cntrApresentacaoControle;
    IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
    IApresentacaoContas *cntrApresentacaoContas;
    IApresentacaoExcursao *cntrApresentacaoExcursao;

    IServicoAutenticacao *cntrServicoAutenticacao;

    cntrApresentacaoControle = new CntrApresentacaoControle();
    cntrApresentacaoAutenticacao = new CntrApresentacaoAutenticacao();
    cntrApresentacaoContas = new CntrApresentacaoContas();
    cntrApresentacaoExcursao = new CntrApresentacaoExcursao();

    cntrServicoAutenticacao = new CntrServicoAutenticacao();


    // Instanciar stubs.

    IServicoAutenticacao *stubServicoAutenticacao;
    IServicoContas *stubServicoContas;
    IServicoExcursao *stubServicoExcursao;

    stubServicoAutenticacao = new StubServicoAutenticacao();
    stubServicoContas = new StubServicoContas();
    stubServicoExcursao = new StubServicoExcursao();

    // Interligar controladoras e stubs.

    cntrApresentacaoControle->setCntrApresentacaoAutenticacao(cntrApresentacaoAutenticacao);
    cntrApresentacaoControle->setCntrApresentacaoContas(cntrApresentacaoContas);
    cntrApresentacaoControle->setCntrApresentacaoExcursao(cntrApresentacaoExcursao);

    cntrApresentacaoAutenticacao->setCntrServicoAutenticacao(cntrServicoAutenticacao);

    cntrApresentacaoContas->setCntrServicoContas(stubServicoContas);
    // cntrApresentacaoContas->setCntrServicoExcursao(stubServicoExcursao); //não sei se vai usar isso

    cntrApresentacaoExcursao->setCntrServicoExcursao(stubServicoExcursao); //TEM QUE IMPLEMENTAR

    cntrApresentacaoControle->executar();                                           // Solicitar serviço.

    return 0;
}

