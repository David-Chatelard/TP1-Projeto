#include <iostream>
using namespace std;

int main () {
  char name[256], title[256];

  cout << "Enter your name: ";
  istream::getline(name,256);

  cout << "Enter your favourite movie: ";
  istream::getline(title,256);

  cout << name << "'s favourite movie is " << title;

  return 0;
}