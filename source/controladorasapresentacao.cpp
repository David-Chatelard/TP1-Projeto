#include "../headers/controladorasapresentacao.h"

//--------------------------------------------------------------------------------------------
// Implementação de métodos da classe CntrApresentacaoControle

void fixBuffer(){
    if(cin.peek()=='\n'){
        cin.ignore();
    }
}

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

    bool apresentar1 = true;                                                                     // Controle de laço
    bool apresentar2 = true;
    while(apresentar1){

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
                        bool apresentar2 = true;                                                 // Controle de laço.
                        while(apresentar2){

                            // Apresenta tela de seleção de serviço.

                            CLR_SCR;                                                            // Limpa janela.

                            cout << texto6 << endl;                                             // Imprime nome do campo.
                            cout << texto7 << endl;                                             // Imprime nome do campo.
                            cout << texto8 << endl;                                             // Imprime nome do campo.
                            cout << texto9 << endl;                                             // Imprime nome do campo.

                            campo = getch() - 48;                                               // Leitura do campo de entrada e conversão de ASCII.

                            switch(campo){
                                case 1: cntrApresentacaoContas->executar(email, &apresentar2);                // Solicita serviço de contas.
                                        break;
                                case 2: cntrApresentacaoExcursao->executar(email);              // Solicita serviço de excursão.
                                        break;
                                case 3: apresentar2 = false;
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
            case 4: apresentar1 = false;
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
        fixBuffer();
        cin >> campo1;                                                                          // Le valor do campo.
        cout << texto2 << " ";                                                                  // Imprime nome do campo.
        fixBuffer();
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

void CntrApresentacaoContas::executar(Email email, bool *autenticado){

    // Mensagens a serem apresentadas na tela de sele��o de servi�o..

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Editar conta";
    char texto3[]="2 - Descadastrar conta";
    char texto4[]="3 - Digite algo para retornar para a lista de servicos";
    char texto5[]="Digite o novo nome: ";
    char texto6[]="Digite a nova senha: ";
    char texto7[]="Dado em formato incorreto. Digite algo.";

    int campo1;                                                                                  // Campo de entrada.
    char auxNome[80];
    char auxSenha[80];

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
                        fixBuffer();
                        cin.getline(auxNome,79);
                        cout << texto6;
                        fixBuffer();
                        cin >> auxSenha;
                        
                        try{
                            nome.setValor(auxNome);
                            senha.setValor(auxSenha);
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
                    usuario.setEmail(email);
                    cntrServicoContas->editar(usuario); //RETORNA BOOLEAN, da para usar isso caso queira
                    break;
            case 2: cntrServicoContas->descadastrar(email);                                     //Descadastrar conta
                    *autenticado = false;
                    apresentar = false;
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
        cout << texto1 << " ";    
        fixBuffer();                                                              // Imprime nome do campo.
        cin.getline(campo1,79);                                                                          // Le valor do campo.
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
// Implementação de métodos da classe CntrApresentacaoExcursao

// Função para quando não está logado e quer ver as excursões
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
            case 1: listarExcursoes();
                    break;
            case 2: apresentar = false;                                                         //Voltar para a lista de servicos
                    break;
        }
    }
}

// Função para quando está logado e quer ver as excursões, suas excursões, suas avaliações ou cadastrar excursão
void CntrApresentacaoExcursao::executar(Email email){ 

    // Mensagens a serem apresentadas na tela de sele��o de servi�o..

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Listar todas as excursoes";
    char texto3[]="2 - Listar minhas excursoes";
    char texto12[]="3 - Listar minhas avaliacoes";
    char texto4[]="4 - Cadastrar excursao";
    char texto5[]="5 - Retornar para o menu";
    char texto6[]="Digite o titulo: ";
    char texto7[]="Digite a cidade: ";
    char texto8[]="Digite a duracao: ";
    char texto9[]="Digite a descricao: ";
    char texto10[]="Digite o endereco: ";
    char texto11[]="Dado em formato incorreto. Digite algo.";

    int campo1;                                                                                  // Campo de entrada.
    char campo2[80];
    char campo3[80];
    char campo4[80];
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
        cout << texto12 << endl;                                                                // Imprime nome do campo.
        cout << texto4 << endl;                                                                 // Imprime nome do campo.
        cout << texto5 << endl;                                                                 // Imprime nome do campo.
    
        campo1 = getch() - 48;                                                                  // Leitura do campo de entrada e conversão de ASCII.

        switch(campo1){
            case 1: listarExcursoes2();
                break;
            case 2: listarExcursoes(email);
                break;
            case 3:     // Listar suas avaliações
                listarAvaliacoes(email);
                break;
            case 4:     // Cadastrar excursão
                while(true){
                    CLR_SCR;
                    cout << texto6;                                                         // Imprime os textos de cadastro da excursão
                    fixBuffer();
                    cin.getline(campo2,79);                                                         // Le os inputs da excursão
                    cout << texto7;
                    fixBuffer();
                    cin.getline(campo3,79);
                    cout << texto8;
                    cin >> campo4;
                    cout << texto9;
                    fixBuffer();
                    cin.getline(campo5,79);
                    cout << texto10;
                    fixBuffer();
                    cin.getline(campo6,79);

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
                // cntrServicoExcursao->cadastrarExcursao(excursao); //RETORNA BOOLEAN, da para usar isso caso queira                             //Cadastrar excursao
                break;
            case 5: apresentar = false;                                                                             //Voltar para a lista de servicos
                break;
        }
    }
}

// Função que lista todas as excursões quando não está logado
void CntrApresentacaoExcursao::listarExcursoes(){
    const int EXCURSOES_POR_PAGINA = 5;
    vector<Excursao> excursoes = cntrServicoExcursao->listarExcursoes();
    int pagina=0, i, j, prox_pag=-1, pag_ant=-1, num_opcoes=0, num_excursoes = excursoes.size(), excursoes_mostradas=0, excursoes_mostradas_pag=0;
    bool apresentar=true;
    int campo1;

    char texto1[]="Lista de excursoes";
    char texto2[]=" - Proxima pagina";
    char texto3[]=" - Pagina anterior";
    char texto4[]=" - Retornar a selecao de servicos";

    while (apresentar){
        prox_pag=-1;
        pag_ant=-1;
        num_opcoes=0;

        CLR_SCR;                                                                                // Limpa janela.
        cout << texto1 << endl;                                                                 // Imprime nome do campo.

        excursoes_mostradas_pag = 0;
        // Imprimir os titulos das excursões
        for (i = 0; i < EXCURSOES_POR_PAGINA; i++){                                             // Imprime as avaliações
            if (excursoes_mostradas >= num_excursoes){     // Caso não exista mais excursões
                break;
            }
            cout << i+1 << " - ";                                                               // Imprime "Num - "
            cout << excursoes[i + (EXCURSOES_POR_PAGINA*pagina)].getTitulo().getValor() << endl;
            excursoes_mostradas++;
            excursoes_mostradas_pag++;
        }

        // Imprimir "Próxima página", se existirem mais excursões
        if (excursoes_mostradas < num_excursoes) {  // Caso exista mais excursoes
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
        for (j = 0; j < excursoes_mostradas_pag; j++){
            if (campo1 == (j+1)){
                int aux = excursoes_mostradas;
                excursoes_mostradas -= excursoes_mostradas_pag;
                detalheExcursao(excursoes[j + (EXCURSOES_POR_PAGINA*pagina)]);
            }
        }
        
        if (campo1 == prox_pag){
            pagina++;
        }
        else if (campo1 == pag_ant){
            pagina--;
            excursoes_mostradas -= (EXCURSOES_POR_PAGINA + excursoes_mostradas_pag);
        }
        else if (campo1 == (i+1+num_opcoes)){
            apresentar = false;
        }
    }
}

// Função que lista todas as excursões quando está logado, tem diferença da função de cima, porque a partir dessa quando entrar nos detalhes de uma excursão pode cadastrar uma avaliação
void CntrApresentacaoExcursao::listarExcursoes2(){
    const int EXCURSOES_POR_PAGINA = 5;
    vector<Excursao> excursoes = cntrServicoExcursao->listarExcursoes();
    int pagina=0, i, j, prox_pag=-1, pag_ant=-1, num_opcoes=0, num_excursoes = excursoes.size(), excursoes_mostradas=0, excursoes_mostradas_pag=0;
    bool apresentar=true;
    int campo1;

    char texto1[]="Lista de excursoes";
    char texto2[]=" - Proxima pagina";
    char texto3[]=" - Pagina anterior";
    char texto4[]=" - Retornar a selecao de servicos";

    while (apresentar){
        prox_pag=-1;
        pag_ant=-1;
        num_opcoes=0;

        CLR_SCR;                                                                                // Limpa janela.
        cout << texto1 << endl;                                                                 // Imprime nome do campo.

        excursoes_mostradas_pag = 0;
        // Imprimir os titulos das excursões
        for (i = 0; i < EXCURSOES_POR_PAGINA; i++){                                             // Imprime as avaliações
            if (excursoes_mostradas >= num_excursoes){     // Caso não exista mais excursões
                break;
            }
            cout << i+1 << " - ";                                                               // Imprime "Num - "
            cout << excursoes[i + (EXCURSOES_POR_PAGINA*pagina)].getTitulo().getValor() << endl;
            excursoes_mostradas++;
            excursoes_mostradas_pag++;
        }

        // Imprimir "Próxima página", se existirem mais excursões
        if (excursoes_mostradas < num_excursoes) {  // Caso exista mais excursoes
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
        for (j = 0; j < excursoes_mostradas_pag; j++){
            if (campo1 == (j+1)){
                int aux = excursoes_mostradas;
                excursoes_mostradas -= excursoes_mostradas_pag;
                detalheExcursao(excursoes[j + (EXCURSOES_POR_PAGINA*pagina)]);
            }
        }
        
        if (campo1 == prox_pag){
            pagina++;
        }
        else if (campo1 == pag_ant){
            pagina--;
            excursoes_mostradas -= (EXCURSOES_POR_PAGINA + excursoes_mostradas_pag);
        }
        else if (campo1 == (i+1+num_opcoes)){
            apresentar = false;
        }
    }
}

// Função que lista as suas excursões e depois permite cadastrar/editar/remover sessões ou cadastrar avaliações
void CntrApresentacaoExcursao::listarExcursoes(Email email){
    const int EXCURSOES_POR_PAGINA = 5;
    vector<Excursao> excursoes = cntrServicoExcursao->listarExcursoes(email);
    int pagina=0, i, j, prox_pag=-1, pag_ant=-1, num_opcoes=0, num_excursoes = excursoes.size(), excursoes_mostradas=0, excursoes_mostradas_pag=0;
    bool apresentar=true;
    int campo1;

    char texto1[]="Lista de excursoes";
    char texto2[]=" - Proxima pagina";
    char texto3[]=" - Pagina anterior";
    char texto4[]=" - Retornar a selecao de servicos";

    while (apresentar){
        vector<Excursao> excursoes = cntrServicoExcursao->listarExcursoes(email);
        num_excursoes = excursoes.size();

        prox_pag=-1;
        pag_ant=-1;
        num_opcoes=0;

        CLR_SCR;                                                                                // Limpa janela.
        cout << texto1 << endl;                                                                 // Imprime nome do campo.

        excursoes_mostradas_pag = 0;
        // Imprimir os titulos das excursões
        for (i = 0; i < EXCURSOES_POR_PAGINA; i++){                                             // Imprime as avaliações
            if (excursoes_mostradas >= num_excursoes){     // Caso não exista mais excursões
                break;
            }
            cout << i+1 << " - ";                                                               // Imprime "Num - "
            cout << excursoes[i + (EXCURSOES_POR_PAGINA*pagina)].getTitulo().getValor() << endl;
            excursoes_mostradas++;
            excursoes_mostradas_pag++;
        }

        // Imprimir "Próxima página", se existirem mais excursões
        if (excursoes_mostradas < num_excursoes) {
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
        for (j = 0; j < excursoes_mostradas_pag; j++){
            if (campo1 == (j+1)){
                int aux = excursoes_mostradas;
                excursoes_mostradas -= excursoes_mostradas_pag;
                detalheExcursao(email, excursoes[j + (EXCURSOES_POR_PAGINA*pagina)]);
            }
        }
        
        if (campo1 == prox_pag){
            pagina++;
        }
        else if (campo1 == pag_ant){
            pagina--;
            excursoes_mostradas -= (EXCURSOES_POR_PAGINA + excursoes_mostradas_pag);
        }
        else if (campo1 == (i+1+num_opcoes)){
            apresentar = false;
        }
    }
}

// Função que mostra os detalhes da excursão quando não está logado e permite ver as sessões e avaliações
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
            case 1: listarAvaliacoes(excursao);
                break;
            case 2: listarSessoes(excursao);
                break;
            case 3: apresentar = false;
                break;
        }
    }
}

// Função que mostra os detalhes da excursão quando está logado e permite ver as sessões e avaliações e permite cadastrar avaliações
void CntrApresentacaoExcursao::detalheExcursao2(Excursao excursao){
    char texto1[] = "Informacoes sobre a excursao";
    char texto2[] = "Titulo: ";
    char texto3[] = "Nota: ";
    char texto4[] = "Cidade: ";
    char texto5[] = "Duracao: ";
    char texto6[] = "Descricao: ";
    char texto7[] = "Endereco: ";
    char texto8[] = "1 - Avaliacoes dessa excursao";
    char texto9[] = "2 - Sessoes dessa excursao";
    char texto11[] = "3 - Cadastrar avaliacao";
    char texto10[] = "4 - Retornar para a lista de excursoes";
    char texto12[] = "Informacoes da avaliacao a ser cadastrada";
    char texto13[] = "Nota: ";
    char texto14[] = "Descricao: ";
    char texto15[] = "Dado em formato incorreto. Digite algo.";

    Avaliacao avaliacao;

    Nota nota;
    Descricao descricao;

    char auxNota[80];
    char auxDescricao[80];

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
            case 1: listarAvaliacoes(excursao);
                break;
            case 2: listarSessoes(excursao);
                break;
            case 3: // cadastrar avaliação
                while(true) {
                    CLR_SCR;
                    cout << texto12 << endl;
                    cout << texto13;
                    cin >> auxNota;
                    cout << texto14;
                    fixBuffer();
                    cin.getline(auxDescricao,79);

                    try {
                        nota.setValor(stoi(auxNota));
                        descricao.setValor(auxDescricao);
                        avaliacao.setNota(nota);
                        avaliacao.setDescricao(descricao);
                        break;
                    }
                    catch(invalid_argument &exp) {
                        CLR_SCR;
                        cout << texto15 << endl;
                        getch();
                    }
                }
                // cntrServicoExcursao->cadastrarAvaliacao(avaliacao);
                break;
            case 4: apresentar = false;
                break;
        }
    }
}

