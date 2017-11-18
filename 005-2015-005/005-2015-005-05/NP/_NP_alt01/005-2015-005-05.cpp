/* Copyright (c) Novak Petrovic
   Released under GNU General Public License v3.0 */

#include <cmath>
#include <string>
#include <iostream>
using namespace std;

int main() {
	bool trazimoX;
	string trenutniBroj;	
	int takmicara,indeks, pogodak;
	const int pokusaja = 5;
	cin >> takmicara;
	string pogoci[takmicara];	
	for (int i=0; i < takmicara; ++i) {
		cin >> pogoci[i];	
	}
	int x[takmicara][pokusaja], y[takmicara][pokusaja];
	for (int i=0; i < takmicara; ++i) {	
	  indeks = 0;
	  pogodak = 0;
	  trazimoX = true;
	  trenutniBroj = "";
	  while (indeks < pogoci[i].length()) {
	      trenutniBroj = "";
	      if (isdigit(pogoci[i][indeks])) {
	        trenutniBroj += pogoci[i][indeks];
	        ++indeks;
	        if (isdigit(pogoci[i][indeks])) {
	          trenutniBroj += pogoci[i][indeks];
	          ++indeks;
	        }
	        if (trazimoX) {
	          x[i][pogodak] = stoi(trenutniBroj);
	          trazimoX = !trazimoX;
	        }
	        else {
	          y[i][pogodak] = stoi(trenutniBroj);
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
	}
	int bodova;	
	float pogodjeniR;
  for (int i=0; i < takmicara; ++i) {
		bodova = 0;
		for (int j=0; j < pokusaja; ++j) {
			pogodjeniR = sqrt(pow(x[i][j], 2)+pow(y[i][j], 2));
			if (pogodjeniR <= 1.0)
				bodova += 10;
			else if (pogodjeniR > 1.0 && pogodjeniR <= 2.0)
				bodova += 9;
			else if (pogodjeniR > 2.0 && pogodjeniR <= 3.0)
				bodova += 8;
			else if (pogodjeniR > 3.0 && pogodjeniR <= 4.0)
				bodova += 7;
			else if (pogodjeniR > 4.0 && pogodjeniR <= 5.0)
				bodova += 6;
			else if (pogodjeniR > 5.0 && pogodjeniR <= 6.0)
				bodova += 5;
			else if (pogodjeniR > 6.0 && pogodjeniR <= 7.0)
				bodova += 4;
			else if (pogodjeniR > 7.0 && pogodjeniR <= 8.0)
				bodova += 3;
			else if (pogodjeniR > 8.0 && pogodjeniR <= 9.0)
				bodova += 2;
			else if (pogodjeniR > 9.0 && pogodjeniR <= 10.0)
				bodova += 1;
		}
		cout << i+1 << ". takmicar " << bodova << " bodova" << endl;
	}
	return 0;
}
