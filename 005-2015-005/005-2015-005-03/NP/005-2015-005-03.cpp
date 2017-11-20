/* Copyright (c) Novak Petrovic
 * Released under GNU General Public License v3.0 */

#include <cstdlib>
#include <iostream>
using namespace std;

int main(void) {
  int N, M, najmanji;
  int brojRedova = 0;
  cin >> N;
  cin >> M;
  int A[N][M];
  bool ignorisati[N];
  // Inicijalizacija
  for (int i = 0; i < N; ++i) ignorisati[i] = false;
  // Unos matrice
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j) cin >> A[i][j];
  // Pronaci najmanji broj u cijeloj matrici
  najmanji = A[0][0];
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j)
      if (A[i][j] < najmanji) najmanji = A[i][j];
  // Koje redove ignorisati
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j)
      if (A[i][j] == najmanji) {
        ignorisati[i] = true;
        ++brojRedova;
        break;
      }
  // Ispis
  // Napomena: Pazi na zagrade kod vanjskog if-else!
  if (brojRedova != N) {
    for (int i = 0; i < N; ++i)
      if (ignorisati[i] == false)
        for (int j = 0; j < M; ++j) cout << A[i][j] << endl;
  } else {
    cout << "Ne postoji matrica koja zadovoljava postavljeni uslov!" << endl;
  }
  return EXIT_SUCCESS;
}
