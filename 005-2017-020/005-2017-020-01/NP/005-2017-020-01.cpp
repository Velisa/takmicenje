/* Copyright (c) Novak Petrovic
 * Released under GNU General Public License v3.0
 */
#include <iostream>
using namespace std;

int main() {
  int N;
  long temp;
  cin >> N;
  long niz[N];
  long suma = 0;
  // Unos niza i racunanje prve sume
  for (int i = 0; i < N; ++i) {
    cin >> niz[i];
    suma += niz[i];
  }
  // Sortiranje niza od najmanjeg do najveceg elementa
  bool sredjen = false;
  while (!sredjen) {
    sredjen = true;
    for (int i = 0; i < N - 1; ++i) {
      if (niz[i] > niz[i + 1]) {
        sredjen = false;
        temp = niz[i];
        niz[i] = niz[i + 1];
        niz[i + 1] = temp;
      }
    }
  }
  // Sve dok ima smisla odbacivati elemente
  int odbaceno = 0;
  while (odbaceno < N) {
    // Provjeravamo da li je suma parna
    if (suma % 2 == 0) {
      break;
    }
    // Posto suma nije parna,
    // odbacujemo sljedeci neparni clan, pocevsi od najmanjeg
    for (int i = 0; i < N; ++i) {
      if (niz[i] != 0 && niz[i] % 2 != 0) {
        niz[i] = 0;
        ++odbaceno;
        break;
      }
    }
    // Racunamo novu sumu
    suma = 0;
    for (int i = 0; i < N; ++i) suma += niz[i];
  }
  if (odbaceno < N) {
    cout << suma;
  } else {
    cout << "Nema rjesenja!";
  }
}