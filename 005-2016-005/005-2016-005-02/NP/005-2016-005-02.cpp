/* Copyright (c) Novak Petrovic
 * GNU General Public License v3.0
 */
#include <iostream>
using namespace std;

int main() {
  int r, k;
  cin >> r;
  cin >> k;
  int nur[r];
  int matrica[r][k];
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < k; ++j) {
      cin >> matrica[i][j];
    }
  }
  for (int i = 0; i < r; ++i) {
    nur[i] = matrica[i][0];
    for (int j = 0; j < k; ++j) {
      if (matrica[i][j] < nur[i]) {
        nur[i] = matrica[i][j];
      }
    }
  }
  int najveci = nur[0];
  for (int i = 1; i < r; ++i) {
    if (nur[i] > najveci) {
      najveci = nur[i];
    }
  }
  cout << "Trazeni broj je " << najveci << ", nalazi se" << endl;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < k; ++j) {
      if (matrica[i][j] == najveci) {
        cout << "u " << (i + 1) << ". redu i " << (j + 1) << ". koloni" << endl;
      }
    }
  }
  return EXIT_SUCCESS;
}