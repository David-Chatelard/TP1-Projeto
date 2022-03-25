#include "controladorasapresentacao.h"

//--------------------------------------------------------------------------------------------
// Implementação de métodos de classes controladoras

void CntrApresentacaoControle::executar(){
    
    // Mensagens a serem apresentadas na tela inicial

    char texto1[] = "Selecione um dos servicos : ";
    char texto2[] = "1 - Acessar sistema.";
    char texto3[] = "2 - Cadastrar usuario.";
    char texto4[] = "3 - Acessar dados sobre produtos financeiros.";
    char texto5[] = "4 - Encerrar execucao do sistema.";

    // Mensagens a serem apresentadas na tela de seleção de serviços

    char texto6[] = "Selecione um dos servicos : ";
    char texto7[] = "1 - Selecionar servicos de pessoal.";
    char texto8[] = "2 - Selecionar servicos relacionados a produtos financeiros.";
    char texto9[] = "3 - Encerrar sessao.";

    char texto10[] = "Falha na autenticacao. Digite algo para continuar.";                      // Mensagem a ser apresentada

    int campo;                                                                                  // Campo de entrada

    bool apresentar = true;                                                                     // Controle de laço

    while(apresentar){

        // Apresenta tela inicial.

        CLR_SCR;                                                                                // Limpa janela.

        cout << texto1 << endl;                                                                 // Imprime nome do campo.
        cout << texto2 << endl;                                                                 // Imprime nome do campo.
        cout << texto3 << endl;                                                                 // Imprime nome do campo.
        cout << texto4 << endl;                                                                 // Imprime nome do campo.
        cout << texto5 << endl;                                                                 // Imprime nome do campo.

        campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.

        switch(campo){
            case 1: if(cntrApresentacaoAutenticacao->autenticar(&email)){                        // Solicita autenticação.
                        bool apresentar = true;                                                 // Controle de laço.
                        while(apresentar){

                            // Apresenta tela de seleção de serviço.

                            CLR_SCR;                                                            // Limpa janela.

                            cout << texto6 << endl;                                             // Imprime nome do campo.
                            cout << texto7 << endl;                                             // Imprime nome do campo.
                            cout << texto8 << endl;                                             // Imprime nome do campo.
                            cout << texto9 << endl;                                             // Imprime nome do campo.

                            campo = getch() - 48;                                               // Leitura do campo de entrada e conversão de ASCII.

                            switch(campo){
                                case 1: cntrApresentacaoContas->executar(email);                // Solicita serviço de contas.
                                        break;
                                case 2: cntrApresentacaoExcursao->executar(email);              // Solicita serviço de excursão.
                                        break;
                                case 3: apresentar = false;
                                        break;
                            }
                        }
                    }
                    else {
                        CLR_SCR;                                                                // Limpa janela.
                        cout << texto10 << endl;                                                // Imprime mensagem.
                        getch();                                                                // Leitura de caracter digitado.
                    }
                    break;
            case 2: cntrApresentacaoContas->cadastrar();
                    break;
            case 3: cntrApresentacaoExcursao->executar();
                    break;
            case 4: apresentar = false;
                    break;
        }
    }
    return;
}