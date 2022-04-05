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






















void CntrApresentacaoExcursao::executar(){

    // Mensagens a serem apresentadas na tela de sele��o de servi�o..

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Listar todas as excursoes";
    char texto3[]="2 - Retornar para o menu";

    int campo1;                                                                                  // Campo de entrada.

    bool apresentar = true;                                                                     // Controle de laço.

    while(apresentar){

        // Apresenta tela de selação de serviço.

        CLR_SCR;                                                                                // Limpa janela.
        cout << texto1 << endl;                                                                 // Imprime nome do campo.
        cout << texto2 << endl;                                                                 // Imprime nome do campo.
        cout << texto3 << endl;                                                                 // Imprime nome do campo.
    
        campo1 = getch() - 48;                                                                  // Leitura do campo de entrada e conversão de ASCII.

        switch(campo1){
            case 1: listarExcursoes(); //apresentar=false;    MUDAR DPS                                                                    
                    break;
            case 2: apresentar = false;                                                         //Voltar para a lista de servicos
                    break;
        }
    }
}

void CntrApresentacaoExcursao::executar(Email email){ 

    // Mensagens a serem apresentadas na tela de sele��o de servi�o..

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Listar todas as excursoes";
    char texto3[]="2 - Listar minhas excursoes";
    char texto4[]="3 - Cadastrar excursao";
    char texto5[]="4 - Retornar para o menu";
    char texto6[]="Digite o titulo: ";
    char texto7[]="Digite a cidade: ";
    char texto8[]="Digite a duracao: ";
    char texto9[]="Digite a descricao: ";
    char texto10[]="Digite o endereco: ";
    char texto11[]="Dado em formato incorreto. Digite algo.";

    int campo1;                                                                                  // Campo de entrada.
    char campo2[80];
    char campo3[80];
    char campo4[80]; //VER COMO FAZER VALIDACAO
    char campo5[80];
    char campo6[80];

    bool apresentar = true;                                                                     // Controle de laço.

    Titulo titulo;
    Cidade cidade;
    Duracao duracao;
    Descricao descricao;
    Endereco endereco;

    Excursao excursao;

    while(apresentar){

        // Apresenta tela de selação de serviço.

        CLR_SCR;                                                                                // Limpa janela.
        cout << texto1 << endl;                                                                 // Imprime nome do campo.
        cout << texto2 << endl;                                                                 // Imprime nome do campo.
        cout << texto3 << endl;                                                                 // Imprime nome do campo.
        cout << texto4 << endl;                                                                 // Imprime nome do campo.
        cout << texto5 << endl;                                                                 // Imprime nome do campo.
    
        campo1 = getch() - 48;                                                                  // Leitura do campo de entrada e conversão de ASCII.

        switch(campo1){
            case 1: listarExcursoes(); //apresentar=false;
                    break;
            case 2: listarExcursoes(email); //apresentar=false;
                    break;
            case 3: while(true){                                                                //Cadastrar excursão
                        CLR_SCR;
                        cout << texto6;                                                         //Imprime os textos de cadastro da excursão
                        cin >> campo2;                                                          //Le os inputs da excursão
                        cout << texto7;
                        cin >> campo3;
                        cout << texto8;
                        cin >> campo4; //VER COMO FAZER VALIDACAO
                        cout << campo4;
                        cout << texto9;
                        cin >> campo5;
                        cout << texto10;
                        cin >> campo6;

                        
                        try{
                            titulo.setValor(campo2);
                            cidade.setValor(campo3);
                            duracao.setValor(stoi(campo4));
                            descricao.setValor(campo5);
                            endereco.setValor(campo6);
                            excursao.setTitulo(titulo);
                            excursao.setCidade(cidade);
                            excursao.setDuracao(duracao);
                            excursao.setDescricao(descricao);
                            excursao.setEndereco(endereco);
                            break;
                        }
                        catch(invalid_argument &exp){
                            CLR_SCR;
                            cout << texto11 << endl;
                            getch();
                        }
                    }
                    cntrServicoExcursao->cadastrarExcursao(excursao); //RETORNA BOOLEAN, da para usar isso caso queira                             //Cadastrar excursao
                    break;
            case 4: apresentar = false;                                                                             //Voltar para a lista de servicos
                    break;
        }
    }
}

