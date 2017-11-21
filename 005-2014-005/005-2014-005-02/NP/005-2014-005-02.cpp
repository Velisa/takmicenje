/* Copyright (c) Novak Petrovic
 * GNU General Public License v3.0
 */
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
  int R, K;
  cin >> R;
  cin >> K;
  int minimax[R];
  int matrica[R][K];
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < K; ++j) {
      cin >> matrica[i][j];
    }
  }
  int najmanji;
  for (int i = 0; i < R; ++i) {
    najmanji = matrica[i][0];
    for (int j = 1; j < K; ++j) {
      if (matrica[i][j] < najmanji) {
        najmanji = matrica[i][j];
      }
    }
    minimax[i] = najmanji;
    cout << i + 1 << ". red: " << najmanji << endl;
  }
  int najveci = minimax[0];
  for (int i = 1; i < R; ++i) {
    if (minimax[i] > najveci) {
      najveci = minimax[i];
    }
  }
  cout << "Maksimalni element je: " << najveci;
  return EXIT_SUCCESS;
}