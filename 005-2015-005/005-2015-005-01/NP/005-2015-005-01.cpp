#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  int A[N];
  float B[2 * N];
  int suma = 0;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    suma += A[i];
  }
  for (int i = 0; i < N; i++) {
    B[2 * i] = A[i];
  }
  B[1] = (float)suma / N;
  for (int i = 3; i < 2 * N; i += 2) {
    B[i] = B[i - 2] + 1;
  }
  for (int i = 0; i < 2 * N; i++) {
    if (i % 2 == 0) {
      // Ovdje moramo koristiti defaultfloat
      // da ne dobijamo decimalni ispis za cijele brojeve
      cout << defaultfloat << B[i] << " ";
    } else {
      B[i] = trunc(round(B[i] * 100)) / 100;
      cout << fixed << setprecision(2) << B[i] << " ";
    }
  }
  return EXIT_SUCCESS;
}
