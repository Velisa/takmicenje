#include <iostream>

using namespace std;

int main(void) {
	int min, indeks;
	int niz[] = {38, 27, 43, 3, 9, 82, 10};
	int N = sizeof(niz)/sizeof(niz[0]);
	//
	cout << endl << "Zadati niz:" << endl;
	for (int a = 0; a < N; a++) {
		cout << niz[a] << "\t";
	}
	//
	min = niz[0];
	indeks = 0;
	for (int i = 1; i < N; i++) {
		if (niz[i] < min) {
			min = niz[i];
			indeks = i;
		}
	}
	//
	cout << endl << endl;
	cout << "Najmanji element: \t\t" << min << endl;
	cout << "Indeks najmanjeg elementa: \t" << indeks << endl;
}