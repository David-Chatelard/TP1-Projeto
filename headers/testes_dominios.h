#ifndef TESTES_DOMINIOS_H_INCLUDED
#define TESTES_DOMINIOS_H_INCLUDED

#include "dominios.h"

#include <string>

using namespace std;

// --------------------------------------------------------------------------
// Exemplo de declara��o de classe para teste de unidade de classe dom�nio.

class TUCidade {
private:
    inline const static string VALOR_VALIDO = "Paris";   // Defini��o de constante para evitar n�mero m�gico.
    inline const static string VALOR_INVALIDO = "Brasilia";   // Defini��o de constante para evitar n�mero m�gico.
    Cidade *cidade;                         // Refer�ncia para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // M�todo para criar unidade em teste.
    void tearDown();                        // M�todo para destruir unidade em teste.
    void testarCenarioSucesso();            // Cen�rio de teste.
    void testarCenarioFalha();              // Cen�rio de teste.

public:
    const static int SUCESSO =  0;          // Defini��o de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Defini��o de constante para reportar resultado de teste.
    int run();                              // M�todo para executar teste.
};




#endif // TESTES_DOMINIOS_H_INCLUDED
