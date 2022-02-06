#include "../headers/dominios.h"

#include <algorithm>
#include <set> 
#include <iostream>
#include <fstream>
#include <string>
#include <iterator> // ver se precisa, pode ser util
#include <cctype>

using namespace std;

/* -----------------------------------------------------------------------
// Estrutura de c�digo para implementacao de classe dom�nio.
// Substituir Dominio por nome da classe.
// Substituir Tipo.
// Implementar validacao

void Dominio::validar(Tipo valor){
    if (valor == INVALIDO)
        throw invalid_argument("Argumento invalido.");
}

void Dominio::setValor(Tipo valor) {
    validar(valor);
    this->valor = valor;
}
----------------------------------------------------------------------- */

// Sets

set<string> cidades {"Hong Kong", "Bangkok", "Macau", "Singapura", "Londres", "Paris", "Dubai", "Delhi", "Istambul", "Kuala Lumpur", "Nova Iorque", "Antalya", "Mumbai", "Shenzhen", "Phuket"};

set<string> meses {"Jan", "Fev", "Mar", "Abr", "Mai", "Jun", "Jul", "Ago", "Set", "Out", "Nov", "Dez"};
set<string> mes_31 {"Jan", "Mar", "Mai", "Jul", "Ago", "Out", "Dez"};

set<char> caracteres_parte_local {'!', '#', '$', '%', '&', '\'', '*', '+', '-', '/', '=', '?', '^', '_', '`', '{', '}', '|', '~'};

set<string> idiomas {"Ingles", "Chines", "Mandarim", "Hindi", "Espanhol", "Frances", "Arabe", "Bengali", "Russo", "Portugues", "Indonesio"};

// Método implementado pelo aluno David Fanchic Chatelard, matrícula 180138863
void Cidade::validar(string valor){
    if (!(cidades.find(valor) != cidades.end()))
      throw invalid_argument("Argumento invalido.");
}

// Método implementado pelo aluno David Fanchic Chatelard, matrícula 180138863
void Cidade::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

// Método implementado pelo aluno David Fanchic Chatelard, matrícula 180138863
void Codigo::validar(string valor){
    // O algoritmo de verificação utilizado será o UPC(https://stringfixer.com/pt/Check_digit)
    const int tam_codigo = 7;
    string aux = valor;

    if (valor.length() != tam_codigo) {
        throw invalid_argument("Argumento invalido.");
    }
    aux.resize(aux.size() - 1);
    int soma_impar = 3 * ((valor[0]-'0') + (valor[2]-'0') + (valor[4]-'0'));
    int soma_par = (valor[1]-'0') + (valor[3]-'0') + (valor[5]-'0');
    int digito_verificacao = (soma_impar + soma_par) % 10;

    if (digito_verificacao != 0) {
        digito_verificacao = 10 - digito_verificacao;
    }

    // Verificar se a condição do str.compare() está funcionando, pois ela retorna 0, tem que ver se c++ aceita 0 e 1 como booleano
    if (((valor[6]-'0') != digito_verificacao) || (!(aux.compare("000000"))))
        throw invalid_argument("Argumento invalido.");
}

// Método implementado pelo aluno David Fanchic Chatelard, matrícula 180138863
void Codigo::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

