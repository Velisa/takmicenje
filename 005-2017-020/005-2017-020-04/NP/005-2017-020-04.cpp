#include <iostream>
using namespace std;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  int niz[N][M];
  string red[N];
  // Postoji test slucaj kada su unesene sve jedinice
  bool sve_jedinice = true;
  for (int i = 0; i < N; ++i) {
    cin >> red[i];
    for (int j = 0; j < M; ++j) {
      if (red[i][j] == '0') {
        niz[i][j] = 0;
        sve_jedinice = false;
      } else {
        niz[i][j] = 1;
      }
    }
  }
  if (sve_jedinice) {
    cout << N;
    return 0;
  }
  bool red_upaljen;
  int upaljenih_redova;
  int nula_u_redovima[N];
  int nula_u_kolonama[M];
  int maks_nula_u_kolonama;
  int indeks_kolone_sa_maks_nula;
  // Moramo iskoristiti sve poteze
  for (int potez = 0; potez < K; ++potez) {
    // Prebrojati nule u redovima
    for (int i = 0; i < N; ++i) {
      nula_u_redovima[i] = 0;
    }
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (niz[i][j] == 0) {
          ++nula_u_redovima[i];
        }
      }
    }
    // Prebrojati nule u kolonama ali samo u redovima gdje je
    // broj nula manji ili jednak preostalom broju poteza
    for (int i = 0; i < M; ++i) {
      nula_u_kolonama[i] = 0;
    }
    for (int j = 0; j < M; ++j) {
      for (int i = 0; i < N; ++i) {
        // Ovdje je vazno smanjiti broj poteza: K - potez
        if (niz[i][j] == 0 && nula_u_redovima[i] <= K - potez) {
          ++nula_u_kolonama[j];
        }
      }
    }
    // Pronaci kolonu sa najvise nula u redovima gdje je
    // broj nula manji ili jednak preostalom broju poteza
    maks_nula_u_kolonama = 0;
    indeks_kolone_sa_maks_nula = 0;
    for (int j = 0; j < M; ++j) {
      if (nula_u_kolonama[j] > maks_nula_u_kolonama) {
        maks_nula_u_kolonama = nula_u_kolonama[j];
        indeks_kolone_sa_maks_nula = j;
      }
    }
    // Izvrsiti "akciju" nad kolonom sa najvise nula
    for (int i = 0; i < N; ++i) {
      if (niz[i][indeks_kolone_sa_maks_nula] == 0) {
        niz[i][indeks_kolone_sa_maks_nula] = 1;
      } else {
        niz[i][indeks_kolone_sa_maks_nula] = 0;
      }
    }
    // Prebrojati upaljene redove
    upaljenih_redova = 0;
    for (int i = 0; i < N; ++i) {
      red_upaljen = true;
      for (int j = 0; j < M; ++j) {
        if (niz[i][j] == 0) {
          red_upaljen = false;
        }
      }
      if (red_upaljen) {
        ++upaljenih_redova;
      }
    }
  }
  // Ispisati broj upaljenih redova
  cout << upaljenih_redova;
  return 0;
}