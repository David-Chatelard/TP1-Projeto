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
            cout << "senha certa ENTER para continuar...";
            getch();
            return true;
        }
        cout << "senha errada ENTER para continuar...";
        getch();
        return false;
    }
    catch(EErroPersistencia &exp) {
        cout << endl << exp.what();
        cout << "erro no sql ENTER para continuar...";
        getch();
        return false;
    }
}




