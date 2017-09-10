/* Copyright (c) Novak Petrovic GNU General Public License v3.0 */

#include <iostream>
#include <cstdlib>
#include <stdio.h>

using namespace std;

int main(void) {
	int r, k;
	scanf("%d,%d", &r, &k);
	int nur[r];
	int matrica[r][k];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < k; j++) {
			cin >> matrica[i][j];
		}
	}
	for (int i = 0; i < r; i++) {
		nur[i] = matrica[i][0];
		for (int j = 0; j < k; j++) {
			if (matrica[i][j] < nur[i]) {
				nur[i] = matrica[i][j];
			}
		}
	}
	//
	int najveci = nur[0];
	for (int i = 1; i < r; i++) {
		if (nur[i] > najveci) {
			najveci = nur[i];
		}
	}
	cout << "Trazeni broj je: " << najveci << "." << endl;
	//
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < k; j++) {
			if (matrica[i][j] == najveci) {
				cout << "Nalazi se u " << (i+1) << ". redu i " << (j+1) << ". koloni. " << endl;
			}
		}
	}	
}