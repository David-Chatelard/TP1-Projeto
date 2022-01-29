#include <iostream>

#include "../headers/dominio.h"
#include "dominio.cpp"
// #include "entidades.h"
// #include "testes.h"

using namespace std;

int main(int argc, char const *argv[]){
    
    Cidade cidade1;

    cidade1.setValor("Hong Kong");

    cout << cidade1.getValor() << endl;

    return 0;
}