void CntrApresentacaoExcursao::listarExcursoes(){
    // COMANDO DE BUSCAR TODAS AS EXCURSOES DA CAMADA DE SERVICO
    const int EXCURSOES_POR_PAGINA = 5;
    Excursao excursoes[30]; // teste
    int pagina=0, i, j, prox_pag=-1, pag_ant=-1, num_opcoes=0;
    bool apresentar=true;
    int campo1;

    char texto1[]="Lista de excursoes.";
    char texto2[]=" - Proxima pagina";
    char texto3[]=" - Pagina anterior";
    char texto4[]=" - Retornar a selecao de servicos";
    
    while (apresentar){
        prox_pag=-1;
        pag_ant=-1;
        num_opcoes=0;

        CLR_SCR;                                                                                // Limpa janela.
        cout << texto1 << endl;                                                                 // Imprime nome do campo.

        // Imprimir os titulos das excursões
        for (i = 0; i < EXCURSOES_POR_PAGINA; i++){                                             // Imprime as avaliações
            if (excursoes[i + (EXCURSOES_POR_PAGINA*pagina)].getTitulo().getValor() == "NULL"){ //tem que mudar para funcionar, mas a ideia é essa, o retorno da função do serviço deve dar uma lista que vai ter "NULL" caso não exista      // Caso não exista mais excursões
                break;
            }
            cout << i+1 << " - ";                                                               // Imprime "Num - "
            cout << excursoes[i + (EXCURSOES_POR_PAGINA*pagina)].getTitulo().getValor() << endl;
        }

        // Imprimir "Próxima página", se existirem mais excursões
        if (excursoes[(i+1) + (EXCURSOES_POR_PAGINA*pagina)].getCodigo().getValor() != "NULL" ) { //tem que mudar para funcionar, mas a ideia é essa, o retorno da função do serviço deve dar uma lista que vai ter "NULL" caso não exista
            num_opcoes++;
            prox_pag = i+1;
            cout << prox_pag << texto2 << endl;                                                                 // Imprime nome do campo.
        }

        // Imprimir "Página anterior", se não estiver na primeira página
        if (pagina != 0) {
            num_opcoes++;
            if (prox_pag == -1){
                pag_ant = i+1;
            }
            else{
                pag_ant = i+2;                
            }
            cout << pag_ant << texto3 << endl;                                                                 // Imprime nome do campo.
        }

        // Imprimir "Retornar"
        cout << i+1+num_opcoes << texto4 << endl;                                                                 // Imprime nome do campo.
    
        campo1 = getch() - 48;                                                                  // Leitura do campo de entrada e conversão de ASCII.

        // Vai na excursão selecionada
        for (j = 0; j < EXCURSOES_POR_PAGINA; j++){
            if (excursoes[j + (EXCURSOES_POR_PAGINA*pagina)].getTitulo().getValor() != "NULL"){ //tem que mudar para funcionar, mas a ideia é essa, o retorno da função do serviço deve dar uma lista que vai ter "NULL" caso não exista      // Caso não exista mais excursões
                if (campo1 == (j+1)){
                    detalheExcursao(excursoes[j + (EXCURSOES_POR_PAGINA*pagina)]);
                }
            }
        }
        
        if (campo1 == prox_pag){
            pagina++;
        }
        else if (campo1 == pag_ant){
            pagina--;
        }
        else if (campo1 == (i+1+num_opcoes)){
            apresentar = false;
        }
    }
}

