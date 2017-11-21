/* Copyright (c) Novak Petrovic
 * GNU General Public License v3.0
 */
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int K, tmp;
  int n = 0;
  cin >> K;
  int al[K], bl[K], cl[K];
  for (int a = 1; a <= K; ++a) {
    for (int b = 1; b <= K; ++b) {
      for (int c = 1; c <= K; ++c) {
        if (pow(a, 2) + pow(b, 2) == pow(c, 2)) {
          al[n] = a;
          bl[n] = b;
          cl[n] = c;
          ++n;
        }
      }
    }
  }
  // Sortiraj elemente unutar trojke (a, b, c),
  // da mozemo identifikovati trojke koje se ponavljaju
  for (int i = 0; i < n; ++i) {
    // Nista ne treba mijenjati
    if ((al[i] <= bl[i]) && (bl[i] <= cl[i])) {
      ;
    }
    // Zamjena a i b
    if ((al[i] > bl[i]) && (bl[i] <= cl[i])) {
      tmp = bl[i];
      bl[i] = al[i];
      al[i] = tmp;
    }
    // Zamjena b i c
    if ((al[i] <= bl[i]) && (bl[i] > cl[i])) {
      tmp = cl[i];
      cl[i] = bl[i];
      bl[i] = tmp;
    }
    // Zamjena a i c
    if ((al[i] > bl[i]) && (bl[i] > cl[i])) {
      tmp = cl[i];
      cl[i] = al[i];
      al[i] = tmp;
    }
  }
  // Sortiranje trojki po "koloni a"
  bool nizURedu = false;
  while (!nizURedu) {
    nizURedu = true;
    for (int i = 0; i < n - 1; ++i) {
      if (al[i] > al[i + 1]) {
        nizURedu = false;
        tmp = al[i + 1];
        al[i + 1] = al[i];
        al[i] = tmp;
        //
        tmp = bl[i + 1];
        bl[i + 1] = bl[i];
        bl[i] = tmp;
        //
        tmp = cl[i + 1];
        cl[i + 1] = cl[i];
        cl[i] = tmp;
      }
    }
  }
  // Sortiranje trojki po "koloni b"
  nizURedu = false;
  while (!nizURedu) {
    nizURedu = true;
    for (int i = 0; i < n - 1; ++i) {
      if (al[i] == al[i + 1] && bl[i] > bl[i + 1]) {
        nizURedu = false;
        tmp = al[i + 1];
        al[i + 1] = al[i];
        al[i] = tmp;
        //
        tmp = bl[i + 1];
        bl[i + 1] = bl[i];
        bl[i] = tmp;
        //
        tmp = cl[i + 1];
        cl[i + 1] = cl[i];
        cl[i] = tmp;
      }
    }
  }
  // Sortiranje trojki po "koloni c"
  nizURedu = false;
  while (!nizURedu) {
    nizURedu = true;
    for (int i = 0; i < n - 1; ++i) {
      if (al[i] && al[i + 1] && bl[i] == bl[i + 1] && cl[i] > cl[i + 1]) {
        nizURedu = false;
        tmp = al[i + 1];
        al[i + 1] = al[i];
        al[i] = tmp;
        //
        tmp = bl[i + 1];
        bl[i + 1] = bl[i];
        bl[i] = tmp;
        //
        tmp = cl[i + 1];
        cl[i + 1] = cl[i];
        cl[i] = tmp;
      }
    }
  }
  // Ispis samo unikatnih trojki
  int i = 0;
  cout << "a "
       << "b "
       << "c" << endl;
  while (i < n - 1) {
    if (al[i] == al[i + 1] && bl[i] == bl[i + 1] && cl[i] == cl[i + 1])
      ;
    else
      cout << al[i] << " " << bl[i] << " " << cl[i] << endl;
    ++i;
  }
  cout << al[i] << " " << bl[i] << " " << cl[i];
  return EXIT_SUCCESS;
}
