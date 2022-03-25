#include "../headers/stubs.h"

//--------------------------------------------------------------------------------------------
// Valores usados como gatilhos de erros.

const string StubServicoAutenticacao::INVALIDO = "12345";
const string StubServicoContas::INVALIDO = "12345";
const string StubServicoExcursao::INVALIDO = "12345";

//--------------------------------------------------------------------------------------------
// Implementações dos métodos de classes stub.

bool StubServicoAutenticacao::autenticar(Email email, Senha senha){
    if(email.getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoContas::cadastrar(Usuario usuario){
    if(usuario.getEmail().getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}

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