void CntrApresentacaoExcursao::listarExcursoes(Email email){
    // COMANDO DE BUSCAR TODAS AS EXCURSOES DESSE EMAIL DA CAMADA DE SERVICO
    const int EXCURSOES_POR_PAGINA = 5;
    Excursao excursoes[30]; // teste
    int pagina=0, i, j, prox_pag=-1, pag_ant=-1, num_opcoes=0;
    bool apresentar=true;
    int campo1;

    char texto1[]="Lista de excursoes.";
    char texto2[]=" - Proxima pagina";
    char texto3[]=" - Pagina anterior";
    char texto4[]=" - Retornar a selecao de servicos";
    
    while (apresentar){
        prox_pag=-1;
        pag_ant=-1;
        num_opcoes=0;

        CLR_SCR;                                                                                // Limpa janela.
        cout << texto1 << endl;                                                                 // Imprime nome do campo.

        // Imprimir os titulos das excursões
        for (i = 0; i < EXCURSOES_POR_PAGINA; i++){                                             // Imprime as avaliações
            if (excursoes[i + (EXCURSOES_POR_PAGINA*pagina)].getTitulo().getValor() == "NULL"){ //tem que mudar para funcionar, mas a ideia é essa, o retorno da função do serviço deve dar uma lista que vai ter "NULL" caso não exista      // Caso não exista mais excursões
                break;
            }
            cout << i+1 << " - ";                                                               // Imprime "Num - "
            cout << excursoes[i + (EXCURSOES_POR_PAGINA*pagina)].getTitulo().getValor() << endl;
        }

        // Imprimir "Próxima página", se existirem mais excursões
        if (excursoes[(i+1) + (EXCURSOES_POR_PAGINA*pagina)].getCodigo().getValor() != "NULL" ) { //tem que mudar para funcionar, mas a ideia é essa, o retorno da função do serviço deve dar uma lista que vai ter "NULL" caso não exista
            num_opcoes++;
            prox_pag = i+1;
            cout << prox_pag << texto2 << endl;                                                                 // Imprime nome do campo.
        }

        // Imprimir "Página anterior", se não estiver na primeira página
        if (pagina != 0) {
            num_opcoes++;
            if (prox_pag == -1){
                pag_ant = i+1;
            }
            else{
                pag_ant = i+2;                
            }
            cout << pag_ant << texto3 << endl;                                                                 // Imprime nome do campo.
        }

        // Imprimir "Retornar"
        cout << i+1+num_opcoes << texto4 << endl;                                                                 // Imprime nome do campo.
    
        campo1 = getch() - 48;                                                                  // Leitura do campo de entrada e conversão de ASCII.

        // Vai na excursão selecionada
        for (j = 0; j < EXCURSOES_POR_PAGINA; j++){
            if (excursoes[j + (EXCURSOES_POR_PAGINA*pagina)].getTitulo().getValor() != "NULL"){ //tem que mudar para funcionar, mas a ideia é essa, o retorno da função do serviço deve dar uma lista que vai ter "NULL" caso não exista      // Caso não exista mais excursões
                if (campo1 == (j+1)){
                    detalheExcursao(email, excursoes[j + (EXCURSOES_POR_PAGINA*pagina)]);
                }
            }
        }
        
        if (campo1 == prox_pag){
            pagina++;
        }
        else if (campo1 == pag_ant){
            pagina--;
        }
        else if (campo1 == (i+1+num_opcoes)){
            apresentar = false;
        }
    }
}

