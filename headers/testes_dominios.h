#ifndef TESTES_DOMINIOS_H_INCLUDED
#define TESTES_DOMINIOS_H_INCLUDED

#include "dominios.h"

using namespace std;

// --------------------------------------------------------------------------
// Exemplo de declara��o de classe para teste de unidade de classe dom�nio.

// class TUCodigo {
// private:
//     const static int VALOR_VALIDO   = 20;   // Defini��o de constante para evitar n�mero m�gico.
//     const static int VALOR_INVALIDO = 30;   // Defini��o de constante para evitar n�mero m�gico.
//     Codigo *codigo;                         // Refer�ncia para unidade em teste.
//     int estado;                             // Estado do teste.
//     void setUp();                           // M�todo para criar unidade em teste.
//     void tearDown();                        // M�todo para destruir unidade em teste.
//     void testarCenarioSucesso();            // Cen�rio de teste.
//     void testarCenarioFalha();              // Cen�rio de teste.

// public:
//     const static int SUCESSO =  0;          // Defini��o de constante para reportar resultado de teste.
//     const static int FALHA   = -1;          // Defini��o de constante para reportar resultado de teste.
//     int run();                              // M�todo para executar teste.
// };


class TUCidade {
private:
    const string VALOR_VALIDO = "Paris";
    const string VALOR_INVALIDO = "Brasilia";
    Cidade *cidade;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};

class TUCodigo {
private:
    const string VALOR_VALIDO = "5347164";
    const string VALOR_INVALIDO = "5347162";
    Codigo *codigo;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};

class TUData {
private:
    const string VALOR_VALIDO = "04-Fev-2022";
    const string VALOR_INVALIDO = "30-Fev-2022";
    Data *data;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};

class TUDescricao {
private:
    const string VALOR_VALIDO = "Esta e uma descricao valida.";
    const string VALOR_INVALIDO = "Esta  e uma descricao invalida..";
    Descricao *descricao;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};

class TUDuracao {
private:
    const static int VALOR_VALIDO = 90;
    const static int VALOR_INVALIDO = 50;
    Duracao *duracao;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};

class TUEmail {
private:
    const string VALOR_VALIDO = "dAvid.2!#$%&'*+-/=?^_`{|}~@gMail-3.com";
    const string VALOR_INVALIDO = ".dAvid..2!#$%&'*+-/=?^_`{|}~.@.gMail-3..com";
    Email *email;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};

class TUEndereco {
private:
    const string VALOR_VALIDO = "Asa Norte.";
    const string VALOR_INVALIDO = "Asa  Norte..";
    Endereco *endereco;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};

class TUHorario {
private:
    const string VALOR_VALIDO = "18:16";
    const string VALOR_INVALIDO = "24:60";
    Horario *horario;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};

class TUIdioma {
private:
    const string VALOR_VALIDO = "Frances";
    const string VALOR_INVALIDO = "Hebraico";
    Idioma *idioma;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};

class TUNome {
private:
    const string VALOR_VALIDO = "David. Chatelard.";
    const string VALOR_INVALIDO = "David..  chatelard.";
    Nome *nome;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};

class TUNota {
private:
    const static int VALOR_VALIDO = 5;
    const static int VALOR_INVALIDO = -2;
    Nota *nota;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};

class TUSenha {
private:
    const string VALOR_VALIDO = "Abc123";
    const string VALOR_INVALIDO = "aaa111";
    Senha *senha;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};

class TUTitulo {
private:
    const string VALOR_VALIDO = "Teste de Unidade.";
    const string VALOR_INVALIDO = "Teste de  Unidade..";
    Titulo *titulo;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};


#endif // TESTES_DOMINIOS_H_INCLUDED