// Função que mostra os detalhes da sua excursão(podendo editar e descadastrar ela) quando está logado e permite ver as sessões e avaliações e permite cadastrar sessões e avaliações
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
    char texto20[] = "3 - Cadastrar sessao";
    char texto21[] = "4 - Cadastrar avaliacao";
    char texto10[] = "5 - Editar excursao";
    char texto11[] = "6 - Descadastrar excursao";
    char texto12[] = "7 - Retornar para a lista de excursoes";
    char texto13[] = "Novo Titulo: ";
    char texto14[] = "Nova Nota: ";
    char texto15[] = "Nova Cidade: ";
    char texto16[] = "Nova Duracao: ";
    char texto17[] = "Nova Descricao: ";
    char texto18[] = "Novo Endereco: ";
    char texto19[] = "Dado em formato incorreto. Digite algo.";
    char texto22[] = "Informacoes da sessao a ser cadastrada";
    char texto23[] = "Data: ";
    char texto24[] = "Horario: ";
    char texto25[] = "Idioma: ";
    char texto26[] = "Informacoes da avaliacao a ser cadastrada";
    char texto27[] = "Nota: ";
    char texto28[] = "Descricao: ";

    bool apresentar=true;

    Titulo titulo;
    Nota nota;
    Cidade cidade;
    Duracao duracao;
    Descricao descricao;
    Endereco endereco;

    Sessao sessao;

    Avaliacao avaliacao;

    Data data;
    Horario horario;
    Idioma idioma;

    Nota notaAvaliacao;
    Descricao descricaoAvaliacao;

    char auxTitulo[80];
    char auxNota[80];
    char auxCidade[80];
    char auxDuracao[80];
    char auxDescricao[80];
    char auxEndereco[80];

    char auxData[80];
    char auxHorario[80];
    char auxIdioma[80];

    char auxNotaAvaliacao[80];
    char auxDescricaoAvaliacao[80];

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
        cout << texto20 << endl;
        cout << texto21 << endl;
        cout << texto10 << endl;
        cout << texto11 << endl;
        cout << texto12 << endl;

        campo1 = getch() - 48;

        switch (campo1) {
            case 1: listarAvaliacoes(excursao);
                break;
            case 2: listarSessoes(email, excursao);
                break;
            case 3: // cadastrar sessão
                while(true) {
                    CLR_SCR;
                    cout << texto22 << endl;
                    cout << texto23;
                    cin >> auxData;
                    cout << texto24;
                    cin >> auxHorario;
                    cout << texto25;
                    cin >> auxIdioma;

                    try {
                        data.setValor(auxData);
                        horario.setValor(auxHorario);
                        idioma.setValor(auxIdioma);
                        sessao.setData(data);
                        sessao.setHorario(horario);
                        sessao.setIdioma(idioma);
                        break;
                    }
                    catch(invalid_argument &exp) {
                        CLR_SCR;
                        cout << texto19 << endl;
                        getch();
                    }
                }
                // cntrServicoExcursao->cadastrarSessao(sessao);
                break;
            case 4: // cadastrar avaliação
                while(true) {
                    CLR_SCR;
                    cout << texto26 << endl;
                    cout << texto27;
                    cin >> auxNotaAvaliacao;
                    cout << texto28;
                    fixBuffer();
                    cin.getline(auxDescricaoAvaliacao,79);

                    try {
                        notaAvaliacao.setValor(stoi(auxNotaAvaliacao));
                        descricaoAvaliacao.setValor(auxDescricaoAvaliacao);
                        avaliacao.setNota(notaAvaliacao);
                        avaliacao.setDescricao(descricaoAvaliacao);
                        break;
                    }
                    catch(invalid_argument &exp) {
                        CLR_SCR;
                        cout << texto19 << endl;
                        getch();
                    }
                }
                // cntrServicoExcursao->cadastrarAvaliacao(avaliacao);
                break;
            case 5: // editar excursão
                while(true) {
                    CLR_SCR;
                    cout << texto13;
                    fixBuffer();
                    cin.getline(auxTitulo,79);
                    // cin >> auxTitulo;
                    cout << texto14;
                    cin >> auxNota;
                    cout << texto15;
                    fixBuffer();
                    cin.getline(auxCidade,79);
                    // cin >> auxCidade;
                    cout << texto16;
                    cin >> auxDuracao;
                    cout << texto17;
                    fixBuffer();
                    cin.getline(auxDescricao,79);
                    // cin >> auxDescricao;
                    cout << texto18;
                    fixBuffer();
                    cin.getline(auxEndereco,79);
                    // cin >> auxEndereco;
                    try {
                        titulo.setValor(auxTitulo);
                        nota.setValor(stoi(auxNota));
                        cidade.setValor(auxCidade);
                        duracao.setValor(stoi(auxDuracao));
                        descricao.setValor(auxDescricao);
                        endereco.setValor(auxEndereco);
                        excursao.setTitulo(titulo);
                        excursao.setNota(nota);
                        excursao.setCidade(cidade);
                        excursao.setDuracao(duracao);
                        excursao.setDescricao(descricao);
                        excursao.setEndereco(endereco);
                        break;
                    }
                    catch(invalid_argument &exp){
                        CLR_SCR;
                        cout << texto19 << endl;
                        getch();
                    }
                }
                cntrServicoExcursao->editarExcursao(excursao);
                break;
            case 6: apresentar = false; 
                cntrServicoExcursao->descadastrarExcursao(excursao);
                break;
            case 7: apresentar = false;
                break;
        }
    }
}