void CntrApresentacaoExcursao::detalheExcursao(Email email, Excursao excursao){
    char texto1[] = "Informacoes sobre a excursao";
    char texto2[] = "Titulo: ";
    char texto3[] = "Nota: ";
    char texto4[] = "Cidade: ";
    char texto5[] = "Duracao: ";
    char texto6[] = "Descricao: ";
    char texto7[] = "Endereco: ";
    char texto8[] = "1 - Avaliacoes dessa excursao";
    char texto9[] = "2 - Sessoes dessa excursao";
    char texto10[] = "3 - Editar excursao";
    char texto11[] = "4 - Descadastrar excursao";
    char texto12[] = "5 - Retornar para a lista de excursoes";

    bool apresentar=true;

    int campo1;

    while (apresentar){

        CLR_SCR;
        cout << texto1 << endl;
        cout << texto2 << excursao.getTitulo().getValor() << endl;
        cout << texto3 << excursao.getNota().getValor() << endl;
        cout << texto4 << excursao.getCidade().getValor() << endl;
        cout << texto5 << excursao.getDuracao().getValor() << endl;
        cout << texto6 << excursao.getDescricao().getValor() << endl;
        cout << texto7 << excursao.getEndereco().getValor() << endl;
        cout << texto8 << endl;
        cout << texto9 << endl;
        cout << texto10 << endl;
        cout << texto11 << endl;
        cout << texto12 << endl;

        campo1 = getch() - 48;

        switch (campo1) {
            case 1: listarAvaliacoes(excursao);//cout << "fon1" << endl; //IMPLEMENTAR listarAvaliacoes(excursao)
                break;
            case 2: cout << "fon2" << endl;//listarSessoes(email, excursao); //IMPLEMENTAR listarSessoes(email, excursao)
                break;
            case 3: apresentar = false; //cntrServicoExcursao->editarExcursao(excursao);
                break;
            case 4: apresentar = false; //cntrServicoExcursao->descadastrarExcursao(excursao);
                break;
            case 5: apresentar = false;
                break;
        }
    }
}

void CntrApresentacaoExcursao::detalheExcursao(Excursao excursao){
    char texto1[] = "Informacoes sobre a excursao";
    char texto2[] = "Titulo: ";
    char texto3[] = "Nota: ";
    char texto4[] = "Cidade: ";
    char texto5[] = "Duracao: ";
    char texto6[] = "Descricao: ";
    char texto7[] = "Endereco: ";
    char texto8[] = "1 - Avaliacoes dessa excursao";
    char texto9[] = "2 - Sessoes dessa excursao";
    char texto10[] = "3 - Retornar para a lista de excursoes";

    bool apresentar=true;

    int campo1;

    while (apresentar){

        CLR_SCR;
        cout << texto1 << endl;
        cout << texto2 << excursao.getTitulo().getValor() << endl;
        cout << texto3 << excursao.getNota().getValor() << endl;
        cout << texto4 << excursao.getCidade().getValor() << endl;
        cout << texto5 << excursao.getDuracao().getValor() << endl;
        cout << texto6 << excursao.getDescricao().getValor() << endl;
        cout << texto7 << excursao.getEndereco().getValor() << endl;
        cout << texto8 << endl;
        cout << texto9 << endl;
        cout << texto10 << endl;

        campo1 = getch() - 48;

        switch (campo1) {
            case 1: listarAvaliacoes(excursao);//cout << "fon1" << endl; //IMPLEMENTAR listarAvaliacoes(excursao)
                break;
            case 2: cout << "fon2" << endl;//listarSessoes(excursao); //IMPLEMENTAR listarSessoes(excursao)
                break;
            case 3: apresentar = false;
                break;
        }
    }
}

