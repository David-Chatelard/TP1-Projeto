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
        comandoSQL += "'" + email.getValor() + "'";
        // comandoSQL += email.getValor();
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
// USUARIOS
//---------------------------------------------------------------------------
// Implementações de métodos da classe ComandoPesquisarUsuario.

ComandoPesquisarUsuario::ComandoPesquisarUsuario(Email email) {
        comandoSQL = "SELECT * FROM usuarios WHERE email = ";
        comandoSQL += "'" + email.getValor() + "'";
        // comandoSQL += email.getValor();
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

//---------------------------------------------------------------------------
// Implementações de métodos da classe ComandoCadastrarUsuario.

ComandoCadastrarUsuario::ComandoCadastrarUsuario(Usuario usuario) {
        comandoSQL = "INSERT INTO usuarios VALUES (";
        comandoSQL += "'" + usuario.getNome().getValor() + "', ";
        comandoSQL += "'" + usuario.getEmail().getValor() + "', ";
        comandoSQL += "'" + usuario.getSenha().getValor() + "')";
}

//---------------------------------------------------------------------------
// Implementações de métodos da classe ComandoRemoverUsuario.

ComandoRemoverUsuario::ComandoRemoverUsuario(Email email) {
        comandoSQL = "DELETE FROM usuarios WHERE email = ";
        comandoSQL += "'" + email.getValor() + "'";
        // comandoSQL += email.getValor();
}

//---------------------------------------------------------------------------
// Implementações de métodos da classe ComandoEditarUsuario.

ComandoAtualizarUsuario::ComandoAtualizarUsuario(Usuario usuario) {
        comandoSQL = "UPDATE usuarios ";
        comandoSQL += "SET nome = '" + usuario.getNome().getValor();
        comandoSQL += "', senha = '" + usuario.getSenha().getValor();
        comandoSQL += "' WHERE email = '" + usuario.getEmail().getValor() + "'";
        // comandoSQL += "' WHERE email = " + usuario.getEmail().getValor();
}

//---------------------------------------------------------------------------
// EXCURSOES
//---------------------------------------------------------------------------
// Implementações de métodos da classe ComandoPesquisarExcursao.

ComandoPesquisarExcursao::ComandoPesquisarExcursao(Codigo codigo) {
        comandoSQL = "SELECT * FROM excursoes WHERE codigo = ";
        comandoSQL += "'" + codigo.getValor() + "'";
        // comandoSQL += codigo.getValor();
}

Excursao ComandoPesquisarExcursao::getResultado() {
        ElementoResultado resultado;
        Excursao excursao;

        Codigo codigo;
        Titulo titulo;
        Nota nota;
        Cidade cidade;
        Duracao duracao;
        Descricao descricao;
        Endereco endereco;

        // Remover codigo;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        codigo.setValor(resultado.getValorColuna());
        excursao.setCodigo(codigo);

        // Remover titulo;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        titulo.setValor(resultado.getValorColuna());
        excursao.setTitulo(titulo);

        // Remover nota;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        nota.setValor(stoi(resultado.getValorColuna()));
        excursao.setNota(nota);

        // Remover cidade;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        cidade.setValor(resultado.getValorColuna());
        excursao.setCidade(cidade);

        // Remover duracao;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        duracao.setValor(stoi(resultado.getValorColuna()));
        excursao.setDuracao(duracao);

        // Remover descricao;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        descricao.setValor(resultado.getValorColuna());
        excursao.setDescricao(descricao);

        // Remover endereco;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        endereco.setValor(resultado.getValorColuna());
        excursao.setEndereco(endereco);

        return excursao;

}

//---------------------------------------------------------------------------
// Implementações de métodos da classe ComandoCadastrarExcursao.

ComandoCadastrarExcursao::ComandoCadastrarExcursao(Excursao excursao) {
        comandoSQL = "INSERT INTO excursoes VALUES (";
        comandoSQL += "'" + excursao.getCodigo().getValor() + "', ";
        comandoSQL += "'" + excursao.getTitulo().getValor() + "', ";
        comandoSQL += "'" + to_string(excursao.getNota().getValor()) + "', ";
        comandoSQL += "'" + excursao.getCidade().getValor() + "', ";
        comandoSQL += "'" + to_string(excursao.getDuracao().getValor()) + "', ";
        comandoSQL += "'" + excursao.getDescricao().getValor() + "', ";
        comandoSQL += "'" + excursao.getEndereco().getValor() + "', ";
        comandoSQL += "'" + excursao.getEmailGuia().getValor() + "')";
}

//---------------------------------------------------------------------------
// Implementações de métodos da classe ComandoRemoverExcursao.

ComandoRemoverExcursao::ComandoRemoverExcursao(Excursao excursao) {
        comandoSQL = "DELETE FROM excursoes WHERE codigo = ";
        comandoSQL += "'" + excursao.getCodigo().getValor() + "'";
        // comandoSQL += excursao.getCodigo().getValor();
}

//---------------------------------------------------------------------------
// Implementações de métodos da classe ComandoEditarExcursao.

ComandoAtualizarExcursao::ComandoAtualizarExcursao(Excursao excursao) {
        comandoSQL = "UPDATE excursoes ";
        comandoSQL += "SET titulo = '" + excursao.getTitulo().getValor();
        comandoSQL += "', nota = '" + to_string(excursao.getNota().getValor());
        comandoSQL += "', cidade = '" + excursao.getCidade().getValor();
        comandoSQL += "', duracao = '" + to_string(excursao.getDuracao().getValor());
        comandoSQL += "', descricao = '" + excursao.getDescricao().getValor();
        comandoSQL += "', endereco = '" + excursao.getEndereco().getValor();
        comandoSQL += "' WHERE codigo = '" + excursao.getCodigo().getValor() + "'";
        // comandoSQL += "' WHERE codigo = " + excursao.getCodigo().getValor();
}

//---------------------------------------------------------------------------
// AVALIACOES
//---------------------------------------------------------------------------
