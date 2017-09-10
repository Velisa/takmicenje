/* Copyright (c) Novak Petrovic GNU General Public License v3.0 */

#include <iostream>

using namespace std;

int main (void) { 
	int N, MAX;
	cin >> N;
	int A[N], B[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		MAX = A[0];
		for (int j = 0; j <= i; j++) {
			if (A[j] >= MAX) {
				MAX = A[j];
				B[i] = MAX;
			}
		}
	}
	cout << "Pocetni niz je: " << A[0];
	for (int i = 1; i < N; i++) {
		cout << "," << A[i];
	}
	cout << endl;
	cout <<  "Novi niz je: " << B[0];
	for (int i = 1; i < N; i++) {
		cout << "," << B[i];
	}
	return 0;
}