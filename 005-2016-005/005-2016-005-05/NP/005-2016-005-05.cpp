/* Copyright (c) Novak Petrovic
 * GNU General Public License v3.0
 */
#include <iostream>
using namespace std;

int main() {
  int N, A, B;
  cin >> N;
  int niz[N];
  cin >> A;
  cin >> B;
  for (int i = 0; i < N; ++i) {
    cin >> niz[i];
  }
  int najveci;
  int najmanji;
  bool nadjen = false;
  for (int i = 0; i < N; ++i) {
    if (niz[i] > A && niz[i] < B) {
      najmanji = niz[i];
      najveci = niz[i];
      nadjen = true;
    }
  }
  if (nadjen) {
    for (int i = 1; i < N; ++i) {
      if (niz[i] > A && niz[i] < B && niz[i] < najmanji) {
        najmanji = niz[i];
      }
      if (niz[i] > A && niz[i] < B && niz[i] > najveci) {
        najveci = niz[i];
      }
    }
    cout << "Najmanji element: " << najmanji << endl;
    cout << "Najveci element: " << najveci;
  } else {
    cout << "Najmanji element: Ne postoji!" << endl;
    cout << "Najveci element: Ne postoji!";
  }
  return EXIT_SUCCESS;
}
