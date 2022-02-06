#include "../headers/testes_entidades.h"


/*----------------------------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Implementa��es de m�todos de classe de teste de unidade.
// No método TUProjeto::testarCenarioSucesso(), precisa implementar os trechos de código de dentro dele para cada atributo da entidade

void TUProjeto::setUp(){
    projeto = new Projeto();
    estado = SUCESSO;
}

void TUProjeto::tearDown(){
    delete projeto;
}

void TUProjeto::testarCenarioSucesso(){
    Codigo codigo;
    codigo.setValor(VALOR_VALIDO);
    projeto->setCodigo(codigo);
    if(projeto->getCodigo().getValor() != VALOR_VALIDO)
        estado = FALHA;

    Prioridade prioridade;
    prioridade.setValor(VALOR_VALIDO);
    projeto->setPrioridade(prioridade);
    if(projeto->getPrioridade().getValor() != VALOR_VALIDO)
        estado = FALHA;
}

int TUProjeto::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

----------------------------------------------------------------------------------------------*/

void TUUsuario::setUp(){
    usuario = new Usuario();
    estado = SUCESSO;
}

void TUUsuario::tearDown(){
    delete usuario;
}

void TUUsuario::testarCenarioSucesso(){
    Nome nome;
    nome.setValor(VALOR_VALIDO_NOME);
    usuario->setNome(nome);
    if(usuario->getNome().getValor() != VALOR_VALIDO_NOME)
        estado = FALHA;

    Email email;
    email.setValor(VALOR_VALIDO_EMAIL);
    usuario->setEmail(email);
    if(usuario->getEmail().getValor() != VALOR_VALIDO_EMAIL)
        estado = FALHA;

    Senha senha;
    senha.setValor(VALOR_VALIDO_SENHA);
    usuario->setSenha(senha);
    if(usuario->getSenha().getValor() != VALOR_VALIDO_SENHA)
        estado = FALHA;
}

int TUUsuario::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

void TUAvaliacao::setUp(){
    avaliacao = new Avaliacao();
    estado = SUCESSO;
}

void TUAvaliacao::tearDown(){
    delete avaliacao;
}

void TUAvaliacao::testarCenarioSucesso(){
    Codigo codigo;
    codigo.setValor(VALOR_VALIDO_CODIGO);
    avaliacao->setCodigo(codigo);
    if(avaliacao->getCodigo().getValor() != VALOR_VALIDO_CODIGO)
        estado = FALHA;

    Nota nota;
    nota.setValor(VALOR_VALIDO_NOTA);
    avaliacao->setNota(nota);
    if(avaliacao->getNota().getValor() != VALOR_VALIDO_NOTA)
        estado = FALHA;

    Descricao descricao;
    descricao.setValor(VALOR_VALIDO_DESCRICAO);
    avaliacao->setDescricao(descricao);
    if(avaliacao->getDescricao().getValor() != VALOR_VALIDO_DESCRICAO)
        estado = FALHA;
}

int TUAvaliacao::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

void TUSessao::setUp(){
    sessao = new Sessao();
    estado = SUCESSO;
}

void TUSessao::tearDown(){
    delete sessao;
}

void TUSessao::testarCenarioSucesso(){
    Codigo codigo;
    codigo.setValor(VALOR_VALIDO_CODIGO);
    sessao->setCodigo(codigo);
    if(sessao->getCodigo().getValor() != VALOR_VALIDO_CODIGO)
        estado = FALHA;

    Data data;
    data.setValor(VALOR_VALIDO_DATA);
    sessao->setData(data);
    if(sessao->getData().getValor() != VALOR_VALIDO_DATA)
        estado = FALHA;

    Horario horario;
    horario.setValor(VALOR_VALIDO_HORARIO);
    sessao->setHorario(horario);
    if(sessao->getHorario().getValor() != VALOR_VALIDO_HORARIO)
        estado = FALHA;
    
    Idioma idioma;
    idioma.setValor(VALOR_VALIDO_IDIOMA);
    sessao->setIdioma(idioma);
    if(sessao->getIdioma().getValor() != VALOR_VALIDO_IDIOMA)
        estado = FALHA;
}

int TUSessao::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

void TUExcursao::setUp(){
    excursao = new Excursao();
    estado = SUCESSO;
}

void TUExcursao::tearDown(){
    delete excursao;
}

void TUExcursao::testarCenarioSucesso(){
    Codigo codigo;
    codigo.setValor(VALOR_VALIDO_CODIGO);
    excursao->setCodigo(codigo);
    if(excursao->getCodigo().getValor() != VALOR_VALIDO_CODIGO)
        estado = FALHA;

    Titulo titulo;
    titulo.setValor(VALOR_VALIDO_TITULO);
    excursao->setTitulo(titulo);
    if(excursao->getTitulo().getValor() != VALOR_VALIDO_TITULO)
        estado = FALHA;

    Nota nota;
    nota.setValor(VALOR_VALIDO_NOTA);
    excursao->setNota(nota);
    if(excursao->getNota().getValor() != VALOR_VALIDO_NOTA)
        estado = FALHA;
    
    Cidade cidade;
    cidade.setValor(VALOR_VALIDO_CIDADE);
    excursao->setCidade(cidade);
    if(excursao->getCidade().getValor() != VALOR_VALIDO_CIDADE)
        estado = FALHA;

    Duracao duracao;
    duracao.setValor(VALOR_VALIDO_DURACAO);
    excursao->setDuracao(duracao);
    if(excursao->getDuracao().getValor() != VALOR_VALIDO_DURACAO)
        estado = FALHA;

    Descricao descricao;
    descricao.setValor(VALOR_VALIDO_DESCRICAO);
    excursao->setDescricao(descricao);
    if(excursao->getDescricao().getValor() != VALOR_VALIDO_DESCRICAO)
        estado = FALHA;
    
    Endereco endereco;
    endereco.setValor(VALOR_VALIDO_ENDERECO);
    excursao->setEndereco(endereco);
    if(excursao->getEndereco().getValor() != VALOR_VALIDO_ENDERECO)
        estado = FALHA;
}

int TUExcursao::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}
