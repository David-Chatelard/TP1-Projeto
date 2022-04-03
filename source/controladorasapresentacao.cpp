#include "../headers/controladorasapresentacao.h"

//--------------------------------------------------------------------------------------------
// Implementação de métodos da classe CntrApresentacaoControle

void CntrApresentacaoControle::executar(){
    
    // Mensagens a serem apresentadas na tela inicial

    char texto1[] = "Selecione um dos servicos : ";
    char texto2[] = "1 - Acessar sistema.";
    char texto3[] = "2 - Cadastrar usuario.";
    char texto4[] = "3 - Acessar dados sobre excursoes.";
    char texto5[] = "4 - Encerrar execucao do sistema.";

    // Mensagens a serem apresentadas na tela de seleção de serviços

    char texto6[] = "Selecione um dos servicos : ";
    char texto7[] = "1 - Selecionar servicos de conta.";
    char texto8[] = "2 - Selecionar servicos relacionados a excursoes.";
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
            case 1: if(cntrApresentacaoAutenticacao->autenticar(&email)){                       // Solicita autenticação.
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

//--------------------------------------------------------------------------------------------
// Implementação de métodos da classe CntrApresentacaoAutenticacao

bool CntrApresentacaoAutenticacao::autenticar(Email *email){

    // Mensagens a serem apresentadas na tela de autenticação.

    char texto1[]="Digite o email: ";
    char texto2[]="Digite a senha: ";
    char texto3[]="Dado em formato incorreto. Digite algo.";

    // Campos de entrada.

    char campo1[80];
    char campo2[80];

    Senha senha;                                                                                // Instancia a classe Senha.

    while(true){

        // Apresenta tela de autenticação.

        CLR_SCR;                                                                                // Limpa janela.

        cout << texto1 << " ";                                                                  // Imprime nome do campo.
        cin >> campo1;                                                                          // Le valor do campo.
        cout << texto2 << " ";                                                                  // Imprime nome do campo.
        cin >> campo2;                                                                          // Le valor do campo.

        try{
            email->setValor(string(campo1));                                                    // Atribui valor ao email.
            senha.setValor(string(campo2));                                                     // Atribui Valor a senha.
            break;                                                                              // Abandona laçoo em caso de formatos corretos.
        }
        catch(invalid_argument &exp){                                                           // Captura exceção devido a formato incorreto.
            CLR_SCR;                                                                            // Limpa janela.
            cout << texto3 << endl;                                                             // Informa formato incorreto.
            getch();                                                                            // Le caracter digitado.
        }
    }
    return (cntr->autenticar(*email, senha));                                                   // Solicita serviço de autenticação.
}

//--------------------------------------------------------------------------------------------
// Implementação de métodos da classe CntrApresentacaoContas

void CntrApresentacaoContas::executar(Email email){

    // Mensagens a serem apresentadas na tela de sele��o de servi�o..

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Editar conta";
    char texto3[]="2 - Descadastrar conta";
    char texto4[]="3 - Digite algo para retornar para a lista de servicos";
    char texto5[]="Digite o novo nome: ";
    char texto6[]="Digite a nova senha: ";
    char texto7[]="Dado em formato incorreto. Digite algo.";

    int campo1;                                                                                  // Campo de entrada.
    char campo2[80];
    char campo3[80];

    bool apresentar = true;                                                                     // Controle de laço.

    Nome nome;
    Senha senha;
    Usuario usuario;

    while(apresentar){

        // Apresenta tela de selação de serviço.

        CLR_SCR;                                                                                // Limpa janela.
        cout << texto1 << endl;                                                                 // Imprime nome do campo.
        cout << texto2 << endl;                                                                 // Imprime nome do campo.
        cout << texto3 << endl;                                                                 // Imprime nome do campo.
        cout << texto4 << endl;                                                                 // Imprime nome do campo.
    
        campo1 = getch() - 48;                                                                  // Leitura do campo de entrada e conversão de ASCII.

        switch(campo1){
            case 1:                                                                             //Editar conta
                    while(true){
                        CLR_SCR;
                        cout << texto5;
                        cin >> campo2;
                        cout << texto6;
                        cin >> campo3;
                        
                        try{
                            nome.setValor(campo2);
                            senha.setValor(campo3);
                            break;
                        }
                        catch(invalid_argument &exp){
                            CLR_SCR;
                            cout << texto7 << endl;
                            getch();
                        }
                    }
                    usuario.setNome(nome);
                    usuario.setSenha(senha);
                    cntrServicoContas->editar(usuario); //RETORNA BOOLEAN, da para usar isso caso queira
                    break;
            case 2: cntrServicoContas->descadastrar(email);                                     //Descadastrar conta
                    break;
            case 3: apresentar = false;                                                                             //Voltar para a lista de servicos
                    break;
        }
    }
}

void CntrApresentacaoContas::cadastrar(){
    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto0[]="Pagina de cadastramento.\n";
    char texto1[]="Digite o nome  : ";
    char texto2[]="Digite o email  : ";
    char texto3[]="Digite a senha  : ";
    char texto4[]="Dado em formato incorreto. Digite algo.";
    char texto5[]="Email ja cadastrado. Digite algo.";

    // Campos de entrada.

    char campo1[80];
    char campo2[80];
    char campo3[80];

    Nome nome;                                                                                // Instancia a classe Nome.
    Email email;                                                                              // Instancia a classe Email.
    Senha senha;                                                                              // Instancia a classe Senha.
    
    Usuario usuario;                                                                          // Instancia a classe Usuario.

    while(true){

        // Apresenta tela de cadastramento.

        CLR_SCR;                                                                                // Limpa janela.

        cout << texto0;
        cout << texto1 << " ";                                                                  // Imprime nome do campo.
        cin >> campo1;                                                                          // Le valor do campo.
        cout << texto2 << " ";                                                                  // Imprime nome do campo.
        cin >> campo2;                                                                          // Le valor do campo.
        cout << texto3 << " ";                                                                  // Imprime nome do campo.
        cin >> campo3;                                                                          // Le valor do campo.

        try{
            nome.setValor(string(campo1));                                                      // Atribui valor ao nome.
            email.setValor(string(campo2));                                                     // Atribui valor ao email.
            senha.setValor(string(campo3));                                                     // Atribui Valor a senha.
            usuario.setNome(nome);
            usuario.setEmail(email);
            usuario.setSenha(senha);
            if (cntrServicoContas->cadastrar(usuario)){                                      // Solicita serviço de autenticação.
                break;
            }
            CLR_SCR;
            cout << texto5 << endl;                                                             // Informa email ja cadastrado.
            getch();                                                                            // Le caracter digitado.
        }
        catch(invalid_argument &exp){                                                           // Captura exceção devido a formato incorreto.
            CLR_SCR;                                                                            // Limpa janela.
            cout << texto4 << endl;                                                             // Informa formato incorreto.
            getch();                                                                            // Le caracter digitado.
        }
    }                                               
}

//--------------------------------------------------------------------------------------------
