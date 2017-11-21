/* Copyright (c) Novak Petrovic
 * GNU General Public License v3.0
 */
#include <cmath>
#include <iostream>
using namespace std;

int main(void) {
  int N, M;
  cin >> N >> M;
  int A[N][M];
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> A[i][j];
    }
  }
  int zbir = 0;
  for (int i = 0; i < N; ++i) {
    zbir = 0;
    for (int j = 0; j < M; ++j) {
      zbir += A[i][j];
    }
    cout << "Zbir el. " << i + 1 << ". vrste je " << zbir << endl;
  }
  for (int i = 0; i < M; ++i) {
    int zbir = 0;
    for (int j = 0; j < N; ++j) {
      zbir += A[j][i];
    }
    cout << "Zbir el. " << i + 1 << ". kolone je " << zbir << endl;
  }
  return EXIT_SUCCESS;
}