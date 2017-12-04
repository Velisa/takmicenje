/* http://github.com/novakpetrovic/takmicenje

Spiralno ispisvanje NxN matrice u smjeru kazaljke na satu.
Na primjer, za N = 4 imamo:
1		2		3		4
12	13	14	5
11	16	15	6
10	9		8		7

 */
#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int niz[N][N];
  int broj = 1;
	// Ima razlike u broju ispisa ako je N parno ili ne
  for (int k = 0; k < (N / 2 + N % 2); ++k) {
		// Od lijeva prema desno
    for (int i = 0 + k; i < N - k; ++i) {
      niz[0 + k][i] = broj;
      ++broj;
    }
		// Od gore prema dole
    for (int j = 1 + k; j < N - k; ++j) {
      niz[j][N - 1 - k] = broj;
      ++broj;
    }
		// Od desno prema lijevo
    for (int j = N - 2 - k; j >= 0 + k; --j) {
      niz[N - 1 - k][j] = broj;
      ++broj;
    }
		// Od dole prema gore
    for (int j = N - 2 - k; j >= 1 + k; --j) {
      niz[j][k] = broj;
      ++broj;
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cout << niz[i][j] << "\t";
    }
    cout << endl;
  }
  return 0;
}