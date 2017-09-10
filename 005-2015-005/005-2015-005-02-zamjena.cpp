/* Copyright (c) Novak Petrovic GNU General Public License v3.0 */

#include <iostream>
#include <cstdlib>

using namespace std;

int main(void) {
	int N = 1000;
	char recenica[N];
	string rijeci[N];
	string trazena_rijec;
	string rijec_za_zamjenu;
	//
	for (int i = 0; i < N; i++) {
		recenica[i] = '^';
	}
	//
	for (int i = 0; i < N; i++) {
		rijeci[i] = "***";
	}
	//
	cin.getline(recenica, N+1);
	//
	getline(cin, trazena_rijec);
	getline(cin, rijec_za_zamjenu);
	//
	int j = 0;
	int k = 0;
	string trenutna_rijec = "";
	while (recenica[j] != '^') {
		if (recenica[j] == ' ' || recenica[j] == '\0') {
			rijeci[k] = trenutna_rijec;
			trenutna_rijec = "";
			k++;
		}
		else {
			trenutna_rijec = trenutna_rijec + recenica[j];
		}
		j++;
	}
	//
	for (int i = 0; i < k; i++) {
		if (rijeci[i] != trazena_rijec) {
			cout << rijeci[i] << " ";
		}
		else {
			cout << rijec_za_zamjenu << " ";
		}
	}
	cout << endl;
}