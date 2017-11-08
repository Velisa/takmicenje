/* Copyright (c) Novak Petrovic
 * Released under GNU General Public License v3.0 */

#include <iostream>
using namespace std;

int main() {
	int N, crta;
	string rezultat = "";
	string grad, pocetak, kraj, sljedeci;
	
	cin >> N;
	cin >> grad;
	string karte[N];
	for (int i=0; i < N; ++i)
		cin >> karte[i];
	rezultat += grad;
	sljedeci = grad;
	while (true) {
		for (int i=0; i < N; ++i) {
			crta = karte[i].find('-');
			pocetak = karte[i].substr(0,crta) << endl;
			kraj = karte[i].substr(crta+1, karte[i].length()) << endl;
			
		}
	}

	return 0;
}
