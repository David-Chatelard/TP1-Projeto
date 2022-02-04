#include <iostream>

#include "../headers/dominios.h"
#include "dominios.cpp"

#include "../headers/entidades.h"
#include "entidades.cpp"

#include "../headers/testes_dominios.h"
#include "testes_dominios.cpp"

using namespace std;

int main(int argc, char const *argv[]){
    
    // Endereco endereco1;

    // endereco1.setValor("Asa  Norte..");

    // cout << endereco1.getValor() << endl;


    //-----------------------------------------------------------------------
    // Exemplo de teste de classe dom�nio.

    // Instanciar classe de teste de dom�nio.

    // TUCodigo testeA;

    // Invocar m�todo e apresentar mensagem acerca do resultado do teste.

    // switch(testeA.run()){
    //     case TUCodigo::SUCESSO: cout << "SUCESSO - CODIGO" << endl;
    //                             break;
    //     case TUCodigo::FALHA  : cout << "FALHA   - CODIGO" << endl;
    //                             break;
    // }

    TUCidade cidade_teste;

    switch(cidade_teste.run()){
        case TUCidade::SUCESSO: cout << "SUCESSO - CIDADE" << endl;
                                break;
        case TUCidade::FALHA  : cout << "FALHA   - CIDADE" << endl;
                                break;
    }

    TUCodigo codigo_teste;

    switch(codigo_teste.run()){
        case TUCodigo::SUCESSO: cout << "SUCESSO - CODIGO" << endl;
                                break;
        case TUCodigo::FALHA  : cout << "FALHA   - CODIGO" << endl;
                                break;
    }

    TUData data_teste;

    switch(data_teste.run()){
        case TUData::SUCESSO: cout << "SUCESSO - DATA" << endl;
                                break;
        case TUData::FALHA  : cout << "FALHA   - DATA" << endl;
                                break;
    }

    TUDescricao descricao_teste;

    switch(descricao_teste.run()){
        case TUDescricao::SUCESSO: cout << "SUCESSO - DESCRICAO" << endl;
                                break;
        case TUDescricao::FALHA  : cout << "FALHA   - DESCRICAO" << endl;
                                break;
    }

    TUDuracao duracao_teste;

    switch(duracao_teste.run()){
        case TUDuracao::SUCESSO: cout << "SUCESSO - DURACAO" << endl;
                                break;
        case TUDuracao::FALHA  : cout << "FALHA   - DURACAO" << endl;
                                break;
    }

    TUEmail email_teste;

    switch(email_teste.run()){
        case TUEmail::SUCESSO: cout << "SUCESSO - EMAIL" << endl;
                                break;
        case TUEmail::FALHA  : cout << "FALHA   - EMAIL" << endl;
                                break;
    }

    TUEndereco endereco_teste;

    switch(endereco_teste.run()){
        case TUEndereco::SUCESSO: cout << "SUCESSO - ENDERECO" << endl;
                                break;
        case TUEndereco::FALHA  : cout << "FALHA   - ENDERECO" << endl;
                                break;
    }

    TUHorario horario_teste;

    switch(horario_teste.run()){
        case TUHorario::SUCESSO: cout << "SUCESSO - HORARIO" << endl;
                                break;
        case TUHorario::FALHA  : cout << "FALHA   - HORARIO" << endl;
                                break;
    }

    TUIdioma idioma_teste;

    switch(idioma_teste.run()){
        case TUIdioma::SUCESSO: cout << "SUCESSO - IDIOMA" << endl;
                                break;
        case TUIdioma::FALHA  : cout << "FALHA   - IDIOMA" << endl;
                                break;
    }

    TUNome nome_teste;

    switch(nome_teste.run()){
        case TUNome::SUCESSO: cout << "SUCESSO - NOME" << endl;
                                break;
        case TUNome::FALHA  : cout << "FALHA   - NOME" << endl;
                                break;
    }

    TUNota nota_teste;

    switch(nota_teste.run()){
        case TUNota::SUCESSO: cout << "SUCESSO - NOTA" << endl;
                                break;
        case TUNota::FALHA  : cout << "FALHA   - NOTA" << endl;
                                break;
    }

    TUSenha senha_teste;

    switch(senha_teste.run()){
        case TUSenha::SUCESSO: cout << "SUCESSO - SENHA" << endl;
                                break;
        case TUSenha::FALHA  : cout << "FALHA   - SENHA" << endl;
                                break;
    }

    TUTitulo titulo_teste;

    switch(titulo_teste.run()){
        case TUTitulo::SUCESSO: cout << "SUCESSO - TITULO" << endl;
                                break;
        case TUTitulo::FALHA  : cout << "FALHA   - TITULO" << endl;
                                break;
    }

    return 0;
}