// Função que lista as avaliações de uma excursão
void CntrApresentacaoExcursao::listarAvaliacoes(Excursao excursao){ // A versão que aceita email vai ser pra listar as minhas avaliacoes e vai mudar no metodo de pegar as avaliacoes e que vai poder editar/excluir as avaliacoes
    const int AVALIACOES_POR_PAGINA = 5;
    vector<Avaliacao> avaliacoes = cntrServicoExcursao->listarAvaliacoes(excursao.getCodigo());
    int pagina=0, i, num_opcoes=1, prox_pag=0, pag_ant=1, num_avaliacoes = avaliacoes.size(), avaliacoes_mostradas=0, avaliacoes_mostradas_pag=0;
    bool apresentar=true;
    int campo1;

    char texto1[]="Lista de avaliacoes";
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

        avaliacoes_mostradas_pag = 0;
        for (i = 0; i < AVALIACOES_POR_PAGINA; i++){                                        // Imprime as avaliações
            if (avaliacoes_mostradas >= num_avaliacoes){ //tem que mudar para funcionar, mas a ideia é essa, o retorno da função do serviço deve dar uma lista que vai ter "NULL" caso não exista      // Caso não exista mais avaliações
                break;
            }
            cout << texto2 << (i + 1) + (AVALIACOES_POR_PAGINA*pagina) << endl;
            cout << "Nota: " << avaliacoes[i + (AVALIACOES_POR_PAGINA*pagina)].getNota().getValor() << endl;
            cout << "Descricao: " << avaliacoes[i + (AVALIACOES_POR_PAGINA*pagina)].getDescricao().getValor() << endl << endl;
            avaliacoes_mostradas++;
            avaliacoes_mostradas_pag++;
        }

        // Imprimir "Próxima página", se existirem mais avaliações
        if (avaliacoes_mostradas < num_avaliacoes){
            prox_pag++;
            cout << prox_pag << texto3 << endl;                                                                 // Opção de próxima página
            num_opcoes++;
            pag_ant++;
        }

        // Imprimir "Página anterior", se não estiver na primeira página
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
            avaliacoes_mostradas -= (AVALIACOES_POR_PAGINA + avaliacoes_mostradas_pag);
        }
        else if (campo1 == num_opcoes){
            apresentar = false;
        }
    }
}

