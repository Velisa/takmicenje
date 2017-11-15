/* Copyright (c) Novak Petrovic
   Released under GNU General Public License v3.0 */

#include <iostream>
using namespace std;

int main() {
	int takmicara;
	string pogoci;
	const int pokusaja = 5;
	int x[pokusaja], y[pokusaja];
	//cin >> takmicara;
	//cin >> pogoci;
  pogoci = "(2,3),(5,7),(10,7),(5,6),(7,7)";
  int indeks = 0;
  int pogodak = 0;
  bool trazimoX = true;
  string trenutniBroj = "";
  while (indeks < pogoci.length()) {
      trenutniBroj = "";
      if (isdigit(pogoci[indeks])) {
        trenutniBroj += pogoci[indeks];
        ++indeks;
        if (isdigit(pogoci[indeks])) {
          trenutniBroj += pogoci[indeks];
          ++indeks;
        }
        if (trazimoX) {
          x[pogodak] = stoi(trenutniBroj);
          trazimoX = !trazimoX;
        }
        else {
          y[pogodak] = stoi(trenutniBroj);
          // x i y moraju imati isti indeks
          // zato ga samo ovdje povecavamo
          ++pogodak;
          trazimoX = !trazimoX;
        }
      }
      else {
        ++indeks;
      }
  }
  for (int i=0; i < pokusaja; ++i)
    cout << x[i] << "\t" << y[i] << endl;
	return 0;
}
