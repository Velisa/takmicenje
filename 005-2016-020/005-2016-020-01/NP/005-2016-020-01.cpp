#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int pocetak, kraj;
  cin >> pocetak >> kraj;
  int broj, cifra, duzina;
  int zbir = 0;
  for (; pocetak <= kraj; ++pocetak) {
    broj = pocetak;
    duzina = to_string(pocetak).length();
    for (int i = 0; i < duzina; ++i) {
      cifra = broj / (int)pow(10, duzina - i - 1);
      zbir += pow(cifra, duzina);
      broj %= (int)pow(10, duzina - i - 1);
    }
    if (zbir == pocetak) {
      cout << pocetak << endl;
    }
    zbir = 0;
  }
  return 0;
}