/* Copyright (c) Novak Petrovic
 * GNU General Public License v3.0
 */
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int niz[n];
  for (int i = 0; i < n; ++i) cin >> niz[i];
  // Kontrolni broj
  int kb = niz[0];
  // Ispisujemo sve brojeve MANJE od kontrolnog broja
  for (int i = 1; i < n; ++i)
    if (niz[i] <= kb) cout << niz[i] << ' ';
  // Zatim ispisujemo kontrolni broj
  cout << kb << ' ';
  // Ispisujemo sve brojeve VECE od kontrolnog broja
  for (int i = 1; i < n; ++i)
    if (niz[i] > kb) cout << niz[i] << ' ';
  return EXIT_SUCCESS;
}
