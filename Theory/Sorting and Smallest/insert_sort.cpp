#include <iostream>

using namespace std;

int main(void) {
	int j, tmp;
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
	for (int i = 1; i < N; i++) {
		tmp = niz[i];
		for (j = i; j > 0; j--) {
			if (niz[j-1] < tmp) {
				break;
			}
			niz[j] = niz[j-1];
		}
		niz[j] = tmp;
		//
		for (int a = 0; a < N; a++) {
			cout << niz[a] << "\t";
		}
		cout << "\t" << "i = " << i << endl;
	}
	//
	cout << endl << "Konacni niz:" << endl;
	for (int a = 0; a < N; a++) {
		cout << niz[a] << "\t";
	}
	cout << endl;
}