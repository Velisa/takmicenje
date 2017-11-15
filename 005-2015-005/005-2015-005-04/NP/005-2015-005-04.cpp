/* Copyright (c) Novak Petrovic
 * Released under GNU General Public License v3.0 */

#include <cmath>
#include <iostream>
using namespace std;

int main() {
	// Deklaracije
	const int N = 8;
	const int K = 3;
	int km, pf, broj, zarez;
	int novcanice[N] = {200, 100, 50, 20, 10, 5, 2, 1};
	float kovanice[K] = {50, 20, 10};
	string kovanice_str[K] = {"0,5", "0,2", "0,1"};
	// Unosenje iznosa
	string iznos;
	cin >> iznos;
	// Rastavljanje na cijeli i decimalni dio
	// Napomena: feninzi su opsegu od 0 do 99
	zarez = iznos.find(',');
	if (zarez == -1) {
		km = stoi(iznos.substr(0, zarez));
		pf = 0;
	}
	else {	
		km = stoi(iznos.substr(0, zarez));
		pf = stoi(iznos.substr(zarez+1, iznos.length()));
	}
	// Provjera da li je isplata moguca
	if (pf % 10 == 0) {
		cout << "Isplata: ";
		// Za ispis zareza
		bool prviPut = true;
		// Ispis novcanica
		for (int i=0; i < N; ++i) {
			broj = km / novcanice[i];
			if (broj != 0) {
				if (prviPut) {
					cout << broj << " novcanica od " << novcanice[i] << " KM";
					prviPut = false;
				}
				else {
					cout << ", " << broj << " novcanica od " << novcanice[i] << " KM";						}
			}
			km = km - broj * novcanice[i];	
		}
		// Ispis kovanica
		// Napomena: feninzi su opsegu od 0 do 99
		for (int i=0; i < K; ++i) {
			broj =  pf / kovanice[i];
			if (broj != 0) {
				if (prviPut) {
					cout << broj << " novcanica od " << kovanice_str[i] << " KM";
					prviPut = false;
				}
				else {
					cout << ", " << broj << " novcanica od " << kovanice_str[i] << " KM";
				}
			}
			pf = pf - broj * kovanice[i];
		}
	}
	else {
		cout << "Isplata nije moguca!";
	}
}
