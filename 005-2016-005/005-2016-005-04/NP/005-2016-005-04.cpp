/* Copyright (c) Novak Petrovic
 * GNU General Public License v3.0
 */
#include <iostream>
using namespace std;

int main() {
  int N, crta;
  string odgovor = "";
  bool krajputa = false;
  string rodnigrad, trenutni, ishodiste, odrediste;
  cin >> N;
  cin >> rodnigrad;
  string karte[N];
  for (int i = 0; i < N; ++i) {
    cin >> karte[i];
  }
  trenutni = rodnigrad;
  odgovor += trenutni;
  while (!krajputa) {
    for (int i = 0; i < N; ++i) {
      crta = karte[i].find('-');
      ishodiste = karte[i].substr(0, crta);
      odrediste = karte[i].substr(crta + 1, karte[i].length());
      if (trenutni == ishodiste) {
        trenutni = odrediste;
        odgovor += "-" + trenutni;
        if (odrediste == rodnigrad) {
          krajputa = true;
          // Treci test slucaj nece proci ukoliko ovdje nemamo break!
          break;
        }
      }
    }
  }
  cout << odgovor;
  return EXIT_SUCCESS;
}
