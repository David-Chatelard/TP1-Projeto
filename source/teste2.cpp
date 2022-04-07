#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

string gerarCodigo(){
    string valor = "";

    for (int i = 0; i < 6; i++){
        valor += to_string(rand() % 10);
    }

    int soma_impar = 3 * ((valor[0]-'0') + (valor[2]-'0') + (valor[4]-'0'));
    int soma_par = (valor[1]-'0') + (valor[3]-'0') + (valor[5]-'0');
    int digito_verificacao = (soma_impar + soma_par) % 10;

    if (digito_verificacao != 0) {
        digito_verificacao = 10 - digito_verificacao;
    }

    valor += to_string(digito_verificacao);

    return valor;
}

void validar(string valor){
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

int main() {
    // unsigned seed = time(0);
    srand(time(0));
    string num1 = gerarCodigo();
    string num2 = gerarCodigo();
    string num3 = gerarCodigo();
    string num4 = gerarCodigo();
    string num5 = gerarCodigo();
    string texto12 = "Erro";

    cout << num1 << endl;
    try{
        num1[6] = '0';
        validar(num1);
    }
    catch(invalid_argument &exp){
        cout << texto12 << endl;
    }

    cout << num2 << endl;
    try{
        validar(num2);
    }
    catch(invalid_argument &exp){
        cout << texto12 << endl;
    }

    cout << num3 << endl;
    try{
        validar(num3);
    }
    catch(invalid_argument &exp){
        cout << texto12 << endl;
    }

    cout << num4 << endl;
    try{
        validar(num4);
    }
    catch(invalid_argument &exp){
        cout << texto12 << endl;
    }
    cout << num5 << endl;
    try{
        validar(num5);
    }
    catch(invalid_argument &exp){
        cout << texto12 << endl;
    } 
}