// Método implementado pelo aluno Emanuel Couto Brenag, matrícula 190057131, o aluno trancou a disciplina
void Data::validar(string valor){
    string separa_data[3] = {"","",""};
    string buffer = "";
    int i = 0;
    bool is_bissexto; 

    // Divide a data em 3 strings (dia, mês e ano)
    for (auto eachchar:valor) {
        if (eachchar != '-') {
            buffer+=eachchar;
        }
        else if (eachchar == '-') {
            separa_data[i] = buffer;
            buffer = "";
            i++;
        }
    }
    separa_data[i] = buffer;

    //Checa se o ano é bissexto
    if (stoi(separa_data[2]) % 4 == 0) {
        if (stoi(separa_data[2]) % 100 == 0) {
            if (stoi(separa_data[2]) % 400 == 0) {
                is_bissexto = true;
            }
            else {
                is_bissexto = false;
            }
        }
        else {
            is_bissexto = true;
        }
    }
    else {
        is_bissexto = false;
    }

    //Testa DD
    if (stoi(separa_data[0]) < 1 || stoi(separa_data[0]) > 31) {
        throw invalid_argument("Argumento invalido.");
    }

    //Testa Mes 30 ou 31
    else if (stoi(separa_data[0]) == 31) {
        if(!(mes_31.find(separa_data[1]) != mes_31.end())) {
            throw invalid_argument("Argumento invalido.");
        }
    }

    //Testa MES   
    else if (!(meses.find(separa_data[1]) != meses.end()))
        throw invalid_argument("Argumento invalido.");           
    
    //Testa AA
    else if (stoi(separa_data[2]) < 2000 || stoi(separa_data[2]) > 9999 )
        throw invalid_argument("Argumento invalido.");   
        
    //Testa Fevereiro e BISSEXTO
    else if (separa_data[1] == "Fev" && stoi(separa_data[0]) > 28) {
        if(stoi(separa_data[0]) > 29) {
            throw invalid_argument("Argumento invalido.");   
        }
        //TESTA BISSEXTO
        //Se dia for 29 e não for bissexto, aponta erro 
        else if(stoi(separa_data[0]) == 29 && !is_bissexto) {
            throw invalid_argument("Argumento invalido.");   
        }
    }
}

// Método implementado pelo aluno Emanuel Couto Brenag, matrícula 190057131, o aluno trancou a disciplina
void Data::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

// Método implementado pelo aluno David Fanchic Chatelard, matrícula 180138863
void Descricao::validar(string valor){
    int num_pontos = 0;
    int num_espacos = 0;
    int tam_descricao = int(valor.length());

    for (auto letra:valor) {
        if (num_pontos >= 2) {
            break;
        }
        else if (num_espacos >= 2) {
            break;
        }
        
        if (letra == '.') {
            num_pontos++;
            num_espacos = 0;
        }
        else if (letra == ' ') {
            num_espacos++;
            num_pontos = 0;
        }
        else {
            num_pontos = 0;
            num_espacos = 0;
        }
    }
    
    if ((tam_descricao > 30) || (tam_descricao < 0) || (num_pontos >= 2) || (num_espacos >= 2))
        throw invalid_argument("Argumento invalido.");
}

// Método implementado pelo aluno David Fanchic Chatelard, matrícula 180138863
void Descricao::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

// Método implementado pelo aluno David Fanchic Chatelard, matrícula 180138863
void Duracao::validar(int valor){
    if ((valor != 30) && (valor != 60) && (valor != 90) && (valor != 120) && (valor != 180))
        throw invalid_argument("Argumento invalido.");
}

// Método implementado pelo aluno David Fanchic Chatelard, matrícula 180138863
void Duracao::setValor(int valor) {
    validar(valor);
    this->valor = valor;
}

// Método implementado pelo aluno David Fanchic Chatelard, matrícula 180138863
void Email::validar(string valor){
    bool letra_invalida_local = false;
    bool letra_invalida_dominio = false;
    int num_pontos = 0;
    string separa_email[2] = {"",""};
    string buffer;
    int i = 0;

    // Divide o email em 2 strings (parte-local e dominio)
    for (auto letra:valor) {
        if(letra != '@') {
            buffer+=letra;
        }
        else if (letra == '@') {
            separa_email[i] = buffer;
            buffer = "";
            i++;
        }
    }
    separa_email[i] = buffer;

    // Verifica a parte-local
    for (auto letra:separa_email[0]) {
        if (!isalnum(letra) && !(caracteres_parte_local.find(letra) != caracteres_parte_local.end())) { //Não é letra e nem número e nem caractere especial permitido. Ainda pode ser '.' ou '@'
            if (letra == '@') {
                letra_invalida_local = true;
                break;
            }
            else if (letra == '.') {
                num_pontos++;
                if (num_pontos >= 2) {
                    letra_invalida_local = true;
                    break;
                }
            }
        }
        else {
            num_pontos = 0;
        }
    }

    // Verifica o dominio
    num_pontos = 0;
    for (auto letra:separa_email[1]) {
        if (letra_invalida_local) {  // A parte-local ja eh invalida
            break;
        }
        if (!isalnum(letra) && !(letra == '-')) { // Nao eh letra e nem '-'. Ainda pode ser '.' ou caracter invalido
            if (letra == '.') {
                num_pontos++;
                if (num_pontos >= 2) {
                    letra_invalida_dominio = true;
                    break;
                }
            }
            else {
                letra_invalida_dominio = true;
                break;
            }
        }
        else {
            num_pontos = 0;
        }
    }

    if ((separa_email[0].length() > 64) || (separa_email[0][0] == '.') || (separa_email[0][separa_email[0].length()-1] == '.') || (letra_invalida_local) || (separa_email[1].length() > 253) || (separa_email[1][0] == '.') || (letra_invalida_dominio))
        throw invalid_argument("Argumento invalido.");
}

