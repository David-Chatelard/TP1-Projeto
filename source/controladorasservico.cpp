#include "../headers/controladorasservico.h"

//--------------------------------------------------------------------------------------------
// Implementação de métodos da classe CntrServicoAutenticacao

bool CntrServicoAutenticacao::autenticar(Email email, Senha senha) {
    ComandoLerSenha comandoLerSenha(email);

    try {
        comandoLerSenha.executar();

        string senhaRecuperada;
        senhaRecuperada = comandoLerSenha.getResultado();

        //Comparar senha informada com a senha recuperada.

        if(senhaRecuperada == senha.getValor()) {
            return true;
        }
        return false;
    }
    catch(EErroPersistencia &exp) {
        cout << endl << exp.what();
        return false;
    }
}

//--------------------------------------------------------------------------------------------
// Implementação de métodos da classe CntrServicoContas

bool CntrServicoContas::descadastrar(Email email){
    ComandoRemoverAvaliacao comandoRemoverAvaliacaoAutor(email); //remove todas as avaliacoes desse autor

    ComandoListarExcursoes comandoListarExcursoes(email); //usado para remover as avalicaoes e sessoes das excursoes desse guia
    vector<Excursao> excursoes;
    ComandoRemoverExcursao comandoRemoverExcursaoGuia(email); //remove todas as excursoes desse guia

    ComandoRemoverUsuario comandoRemoverUsuario(email); //remove o usuario

   try{
        comandoRemoverAvaliacaoAutor.executar(); //remove todas as avaliacoes desse autor
        comandoListarExcursoes.executar(); //lista as excursoes para deletar os filhos
        excursoes = comandoListarExcursoes.getResultado();
        for(int i=0; i<excursoes.size(); i++){
            Codigo codigo = excursoes[i].getCodigo();
            ComandoRemoverSessao comandoRemoverSessaoGuia(codigo); //Remove todas as sessoes de cada excursao do guia
            ComandoRemoverAvaliacao comandoRemoverAvaliacaoGuia(codigo); //Remove todas as avaliacoes de cada excursao do guia
            comandoRemoverSessaoGuia.executar();
            comandoRemoverAvaliacaoGuia.executar();
        }
        comandoRemoverExcursaoGuia.executar(); //remove todas as excursoes do autor
        comandoRemoverUsuario.executar(); // remove o usuario
        return true;
    }
    catch(EErroPersistencia &exp) {
        cout << endl << exp.what();
        return false;
    }
}

bool CntrServicoContas::editar(Usuario usuario){
    ComandoAtualizarUsuario comandoAtualizarUsuario(usuario);

    try {
        comandoAtualizarUsuario.executar();
        return true;
    }
    catch(EErroPersistencia &exp) {
        cout << endl << exp.what();
        return false;
    }
}

bool CntrServicoContas::cadastrar(Usuario usuario) {
    ComandoCadastrarUsuario comandoCadastrarUsuario(usuario);
    
    try {
        comandoCadastrarUsuario.executar();
        return true;
    }
    catch(EErroPersistencia &exp) {
        cout << endl << exp.what();
        return false;
    }
    
}

//--------------------------------------------------------------------------------------------
// Implementação de métodos da classe CntrServicoExcursao

// Listar
// Lista as excursões desse email
vector<Excursao> CntrServicoExcursao::listarExcursoes(Email email){
    vector<Excursao> vazio;
    ComandoListarExcursoes comandoListarExcursoes(email);

    try {
        comandoListarExcursoes.executar();
        return comandoListarExcursoes.getResultado();
    }
    catch(EErroPersistencia &exp) {
        cout << endl << exp.what();
    }
    return vazio;

}

// Lista todas as excursões
vector<Excursao> CntrServicoExcursao::listarExcursoes(){
    vector<Excursao> vazio;
    ComandoListarExcursoes comandoListarExcursoes;

    try {
        comandoListarExcursoes.executar();
        return comandoListarExcursoes.getResultado();
    }
    catch(EErroPersistencia &exp) {
        cout << endl << exp.what();
    }
    return vazio;

}

