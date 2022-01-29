#include "../headers/dominio.h"
#include <algorithm>
#include <set> 
#include <iostream>
#include <fstream>
#include <string>
#include <iterator> // ver se precisa, pode ser útil

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
//set<string> mes_30 {"Abr", "Jun", "Set", "Nov"};
set<string> mes_31 {"Jan", "Mar", "Mai", "Jul", "Ago", "Out", "Dez"};

// set<string> caracteres_parte_local {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '!', '#', '$', '%', '&', '\''};
set<char> caracteres_parte_local {'!', '#', '$', '%', '&', '\'', '*', '+', '-', '/', '=', '?', '^', '_', '`', '{', '}', '|', '~'};

set<string> idiomas {"Ingles", "Chines", "Mandarim", "Hindi", "Espanhol", "Frances", "Arabe", "Bengali", "Russo", "Portugues", "Indonesio"};

void Cidade::validar(string valor){
    if(!(cidades.find(valor) != cidades.end()))
      throw invalid_argument("Argumento invalido.");
}

void Cidade::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

void Codigo::validar(string valor){
    // O algoritmo de verificação utilizado será o UPS(https://stringfixer.com/pt/Check_digit)
    int soma_impar = 3 * (int(valor[0]) + int(valor[2]) + int(valor[4]));
    int soma_par = int(valor[1]) + int(valor[3]) + int(valor[5]);
    int digito_verificacao = (soma_impar + soma_par) % 10;

    if (digito_verificacao != 0){
        digito_verificacao = 10 - digito_verificacao;
    }

    if (int(valor[6]) != digito_verificacao)
        throw invalid_argument("Argumento invalido.");
}

void Codigo::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

