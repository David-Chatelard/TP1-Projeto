#include <iostream>
using namespace std;

int main () {
  char name[256], title[256];

  cout << "Enter your name: ";
  cin.getline(name,255);

  cout << "Enter your favourite movie: ";
  cin.getline(title,255);

  cout << name << "'s favourite movie is " << title;

  return 0;
}