/* Copyright (c) Novak Petrovic
 * GNU General Public License v3.0
 */
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int jankoSat, jankoMin, jankoVrijeme;
  int petarSat, petarMin, petarVrijeme;
  int markoSat, markoMin, markoVrijeme;
  int trojica = 3;
  cin >> jankoSat >> jankoMin;
  cin >> petarSat >> petarMin;
  cin >> markoSat >> markoMin;
  int vremena[trojica];
  vremena[0] = jankoSat * 60 + jankoMin;
  vremena[1] = petarSat * 60 + petarMin;
  vremena[2] = markoSat * 60 + markoMin;
  int temp;
  bool slozen = false;
  while (!slozen) {
    slozen = true;
    for (int i = 0; i < trojica - 1; ++i) {
      if (vremena[i] > vremena[i + 1]) {
        temp = vremena[i];
        vremena[i] = vremena[i + 1];
        vremena[i + 1] = temp;
        slozen = false;
      }
    }
  }
  if (vremena[0] + 10 >= vremena[1]) {
    if (vremena[1] + 5 >= vremena[2]) {
      cout << "sreli su se";
    } else {
      cout << "nisu se sreli";
    }
  } else {
    cout << "nisu se sreli";
  }
  return EXIT_SUCCESS;
}