#ifndef UNIDADEPERSISTENCIA_H_INCLUDED
#define UNIDADEPERSISTENCIA_H_INCLUDED

//---------------------------------------------------------------------------
// Incluir cabe�alhos.

#include "dominios.h"
#include "entidades.h"

#include <list>

#include <iostream>
#include <conio.h>
#include <string>
#include <stdio.h>

#include "sqlite3.h"            // Incluir cabe�alho da biblioteca SQLite.

using namespace std;

//---------------------------------------------------------------------------
// Declara��o da classe EErroPersistencia.

class EErroPersistencia {
private:
        string mensagem;
public:
        EErroPersistencia(string);
        string what();
};

//---------------------------------------------------------------------------
// Declara��o da classe ElementoResultado.

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
// Declara��o da classe ComandoSQL.

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
// Declara��o da classe ComandoLerSenha.

class ComandoLerSenha:public ComandoSQL {
public:
        ComandoLerSenha(Matricula);
        string getResultado();
};

//---------------------------------------------------------------------------
//Classe ComandoPesquisarAluno.

class ComandoPesquisarAluno:public ComandoSQL {
public:
        ComandoPesquisarAluno(Matricula);
        Aluno getResultado();
};

//---------------------------------------------------------------------------
// Declara��o da classe ComandoCadastrarAluno.

class ComandoCadastrarAluno:public ComandoSQL {
public:
        ComandoCadastrarAluno(Aluno);
};

//---------------------------------------------------------------------------
//Classe ComandoAtualizarAluno.

class ComandoAtualizarAluno:public ComandoSQL {
public:
        ComandoAtualizarAluno(Aluno);
};

//---------------------------------------------------------------------------
// Declara��o da classe ComandoRemoverAluno.

class ComandoRemoverAluno:public ComandoSQL {
public:
        ComandoRemoverAluno(Matricula);
};

//---------------------------------------------------------------------------
//Classe ComandoCadastrarDisciplina.

class ComandoCadastrarDisciplina:public ComandoSQL {
public:
        ComandoCadastrarDisciplina(Disciplina);
};

//---------------------------------------------------------------------------
// Implementa��es de m�todos.

inline string ElementoResultado::getNomeColuna() const {
        return nomeColuna;
}

inline string ElementoResultado::getValorColuna() const {
        return valorColuna;
}

#endif
