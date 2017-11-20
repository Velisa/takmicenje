/* Copyright (c) Novak Petrovic
 * Released under GNU General Public License v3.0 */

#include <math.h>
#include <iostream>
using namespace std;

int main(void) {
  const int D = 5;
  int matrica[D][D];
  int posjeceni[D * D];
  int i = 0;
  int red = 0;
  int kol = 0;
  int sred, skol;
  bool nadjeno = false;
  bool ukradeno = false;
  for (int i = 0; i < D; ++i) {
    for (int j = 0; j < D; ++j) {
      cin >> matrica[i][j];
    }
  }
  while (!nadjeno && !ukradeno) {
    posjeceni[i] = 10 * red + kol;
    ++i;
    sred = matrica[red][kol] / 10 - 1;
    skol = matrica[red][kol] % 10 - 1;
    ukradeno = false;
    // Vazno je da j < i - 1
    // ne gledamo posljednju dodatu celiju
    // u slucaju da se tu nalazi blago
    for (int j = 0; j < i - 1; ++j) {
      if ((10 * sred + skol) == posjeceni[j]) {
        ukradeno = true;
        cout << "Blago je ukradeno" << endl;
        break;
      }
    }
    if (!ukradeno && red == sred && kol == skol) {
      cout << "blago je u " << red + 1 << " " << kol + 1 << endl;
      nadjeno = true;
    }
    if (!nadjeno && !ukradeno) {
      cout << "posjetili " << sred + 1 << " " << skol + 1 << endl;
    }
    red = sred;
    kol = skol;
  }
  return 0;
}
