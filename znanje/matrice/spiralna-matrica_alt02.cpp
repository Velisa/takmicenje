/* http://github.com/novakpetrovic/takmicenje

Spiralno ispisvanje NxN matrice u smjeru kazaljke na satu.
Na primjer, za N = 4 imamo:
1		2		3		4
12	13	14	5
11	16	15	6
10	9		8		7

 */
#include <iostream>
using namespace std;

int main() {
  int N;
	cin >> N;
	int niz[N * N] = {0};
	// Definicija koraka
	int lijevo = -1;
	int desno = 1;
	int dole = N;
	int gore = -N;
	// Pocetna pozicija i pravac
	int pos = 0;
	// Pravac mora biti "jedan prije" zeljenog pravca
	int dir = gore;
	for (int i = 0; i < N * N; ++i) {
		// Upis elementa
    niz[pos] = i + 1;
		// Provjera da li treba promijeniti pravac
    if (	// Da li smo u gornjem lijevom uglu
					pos == 0 || 
					// Gornji desni ugao
					pos == N - 1 ||
					// Donji lijevi ugao
					pos == N*(N - 1) ||
					// Donji desni ugao
					pos == N*N - 1 ||
					// Sljedeci element vec popunjen
					niz[pos + dir] != 0
				) {
					// Promjena pravca
					if (dir == lijevo) dir = gore;
					else if (dir == gore) dir = desno;
					else if (dir == desno) dir = dole;
					else if (dir == dole) dir = lijevo;
		}
    // Sljedeca pozicija
		pos += dir;
	}
	// Ispis
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << niz[j + i * N] << "\t";
		}
		cout << endl;
	}
  return 0;
}