void CntrApresentacaoExcursao::listarAvaliacoes(Excursao excursao){ // A versão que aceita email vai ser pra listar as minhas avaliacoes e vai mudar no metodo de pegar as avaliacoes e que vai poder editar/excluir as avaliacoes
    // COMANDO DE BUSCAR TODAS AS AVALIACOES DA CAMADA DE SERVICO
    const int AVALIACOES_POR_PAGINA = 5;
    Avaliacao avaliacoes[30]; // teste
    int pagina=0, i, num_opcoes=1, prox_pag=0, pag_ant=1;
    bool apresentar=true;
    int campo1;

    char texto1[]="Lista de avaliacoes.";
    char texto2[]="Avaliacao ";
    char texto3[]=" - Proxima pagina";
    char texto4[]=" - Pagina anterior";
    char texto5[]=" - Retornar aos detalhes da excursao";
    
    while (apresentar){
        num_opcoes=1;
        prox_pag=0;
        pag_ant=1;

        CLR_SCR;                                                                                // Limpa janela.
        cout << texto1 << endl;

        for (i = 0; i < AVALIACOES_POR_PAGINA; i++){                                        // Imprime as avaliações
            if (avaliacoes[i + (AVALIACOES_POR_PAGINA*pagina)].getCodigo().getValor() == "NULL"){ //tem que mudar para funcionar, mas a ideia é essa, o retorno da função do serviço deve dar uma lista que vai ter "NULL" caso não exista      // Caso não exista mais avaliações
                break;
            }
            cout << texto2 << (i + 1) + (AVALIACOES_POR_PAGINA*pagina) << endl;
            cout << "Nota: " << avaliacoes[i + (AVALIACOES_POR_PAGINA*pagina)].getNota().getValor() << endl;
            cout << "Descricao: " << avaliacoes[i + (AVALIACOES_POR_PAGINA*pagina)].getDescricao().getValor() << endl << endl;
        }

        if (avaliacoes[(i+1) + (AVALIACOES_POR_PAGINA*pagina)].getCodigo().getValor() != "NULL" ){  // Se tiver mais avaliações
            prox_pag++;
            cout << prox_pag << texto3 << endl;                                                                 // Opção de próxima página
            num_opcoes++;
            pag_ant++;
        }
        if (pagina != 0){
            cout << pag_ant << texto4 << endl;                                                                 // Opção de página anterior
            num_opcoes++;
        }
        cout << num_opcoes << texto5 << endl;                                                                 // Imprime nome do campo.
    
        campo1 = getch() - 48;                                                                  // Leitura do campo de entrada e conversão de ASCII.

        if (campo1 == prox_pag){
            pagina++;
        }
        else if (campo1 == pag_ant && pagina != 0){
            pagina--;
        }
        else if (campo1 == num_opcoes){
            apresentar = false;
        }
    }
}

void CntrApresentacaoExcursao::listarSessoes(Excursao excursao){
    // COMANDO DE BUSCAR TODAS AS SESSOES DESSA EXCURSAO DA CAMADA DE SERVICO
    const int SESSOES_POR_PAGINA = 5;
    Sessao sessoes[30]; // teste
    int pagina=0, i, num_opcoes=1, prox_pag=0, pag_ant=1;
    bool apresentar=true;
    int campo1;

    char texto1[]="Lista de sessoes.";
    char texto2[]="Sessao ";
    char texto3[]=" - Proxima pagina";
    char texto4[]=" - Pagina anterior";
    char texto5[]=" - Retornar aos detalhes da excursao";
    
    while (apresentar){
        num_opcoes=1;
        prox_pag=0;
        pag_ant=1;

        CLR_SCR;                                                                                // Limpa janela.
        cout << texto1 << endl;

        for (i = 0; i < SESSOES_POR_PAGINA; i++){                                        // Imprime as sessões
            if (sessoes[i + (SESSOES_POR_PAGINA*pagina)].getCodigo().getValor() == "NULL"){ //tem que mudar para funcionar, mas a ideia é essa, o retorno da função do serviço deve dar uma lista que vai ter "NULL" caso não exista      // Caso não exista mais sessões
                break;
            }
            cout << texto2 << (i + 1) + (SESSOES_POR_PAGINA*pagina) << endl;
            cout << "Data: " << sessoes[i + (SESSOES_POR_PAGINA*pagina)].getData().getValor() << endl;
            cout << "Horario: " << sessoes[i + (SESSOES_POR_PAGINA*pagina)].getHorario().getValor() << endl;
            cout << "Idioma: " << sessoes[i + (SESSOES_POR_PAGINA*pagina)].getIdioma().getValor() << endl << endl;
        }

        if (sessoes[(i+1) + (SESSOES_POR_PAGINA*pagina)].getCodigo().getValor() != "NULL" ){  // Se tiver mais sessões
            prox_pag++;
            cout << prox_pag << texto3 << endl;                                                                 // Opção de próxima página
            num_opcoes++;
            pag_ant++;
        }
        if (pagina != 0){
            cout << pag_ant << texto4 << endl;                                                                 // Opção de página anterior
            num_opcoes++;
        }
        cout << num_opcoes << texto5 << endl;                                                                 // Imprime nome do campo.
    
        campo1 = getch() - 48;                                                                  // Leitura do campo de entrada e conversão de ASCII.

        if (campo1 == prox_pag){
            pagina++;
        }
        else if (campo1 == pag_ant && pagina != 0){
            pagina--;
        }
        else if (campo1 == num_opcoes){
            apresentar = false;
        }
    }
}

