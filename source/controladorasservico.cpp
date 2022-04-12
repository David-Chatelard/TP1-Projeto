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

// TEM QUE TESTAR A PARTE DE APAGAR TODAS AS EXCURSOES E AVALIACOES, SO DESCOMENTAR
bool CntrServicoContas::descadastrar(Email email){
    // ComandoRemoverAvaliacao comandoRemoverAvaliacao(email); //remove todas as avaliacoes desse autor

    // ComandoListarExcursoes comandoListarExcursoes(email); //usado para remover as ava
    // vector<Excursao> excursoes;
    // ComandoRemoverExcursao comandoRemoverExcursao(email);

    ComandoRemoverUsuario comandoRemoverUsuario(email); //remove o usuario

//    try{
//        comandoRemoverAvaliacao.executar(); //remove todas as avaliacoes desse autor
//        comandoListarExcursoes.executar(); //lista as excursoes para deletar os filhos
//        excursoes = comandoListarExcursoes.getResultado();
//        for(int i=0;i<=excursoes.size();i++){
//            Codigo codigo = excursoes[i].getCodigo();
//            ComandoRemoverSessao auxSessao(codigo); //Remove todas as avaliacoes de cada excursao do autor
//            ComandoRemoverAvaliacao auxAvaliacao(codigo); //Remove todas as sessoes de cada excursao do autor
//            auxSessao.executar();
//            auxAvaliacao.executar();
//        }
//        comandoRemoverExcursao.executar(); //remove todas as excursoes do autor
//     }
//     catch(EErroPersistencia &exp) {
//         cout << endl << exp.what();
//         false;
//     }
    try{
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

//acho que pode tirar e usar só a listarExcursoes()
vector<Excursao> CntrServicoExcursao::listarExcursoes2(Email email){
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



// //cadastrar
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


// //editar
// bool CntrServicoExcursao::editarExcursao(Excursao excursao){
//     ComandoAtualizarExcursao comandoAtualizarExcursao(excursao);

//     try {
//         comandoAtualizarExcursao.executar();
//         return true;
//     }
//     catch(EErroPersistencia &exp) {
//         cout << endl << exp.what();
//         return false;
//     }
// }
// bool CntrServicoExcursao::editarSessao(Sessao sessao){
//     ComandoAtualizarSessao comandoAtualizarSessao(sessao);

//     try {
//         comandoAtualizarSessao.executar();
//         return true;
//     }
//     catch(EErroPersistencia &exp) {
//         cout << endl << exp.what();
//         return false;
//     }
// }
// bool CntrServicoExcursao::editarAvaliacao(Avaliacao avaliacao){
//     ComandoAtualizarAvaliacao comandoAtualizarAvaliacao(avaliacao);

//     try {
//         comandoAtualizarAvaliacao.executar();
//         return true;
//     }
//     catch(EErroPersistencia &exp) {
//         cout << endl << exp.what();
//         return false;
//     }
// }


// //descadastrar
// bool CntrServicoExcursao::descadastrarExcursao(Excursao excursao){ //descadastra uma excursao
//     ComandoRemoverAvaliacao comandoRemoverAvaliacao(excursao.getCodigo()); //remove todas as avaliacoes linkadas com essa excursao
//     ComandoRemoverSessao comandoRemoverSessao(excursao.getCodigo()); //remove todas as sessoes linkadas com essa excursao
//     ComandoRemoverExcursao comandoRemoverExcursao(excursao);

//     try{
//         comandoRemoverAvaliacao.executar();
//         comandoRemoverSessao.executar();
//         comandoRemoverExcursao.executar();
//         return true;
//     }
//     catch(EErroPersistencia &exp) {
//         cout << endl << exp.what();
//         return false;
//     }
// }
// bool CntrServicoExcursao::descadastrarSessao(Sessao sessao){ //descadastra uma sessao
//     ComandoRemoverSessao comandoRemoverSessao(sessao);

//     try{
//         comandoRemoverSessao.executar();
//         return true;
//     }
//     catch(EErroPersistencia &exp) {
//         cout << endl << exp.what();
//         return false;
//     }
// }
// bool CntrServicoExcursao::descadastrarAvaliacao(Avaliacao avaliacao){ //descadastra uma avaliacao
//     ComandoRemoverAvaliacao comandoRemoverAvaliacao(avaliacao);

//     try{
//         comandoRemoverAvaliacao.executar();
//         return true;
//     }
//     catch(EErroPersistencia &exp) {
//         cout << endl << exp.what();
//         return false;
//     }
// }

