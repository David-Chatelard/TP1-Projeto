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
        comandoSQL += "'" + email.getValor() + "';";
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
// Implementações de métodos da classe ComandoListarExcursoes.

// Função que bota todas as excursões em listaResultado
ComandoListarExcursoes::ComandoListarExcursoes() {
        comandoSQL = "SELECT * FROM excursoes";
}

// Função que bota todas as excursões desse email em listaResultado
ComandoListarExcursoes::ComandoListarExcursoes(Email emailGuia) {
        comandoSQL = "SELECT * FROM excursoes WHERE emailGuia = ";
        comandoSQL += "'" + emailGuia.getValor() + "'";
        // comandoSQL += email.getValor();
}

// Função que retorna as excursões, que estão em listaResultado, em vetorResultado e limpa listaResultado
vector<Excursao> ComandoListarExcursoes::getResultado() {
        int i=0, tam_lista;
        ElementoResultado resultado;
        Excursao excursao;

        Codigo codigo;
        Titulo titulo;
        Nota nota;
        Cidade cidade;
        Duracao duracao;
        Descricao descricao;
        Endereco endereco;
        Email emailGuia;

        // vector<Excursao> vetorResultado(listaResultado.size() / 8);                     // Cria vetor
        vector<Excursao> vetorResultado;                     // Cria vetor
        tam_lista = listaResultado.size() / 8;
        
        for (i = 0; i < tam_lista; i++) {
                // Remover codigo;
                if (listaResultado.empty())
                        throw EErroPersistencia("Lista de resultados vazia.");
                resultado = listaResultado.back();
                listaResultado.pop_back();
                // cout << "Codigo: " << resultado.getValorColuna() << endl;
                // getch();
                codigo.setValor(resultado.getValorColuna());
                excursao.setCodigo(codigo);

                // Remover titulo;
                if (listaResultado.empty())
                        throw EErroPersistencia("Lista de resultados vazia.");
                resultado = listaResultado.back();
                listaResultado.pop_back();
                // cout << "Titulo: " << resultado.getValorColuna() << endl;
                // getch();
                titulo.setValor(resultado.getValorColuna());
                excursao.setTitulo(titulo);

                // Remover nota;
                if (listaResultado.empty())
                        throw EErroPersistencia("Lista de resultados vazia.");
                resultado = listaResultado.back();
                listaResultado.pop_back();
                // cout << "Nota: " << resultado.getValorColuna() << endl;
                // getch();
                nota.setValor(stoi(resultado.getValorColuna()));
                excursao.setNota(nota);

                // Remover cidade;
                if (listaResultado.empty())
                        throw EErroPersistencia("Lista de resultados vazia.");
                resultado = listaResultado.back();
                listaResultado.pop_back();
                // cout << "Cidade: " << resultado.getValorColuna() << endl;
                // getch();
                cidade.setValor(resultado.getValorColuna());
                excursao.setCidade(cidade);

                // Remover duracao;
                if (listaResultado.empty())
                        throw EErroPersistencia("Lista de resultados vazia.");
                resultado = listaResultado.back();
                listaResultado.pop_back();
                // cout << "Duracao: " << resultado.getValorColuna() << endl;
                // getch();
                duracao.setValor(stoi(resultado.getValorColuna()));
                excursao.setDuracao(duracao);

                // Remover descricao;
                if (listaResultado.empty())
                        throw EErroPersistencia("Lista de resultados vazia.");
                resultado = listaResultado.back();
                listaResultado.pop_back();
                // cout << "Descricao: " << resultado.getValorColuna() << endl;
                // getch();
                descricao.setValor(resultado.getValorColuna());
                excursao.setDescricao(descricao);

                // Remover endereco;
                if (listaResultado.empty())
                        throw EErroPersistencia("Lista de resultados vazia.");
                resultado = listaResultado.back();
                listaResultado.pop_back();
                // cout << "Endereco: " << resultado.getValorColuna() << endl;
                // getch();
                endereco.setValor(resultado.getValorColuna());
                excursao.setEndereco(endereco);

                // Remover emailGuia;
                if (listaResultado.empty())
                        throw EErroPersistencia("Lista de resultados vazia.");
                resultado = listaResultado.back();
                listaResultado.pop_back();
                // cout << "EmailGuia: " << resultado.getValorColuna() << endl;
                // getch();
                emailGuia.setValor(resultado.getValorColuna());
                excursao.setEmailGuia(emailGuia);

                // vetorResultado[i] = excursao;
                vetorResultado.push_back(excursao);
        }

        // for (int j = 0; j < vetorResultado.size(); j++){
        //         cout << vetorResultado[j].getCodigo().getValor() << endl;
        //         cout << vetorResultado[j].getTitulo().getValor() << endl;
        //         cout << vetorResultado[j].getNota().getValor() << endl;
        //         cout << vetorResultado[j].getCidade().getValor() << endl;
        //         cout << vetorResultado[j].getDuracao().getValor() << endl;
        //         cout << vetorResultado[j].getDescricao().getValor() << endl;
        //         cout << vetorResultado[j].getEndereco().getValor() << endl;
        //         cout << vetorResultado[j].getEmailGuia().getValor() << endl << endl;
        //         getch();
        // }
        
        
        return vetorResultado;
}

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

