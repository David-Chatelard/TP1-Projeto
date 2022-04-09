#include "../headers/stubs.h"

//--------------------------------------------------------------------------------------------
// Valores usados como gatilhos de erros.

// const string StubServicoAutenticacao::INVALIDO = "12345";
// const string StubServicoContas::INVALIDO = "12345";
// const string StubServicoContas::INVALIDO_NOME = "amgongas";
const string StubServicoExcursao::INVALIDO = "12345";

//--------------------------------------------------------------------------------------------
// Implementações dos métodos da classe StubServicoAutenticacao.

// bool StubServicoAutenticacao::autenticar(Email email, Senha senha){
//     if(email.getValor().compare(INVALIDO) == 0)
//         return false;
//     return true;
// }

//--------------------------------------------------------------------------------------------
// Implementações dos métodos da classe StubServicoContas.

// bool StubServicoContas::cadastrar(Usuario usuario){
//     if(usuario.getEmail().getValor().compare(INVALIDO) == 0)
//         return false;
//     return true;
// }

// bool StubServicoContas::editar(Usuario usuario){
//     if(usuario.getNome().getValor().compare(INVALIDO_NOME) == 0)
//         return false;
//     return true;
// }

// bool StubServicoContas::descadastrar(Email email){
//     if(email.getValor().compare(INVALIDO) == 0)
//         return false;
//     return true;
// }

//--------------------------------------------------------------------------------------------
// Implementações dos métodos da classe StubServicoExcursao.

// bool StubServicoExcursao::cadastrarConta(Conta conta){
//     if(conta.getNumero().getValor().compare(INVALIDO) == 0)
//         return false;
//     return true;
// }

// bool StubServicoExcursao::consultarConta(Conta *conta){
//     if(conta->getNumero().getValor().compare(INVALIDO) == 0)
//         return false;

//     //--------------------------------------------------------------------------------------------
//     //--------------------------------------------------------------------------------------------
//     // Implementar código que atribui valores ao objeto identificado por conta.
//     //--------------------------------------------------------------------------------------------
//     //--------------------------------------------------------------------------------------------

//     return true;
// }

// bool StubServicoExcursao::cadastrarProdutoInvestimento(Produto produto){
//     if(produto.getCodigo().getValor().compare(INVALIDO) == 0)
//         return false;
//     return true;
// }

// bool StubServicoExcursao::descadastrarProdutoInvestimento(Codigo codigo){
//     if(codigo.getValor().compare(INVALIDO) == 0)
//         return false;
//     return true;
// }

// bool StubServicoExcursao::realizarAplicacao(Aplicacao aplicacao){
//     if(aplicacao.getCodigo().getValor().compare(INVALIDO) == 0)
//         return false;
//     return true;
// }

// bool StubServicoExcursao::recuperarAplicacao(Aplicacao *aplicacao){
//     if(aplicacao->getCodigo().getValor().compare(INVALIDO) == 0)
//         return false;

//     //--------------------------------------------------------------------------------------------
//     //--------------------------------------------------------------------------------------------
//     // Implementar c�digo que atribui valores ao objeto identificado por aplicacao.
//     //--------------------------------------------------------------------------------------------
//     //--------------------------------------------------------------------------------------------

//     return true;
// }


bool StubServicoExcursao::cadastrarExcursao(Excursao excursao){
    if(excursao.getTitulo().getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoExcursao::consultarExcursao(Excursao *excursao){
    if(excursao->getCodigo().getValor().compare(INVALIDO) == 0)
        return false;

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Implementar código que atribui valores ao objeto identificado por excursao.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    return true;
}

bool StubServicoExcursao::descadastrarExcursao(Excursao excursao){
    if(excursao.getCodigo().getValor().compare(INVALIDO) == 0) //talvez tenha que mudar algo aqui
        return false;
    return true;
}

bool StubServicoExcursao::cadastrarSessao(Sessao sessao){
    if(sessao.getCodigo().getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoExcursao::consultarSessao(Sessao *sessao){
    if(sessao->getCodigo().getValor().compare(INVALIDO) == 0)
        return false;

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Implementar código que atribui valores ao objeto identificado por excursao.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    return true;
}

bool StubServicoExcursao::descadastrarSessao(Sessao sessao){
    if(sessao.getCodigo().getValor().compare(INVALIDO) == 0) //talvez tenha que mudar algo aqui
        return false;
    return true;
}

bool StubServicoExcursao::cadastrarAvaliacao(Avaliacao avaliacao){
    if(avaliacao.getCodigo().getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoExcursao::consultarAvaliacao(Avaliacao *avaliacao){
    if(avaliacao->getCodigo().getValor().compare(INVALIDO) == 0)
        return false;

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Implementar código que atribui valores ao objeto identificado por excursao.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    return true;
}

bool StubServicoExcursao::descadastrarAvaliacao(Avaliacao avaliacao){
    if(avaliacao.getCodigo().getValor().compare(INVALIDO) == 0) //talvez tenha que mudar algo aqui
        return false;
    return true;
}
