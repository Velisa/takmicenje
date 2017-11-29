#include <iostream>
using namespace std;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  int niz[N][M];
  string red[N];
  for (int i = 0; i < N; ++i) {
    cin >> red[i];
    for (int j = 0; j < M; ++j) {
      if (red[i][j] == '0') {
        niz[i][j] = 0;
      } else {
        niz[i][j] = 1;
      }
    }
  }

  // Potrebo je uspostaviti petlju za K, ovo je samo za jedan pokusaj

  // Prebrojati nule u redovima
  int nule_redovi[N];
  for (int i = 0; i < N; ++i) nule_redovi[i] = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (niz[i][j] == 0) {
        ++nule_redovi[i];
      }
    }
  }
  // Prebrojati nule u kolonama sa kvalifikovanim redovima
  int nule_kolone[M];
  for (int j = 0; j < M; ++j) {
    for (int i = 0; i < N; ++i) {
      if (niz[i][j] == 0 && nule_redovi[i] <= K) {
        ++nule_kolone[j];
      }
    }
  }
  // Pronaci kolonu sa najvise nula u kvalifikovanim redovima
  int kol_max = 0;
  int indeks_kol_maks;
  for (int i = 0; i < M; ++i) {
    if (nule_kolone[i] > kol_max) {
      kol_max = nule_kolone[i];
      indeks_kol_maks = i;
    }
  }
  // Jedna "akcija" nad kolonom
  for (int i = 0; i < N; ++i) {
    if (niz[i][indeks_kol_maks] == 0) {
      niz[i][indeks_kol_maks] = 1;
    } else {
      niz[i][indeks_kol_maks] = 0;
    }
  }
  // Prebrojavanje upaljenih redova
  int redova = 0;
  bool red_upaljen;
  for (int i = 0; i < N; ++i) {
    red_upaljen = true;
    for (int j = 0; j < M; ++j) {
      if (niz[i][j] == 0) {
        red_upaljen = false;
      }
    }
    if (red_upaljen) {
      ++redova;
    }
  }
  // Ispis redova
  cout << redova;
  return 0;
}
