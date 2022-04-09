#ifndef UNIDADEPERSISTENCIA_H_INCLUDED
#define UNIDADEPERSISTENCIA_H_INCLUDED

//---------------------------------------------------------------------------
// Incluir cabeçalhos.

#include "dominios.h"
#include "entidades.h"

#include <list>
#include <vector>

#include <iostream>
#include <conio.h>
#include <string>
#include <stdio.h>

#include "../sqlite-amalgamation-3380200/sqlite3.h"            // Incluir cabeçalho da biblioteca SQLite.

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
             nomeBancoDados = "banco_de_dados.db";                             // Nome do banco de dados.
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
// USUARIOS
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


//---------------------------------------------------------------------------
// EXCURSOES
//---------------------------------------------------------------------------
//Classe ComandoListarExcursoes.

class ComandoListarExcursoes:public ComandoSQL {
public:
        ComandoListarExcursoes();
        ComandoListarExcursoes(Email);
        vector<Excursao> getResultado();
};

//---------------------------------------------------------------------------
//Classe ComandoPesquisarExcursao.

class ComandoPesquisarExcursao:public ComandoSQL {
public:
        ComandoPesquisarExcursao(Codigo);
        Excursao getResultado();
};

//---------------------------------------------------------------------------
//Classe ComandoCadastrarExcursao.

class ComandoCadastrarExcursao:public ComandoSQL {
public:
        ComandoCadastrarExcursao(Excursao);
};

//---------------------------------------------------------------------------
// Declaração da classe ComandoRemoverExcursao.

class ComandoRemoverExcursao:public ComandoSQL {
public:
        ComandoRemoverExcursao(Excursao);
        ComandoRemoverExcursao(Email);
};

//---------------------------------------------------------------------------
//Classe ComandoAtualizarExcursao.

class ComandoAtualizarExcursao:public ComandoSQL {
public:
        ComandoAtualizarExcursao(Excursao);
};


//---------------------------------------------------------------------------
// AVALIACOES
//---------------------------------------------------------------------------
//Classe ComandoListarAvaliacoes.

class ComandoListarAvaliacoes:public ComandoSQL {
public:
        ComandoListarAvaliacoes(Codigo);
        ComandoListarAvaliacoes(Email);
        vector<ElementoResultado> getResultado();
};

//---------------------------------------------------------------------------
//Classe ComandoPesquisarAvaliacao.

class ComandoPesquisarAvaliacao:public ComandoSQL {
public:
        ComandoPesquisarAvaliacao(Codigo);
        Avaliacao getResultado();
};

//---------------------------------------------------------------------------
//Classe ComandoCadastrarAvaliacao.

class ComandoCadastrarAvaliacao:public ComandoSQL {
public:
        ComandoCadastrarAvaliacao(Avaliacao);
};

//---------------------------------------------------------------------------
// Declaração da classe ComandoRemoverAvaliacao.

class ComandoRemoverAvaliacao:public ComandoSQL {
public:
        ComandoRemoverAvaliacao(Avaliacao);
        ComandoRemoverAvaliacao(Codigo);
        ComandoRemoverAvaliacao(Email);
};

//---------------------------------------------------------------------------
//Classe ComandoAtualizarAvaliacao.

class ComandoAtualizarAvaliacao:public ComandoSQL {
public:
        ComandoAtualizarAvaliacao(Avaliacao);
};


//---------------------------------------------------------------------------
// SESSOES
//---------------------------------------------------------------------------
//Classe ComandoListarSessoes.

class ComandoListarSessoes:public ComandoSQL {
public:
        ComandoListarSessoes(Codigo);
        vector<ElementoResultado> getResultado();
};

//---------------------------------------------------------------------------
//Classe ComandoPesquisarSessao.

class ComandoPesquisarSessao:public ComandoSQL {
public:
        ComandoPesquisarSessao(Codigo);
        Sessao getResultado();
};

//---------------------------------------------------------------------------
//Classe ComandoCadastrarSessao.

class ComandoCadastrarSessao:public ComandoSQL {
public:
        ComandoCadastrarSessao(Sessao);
};

//---------------------------------------------------------------------------
// Declaração da classe ComandoRemoverSessao.

class ComandoRemoverSessao:public ComandoSQL {
public:
        ComandoRemoverSessao(Sessao);
        ComandoRemoverSessao(Codigo);
};

//---------------------------------------------------------------------------
//Classe ComandoAtualizarSessao.

class ComandoAtualizarSessao:public ComandoSQL {
public:
        ComandoAtualizarSessao(Sessao);
};


//---------------------------------------------------------------------------
// Implementações de métodos.

inline string ElementoResultado::getNomeColuna() const {
        return nomeColuna;
}

inline string ElementoResultado::getValorColuna() const {
        return valorColuna;
}

#endif