// Lista as avaliações dessa excursao
vector<Avaliacao> CntrServicoExcursao::listarAvaliacoes(Codigo codigo){
    vector<Avaliacao> vazio;
    ComandoListarAvaliacoes comandoListarAvaliacoes(codigo);

    try {
        comandoListarAvaliacoes.executar();
        return comandoListarAvaliacoes.getResultado();
    }
    catch(EErroPersistencia &exp) {
        cout << endl << exp.what();
    }
    return vazio;

}

// Lista as avaliações desse email
vector<Avaliacao> CntrServicoExcursao::listarAvaliacoes(Email email){
    vector<Avaliacao> vazio;
    ComandoListarAvaliacoes comandoListarAvaliacoes(email);

    try {
        comandoListarAvaliacoes.executar();
        return comandoListarAvaliacoes.getResultado();
    }
    catch(EErroPersistencia &exp) {
        cout << endl << exp.what();
    }
    return vazio;

}

// Lista as sessões dessa excursao
vector<Sessao> CntrServicoExcursao::listarSessoes(Codigo codigo){
    vector<Sessao> vazio;
    ComandoListarSessoes comandoListarSessoes(codigo);

    try {
        comandoListarSessoes.executar();
        return comandoListarSessoes.getResultado();
    }
    catch(EErroPersistencia &exp) {
        cout << endl << exp.what();
    }
    return vazio;

}



// Cadastrar
bool CntrServicoExcursao::cadastrarExcursao(Excursao excursao, Email email) {
    ComandoListarExcursoes comandoListarExcursoes; //usado para ver se o codigo gerado ja esta em uso
    vector<Excursao> excursoes;
    Codigo codigo_aux;
    Nota nota;
    
    try{
        comandoListarExcursoes.executar(); //lista as excursoes para comparar o codigo
        excursoes = comandoListarExcursoes.getResultado();
        while (true)
        {
            bool passou = true;
            string aux = codigo_aux.gerarCodigo();
            for (int i = 0; i < excursoes.size(); i++)
            {
                if (aux == excursoes[i].getCodigo().getValor())
                {
                    passou = false;
                    break;
                }
            }
            if (passou)
            {
                codigo_aux.setValor(aux);
                excursao.setCodigo(codigo_aux);
                break;
            }            
        }
        nota.setValor(0);
        excursao.setNota(nota);
        excursao.setEmailGuia(email);
        ComandoCadastrarExcursao comandoCadastrarExcursao(excursao);
        comandoCadastrarExcursao.executar();
        return true;
    }
    catch(EErroPersistencia &exp) {
        cout << endl << exp.what();
        return false;
    }    
}

bool CntrServicoExcursao::cadastrarSessao(Sessao sessao, Excursao excursao) {
    ComandoListarSessoes comandoListarSessoes;
    vector<Sessao> sessoes;
    Codigo codigo_aux;

    try{
        comandoListarSessoes.executar(); //lista as excursoes para comparar o codigo
        sessoes = comandoListarSessoes.getResultado();
        while (true)
        {
            bool passou = true;
            string aux = codigo_aux.gerarCodigo();
            for (int i = 0; i < sessoes.size(); i++)
            {
                if (aux == sessoes[i].getCodigo().getValor())
                {
                    passou = false;
                    break;
                }
            }
            if (passou)
            {
                codigo_aux.setValor(aux);
                sessao.setCodigo(codigo_aux);
                break;
            }            
        }
        sessao.setCodigoExcursao(excursao.getCodigo());
        ComandoCadastrarSessao comandoCadastrarSessao(sessao);
        comandoCadastrarSessao.executar();
        return true;
    }
    catch(EErroPersistencia &exp) {
        cout << endl << exp.what();
        return false;
    }    
}

