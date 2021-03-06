#ifndef TESTES_ENTIDADES_H_INCLUDED
#define TESTES_ENTIDADES_H_INCLUDED

#include "entidades.h"

#include <string>

using namespace std;

/*----------------------------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Exemplo de declara��o de classe para teste de unidade de classe entidade.
// Tem que adicionar as linhas 16 e 17 para cada atributo da entidade a ser testada(por exemplo, no caso do usuario teria que ter pro nome, email e senha)

class TUProjeto {
private:
    const static int VALOR_VALIDO   = 20;   // Defini��o de constante para evitar n�mero m�gico.
    Projeto *projeto;                       // Refer�ncia para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // M�todo para criar unidade em teste.
    void tearDown();                        // M�todo para destruir unidade em teste.
    void testarCenarioSucesso();            // Cen�rio de teste.
public:
    const static int SUCESSO =  0;          // Defini��o de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Defini��o de constante para reportar resultado de teste.
    int run();                              // M�todo para executar teste.
};

----------------------------------------------------------------------------------------------*/

class TUUsuario {
private:
    const string VALOR_VALIDO_NOME    = "Alexandre Cunha.";   
    const string VALOR_VALIDO_EMAIL   = "Email_Teste.123@gmail.com";   
    const string VALOR_VALIDO_SENHA   = "BfA843";
    Usuario *usuario;                       
    int estado;                             
    void setUp();                          
    void tearDown();                        
    void testarCenarioSucesso();            
public:
    const static int SUCESSO =  0;          
    const static int FALHA   = -1;          
    int run();                              
};

class TUAvaliacao {
private:
    const string VALOR_VALIDO_CODIGO    = "5347164";   
    const static int VALOR_VALIDO_NOTA   = 0;   
    const string VALOR_VALIDO_DESCRICAO = "O aluno foi pessimo";
    Avaliacao *avaliacao;                       
    int estado;                             
    void setUp();                          
    void tearDown();                        
    void testarCenarioSucesso();            
public:
    const static int SUCESSO =  0;          
    const static int FALHA   = -1;          
    int run();                              
};

class TUSessao {
private:
    const string VALOR_VALIDO_CODIGO    = "5347164";   
    const string VALOR_VALIDO_DATA      = "12-Out-2027";   
    const string VALOR_VALIDO_HORARIO   = "00:00";
    const string VALOR_VALIDO_IDIOMA    = "Mandarim";
    Sessao *sessao;                       
    int estado;                             
    void setUp();                          
    void tearDown();                        
    void testarCenarioSucesso();            
public:
    const static int SUCESSO =  0;          
    const static int FALHA   = -1;          
    int run();                              
};

class TUExcursao {
private:
    const string VALOR_VALIDO_CODIGO      = "5347164";   
    const string VALOR_VALIDO_TITULO      = "Trilha Chinesa";   
    const static int VALOR_VALIDO_NOTA     = 3;
    const string VALOR_VALIDO_CIDADE      = "Bangkok";
    const static int VALOR_VALIDO_DURACAO  = 180;
    const string VALOR_VALIDO_DESCRICAO   = "Venha descobrir a China";
    const string VALOR_VALIDO_ENDERECO    = "A ser definido";
    Excursao *excursao;                       
    int estado;                             
    void setUp();                          
    void tearDown();                        
    void testarCenarioSucesso();            
public:
    const static int SUCESSO =  0;          
    const static int FALHA   = -1;          
    int run();                              
};

#endif // TESTES_ENTIDADES_H_INCLUDED
