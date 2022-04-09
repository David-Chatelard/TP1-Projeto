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
    ComandoRemoverUsuario comandoRemoverUsuario(email);

    try{
        comandoRemoverUsuario.executar();
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
