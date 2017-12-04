/* http://github.com/novakpetrovic/takmicenje

Spiralno ispisvanje NxM matrice u smjeru kazaljke na satu.
Na primjer, za N = 4, M = 5 imamo:
1		2		3		4		5
14	15	16	17	6
13	20	19	18	7
12	11	10	9		8

 */
#include <iostream>
using namespace std;

int main() {
	// N redova
	// M kolona
  int N, M;
	cin >> N;
	cin >> M;
	// Niz mora biti inicijalizovan na 0
	int niz[N * M] = {0};
	// Definicija koraka
	int lijevo = -1;
	int desno = 1;
	int dole = M;
	int gore = -M;
	// Pocetna pozicija i pravac
	int pos = 0;
	// Pravac mora biti "jedan prije" zeljenog pravca
	int dir = gore;
	for (int i = 0; i < N * M; ++i) {
		// Upis elementa
    niz[pos] = i + 1;
		// Provjera da li treba promijeniti pravac
    if (	// Da li smo u gornjem lijevom uglu?
					pos == 0 || 
					// Da li smo u gornjem desnom uglu?
					pos == M - 1 ||
					// Da li smo u donjem lijevom uglu?
					pos == M*(N - 1) ||
					// Da li smo u donjem desnom uglu?
					pos == N*M - 1 ||
					// Da li je sljedeci element vec popunjen?
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
		for (int j = 0; j < M; ++j) {
			cout << niz[j + i * M] << "\t";
		}
		cout << endl;
	}
  return 0;
}