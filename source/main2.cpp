#include <string.h>
#include <stdexcept>
#include <iostream>

#include "../headers/dominios.h"
#include "../headers/interfaces.h"
#include "../headers/controladorasapresentacao.h"
#include "../headers/stubs.h"

using namespace std;

int main() {
    // Declarar poteiros e instanciar controladoras.

    CntrApresentacaoControle *cntrApresentacaoControle;
    IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
    IApresentacaoContas *cntrApresentacaoContas;
    IApresentacaoExcursao *cntrApresentacaoExcursao;

    cntrApresentacaoControle = new CntrApresentacaoControle();
    cntrApresentacaoAutenticacao = new CntrApresentacaoAutenticacao();
    cntrApresentacaoContas = new CntrApresentacaoContas();
    cntrApresentacaoExcursao = new CntrApresentacaoExcursao();

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

    cntrApresentacaoAutenticacao->setCntrServicoAutenticacao(stubServicoAutenticacao);

    cntrApresentacaoContas->setCntrServicoContas(stubServicoContas);
    // cntrApresentacaoContas->setCntrServicoExcursao(stubServicoExcursao); //não sei se vai usar isso

    cntrApresentacaoExcursao->setCntrServicoExcursao(stubServicoExcursao);

    cntrApresentacaoControle->executar();                                           // Solicitar serviço.

    return 0;
}

