/* Copyright (c) Novak Petrovic
 * GNU General Public License v3.0
 */
#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int niz[N];
  int prostiNiz[N];
  int slozeniNiz[N];
  int indeksProsti = 0;
  int indeksSlozeni = 0;
  for (int i = 0; i < N; ++i) {
    cin >> niz[i];
  }
  bool prosti = true;
  for (int i = 0; i < N; ++i) {
    prosti = true;
    for (int j = 2; j < niz[i]; ++j) {
      if (niz[i] % j == 0) {
        prosti = false;
      }
    }
    if (prosti) {
      prostiNiz[indeksProsti] = niz[i];
      ++indeksProsti;
    } else {
      slozeniNiz[indeksSlozeni] = niz[i];
      ++indeksSlozeni;
    }
  }
  for (int i = 0; i < indeksProsti; ++i) {
    cout << prostiNiz[i] << endl;
  }
  for (int i = 0; i < indeksSlozeni; ++i) {
    cout << slozeniNiz[i] << endl;
  }
  return EXIT_SUCCESS;
}
