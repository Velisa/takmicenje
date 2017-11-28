#include <iostream>
using namespace std;

int main() {
  string izraz;
  cin >> izraz;
  int brojeva;
  if (izraz[0] == '-' || izraz[0] == '+') {
    brojeva = 0;
  } else {
    brojeva = 1;
  }
  for (int i = 0; i < izraz.length(); ++i) {
    if (izraz[i] == '-' || izraz[i] == '+') ++brojeva;
  }
  int k = 0;
  long long int niz[brojeva];
  string broj = "";
  // Moramo imati <= da bismo mogli izvuci posljednji broj
  for (int i = 0; i <= izraz.length(); ++i) {
    if (isdigit(izraz[i]) || i == 0) {
      broj = broj + izraz[i];
    } else {
      niz[k] = stoll(broj);
      ++k;
      broj = izraz[i];
    }
  }
  long long int temp;
  bool slozen = false;
  while (!slozen) {
    slozen = true;
    for (int i = 0; i < brojeva - 1; ++i) {
      if (niz[i] > niz[i + 1]) {
        slozen = false;
        temp = niz[i];
        niz[i] = niz[i + 1];
        niz[i + 1] = temp;
      }
    }
  }
  string sbroj;
  long long int broj1;
  long long int broj2;
  long long int suma = 0;
  for (int i = 0; i < brojeva; ++i) suma += niz[i];
  long long int nova_suma = suma;
  for (int i = 0; i < brojeva; ++i) {
    if (niz[i] < -9) {
      nova_suma = suma - niz[i];
      sbroj = to_string(niz[i]);
      for (int k = 2; k < sbroj.length(); ++k) {
        broj1 = stoll(sbroj.substr(0, k));
        nova_suma += broj1;
        // Alternativno:
        // broj1 = atoll((sbroj.substr(0, k)).c_str());
        broj2 = stoll(sbroj.substr(k, sbroj.length()));
        nova_suma += broj2;
        // Alternativno:
        // broj2 = atoll((sbroj.substr(k, sbroj.length())).c_str());
        if (nova_suma > suma) {
          suma = nova_suma;
        }
        nova_suma -= broj1;
        nova_suma -= broj2;
      }
    }
  }
  cout << suma;
  return 0;
}