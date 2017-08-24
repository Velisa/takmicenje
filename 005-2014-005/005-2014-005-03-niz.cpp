#include <iostream>

using namespace std;

int main (void) { 
	int N;
	int indeks_prosti = 0;
	int indeks_slozeni = 0;
	cin >> N;
	int niz[N], prosti_niz[N], slozeni_niz[N];
	for (int i = 0; i < N; i++) {
		cin >> niz[i];
	}
	bool prosti;
	for (int i = 0; i < N; i++) {
		prosti = true;
		for (int j = 2; j < niz[i]; j++) {
			if (niz[i] % j == 0) {
				prosti = false;
			}
		}
		if (prosti) {
			prosti_niz[indeks_prosti] = niz[i];
			indeks_prosti++;
		}
		else {
			slozeni_niz[indeks_slozeni] = niz[i];
			indeks_slozeni++;
		}
	}
	for (int i = 0; i < indeks_prosti; i++) {
		cout << prosti_niz[i] << endl;
	}
	for (int i = 0; i < indeks_slozeni; i++) {
		cout << slozeni_niz[i] << endl;
	}
  return 0;
}
