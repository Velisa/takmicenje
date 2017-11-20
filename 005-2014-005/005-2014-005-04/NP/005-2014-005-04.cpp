/* Copyright (c) Novak Petrovic
 * Released under GNU General Public License v3.0 */

#include <iostream>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  int A[N];
  int B[N];
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  int najveci;
  for (int i = 0; i < N; ++i) {
    najveci = A[0];
    for (int j = 0; j <= i; ++j) {
      if (A[j] >= najveci) {
        najveci = A[j];
        B[i] = najveci;
      }
    }
  }
  cout << "Pocetni niz je: " << A[0];
  for (int i = 1; i < N; ++i) {
    cout << "," << A[i];
  }
  cout << endl;
  cout << "Novi niz je: " << B[0];
  for (int i = 1; i < N; ++i) {
    cout << "," << B[i];
  }
  return EXIT_SUCCESS;
}