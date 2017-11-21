/* Copyright (c) Novak Petrovic
 * GNU General Public License v3.0
 */
#include <iostream>
using namespace std;

int main() {
  int N, M, k, l;
  int suma = 0;
  cin >> N;
  cin >> M;
  int matrica[N][M];
  for (int n = 0; n < N; ++n) {
    for (int m = 0; m < M; ++m) {
      cin >> matrica[n][m];
    }
  }
  cin >> k;
  cin >> l;
  for (int n = 0; n < N; ++n) {
    for (int m = 0; m < M; ++m) {
      // Ne sabiremo izabrani element
      if (n != (k - 1) && m != (l - 1)) {
        // Ako je element na glavnoj dijagonali
        if (k == l) {
          if (n == m) {
            suma += matrica[n][m];
          }
        }
        // Ako element nije na glavnoj dijagonali
        // Ovaj uslov identifikuje sve elemente na dijagonali
        // koja ide od lijevo gore do desno dole
        else {
          if ((k - 1) - (l - 1) == (n - m)) {
            suma += matrica[n][m];
          }
        }
        // Ovaj uslov vazi za oba prethodna uslova
        // Ovaj uslov identifikuje sve elemente na dijagonali
        // koja ide od lijevo dole do desno gore
        // (bez obzira da li je na glavnoj dijagonali ili ne)
        if ((n + m) == ((k - 1) + (l - 1))) {
          suma += matrica[n][m];
        }
      }
    }
  }
  cout << suma;
  return EXIT_SUCCESS;
}
