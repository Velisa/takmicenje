#include <iostream>
using namespace std;

int main() {
  string izraz;
  cin >> izraz;
  unsigned long long int brojeva;
  if (izraz[0] == '-' || izraz[0] == '+') {
    brojeva = 0;
  } else {
    brojeva = 1;
  }
  for (unsigned long long int i = 0; i < izraz.length(); ++i) {
    if (izraz[i] == '-' || izraz[i] == '+') ++brojeva;
  }
  unsigned long long int k = 0;
  unsigned long long int niz[brojeva];
  string broj = "";
  // Moramo imati <= da bismo mogli izvuci posljednji broj
  for (unsigned long long int i = 0; i <= izraz.length(); ++i) {
    if (isdigit(izraz[i]) || i == 0) {
      broj = broj + izraz[i];
    } else {
      niz[k] = atoi(broj.c_str());
      ++k;
      broj = izraz[i];
    }
  }
  unsigned long long int temp;
  bool slozen = false;
  while (!slozen) {
    slozen = true;
    for (unsigned long long int i = 0; i < brojeva - 1; ++i) {
      if (niz[i] > niz[i + 1]) {
        slozen = false;
        temp = niz[i];
        niz[i] = niz[i + 1];
        niz[i + 1] = temp;
      }
    }
  }
  string sbroj;
  unsigned long long int suma = 0;
  for (unsigned long long int i = 0; i < brojeva; ++i) suma += niz[i];
  unsigned long long int novi_niz[brojeva];
  novi_niz[0] = suma;
  unsigned long long int nova_suma;
  unsigned long long int cnt = 0;
  for (unsigned long long int i = 0; i < brojeva; ++i) {
    if (niz[i] < -9) {
      nova_suma = suma - niz[i];
      sbroj = to_string(niz[i]);
      for (unsigned long long int k = 2; k < sbroj.length(); ++k) {
        // nova_suma += atoi((sbroj.substr(0, k)).c_str());

        nova_suma += stoll(sbroj.substr(0, k));
        cout << stoll(sbroj.substr(0, k)) << endl;
        // nova_suma += atoi((sbroj.substr(k, sbroj.length())).c_str());
        nova_suma += stoll(sbroj.substr(k, sbroj.length()));
        cout << stoll(sbroj.substr(k, sbroj.length())) << endl;
        if (nova_suma > suma) {
          suma = nova_suma;
        }
        // nova_suma -= atoi((sbroj.substr(0, k)).c_str());
        nova_suma -= stoll(sbroj.substr(0, k));
        // nova_suma -= atoi((sbroj.substr(k, sbroj.length())).c_str());
        nova_suma -= stoll(sbroj.substr(k, sbroj.length()));
      }
      novi_niz[cnt] = suma;
      ++cnt;
    }
  }
  unsigned long long int max = novi_niz[0];
  for (unsigned long long int i = 1; i < cnt; ++i) {
    if (novi_niz[i] > max) max = novi_niz[i];
  }
  cout << max;
  return 0;
}