void Data::validar(string valor){
    string separa_data[3] = {"","",""};
    string buffer = "";
    int i = 0;
    bool is_bissexto; 

    // Divide a data em 3 strings (dia, mês e ano)
    for(auto eachchar:valor)
    {
        if(eachchar != '-')
        {
            buffer+=eachchar;
        }
        else if (eachchar == '-')
        {
            separa_data[i] = buffer;
            buffer = "";
            i++;
        }
    }
    separa_data[i] = buffer;

    //Checa se o ano é bissexto
    //VERIFICAR A POSSIBILIDADE DE CRIAR UM MÉTODO PARA ISSO DENTRO DA CLASSE DATA
    if(stoi(separa_data[2]) % 4 == 0)
    {
        if(stoi(separa_data[2]) % 100 == 0)
        {
            if(stoi(separa_data[2]) % 400 == 0)
            {
                is_bissexto = true;
            }
            else
            {
                is_bissexto = false;
            }
        }
        else
        {
            is_bissexto = true;
        }
    }
    else
    {
        is_bissexto = false;
    }

    //Testa DD
    if (stoi(separa_data[0]) < 1 || stoi(separa_data[0]) > 31)
    {
        throw invalid_argument("Argumento invalido.");
    }

    //Testa Mes 30 ou 31
    else if (stoi(separa_data[0]) == 31)
    {
        if(!(mes_31.find(separa_data[1]) != mes_31.end()))
        {
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
    else if (separa_data[1] == "Fev" && stoi(separa_data[0]) > 28)
    {
        if(stoi(separa_data[0]) > 29)
        {
            throw invalid_argument("Argumento invalido.");   
        }
        //TESTA BISSEXTO
        //Se dia for 29 e não for bissexto, aponta erro 
        else if(stoi(separa_data[0]) == 29 && !is_bissexto)
        {
            throw invalid_argument("Argumento invalido.");   
        }
    }
}

void Data::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

void Descricao::validar(string valor){
    int num_pontos = 0;
    int num_espacos = 0;

    for (auto letra:valor){
        if (num_pontos >= 2){
            break;
        }
        else if (num_espacos >= 2){
            break;
        }
        
        if (letra == '.'){
            num_pontos++;
            num_espacos = 0;
        }
        else if (letra == ' '){
            num_espacos++;
            num_pontos = 0;
        }
        else{
            num_pontos = 0;
            num_espacos = 0;
        }
    }
    
    if ((valor.length() > 30) || (valor.length() < 0) || (num_pontos >= 2) || (num_espacos >= 2))
        throw invalid_argument("Argumento invalido.");
}

void Descricao::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

void Duracao::validar(int valor){
    if ((valor != 30) || (valor != 60) || (valor != 90) || (valor != 120) || (valor != 180))
        throw invalid_argument("Argumento invalido.");
}

void Duracao::setValor(int valor) {
    validar(valor);
    this->valor = valor;
}

void Email::validar(string valor){
    bool letra_invalida_local = false;
    bool letra_invalida_dominio = false;
    int num_pontos = 0;
    string separa_email[2] = {"",""};
    string buffer;
    int i = 0;
    // Divide o email em 2 strings (parte-local e dominio)
    for (auto letra:valor){
        if(letra != '@'){
            buffer+=letra;
        }
        else if (letra == '@'){
            separa_email[i] = buffer;
            buffer = "";
            i++;
        }
    }
    
    for (auto letra:valor) {
        if (!isalnum(letra) || !(caracteres_parte_local.find(letra) != caracteres_parte_local.end())){ //nao eh letra, nem numero e nem caractere especial permitido. Ainda pode ser '.' ou '@'
            if (letra == '.'){
                num_pontos++; //PAREI AQUI MEU CEREBRO DESLIGOU
            }
        }
    }

    
    if ((separa_email[0].length() > 64) || (separa_email[0][0] == '.') || (separa_email[0][separa_email[0].length()-1] == '.') || (letra_invalida_local) || (letra_invalida_dominio))
        throw invalid_argument("Argumento invalido.");
}

void Email::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

void Endereco::validar(string valor){
string buffer = "";
bool is_dot, erro_dot= false;
bool is_space, erro_space = false; 

for(auto eachchar:valor)
    {
        if(eachchar == ' ')
        {
            if(is_space == true)
            {
                erro_space = true;
            }
            else
            {
                is_space = true; 
                buffer+=eachchar;
            }
        }
        else if(eachchar == '.')
        {
            if(is_dot == true)
            {
                erro_dot = true;
            }
            else
            {
                is_dot = true; 
                buffer+=eachchar;
            }
        }
        else
        {
            is_dot = false;
            is_space = false;
            buffer+=eachchar;
        }
    }
    if(erro_dot == true || erro_space == true || buffer.size() > 20)
    {
        throw invalid_argument("Argumento invalido.");
    }
}

void Endereco::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

//VERIFICAR A NECESSIDADE DE CONFERIR  SE A ENTRADA É DE FATO DADA POR NÚMEROS (VAI DAR PAU POR CONTA DO STOI)
void Horario::validar(string valor){
    string separa_hora[2] = {"",""};
    string buffer = "";
    int i = 0;

    // Divide a hora em 2 strings (hora e minutos)
    for(auto eachchar:valor)
    {
        if(eachchar != ':')
        {
            buffer+=eachchar;
        }
        else if (eachchar == ':')
        {
            separa_hora[i] = buffer;
            buffer = "";
            i++;
        }
    }
    separa_hora[i] = buffer;

    if(stoi(separa_hora[0]) < 0 || stoi(separa_hora[0]) > 23)
    {
        throw invalid_argument("Argumento invalido.");
    }
    else if(stoi(separa_hora[1]) < 0 || stoi(separa_hora[1]) > 59)
    {
        throw invalid_argument("Argumento invalido.");
    }
}

void Horario::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

void Idioma::validar(string valor){
    if(!(idiomas.find(valor) != idiomas.end()))
        throw invalid_argument("Argumento invalido.");
}

void Idioma::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

//PRECISA IMPLEMENTAR (PREGUIÇA)
void Nome::validar(string valor){
    



}



void Nome::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

void Nota::validar(string valor){
    if(stoi(valor) > 5 || stoi(valor) < 0)
        throw invalid_argument("Argumento invalido.");
}

void Nota::setValor(string valor){
    validar(valor);
    this->valor = valor;
}