// Função que remove a excursão que possui o código
ComandoRemoverExcursao::ComandoRemoverExcursao(Excursao excursao) {
        comandoSQL = "DELETE FROM excursoes WHERE codigo = ";
        comandoSQL += "'" + excursao.getCodigo().getValor() + "'";
        // comandoSQL += excursao.getCodigo().getValor();
}

// Função que remove todas excursões que possuem esse email
ComandoRemoverExcursao::ComandoRemoverExcursao(Email emailGuia) {
        comandoSQL = "DELETE FROM excursoes WHERE emailGuia = ";
        comandoSQL += "'" + emailGuia.getValor() + "'";
        // comandoSQL += emailGuia.getValor();
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
// Implementações de métodos da classe ComandoListarAvaliacoes.


// Função que bota todas as avaliações em listaResultado
ComandoListarAvaliacoes::ComandoListarAvaliacoes() {
        comandoSQL = "SELECT * FROM avaliacoes";
}

// Função que bota todas as avaliações dessa excursão em listaResultado
ComandoListarAvaliacoes::ComandoListarAvaliacoes(Codigo codigoExcursao) {
        comandoSQL = "SELECT * FROM avaliacoes WHERE codigoExcursao = ";
        comandoSQL += "'" + codigoExcursao.getValor() + "'";
}

// Função que bota todas as avaliações desse email em listaResultado
ComandoListarAvaliacoes::ComandoListarAvaliacoes(Email emailAutor) {
        comandoSQL = "SELECT * FROM avaliacoes WHERE emailAutor = ";
        comandoSQL += "'" + emailAutor.getValor() + "'";
        // comandoSQL += email.getValor();
}

// Função que retorna as avaliações, que estão em listaResultado, em vetorResultado e limpa listaResultado
vector<Avaliacao> ComandoListarAvaliacoes::getResultado() {
        int i=0, tam_lista;
        ElementoResultado resultado;
        Avaliacao avaliacao;

        Codigo codigo;
        Nota nota;
        Descricao descricao;
        Email emailAutor;
        Codigo codigoExcursao;

        // vector<Avaliacao> vetorResultado(listaResultado.size() / 5);                     // Cria vetor
        vector<Avaliacao> vetorResultado;                     // Cria vetor
        tam_lista = listaResultado.size() / 5;
        
        for (i = 0; i < tam_lista; i++) {
                // Remover codigo;
                if (listaResultado.empty())
                        throw EErroPersistencia("Lista de resultados vazia.");
                resultado = listaResultado.back();
                listaResultado.pop_back();
                // cout << "Codigo: " << resultado.getValorColuna() << endl;
                // getch();
                codigo.setValor(resultado.getValorColuna());
                avaliacao.setCodigo(codigo);

                // Remover nota;
                if (listaResultado.empty())
                        throw EErroPersistencia("Lista de resultados vazia.");
                resultado = listaResultado.back();
                listaResultado.pop_back();
                // cout << "Nota: " << resultado.getValorColuna() << endl;
                // getch();
                nota.setValor(stoi(resultado.getValorColuna()));
                avaliacao.setNota(nota);

                // Remover descricao;
                if (listaResultado.empty())
                        throw EErroPersistencia("Lista de resultados vazia.");
                resultado = listaResultado.back();
                listaResultado.pop_back();
                // cout << "Descricao: " << resultado.getValorColuna() << endl;
                // getch();
                descricao.setValor(resultado.getValorColuna());
                avaliacao.setDescricao(descricao);

                // Remover emailAutor;
                if (listaResultado.empty())
                        throw EErroPersistencia("Lista de resultados vazia.");
                resultado = listaResultado.back();
                listaResultado.pop_back();
                // cout << "EmailAutor: " << resultado.getValorColuna() << endl;
                // getch();
                emailAutor.setValor(resultado.getValorColuna());
                avaliacao.setEmailAutor(emailAutor);

                // Remover codigoExcursao;
                if (listaResultado.empty())
                        throw EErroPersistencia("Lista de resultados vazia.");
                resultado = listaResultado.back();
                listaResultado.pop_back();
                // cout << "CodigoExcursao: " << resultado.getValorColuna() << endl;
                // getch();
                codigoExcursao.setValor(resultado.getValorColuna());
                avaliacao.setCodigoExcursao(codigoExcursao);

                vetorResultado.push_back(avaliacao);
        }

        // for (int j = 0; j < vetorResultado.size(); j++){
        //         cout << vetorResultado[j].getCodigo().getValor() << endl;
        //         cout << vetorResultado[j].getNota().getValor() << endl;
        //         cout << vetorResultado[j].getDescricao().getValor() << endl;
        //         cout << vetorResultado[j].getEmailAutor().getValor() << endl;
        //         cout << vetorResultado[j].getCodigoExcursao().getValor() << endl << endl;
        //         getch();
        // }
        
        
        return vetorResultado;
}

//---------------------------------------------------------------------------
// Implementações de métodos da classe ComandoPesquisarAvaliacao.

ComandoPesquisarAvaliacao::ComandoPesquisarAvaliacao(Codigo codigo) {
        comandoSQL = "SELECT * FROM avaliacoes WHERE codigo = ";
        comandoSQL += "'" + codigo.getValor() + "'";
        // comandoSQL += codigo.getValor();
}

Avaliacao ComandoPesquisarAvaliacao::getResultado() {
        ElementoResultado resultado;
        Avaliacao avaliacao;

        Codigo codigo;
        Nota nota;
        Descricao descricao;

        // Remover codigo;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        codigo.setValor(resultado.getValorColuna());
        avaliacao.setCodigo(codigo);

        // Remover nota;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        nota.setValor(stoi(resultado.getValorColuna()));
        avaliacao.setNota(nota);

        // Remover descricao;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        descricao.setValor(resultado.getValorColuna());
        avaliacao.setDescricao(descricao);

        return avaliacao;

}

//---------------------------------------------------------------------------
// Implementações de métodos da classe ComandoCadastrarAvaliacao.

ComandoCadastrarAvaliacao::ComandoCadastrarAvaliacao(Avaliacao avaliacao) {
        comandoSQL = "INSERT INTO avaliacoes VALUES (";
        comandoSQL += "'" + avaliacao.getCodigo().getValor() + "', ";
        comandoSQL += "'" + to_string(avaliacao.getNota().getValor()) + "', ";
        comandoSQL += "'" + avaliacao.getDescricao().getValor() + "', ";
        comandoSQL += "'" + avaliacao.getEmailAutor().getValor() + "', ";
        comandoSQL += "'" + avaliacao.getCodigoExcursao().getValor() + "')";
}

//---------------------------------------------------------------------------
// Implementações de métodos da classe ComandoRemoverAvaliacao.

// Função que remove a avaliação que possui o código
ComandoRemoverAvaliacao::ComandoRemoverAvaliacao(Avaliacao avaliacao) {
        comandoSQL = "DELETE FROM avaliacoes WHERE codigo = ";
        comandoSQL += "'" + avaliacao.getCodigo().getValor() + "'";
        // comandoSQL += avaliacao.getCodigo().getValor();
}

// Função que remove todas avaliações que possuem esse código de excursão
ComandoRemoverAvaliacao::ComandoRemoverAvaliacao(Codigo codigoExcursao) {
        comandoSQL = "DELETE FROM avaliacoes WHERE codigoExcursao = ";
        comandoSQL += "'" + codigoExcursao.getValor() + "'";
        // comandoSQL += codigoExcursao.getValor();
}

// Função que remove todas avaliações que possuem esse email
ComandoRemoverAvaliacao::ComandoRemoverAvaliacao(Email emailAutor) {
        comandoSQL = "DELETE FROM avaliacoes WHERE emailAutor = ";
        comandoSQL += "'" + emailAutor.getValor() + "'";
        // comandoSQL += emailAutor.getValor();
}

//---------------------------------------------------------------------------
// Implementações de métodos da classe ComandoEditarAvaliacao.

ComandoAtualizarAvaliacao::ComandoAtualizarAvaliacao(Avaliacao avaliacao) {
        comandoSQL = "UPDATE avaliacoes ";
        comandoSQL += "SET nota = '" + to_string(avaliacao.getNota().getValor());
        comandoSQL += "', descricao = '" + avaliacao.getDescricao().getValor();
        comandoSQL += "' WHERE codigo = '" + avaliacao.getCodigo().getValor() + "'";
        // comandoSQL += "' WHERE codigo = " + avaliacao.getCodigo().getValor();
}


//---------------------------------------------------------------------------
// SESSOES
//---------------------------------------------------------------------------
// Implementações de métodos da classe ComandoListarSessoes.

// Função que bota todas as sessoes em listaResultado
ComandoListarSessoes::ComandoListarSessoes() {
        comandoSQL = "SELECT * FROM sessoes";
}

// Função que bota todas as sessões dessa excursão em listaResultado
ComandoListarSessoes::ComandoListarSessoes(Codigo codigoExcursao) {
        comandoSQL = "SELECT * FROM sessoes WHERE codigoExcursao = ";
        comandoSQL += "'" + codigoExcursao.getValor() + "'";
}

// Função que retorna as sessões, que estão em listaResultado, em vetorResultado e limpa listaResultado
vector<Sessao> ComandoListarSessoes::getResultado() {
        int i=0, tam_lista;
        ElementoResultado resultado;
        Sessao sessao;

        Codigo codigo;
        Data data;
        Horario horario;
        Idioma idioma;
        Codigo codigoExcursao;

        // vector<Sessao> vetorResultado(listaResultado.size() / 5);                     // Cria vetor
        vector<Sessao> vetorResultado;                     // Cria vetor
        tam_lista = listaResultado.size() / 5;
        
        for (i = 0; i < tam_lista; i++) {
                // Remover codigo;
                if (listaResultado.empty())
                        throw EErroPersistencia("Lista de resultados vazia.");
                resultado = listaResultado.back();
                listaResultado.pop_back();
                // cout << "Codigo: " << resultado.getValorColuna() << endl;
                // getch();
                codigo.setValor(resultado.getValorColuna());
                sessao.setCodigo(codigo);

                // Remover data;
                if (listaResultado.empty())
                        throw EErroPersistencia("Lista de resultados vazia.");
                resultado = listaResultado.back();
                listaResultado.pop_back();
                // cout << "data: " << resultado.getValorColuna() << endl;
                // getch();
                data.setValor(resultado.getValorColuna());
                sessao.setData(data);

                // Remover horario;
                if (listaResultado.empty())
                        throw EErroPersistencia("Lista de resultados vazia.");
                resultado = listaResultado.back();
                listaResultado.pop_back();
                // cout << "horario: " << resultado.getValorColuna() << endl;
                // getch();
                horario.setValor(resultado.getValorColuna());
                sessao.setHorario(horario);

                // Remover idioma;
                if (listaResultado.empty())
                        throw EErroPersistencia("Lista de resultados vazia.");
                resultado = listaResultado.back();
                listaResultado.pop_back();
                // cout << "idioma: " << resultado.getValorColuna() << endl;
                // getch();
                idioma.setValor(resultado.getValorColuna());
                sessao.setIdioma(idioma);

                // Remover codigoExcursao;
                if (listaResultado.empty())
                        throw EErroPersistencia("Lista de resultados vazia.");
                resultado = listaResultado.back();
                listaResultado.pop_back();
                // cout << "CodigoExcursao: " << resultado.getValorColuna() << endl;
                // getch();
                codigoExcursao.setValor(resultado.getValorColuna());
                sessao.setCodigoExcursao(codigoExcursao);

                vetorResultado.push_back(sessao);
        }

        // for (int j = 0; j < vetorResultado.size(); j++){
        //         cout << vetorResultado[j].getCodigo().getValor() << endl;
        //         cout << vetorResultado[j].getNota().getValor() << endl;
        //         cout << vetorResultado[j].getDescricao().getValor() << endl;
        //         cout << vetorResultado[j].getEmailAutor().getValor() << endl;
        //         cout << vetorResultado[j].getCodigoExcursao().getValor() << endl << endl;
        //         getch();
        // }
        
        
        return vetorResultado;
}

//---------------------------------------------------------------------------
// Implementações de métodos da classe ComandoPesquisarSessao.

ComandoPesquisarSessao::ComandoPesquisarSessao(Codigo codigo) {
        comandoSQL = "SELECT * FROM sessoes WHERE codigo = ";
        comandoSQL += "'" + codigo.getValor() + "'";
        // comandoSQL += codigo.getValor();
}

Sessao ComandoPesquisarSessao::getResultado() {
        ElementoResultado resultado;
        Sessao sessao;

        Codigo codigo;
        Data data;
        Horario horario;
        Idioma idioma;

        // Remover codigo;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        codigo.setValor(resultado.getValorColuna());
        sessao.setCodigo(codigo);

        // Remover data;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        data.setValor(resultado.getValorColuna());
        sessao.setData(data);

        // Remover horario;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        horario.setValor(resultado.getValorColuna());
        sessao.setHorario(horario);

        // Remover idioma;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        idioma.setValor(resultado.getValorColuna());
        sessao.setIdioma(idioma);

        return sessao;

}

//---------------------------------------------------------------------------
// Implementações de métodos da classe ComandoCadastrarSessao.

ComandoCadastrarSessao::ComandoCadastrarSessao(Sessao sessao) {
        comandoSQL = "INSERT INTO sessoes VALUES (";
        comandoSQL += "'" + sessao.getCodigo().getValor() + "', ";
        comandoSQL += "'" + sessao.getData().getValor() + "', ";
        comandoSQL += "'" + sessao.getHorario().getValor() + "', ";
        comandoSQL += "'" + sessao.getIdioma().getValor() + "', ";
        comandoSQL += "'" + sessao.getCodigoExcursao().getValor() + "')";
}

//---------------------------------------------------------------------------
// Implementações de métodos da classe ComandoRemoverSessao.

// Função que remove a sessão que possui o código
ComandoRemoverSessao::ComandoRemoverSessao(Sessao sessao) {
        comandoSQL = "DELETE FROM sessoes WHERE codigo = ";
        comandoSQL += "'" + sessao.getCodigo().getValor() + "'";
        // comandoSQL += sessao.getCodigo().getValor();
}

// Função que remove todas sessões que possuem esse código de excursão
ComandoRemoverSessao::ComandoRemoverSessao(Codigo codigoExcursao) {
        comandoSQL = "DELETE FROM sessoes WHERE codigoExcursao = ";
        comandoSQL += "'" + codigoExcursao.getValor() + "'";
        // comandoSQL += codigoExcursao.getValor();
}

//---------------------------------------------------------------------------
// Implementações de métodos da classe ComandoEditarSessao.

ComandoAtualizarSessao::ComandoAtualizarSessao(Sessao sessao) {
        comandoSQL = "UPDATE sessoes ";
        comandoSQL += "SET data = '" + sessao.getData().getValor();
        comandoSQL += "', horario = '" + sessao.getHorario().getValor();
        comandoSQL += "', idioma = '" + sessao.getIdioma().getValor();
        comandoSQL += "' WHERE codigo = '" + sessao.getCodigo().getValor() + "'";
        // comandoSQL += "' WHERE codigo = " + sessao.getCodigo().getValor();
}
