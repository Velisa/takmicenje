#include <iostream>

using namespace std;

int main(void) {
	int i, j, tmp, min;
	int niz[] = {38, 27, 43, 3, 9, 82, 10};
	int N = sizeof(niz)/sizeof(niz[0]);
	//
	cout << endl << "Pocetni niz:" << endl;
	for (int a = 0; a < N; a++) {
		cout << niz[a] << "\t";
	}
	cout << endl << endl;
	cout << "Niz tokom sortiranja:" << endl;
	//
	for (i = 0; i < N - 1; i++) {
		min = i;
		for (j = i + 1; j < N; j++) {
			if (niz[j] < niz[min]) {
				min = j;
			}
		}
		//
		for (int a = 0; a < N; a++) {
			cout << niz[a] << "\t";
		}
		cout << "\t" << "i = " << i << endl;
		//
		tmp = niz[i];
		niz[i] = niz[min];
		niz[min] = tmp;
	}
	//
	cout << endl << "Konacni niz:" << endl;
	for (int a = 0; a < N; a++) {
		cout << niz[a] << "\t";
	}
	cout << endl;
}