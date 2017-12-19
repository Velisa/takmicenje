#include <iostream>
using namespace std;

int dodajSljedeci(int trenutni_grad) {
	
}

int main() {
/*
	int n, m, k, glavni_grad;
	cin >> n >> m >> k;
	int minute[n][n];
	int specijalni_gradovi[k];
	for (int i = 0; i < k; ++i) {
		cin >> specijalni_gradovi[i];
		--specijalni_gradovi[i];
	}
	cin >> glavni_grad;
	--glavni_grad;
	int x, y, t;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y >> t;
		minute[x-1][y-1] = t;
		minute[y-1][x-1] = t;
	}
	int vrijeme;
	string putanja;
	bool stigao = false;
*/
	string putanja;
	for (int i = 0; i < 24; ++i) {
		putanja = "0";
		for (int i0 = 1; i0 < 4; ++i0) {
			for (int i1 = 2; i1 < 4; ++i1) {
				for (int i2 = 3; i2 < 4; ++i2) {
					putanja += to_string(i0) + to_string(i1) + to_string(i2);
					cout << putanja << endl; 
				}
			}
		}
		
	}
	return 0;
}