// Método implementado pelo aluno David Fanchic Chatelard, matrícula 180138863
void Email::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

// Método implementado pelo aluno Emanuel Couto Brenag, matrícula 190057131, o aluno trancou a disciplina
void Endereco::validar(string valor){
    string buffer = "";
    bool is_dot, erro_dot= false;
    bool is_space, erro_space = false; 

    for (auto eachchar:valor) {
            if (eachchar == ' ') {
                if(is_space == true) {
                    erro_space = true;
                }
                else {
                    is_space = true; 
                    buffer+=eachchar;
                }
            }
            else if (eachchar == '.') {
                if (is_dot == true) {
                    erro_dot = true;
                }
                else {
                    is_dot = true; 
                    buffer+=eachchar;
                }
            }
            else {
                is_dot = false;
                is_space = false;
                buffer += eachchar;
            }
        }
        if(erro_dot == true || erro_space == true || buffer.size() > 20)
            throw invalid_argument("Argumento invalido.");
}

// Método implementado pelo aluno Emanuel Couto Brenag, matrícula 190057131, o aluno trancou a disciplina
void Endereco::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

//VERIFICAR A NECESSIDADE DE CONFERIR  SE A ENTRADA É DE FATO DADA POR NÚMEROS (PODE DAR PROBLEMA POR CAUSA DO STOI)
// Método implementado pelo aluno Emanuel Couto Brenag, matrícula 190057131, o aluno trancou a disciplina
void Horario::validar(string valor){
    string separa_hora[2] = {"",""};
    string buffer = "";
    int i = 0;

    // Divide a hora em 2 strings (hora e minutos)
    for (auto eachchar:valor) {
        if (eachchar != ':') {
            buffer+=eachchar;
        }
        else if (eachchar == ':') {
            separa_hora[i] = buffer;
            buffer = "";
            i++;
        }
    }
    separa_hora[i] = buffer;

    if (stoi(separa_hora[0]) < 0 || stoi(separa_hora[0]) > 23) {
        throw invalid_argument("Argumento invalido.");
    }
    else if (stoi(separa_hora[1]) < 0 || stoi(separa_hora[1]) > 59) {
        throw invalid_argument("Argumento invalido.");
    }
}

// Método implementado pelo aluno Emanuel Couto Brenag, matrícula 190057131, o aluno trancou a disciplina
void Horario::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

// Método implementado pelo aluno David Fanchic Chatelard, matrícula 180138863
void Idioma::validar(string valor){
    if(!(idiomas.find(valor) != idiomas.end()))
        throw invalid_argument("Argumento invalido.");
}

// Método implementado pelo aluno David Fanchic Chatelard, matrícula 180138863
void Idioma::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

