/* Copyright (c) Novak Petrovic
 * GNU General Public License v3.0
 */
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  int N;             // Broj klijenata
  int K;             // Broj kablova
  int broj_kablova;  // Koliko cijelih kablova mozemo napraviti
  bool nadjeno = false;
  float duzina;         // U ovoj promjenjljivoj je odgovori
  float kablovi[5000];  // Ovo je niz duzina kablovai
  float ukupnaDuzina = 0.0;
  cin >> N >> K;
  for (int i = 0; i < K; ++i) {
    cin >> kablovi[i];
    ukupnaDuzina += kablovi[i];
  }
  duzina = ukupnaDuzina / K;  // Maksimalna moguca duzina
  // Ideja je da se krene od maksimalne moguce duzine
  // pojedinacnog kabla i taj broj smanjuje sve dok se
  // ne dobije odgovarajuci broj potrebnih kablova
  while (!nadjeno) {
    broj_kablova = 0;
    for (int i = 0; i < K; ++i) {
      broj_kablova += (int)floor(kablovi[i] / duzina);
    }
    if (broj_kablova == N) {
      nadjeno = true;
    } else {
      /* Veca preciznost je potrebna za neke primjere */
      duzina -= 0.001;
    }
  }
  cout << fixed << setprecision(2) << duzina;
  return EXIT_SUCCESS;
}