// Função que lista todas as suas avaliações e permite editar/descadastrar uma avaliação
void CntrApresentacaoExcursao::listarAvaliacoes(Email email){ // A versão que aceita email vai ser pra listar as minhas avaliacoes e vai mudar no metodo de pegar as avaliacoes e que vai poder editar/excluir as avaliacoes
    const int AVALIACOES_POR_PAGINA = 5;
    vector<Avaliacao> avaliacoes = cntrServicoExcursao->listarAvaliacoes(email);


    int pagina=0, i, num_opcoes=1, prox_pag=0, pag_ant=1, num_avaliacoes = avaliacoes.size(), avaliacoes_mostradas=0, avaliacoes_mostradas_pag=0;
    int campo1;

    char avaliacao_a_editar[10];
    char avaliacao_a_excluir[10];

    bool apresentar=true;
    
    char aux_nota[80];
    char aux_descricao[80];

    Avaliacao avaliacao;
    Nota nota;
    Descricao descricao;

    char texto1[]="Lista de avaliacoes";
    char texto2[]="Avaliacao ";
    char texto3[]="1 - Editar avaliacao";
    char texto4[]="2 - Descadastrar avaliacao";
    char texto5[]=" - Proxima pagina";
    char texto6[]=" - Pagina anterior";
    char texto7[]=" - Retornar para a lista de servicos";
    char texto8[]="Digite o numero da avaliacao que deseja editar";
    char texto9[]="Nova nota: ";
    char texto10[]="Nova descricao: ";
    char texto12[]="Dado em formato incorreto. Digite algo.";
    char texto13[]="Digite o numero da avaliacao que deseja descadastrar";
    
    while (apresentar){
        vector<Avaliacao> avaliacoes = cntrServicoExcursao->listarAvaliacoes(email);
        num_avaliacoes = avaliacoes.size();

        num_opcoes=3;
        prox_pag=0;
        pag_ant=3;

        CLR_SCR;                                                                                // Limpa janela.
        cout << texto1 << endl;

        avaliacoes_mostradas_pag = 0;
        // Mostra as avaliacoes na tela
        for (i = 0; i < AVALIACOES_POR_PAGINA; i++){                                        // Imprime as sessões
            if (avaliacoes_mostradas >= num_avaliacoes){ //tem que mudar para funcionar, mas a ideia é essa, o retorno da função do serviço deve dar uma lista que vai ter "NULL" caso não exista      // Caso não exista mais avaliações
                break;
            }
            cout << texto2 << (i + 1) + (AVALIACOES_POR_PAGINA*pagina) << endl;
            cout << "Nota: " << avaliacoes[i + (AVALIACOES_POR_PAGINA*pagina)].getNota().getValor() << endl;
            cout << "Descricao: " << avaliacoes[i + (AVALIACOES_POR_PAGINA*pagina)].getDescricao().getValor() << endl << endl;
            avaliacoes_mostradas++;
            avaliacoes_mostradas_pag++;
        }

        cout << texto3 << endl;
        cout << texto4 << endl;

        // Imprimir "Próxima página", se existirem mais avaliações
        if (avaliacoes_mostradas < num_avaliacoes){
            prox_pag = 3;
            cout << prox_pag << texto5 << endl;                                                                 // Opção de próxima página
            num_opcoes++;
            pag_ant++;
        }

        // Imprimir "Página anterior", se não estiver na primeira página
        if (pagina != 0){
            cout << pag_ant << texto6 << endl;                                                                 // Opção de página anterior
            num_opcoes++;
        }
        cout << num_opcoes << texto7 << endl;                                                                 // Imprime nome do campo.
    
        campo1 = getch() - 48;                                                                                // Leitura do campo de entrada e conversão de ASCII.

        if (campo1 == 1) { // editar avaliação
            CLR_SCR;                                                                                // Limpa janela.
            cout << texto1 << endl;

            avaliacoes_mostradas -= avaliacoes_mostradas_pag;
            avaliacoes_mostradas_pag = 0;
            // Mostra as avaliacoes
            for (i = 0; i < AVALIACOES_POR_PAGINA; i++){                                        // Imprime as sessões
                if (avaliacoes_mostradas >= num_avaliacoes){ //tem que mudar para funcionar, mas a ideia é essa, o retorno da função do serviço deve dar uma lista que vai ter "NULL" caso não exista      // Caso não exista mais avaliações
                    break;
                }
                cout << texto2 << (i + 1) + (AVALIACOES_POR_PAGINA*pagina) << endl;
                cout << "Nota: " << avaliacoes[i + (AVALIACOES_POR_PAGINA*pagina)].getNota().getValor() << endl;
                cout << "Descricao: " << avaliacoes[i + (AVALIACOES_POR_PAGINA*pagina)].getDescricao().getValor() << endl << endl;
                avaliacoes_mostradas++;
                avaliacoes_mostradas_pag++;
            }

            cout << texto8 << endl;
            cin >> avaliacao_a_editar;

            // Vai na avaliacao selecionada
            for (int j = 0; j < AVALIACOES_POR_PAGINA; j++){
                if (stoi(avaliacao_a_editar) == ((j + 1) + (AVALIACOES_POR_PAGINA*pagina))){
                    while (true){
                        CLR_SCR;
                        cout << texto9;
                        cin >> aux_nota;
                        cout << texto10;
                        fixBuffer();
                        cin.getline(aux_descricao,79);
                        try {
                            nota.setValor(stoi(aux_nota));
                            descricao.setValor(aux_descricao);
                            avaliacao.setCodigo(avaliacoes[j + (AVALIACOES_POR_PAGINA*pagina)].getCodigo());
                            avaliacao.setNota(nota);
                            avaliacao.setDescricao(descricao);
                            break;
                        }
                        catch(invalid_argument &exp) {
                            CLR_SCR;
                            cout << texto12 << endl;
                            getch();
                        }
                    }
                    cntrServicoExcursao->editarAvaliacao(avaliacao);
                }
            }
            avaliacoes_mostradas -= avaliacoes_mostradas_pag;
        }
        else if (campo1 == 2) { //descadastrar avaliação
            CLR_SCR;                                                                                // Limpa janela.
            cout << texto1 << endl;

            avaliacoes_mostradas -= avaliacoes_mostradas_pag;
            avaliacoes_mostradas_pag = 0;
            // Mostra as avaliacoes
            for (i = 0; i < AVALIACOES_POR_PAGINA; i++){                                        // Imprime as sessões
                if (avaliacoes_mostradas >= num_avaliacoes){ //tem que mudar para funcionar, mas a ideia é essa, o retorno da função do serviço deve dar uma lista que vai ter "NULL" caso não exista      // Caso não exista mais avaliações
                    break;
                }
                cout << texto2 << (i + 1) + (AVALIACOES_POR_PAGINA*pagina) << endl;
                cout << "Nota: " << avaliacoes[i + (AVALIACOES_POR_PAGINA*pagina)].getNota().getValor() << endl;
                cout << "Descricao: " << avaliacoes[i + (AVALIACOES_POR_PAGINA*pagina)].getDescricao().getValor() << endl << endl;
                avaliacoes_mostradas++;
                avaliacoes_mostradas_pag++;
            }

            cout << texto13 << endl;
            cin >> avaliacao_a_excluir;

            // Vai na avaliacao selecionada
            for (int j = 0; j < AVALIACOES_POR_PAGINA; j++){
                if (stoi(avaliacao_a_excluir) == ((j + 1) + (AVALIACOES_POR_PAGINA*pagina))){
                    cntrServicoExcursao->descadastrarAvaliacao(avaliacoes[j + (AVALIACOES_POR_PAGINA*pagina)]);
                }
            }
            avaliacoes_mostradas -= avaliacoes_mostradas_pag;
        }
        else if (campo1 == prox_pag){
            pagina++;
        }
        else if (campo1 == pag_ant && pagina != 0){
            pagina--;
            avaliacoes_mostradas -= (AVALIACOES_POR_PAGINA + avaliacoes_mostradas_pag);
        }
        else if (campo1 == num_opcoes){
            apresentar = false;
        }
    }
}

