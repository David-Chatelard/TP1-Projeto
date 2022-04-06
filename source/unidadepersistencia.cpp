//---------------------------------------------------------------------------
// Incluir cabeçalhos.

#include "../headers/unidadepersistencia.h"

// Atributo estático.

list<ElementoResultado> ComandoSQL::listaResultado;

//---------------------------------------------------------------------------
// Implementações de métodos da classe ErroPersistencia.

EErroPersistencia::EErroPersistencia(string mensagem){
        this->mensagem = mensagem;
}

string EErroPersistencia::what() {
        return mensagem;
}

//---------------------------------------------------------------------------
// Implementações de métodos da classe ElementoResultado.

void ElementoResultado::setNomeColuna(const string& nomeColuna) {
        this->nomeColuna = nomeColuna;
}

void ElementoResultado::setValorColuna(const string& valorColuna){
        this->valorColuna = valorColuna;
}

//---------------------------------------------------------------------------
// Implementações de métodos da classe ComandoSQL.

void ComandoSQL::conectar() {
      rc = sqlite3_open(nomeBancoDados, &bd);
      if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na conexao ao banco de dados");
}

void ComandoSQL::desconectar() {
      rc =  sqlite3_close(bd);
      if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na desconexao ao banco de dados");
}

void ComandoSQL::executar() {
        conectar();
        rc = sqlite3_exec(bd, comandoSQL.c_str(), callback, 0, &mensagem);
        if(rc != SQLITE_OK){
                sqlite3_free(mensagem);
                desconectar();
                throw EErroPersistencia("Erro na execucao do comando SQL");
        }
        desconectar();
}

int ComandoSQL::callback(void *NotUsed, int argc, char **valorColuna, char **nomeColuna){
      NotUsed=0;
      ElementoResultado elemento;
      int i;
      for(i=0; i<argc; i++){
        elemento.setNomeColuna(nomeColuna[i]);
        elemento.setValorColuna(valorColuna[i] ? valorColuna[i]: "NULL");
        listaResultado.push_front(elemento);
      }
      return 0;
}

//---------------------------------------------------------------------------
// Implementações de métodos da classe ComandoLerSenha.

ComandoLerSenha::ComandoLerSenha(Email email) {
        comandoSQL = "SELECT senha FROM usuarios WHERE email = ";
        comandoSQL += email.getValor();
}

string ComandoLerSenha::getResultado() {
        ElementoResultado resultado;
        string senha;

        //Remover senha;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        senha = resultado.getValorColuna();

        return senha;
}

//---------------------------------------------------------------------------
// Implementações de métodos da classe ComandoPesquisarUsuario.

ComandoPesquisarUsuario::ComandoPesquisarUsuario(Email email) {
        comandoSQL = "SELECT * FROM usuarios WHERE email = ";
        comandoSQL += email.getValor();
}

Usuario ComandoPesquisarUsuario::getResultado() {
        ElementoResultado resultado;
        Usuario usuario;

        Nome nome;
        Email email;
        Senha senha;

        // Remover nome;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        nome.setValor(resultado.getValorColuna());
        usuario.setNome(nome);

        // Remover email;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        email.setValor(resultado.getValorColuna());
        usuario.setEmail(email);

        // Remover senha;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        senha.setValor(resultado.getValorColuna());
        usuario.setSenha(senha);

        return usuario;

}

// //---------------------------------------------------------------------------
// // Implementações de métodos da classe ComandoCadastrarAluno.

// ComandoCadastrarAluno::ComandoCadastrarAluno(Aluno aluno) {
//         comandoSQL = "INSERT INTO alunos VALUES (";
//         comandoSQL += "'" + aluno.getNome().getValor() + "', ";
//         comandoSQL += "'" + aluno.getMatricula().getValor() + "', ";
//         comandoSQL += "'" + aluno.getSenha().getValor() + "', ";
//         comandoSQL += "'" + aluno.getTelefone().getValor() + "', ";
//         comandoSQL += "'" + aluno.getMatriculaOrientador().getValor() + "')";
// }

// //---------------------------------------------------------------------------
// // Implementações de métodos da classe ComandoRemoverAluno.

// ComandoRemoverAluno::ComandoRemoverAluno(Matricula matricula) {
//         comandoSQL = "DELETE FROM alunos WHERE matricula = ";
//         comandoSQL += matricula.getValor();
// }

// //---------------------------------------------------------------------------
// // Implementações de métodos da classe ComandoEditarAluno.

// ComandoAtualizarAluno::ComandoAtualizarAluno(Aluno aluno) {
//         comandoSQL = "UPDATE alunos ";
//         comandoSQL += "SET nome = '" + aluno.getNome().getValor();
//         comandoSQL += "', senha = '" + aluno.getSenha().getValor();
//         comandoSQL += "', telefone = '" + aluno.getTelefone().getValor();
//         comandoSQL += "', matriculaorientador = '" + aluno.getMatriculaOrientador().getValor();
//         comandoSQL += "' WHERE matricula = " + aluno.getMatricula().getValor();
// }

// //---------------------------------------------------------------------------
// // Implementações de métodos da classe ComandoCadastrarDisciplina.

// ComandoCadastrarDisciplina::ComandoCadastrarDisciplina(Disciplina disciplina) {
//         comandoSQL = "INSERT INTO disciplinas VALUES (";
//         comandoSQL += "'" + disciplina.getNome().getValor() + "', ";
//         comandoSQL += "'" + disciplina.getCodigo().getValor() + "')";
// }