void CntrApresentacaoExcursao::listarSessoes(Email email, Excursao excursao){
    // COMANDO DE BUSCAR TODAS AS SESSOES DESSA EXCURSAO DA CAMADA DE SERVICO
    const int SESSOES_POR_PAGINA = 5;

    Sessao sessoes[30]; // teste

    int pagina=0, i, num_opcoes=1, prox_pag=0, pag_ant=1;
    int campo1, sessao_a_editar, sessao_a_excluir;

    bool apresentar=true;
    
    char aux_data[80];
    char aux_horario[80];
    char aux_idioma[80];

    Sessao sessao;
    Codigo codigo;
    Data data;
    Horario horario;
    Idioma idioma;

    char texto1[]="Lista de sessoes.";
    char texto2[]="Sessao ";
    char texto3[]="1 - Editar sessao";
    char texto4[]="2 - Descadastrar sessao";
    char texto5[]=" - Proxima pagina";
    char texto6[]=" - Pagina anterior";
    char texto7[]=" - Retornar aos detalhes da excursao";
    char texto8[]="Digite o numero da sessao que deseja editar";
    char texto9[]="Nova data: ";
    char texto10[]="Novo horario: ";
    char texto11[]="Novo idioma: ";
    char texto12[]="Dado em formato incorreto. Digite algo.";
    char texto13[]="Digite o numero da sessao que deseja descadastrar";
    
    while (apresentar){
        num_opcoes=3;
        prox_pag=0;
        pag_ant=3;

        CLR_SCR;                                                                                // Limpa janela.
        cout << texto1 << endl;

        for (i = 0; i < SESSOES_POR_PAGINA; i++){                                        // Imprime as sessões
            if (sessoes[i + (SESSOES_POR_PAGINA*pagina)].getCodigo().getValor() == "NULL"){ //tem que mudar para funcionar, mas a ideia é essa, o retorno da função do serviço deve dar uma lista que vai ter "NULL" caso não exista      // Caso não exista mais sessões
                break;
            }
            cout << texto2 << (i + 1) + (SESSOES_POR_PAGINA*pagina) << endl;
            cout << "Data: " << sessoes[i + (SESSOES_POR_PAGINA*pagina)].getData().getValor() << endl;
            cout << "Horario: " << sessoes[i + (SESSOES_POR_PAGINA*pagina)].getHorario().getValor() << endl;
            cout << "Idioma: " << sessoes[i + (SESSOES_POR_PAGINA*pagina)].getIdioma().getValor() << endl << endl;
        }

        cout << texto3 << endl;
        cout << texto4 << endl;

        if (sessoes[(i+1) + (SESSOES_POR_PAGINA*pagina)].getCodigo().getValor() != "NULL" ){  // Se tiver mais sessões
            prox_pag = 3;
            cout << prox_pag << texto5 << endl;                                                                 // Opção de próxima página
            num_opcoes++;
            pag_ant++;
        }
        if (pagina != 0){
            cout << pag_ant << texto6 << endl;                                                                 // Opção de página anterior
            num_opcoes++;
        }
        cout << num_opcoes << texto7 << endl;                                                                 // Imprime nome do campo.
    
        campo1 = getch() - 48;                                                                                // Leitura do campo de entrada e conversão de ASCII.

        if (campo1 == 1) { // editar sessão
            CLR_SCR;                                                                                // Limpa janela.
            cout << texto1 << endl;

            for (i = 0; i < SESSOES_POR_PAGINA; i++){                                        // Imprime as sessões
                if (sessoes[i + (SESSOES_POR_PAGINA*pagina)].getCodigo().getValor() == "NULL"){ //tem que mudar para funcionar, mas a ideia é essa, o retorno da função do serviço deve dar uma lista que vai ter "NULL" caso não exista      // Caso não exista mais sessões
                    break;
                }
                cout << texto2 << (i + 1) + (SESSOES_POR_PAGINA*pagina) << endl;
                cout << "Data: " << sessoes[i + (SESSOES_POR_PAGINA*pagina)].getData().getValor() << endl;
                cout << "Horario: " << sessoes[i + (SESSOES_POR_PAGINA*pagina)].getHorario().getValor() << endl;
                cout << "Idioma: " << sessoes[i + (SESSOES_POR_PAGINA*pagina)].getIdioma().getValor() << endl << endl;
            }

            cout << texto8 << endl;
            sessao_a_editar = getch() - 48;                                                                  // Leitura do campo de entrada e conversão de ASCII.

            // Vai na excursão selecionada
            for (int j = 0; j < SESSOES_POR_PAGINA; j++){
                if (sessoes[j + (SESSOES_POR_PAGINA*pagina)].getCodigo().getValor() != "NULL"){ //tem que mudar para funcionar, mas a ideia é essa, o retorno da função do serviço deve dar uma lista que vai ter "NULL" caso não exista      // Caso não exista mais excursões
                    if (sessao_a_editar == (j+1)){
                        while (true){
                            CLR_SCR;
                            cout << texto9;
                            cin >> aux_data;
                            cout << texto10;
                            cin >> aux_horario;
                            cout << texto11;
                            cin >> aux_idioma;
                            try {
                                data.setValor(aux_data);
                                horario.setValor(aux_horario);
                                idioma.setValor(aux_idioma);
                                sessao.setCodigo(sessoes[j + (SESSOES_POR_PAGINA*pagina)].getCodigo());
                                sessao.setData(data);
                                sessao.setHorario(horario);
                                sessao.setIdioma(idioma);
                                break;
                            }
                            catch(invalid_argument &exp) {
                                CLR_SCR;
                                cout << texto12 << endl;
                                getch();
                            }
                        }
                        // cntrServicoExcursao->editarSessao(email, sessao); TEM QUE IMPLEMENTAR NO SERVIÇO
                    }
                }
            }
        }
        else if (campo1 == 2) { //descadastrar sessão
            CLR_SCR;                                                                                // Limpa janela.
            cout << texto1 << endl;

            for (i = 0; i < SESSOES_POR_PAGINA; i++){                                        // Imprime as sessões
                if (sessoes[i + (SESSOES_POR_PAGINA*pagina)].getCodigo().getValor() == "NULL"){ //tem que mudar para funcionar, mas a ideia é essa, o retorno da função do serviço deve dar uma lista que vai ter "NULL" caso não exista      // Caso não exista mais sessões
                    break;
                }
                cout << texto2 << (i + 1) + (SESSOES_POR_PAGINA*pagina) << endl;
                cout << "Data: " << sessoes[i + (SESSOES_POR_PAGINA*pagina)].getData().getValor() << endl;
                cout << "Horario: " << sessoes[i + (SESSOES_POR_PAGINA*pagina)].getHorario().getValor() << endl;
                cout << "Idioma: " << sessoes[i + (SESSOES_POR_PAGINA*pagina)].getIdioma().getValor() << endl << endl;
            }

            cout << texto13 << endl;
            sessao_a_excluir = getch() - 48;                                                                  // Leitura do campo de entrada e conversão de ASCII.

            // Vai na excursão selecionada
            for (int j = 0; j < SESSOES_POR_PAGINA; j++){
                if (sessoes[j + (SESSOES_POR_PAGINA*pagina)].getCodigo().getValor() != "NULL"){ //tem que mudar para funcionar, mas a ideia é essa, o retorno da função do serviço deve dar uma lista que vai ter "NULL" caso não exista      // Caso não exista mais excursões
                    if (sessao_a_excluir == (j+1)){
                        // cntrServicoExcursao->descadastrarSessao(sessoes[j + (SESSOES_POR_PAGINA*pagina)]);; TEM QUE IMPLEMENTAR NO SERVIÇO
                    }
                }
            }
        }
        else if (campo1 == prox_pag){
            pagina++;
        }
        else if (campo1 == pag_ant && pagina != 0){
            pagina--;
        }
        else if (campo1 == num_opcoes){
            apresentar = false;
        }
    }
}