#ifndef UNIDADEPERSISTENCIA_H_INCLUDED
#define UNIDADEPERSISTENCIA_H_INCLUDED

//---------------------------------------------------------------------------
// Incluir cabeçalhos.

#include "dominios.h"
#include "entidades.h"

#include <list>

#include <iostream>
#include <conio.h>
#include <string>
#include <stdio.h>

#include "sqlite3.h"            // Incluir cabeçalho da biblioteca SQLite.

using namespace std;

//---------------------------------------------------------------------------
// Declaração da classe EErroPersistencia.

class EErroPersistencia {
private:
        string mensagem;
public:
        EErroPersistencia(string);
        string what();
};

//---------------------------------------------------------------------------
// Declaração da classe ElementoResultado.

class ElementoResultado {
private:
        string nomeColuna;
        string valorColuna;
public:
        void setNomeColuna(const string&);
        string getNomeColuna() const;
        void setValorColuna(const string&);
        string getValorColuna() const;
};

//---------------------------------------------------------------------------
// Declaração da classe ComandoSQL.

class ComandoSQL {
private:
        const char *nomeBancoDados;
        sqlite3 *bd;
        char *mensagem;
        int rc;
        void conectar();
        void desconectar();
        static int callback(void *, int, char **, char **);

protected:
        static list<ElementoResultado> listaResultado;
        string comandoSQL;
public:
        ComandoSQL() {
             nomeBancoDados = "testedb.db";                             // Nome do banco de dados.
        }
        void executar();
};

//---------------------------------------------------------------------------
// Declaração da classe ComandoLerSenha.

class ComandoLerSenha:public ComandoSQL {
public:
        ComandoLerSenha(Email);
        string getResultado();
};

//---------------------------------------------------------------------------
//Classe ComandoPesquisarUsuario.

class ComandoPesquisarUsuario:public ComandoSQL {
public:
        ComandoPesquisarUsuario(Email);
        Usuario getResultado();
};

//---------------------------------------------------------------------------
// Declaração da classe ComandoCadastrarUsuario.

class ComandoCadastrarUsuario:public ComandoSQL {
public:
        ComandoCadastrarUsuario(Usuario);
};

//---------------------------------------------------------------------------
// Declaração da classe ComandoRemoverUsuario.

class ComandoRemoverUsuario:public ComandoSQL {
public:
        ComandoRemoverUsuario(Email);
};

//---------------------------------------------------------------------------
//Classe ComandoAtualizarUsuario.

class ComandoAtualizarUsuario:public ComandoSQL {
public:
        ComandoAtualizarUsuario(Usuario);
};

// //---------------------------------------------------------------------------
// //Classe ComandoCadastrarDisciplina.

// class ComandoCadastrarDisciplina:public ComandoSQL {
// public:
//         ComandoCadastrarDisciplina(Disciplina);
// };

//---------------------------------------------------------------------------
// Implementações de métodos.

inline string ElementoResultado::getNomeColuna() const {
        return nomeColuna;
}

inline string ElementoResultado::getValorColuna() const {
        return valorColuna;
}

#endif