// Método implementado pelo aluno Alexandre Abrahami Pinto da Cunha, matrícula 180041169
void Nome::validar(string valor){
    int tam_nome = int(valor.length());

    for (int i = 0; i < tam_nome; i++) {

        //Verifica se é letra, espaço em branco ou ponto
        if (!isalpha(valor[i]) && !isblank(valor[i]) && valor[i] != '.')
            throw invalid_argument("Argumento invalido.");
            
        //Verifica se o ponto é precedido por letra e seguido por um espaço em branco caso não seja o último caractere
        if (valor[i] == '.' && i == 0) {
            throw invalid_argument("Argumento invalido.");
        }
        else if (valor[i] == '.' && i < (tam_nome - 1)) {  
            if (!isalpha(valor[i-1]) || !isblank(valor[i+1]))
                throw invalid_argument("Argumento invalido.");
        }
        else if (valor[i] == '.' && i == (tam_nome - 1)) {
            if (!isalpha(valor[i-1]))
                throw invalid_argument("Argumento invalido.");
        }
        
        //Verifica se não há espaços em branco em sequência e se a primeira letra de cada termo é letra maiúscula
        if (valor[i] == ' ' && i == 0) {
            if (!isupper(valor[i + 1]))
                throw invalid_argument("Argumento invalido.");
        }
        else if (valor[i] == ' ' && i < (tam_nome - 1)) {  
            if (isblank(valor[i-1]) || isblank(valor[i+1]) || !isupper(valor[i+1]))
                throw invalid_argument("Argumento invalido.");       
        }
        else if (valor[i] == ' ' && i == (tam_nome - 1)) {
            if (isblank(valor[i-1]))
                throw invalid_argument("Argumento invalido.");
        }
    }
    //Verifica se o nome possui entre 5 e 20 caracteres
    if (tam_nome < 5 || tam_nome > 20)
        throw invalid_argument("Argumento invalido.");
}

// Método implementado pelo aluno Alexandre Abrahami Pinto da Cunha, matrícula 180041169
void Nome::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

// Método implementado pelo aluno David Fanchic Chatelard, matrícula 180138863
void Nota::validar(int valor){
    if(valor > 5 || valor < 0)
        throw invalid_argument("Argumento invalido.");
}

// Método implementado pelo aluno David Fanchic Chatelard, matrícula 180138863
void Nota::setValor(int valor){
    validar(valor);
    this->valor = valor;
}

// Método implementado pelo aluno Emanuel Couto Brenag, matrícula 190057131, o aluno trancou a disciplina
void Senha::validar(string valor){
    //Lenght da string é de 6
    const int tam_string = 6;
    string senha = "";
    bool has_lowercase = false, has_uppercase = false, has_digit = false, has_repeated_char = false, has_invalid_char = false;
    for(auto eachchar:valor) {
        if (senha.find(eachchar) != string::npos) {
            has_repeated_char = true;
        }
        if (!isalnum(eachchar)) {
            has_invalid_char= true;
            senha+=eachchar;
        }
        //Checa se tem pelo menos um digito
        if (isdigit(eachchar)) {
            has_digit = true;
            senha+=eachchar;
        }
        //Checa se tem pelo menos uma letra maiuscula
        else if (isupper(eachchar)) {
            has_uppercase = true;
            senha+=eachchar;
        }
        //Checa se tem pelo menos uma letra minuscula
        else if (islower(eachchar)) {
            has_lowercase = true;
            senha+=eachchar;
        }
    }
    if (valor.length() != tam_string || !has_lowercase || !has_uppercase || !has_digit || has_repeated_char || has_invalid_char) {
        throw invalid_argument("Argumento invalido.");
    }
}

// Método implementado pelo aluno Emanuel Couto Brenag, matrícula 190057131, o aluno trancou a disciplina
void Senha::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

// Método implementado pelo aluno Alexandre Abrahami Pinto da Cunha, matrícula 180041169
void Titulo::validar(string valor){
    int num_letras = 0, tam_titulo = int(valor.length());

    for (int i = 0; i < tam_titulo; i++) {

        //Conta o número de letras, já que pode haver outros caracteres
        if (isalpha(valor[i]))
            num_letras++;

        //Verifica se não há pontos em sequência
        if (valor[i] == '.' && i != 0) {  
            if (valor[i-1] == '.')
                throw invalid_argument("Argumento invalido.");       
        }
    
        //Verifica se não há espaços em branco em sequência
        if (valor[i] == ' ' && i != 0) {  
            if (isblank(valor[i-1]))
                throw invalid_argument("Argumento invalido.");       
        }
    }

    //Verifica se o título possui entre 5 e 20 letras
    if (num_letras < 5 || num_letras > 20)
        throw invalid_argument("Argumento invalido.");

}

// Método implementado pelo aluno Alexandre Abrahami Pinto da Cunha, matrícula 180041169
void Titulo::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}