// Função que lista as sessões de uma excursão
void CntrApresentacaoExcursao::listarSessoes(Excursao excursao){
    const int SESSOES_POR_PAGINA = 5;
    vector<Sessao> sessoes = cntrServicoExcursao->listarSessoes(excursao.getCodigo());
    int pagina=0, i, num_opcoes=1, prox_pag=0, pag_ant=1, num_sessoes = sessoes.size(), sessoes_mostradas=0, sessoes_mostradas_pag=0;
    bool apresentar=true;
    int campo1;

    char texto1[]="Lista de sessoes";
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

        sessoes_mostradas_pag = 0;
        // Mostra as sessoes na tela
        for (i = 0; i < SESSOES_POR_PAGINA; i++){                                        // Imprime as sessões
            if (sessoes_mostradas >= num_sessoes){ //tem que mudar para funcionar, mas a ideia é essa, o retorno da função do serviço deve dar uma lista que vai ter "NULL" caso não exista      // Caso não exista mais avaliações
                break;
            }
            cout << texto2 << (i + 1) + (SESSOES_POR_PAGINA*pagina) << endl;
            cout << "Data: " << sessoes[i + (SESSOES_POR_PAGINA*pagina)].getData().getValor() << endl;
            cout << "Horario: " << sessoes[i + (SESSOES_POR_PAGINA*pagina)].getHorario().getValor() << endl;
            cout << "Idioma: " << sessoes[i + (SESSOES_POR_PAGINA*pagina)].getIdioma().getValor() << endl << endl;
            sessoes_mostradas++;
            sessoes_mostradas_pag++;
        }

        // Imprimir "Próxima página", se existirem mais sessões
        if (sessoes_mostradas < num_sessoes){
            prox_pag++;
            cout << prox_pag << texto3 << endl;                                                                 // Opção de próxima página
            num_opcoes++;
            pag_ant++;
        }

        // Imprimir "Página anterior", se não estiver na primeira página
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
            sessoes_mostradas -= (SESSOES_POR_PAGINA + sessoes_mostradas_pag);
        }
        else if (campo1 == num_opcoes){
            apresentar = false;
        }
    }
}

