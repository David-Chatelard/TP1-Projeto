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
// bool CntrServicoExcursao::cadastrarExcursao(Excursao excursao) {
//     ComandoCadastrarExcursao ComandoCadastrarExcursao(excursao);
    
//     try {
//         ComandoCadastrarExcursao.executar();
//         return true;
//     }
//     catch(EErroPersistencia &exp) {
//         cout << endl << exp.what();
//         return false;
//     }
// }

// bool CntrServicoExcursao::cadastrarSessao(Sessao sessao) {
//     ComandoCadastrarSessao ComandoCadastrarSessao(sessao);
    
//     try {
//         ComandoCadastrarSessao.executar();
//         return true;
//     }
//     catch(EErroPersistencia &exp) {
//         cout << endl << exp.what();
//         return false;
//     }
// }

// bool CntrServicoExcursao::cadastrarAvaliacao(Avaliacao avaliacao) {
//     ComandoCadastrarAvaliacao ComandoCadastrarAvaliacao(avaliacao);
    
//     try {
//         ComandoCadastrarAvaliacao.executar();
//         return true;
//     }
//     catch(EErroPersistencia &exp) {
//         cout << endl << exp.what();
//         return false;
//     }
// }


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