bool CntrServicoExcursao::cadastrarAvaliacao(Avaliacao avaliacao, Excursao excursao, Email email) {
    ComandoListarAvaliacoes comandoListarAvaliacoes;
    vector<Avaliacao> avaliacoes;
    Codigo codigo_aux;

    try{
        comandoListarAvaliacoes.executar(); //lista as excursoes para comparar o codigo
        avaliacoes = comandoListarAvaliacoes.getResultado();
        while (true)
        {
            bool passou = true;
            string aux = codigo_aux.gerarCodigo();
            for (int i = 0; i < avaliacoes.size(); i++)
            {
                if (aux == avaliacoes[i].getCodigo().getValor())
                {
                    passou = false;
                    break;
                }
            }
            if (passou)
            {
                codigo_aux.setValor(aux);
                avaliacao.setCodigo(codigo_aux);
                break;
            }            
        }        
        avaliacao.setCodigoExcursao(excursao.getCodigo());
        avaliacao.setEmailAutor(email);
        ComandoCadastrarAvaliacao comandoCadastrarAvaliacao(avaliacao);
        comandoCadastrarAvaliacao.executar();
        return true;
    }
    catch(EErroPersistencia &exp) {
        cout << endl << exp.what();
        return false;
    }    
}


// Editar
bool CntrServicoExcursao::editarExcursao(Excursao excursao){
    ComandoAtualizarExcursao comandoAtualizarExcursao(excursao);

    try {
        comandoAtualizarExcursao.executar();
        return true;
    }
    catch(EErroPersistencia &exp) {
        cout << endl << exp.what();
        return false;
    }
}

bool CntrServicoExcursao::editarSessao(Sessao sessao){
    ComandoAtualizarSessao comandoAtualizarSessao(sessao);

    try {
        comandoAtualizarSessao.executar();
        return true;
    }
    catch(EErroPersistencia &exp) {
        cout << endl << exp.what();
        return false;
    }
}

bool CntrServicoExcursao::editarAvaliacao(Avaliacao avaliacao){
    ComandoAtualizarAvaliacao comandoAtualizarAvaliacao(avaliacao);

    try {
        comandoAtualizarAvaliacao.executar();
        return true;
    }
    catch(EErroPersistencia &exp) {
        cout << endl << exp.what();
        return false;
    }
}


// Descadastrar
bool CntrServicoExcursao::descadastrarExcursao(Excursao excursao){ //descadastra uma excursao
    ComandoRemoverAvaliacao comandoRemoverAvaliacao(excursao.getCodigo()); //remove todas as avaliacoes linkadas com essa excursao
    ComandoRemoverSessao comandoRemoverSessao(excursao.getCodigo()); //remove todas as sessoes linkadas com essa excursao
    ComandoRemoverExcursao comandoRemoverExcursao(excursao);

    try{
        comandoRemoverAvaliacao.executar();
        comandoRemoverSessao.executar();
        comandoRemoverExcursao.executar();
        return true;
    }
    catch(EErroPersistencia &exp) {
        cout << endl << exp.what();
        return false;
    }
}

bool CntrServicoExcursao::descadastrarSessao(Sessao sessao){ //descadastra uma sessao
    ComandoRemoverSessao comandoRemoverSessao(sessao);

    try{
        comandoRemoverSessao.executar();
        return true;
    }
    catch(EErroPersistencia &exp) {
        cout << endl << exp.what();
        return false;
    }
}

bool CntrServicoExcursao::descadastrarAvaliacao(Avaliacao avaliacao){ //descadastra uma avaliacao
    ComandoRemoverAvaliacao comandoRemoverAvaliacao(avaliacao);

    try{
        comandoRemoverAvaliacao.executar();
        return true;
    }
    catch(EErroPersistencia &exp) {
        cout << endl << exp.what();
        return false;
    }
}

// Atualizar a nota da excursao para ser a media das notas das avaliacoes dessa excursao

void CntrServicoExcursao::atualizarNotaExcursao(Excursao excursao) {
    ComandoListarAvaliacoes comandoListarAvaliacoes(excursao.getCodigo());
    vector<Avaliacao> avaliacoes;
    int num_notas=0, soma_notas=0;

    Nota nota;

    try{
        comandoListarAvaliacoes.executar();
        avaliacoes = comandoListarAvaliacoes.getResultado();
        for (int i = 0; i < avaliacoes.size(); i++) {
            soma_notas += avaliacoes[i].getNota().getValor();
            num_notas++;
        }
        if (avaliacoes.size() > 0){
            nota.setValor(soma_notas/num_notas);
            excursao.setNota(nota);
            ComandoAtualizarExcursao comandoAtualizarExcursao(excursao);
            comandoAtualizarExcursao.executar();
        }
    }
    catch(EErroPersistencia &exp) {
        cout << endl << exp.what();
    }
}