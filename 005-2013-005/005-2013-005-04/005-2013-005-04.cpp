/* Copyright (c) Novak Petrovic GNU General Public License v3.0 */

#include <iostream>

using namespace std;

int main (void) { 
	int N, M, k, l;
	int suma = 0;
	//cout << "Unesite broj redova, N (N <= 5): ";
	cin >> N;
	//cout << "Unesite broj kolona, M (M <= 5): ";
	cin >> M;
	int matrica[N][M];
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			//cout << "Unesite " << (n+1)*(m+1) << ". element matrice: ";
			cin >> matrica[n][m];
		}
	}
	//cout << "Unesite broj reda, k (k <= 5): ";
	cin >> k;
	//cout << "Unesite broj kolone, l (l <= 5): ";
	cin >> l;
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			// Ne sabiramo izabrani element
			if (n != (k-1) &&  m != (l-1)) {
				// Ako je element na glavnoj dijagonali
				if (k == l) {
					if (n==m) {
						suma += matrica[n][m];
					}
				}
				// Ako element nije na glavnoj dijagonali
				else {
					if ((k-1)-(l-1) == (n-m)) {
						suma += matrica[n][m];
					}	
				}
				// Ovaj uslov vazi za oba prethodna uslova
				if ((n+m) == ((k-1)+(l-1))) {
						suma += matrica[n][m];
				}
			}
		}
	}
	cout << "Zbir dijagonala je: " << suma << endl;
  return 0;
}
