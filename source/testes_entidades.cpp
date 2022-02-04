#include "../headers/testes_entidades.h"


/*----------------------------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Implementa��es de m�todos de classe de teste de unidade.
// No método TUProjeto::testarCenarioSucesso(), precisa implementar os trechos de código de dentro dele para cada atributo da entidade

void TUProjeto::setUp(){
    projeto = new Projeto();
    estado = SUCESSO;
}

void TUProjeto::tearDown(){
    delete projeto;
}

void TUProjeto::testarCenarioSucesso(){
    Codigo codigo;
    codigo.setValor(VALOR_VALIDO);
    projeto->setCodigo(codigo);
    if(projeto->getCodigo().getValor() != VALOR_VALIDO)
        estado = FALHA;

    Prioridade prioridade;
    prioridade.setValor(VALOR_VALIDO);
    projeto->setPrioridade(prioridade);
    if(projeto->getPrioridade().getValor() != VALOR_VALIDO)
        estado = FALHA;
}

int TUProjeto::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

----------------------------------------------------------------------------------------------*/



