#include <iostream>

using namespace std;

int main(void) {
	int tmp;
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
	for (int i = N - 1; i >= 0; i--) {
		if (i != 0) {
			cout << "i = " << i << endl;
		}
		for (int j = 0; j <= i - 1; j++) {
			if (niz[j] > niz[j+1]) {
				tmp = niz[j+1];
				niz[j+1] = niz[j];
				niz[j] = tmp;
			}
			for (int a = 0; a < N; a++) {
				cout << niz[a] << "\t";
			}
			cout << "j = " << j << endl;
		}
		cout << endl << endl;
	}
	//
	cout << endl << "Konacni niz:" << endl;
	for (int a = 0; a < N; a++) {
		cout << niz[a] << "\t";
	}
	cout << endl;
}