// Função que lista as sessões de uma excursão e permite editar/descadastrar uma sessão
void CntrApresentacaoExcursao::listarSessoes(Email email, Excursao excursao){
    const int SESSOES_POR_PAGINA = 5;
    vector<Sessao> sessoes = cntrServicoExcursao->listarSessoes(excursao.getCodigo());

    int pagina=0, i, num_opcoes=1, prox_pag=0, pag_ant=1, num_sessoes = sessoes.size(), sessoes_mostradas=0, sessoes_mostradas_pag=0;
    int campo1;

    char sessao_a_editar[10];
    char sessao_a_excluir[10];

    bool apresentar=true;
    
    char aux_data[80];
    char aux_horario[80];
    char aux_idioma[80];

    Sessao sessao;
    Codigo codigo;
    Data data;
    Horario horario;
    Idioma idioma;

    char texto1[]="Lista de sessoes";
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
        vector<Sessao> sessoes = cntrServicoExcursao->listarSessoes(excursao.getCodigo());
        num_sessoes = sessoes.size();

        num_opcoes=3;
        prox_pag=0;
        pag_ant=3;

        CLR_SCR;                                                                                // Limpa janela.
        cout << texto1 << endl;

        sessoes_mostradas_pag = 0;
        // Mostra as sessoes na tela
        for (i = 0; i < SESSOES_POR_PAGINA; i++){                                        // Imprime as sessões
            if (sessoes_mostradas >= num_sessoes){ //tem que mudar para funcionar, mas a ideia é essa, o retorno da função do serviço deve dar uma lista que vai ter "NULL" caso não exista      // Caso não exista mais avaliações
                break;
            }
            cout << texto2 << (i + 1) + (SESSOES_POR_PAGINA*pagina) << endl;
            cout << "Data: " << sessoes[i + (SESSOES_POR_PAGINA*pagina)].getData().getValor() << endl;
            cout << "Horario: " << sessoes[i + (SESSOES_POR_PAGINA*pagina)].getHorario().getValor() << endl;
            cout << "Idioma: " << sessoes[i + (SESSOES_POR_PAGINA*pagina)].getIdioma().getValor() << endl << endl;
            sessoes_mostradas++;
            sessoes_mostradas_pag++;
        }

        cout << texto3 << endl;
        cout << texto4 << endl;

        // Imprimir "Próxima página", se existirem mais sessões
        if (sessoes_mostradas < num_sessoes){
            prox_pag = 3;
            cout << prox_pag << texto5 << endl;                                                                 // Opção de próxima página
            num_opcoes++;
            pag_ant++;
        }

        // Imprimir "Próxima página", se existirem mais sessões
        if (pagina != 0){
            cout << pag_ant << texto6 << endl;                                                                 // Opção de página anterior
            num_opcoes++;
        }
        cout << num_opcoes << texto7 << endl;                                                                 // Imprime nome do campo.
    
        campo1 = getch() - 48;                                                                                // Leitura do campo de entrada e conversão de ASCII.

        if (campo1 == 1) { // editar sessão
            CLR_SCR;                                                                                // Limpa janela.
            cout << texto1 << endl;

            sessoes_mostradas -= sessoes_mostradas_pag;
            sessoes_mostradas_pag = 0;
            // Mostra as sessoes
            for (i = 0; i < SESSOES_POR_PAGINA; i++){                                        // Imprime as sessões
                if (sessoes_mostradas >= num_sessoes){ //tem que mudar para funcionar, mas a ideia é essa, o retorno da função do serviço deve dar uma lista que vai ter "NULL" caso não exista      // Caso não exista mais avaliações
                    break;
                }
                cout << texto2 << (i + 1) + (SESSOES_POR_PAGINA*pagina) << endl;
                cout << "Data: " << sessoes[i + (SESSOES_POR_PAGINA*pagina)].getData().getValor() << endl;
                cout << "Horario: " << sessoes[i + (SESSOES_POR_PAGINA*pagina)].getHorario().getValor() << endl;
                cout << "Idioma: " << sessoes[i + (SESSOES_POR_PAGINA*pagina)].getIdioma().getValor() << endl << endl;
                sessoes_mostradas++;
                sessoes_mostradas_pag++;
            }

            cout << texto8 << endl;
            cin >> sessao_a_editar;

            // Vai na sessao selecionada
            for (int j = 0; j < SESSOES_POR_PAGINA; j++){
                if (stoi(sessao_a_editar) == ((j + 1) + (SESSOES_POR_PAGINA*pagina))){
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
                    cntrServicoExcursao->editarSessao(sessao);
                }
            }
            sessoes_mostradas -= sessoes_mostradas_pag;
        }
        else if (campo1 == 2) { //descadastrar sessão
            CLR_SCR;                                                                                // Limpa janela.
            cout << texto1 << endl;

            sessoes_mostradas -= sessoes_mostradas_pag;
            sessoes_mostradas_pag = 0;
            // Mostra as sessoes
            for (i = 0; i < SESSOES_POR_PAGINA; i++){                                        // Imprime as sessões
                if (sessoes_mostradas >= num_sessoes){   // Caso não exista mais avaliações
                    break;
                }
                cout << texto2 << (i + 1) + (SESSOES_POR_PAGINA*pagina) << endl;
                cout << "Data: " << sessoes[i + (SESSOES_POR_PAGINA*pagina)].getData().getValor() << endl;
                cout << "Horario: " << sessoes[i + (SESSOES_POR_PAGINA*pagina)].getHorario().getValor() << endl;
                cout << "Idioma: " << sessoes[i + (SESSOES_POR_PAGINA*pagina)].getIdioma().getValor() << endl << endl;
                sessoes_mostradas++;
                sessoes_mostradas_pag++;
            }

            cout << texto13 << endl;
            cin >> sessao_a_excluir;

            // Vai na sessao selecionada
            for (int j = 0; j < SESSOES_POR_PAGINA; j++){
                if (stoi(sessao_a_excluir) == ((j + 1) + (SESSOES_POR_PAGINA*pagina))){
                    cntrServicoExcursao->descadastrarSessao(sessoes[j + (SESSOES_POR_PAGINA*pagina)]);
                }
            }
            sessoes_mostradas -= sessoes_mostradas_pag;
        }
        else if (campo1 == prox_pag){
            pagina++;
        }
        else if (campo1 == pag_ant && pagina != 0){
            pagina--;
            sessoes_mostradas -= (SESSOES_POR_PAGINA + sessoes_mostradas_pag);
        }
        else if (campo1 == num_opcoes){
            apresentar = false;
        }
    }
}
