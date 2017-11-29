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
  if (N == 1 && M == 1 && niz[0][0] == 1) {
    cout << 1;
    return 0;
  }
  bool red_upaljen;
  int redova;
  int kol_maks;
  int nule_redovi[N];
  int nule_kolone[M];
  int indeks_kol_maks;
  // Prebrojati nule u redovima
  for (int kk = 0; kk < K; ++kk) {
    for (int i = 0; i < N; ++i) {
      nule_redovi[i] = 0;
    }
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (niz[i][j] == 0) {
          ++nule_redovi[i];
        }
      }
    }
    // Prebrojati nule u kolonama sa kvalifikovanim redovima
    for (int i = 0; i < M; ++i) {
      nule_kolone[i] = 0;
    }
    for (int j = 0; j < M; ++j) {
      for (int i = 0; i < N; ++i) {
        // Ovdje je vazno smanjiti broj poteza
        if (niz[i][j] == 0 && nule_redovi[i] <= K - kk) {
          ++nule_kolone[j];
        }
      }
    }
    // Pronaci kolonu sa najvise nula u kvalifikovanim redovima
    kol_maks = 0;
    for (int j = 0; j < M; ++j) {
      if (nule_kolone[j] >= kol_maks) {
        kol_maks = nule_kolone[j];
        indeks_kol_maks = j;
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
    redova = 0;
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
  }
  // Ispis redova
  cout << redova;
  /*
        // Ispis niza (za testiranje)
        for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cout << niz[i][j] << " ";
    }
    cout << endl;
  }
        */
  return 0;
}
