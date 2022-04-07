#include <iostream>
#include <string.h>
#include <list>
#include <vector>
using namespace std;

int main () {
  // Criando lista
  list<string> listOfStrs = { "of", "is", "from", "this", "at", "to" };

  // Printando lista
  for (string fon : listOfStrs){
    cout << fon << endl;
  }
  cout << endl;
  
  // Copiando lista para lista
  list<string> listOfStrs_2(listOfStrs);

  // Printando lista copiada
  for (string fon : listOfStrs_2){
    cout << fon << endl;
  }

  cout << endl;

  // Criando vetor do tamanho da lista
  vector<string> vectorOfStrs(listOfStrs.size());

  // Copiando lista para vetor
  copy(listOfStrs.begin(), listOfStrs.end(), vectorOfStrs.begin());

  // Printando vetor de varias maneiras
  // for (string fon : vectorOfStrs){
  //   cout << fon << endl;
  // }
  // for (int i = 0; i < vectorOfStrs.size(); i++) {
  //   cout << vectorOfStrs[i] << endl;
  // }
  cout << vectorOfStrs[3] << endl;
  cout << vectorOfStrs[0] << endl;
  cout << vectorOfStrs[5] << endl;

  cout << endl;

  // Limpando a lista inicial
  listOfStrs.clear();

  // Printando lista
  for (string fon : listOfStrs){
    cout << fon << endl;
  }
  cout << listOfStrs.empty();
  
  return 0;
}