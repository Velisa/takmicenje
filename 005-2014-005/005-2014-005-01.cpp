/* Copyright (c) Novak Petrovic GNU General Public License v3.0 */

#include <iostream>
#include <cstdlib> // Ovo je potrebno za atoi

using namespace std;

int main (void) { 
	//
	// Linija ispod se ne moze koristiti!
	// cin >> datum
	//
	// Ovo je jedna alternativa:
	// getline(cin, datum);
	// ali onda moramo koristiti tokenizer
	//
	// Ovo je mozda najbolja opcija
	char datum[10];
	//
	string dan = "";
	string mjesec = "";
	string godina = "";
	//
	int uneseni_dan, uneseni_mjesec, unesena_godina;
	int sljedeci_dan, sljedeci_mjesec, sljedeca_godina;
	int prethodni_dan, prethodni_mjesec, prethodna_godina;
	//
	bool vazeci_datum = true;
	bool prestupna_godina = false;
	//
	// Mislim da je u nasim okolnostima ovo najbolji nacin -- VAZNO!!
	cin.getline(datum, sizeof(datum)+1);
	//
	int i = 0;
	//
	// Ovdje je vazno koristiti apostrofe! -- VAZNO!!
	while (datum[i] != ' ') {
		dan = dan + datum[i];
		i++;
	}
	i++;
	//
	// Ovdje je vazno koristiti apostrofe! -- VAZNO!!
	while (datum[i] != ' ') {
		mjesec = mjesec + datum[i];
		i++;
	}
	i++;
	for (int j = 0; j < 5; j++) {
		godina = godina + datum[i+j];
	}
	//
	// Pretvaranje stringa u integer -- VAZNO!!
	uneseni_dan = atoi(dan.c_str());
	uneseni_mjesec = atoi(mjesec.c_str());
	unesena_godina = atoi(godina.c_str());
	//
	// Prvo utvrditi da li je godina prestupna
	if (unesena_godina % 4 == 0) {
		prestupna_godina = true;
		if (unesena_godina % 100 == 0) {
			if (unesena_godina % 400 == 0) {
				prestupna_godina = true;
			}
			else {
				prestupna_godina = false;
			}
		}
	}
	//
	// Utvrdjujemo prethodni i sljedeci datum za svaki mjesec
	switch (uneseni_mjesec) {
		case 1:
		if (uneseni_dan > 31) {
				vazeci_datum = false;
			}
			else {
				sljedeci_dan = uneseni_dan + 1;
				sljedeci_mjesec = uneseni_mjesec;
				sljedeca_godina = unesena_godina;
				if (sljedeci_dan > 31) {
					sljedeci_dan = 1;
					sljedeci_mjesec = sljedeci_mjesec + 1;
					if (sljedeci_mjesec == 13) {
						sljedeci_mjesec = 1;
						sljedeca_godina = sljedeca_godina + 1;
					}
				}
				prethodni_dan = uneseni_dan - 1;
				prethodni_mjesec = uneseni_mjesec;
				prethodna_godina = unesena_godina;
				if (prethodni_dan == 0) {
					prethodni_dan = 31;
					prethodni_mjesec = prethodni_mjesec - 1;
					if (prethodni_mjesec == 0) {
						prethodni_mjesec = 12;
						prethodna_godina = prethodna_godina - 1;
					}
				}
			}
			break;
		case 5:
		case 7:
		case 10:
		case 12:
			if (uneseni_dan > 31) {
				vazeci_datum = false;
			}
			else {
				sljedeci_dan = uneseni_dan + 1;
				sljedeci_mjesec = uneseni_mjesec;
				sljedeca_godina = unesena_godina;
				if (sljedeci_dan > 31) {
					sljedeci_dan = 1;
					sljedeci_mjesec = sljedeci_mjesec + 1;
					if (sljedeci_mjesec == 13) {
						sljedeci_mjesec = 1;
						sljedeca_godina = sljedeca_godina + 1;
					}
				}
				prethodni_dan = uneseni_dan - 1;
				prethodni_mjesec = uneseni_mjesec;
				prethodna_godina = unesena_godina;
				if (prethodni_dan == 0) {
					prethodni_dan = 30;
					prethodni_mjesec = prethodni_mjesec - 1;
					if (prethodni_mjesec == 0) {
						prethodni_mjesec = 12;
						prethodna_godina = prethodna_godina - 1;
					}
				}
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (uneseni_dan > 30) {
				vazeci_datum = false;
			}
			else {
				sljedeci_dan = uneseni_dan + 1;
				sljedeci_mjesec = uneseni_mjesec;
				sljedeca_godina = unesena_godina;
				if (sljedeci_dan == 31) {
					sljedeci_dan = 1;
					sljedeci_mjesec = sljedeci_mjesec + 1;
					if (sljedeci_mjesec == 13) {
						sljedeci_mjesec = 1;
						sljedeca_godina = sljedeca_godina + 1;
					}
				}
				prethodni_dan = uneseni_dan - 1;
				prethodni_mjesec = uneseni_mjesec;
				prethodna_godina = unesena_godina;
				if (prethodni_dan == 0) {
					prethodni_dan = 31;
					prethodni_mjesec = prethodni_mjesec - 1;
					if (prethodni_mjesec == 0) {
						prethodni_mjesec = 12;
						prethodna_godina = prethodna_godina - 1;
					}
				}
			}
			break;
		case 2:
			if (!prestupna_godina & uneseni_dan > 28) {
				vazeci_datum = false;
			}
			else if (prestupna_godina & uneseni_dan > 29) {
				vazeci_datum = false;
			}
			else if (prestupna_godina) {
				sljedeci_dan = uneseni_dan + 1;
				sljedeci_mjesec = uneseni_mjesec;
				sljedeca_godina = unesena_godina;
				if (sljedeci_dan == 30) {
					sljedeci_dan = 1;
					sljedeci_mjesec = sljedeci_mjesec + 1;
				}
				prethodni_dan = uneseni_dan - 1;
				prethodni_mjesec = uneseni_mjesec;
				prethodna_godina = unesena_godina;
				if (prethodni_dan == 0) {
					prethodni_dan = 31;
					prethodni_mjesec = prethodni_mjesec - 1;
				}
			}
			else {
				sljedeci_dan = uneseni_dan + 1;
				sljedeci_mjesec = uneseni_mjesec;
				sljedeca_godina = unesena_godina;
				if (sljedeci_dan == 29) {
					sljedeci_dan = 1;
					sljedeci_mjesec = sljedeci_mjesec + 1;
				}
				prethodni_dan = uneseni_dan - 1;
				prethodni_mjesec = uneseni_mjesec;
				prethodna_godina = unesena_godina;
				if (prethodni_dan == 0) {
					prethodni_dan = 31;
					prethodni_mjesec = prethodni_mjesec - 1;
				}
			}
			break;
		case 3:
			if (uneseni_dan > 31) {
				vazeci_datum = false;
			}
			if (prestupna_godina) {
				sljedeci_dan = uneseni_dan + 1;
				sljedeci_mjesec = uneseni_mjesec;
				sljedeca_godina = unesena_godina;
				if (sljedeci_dan > 31) {
					sljedeci_dan = 1;
					sljedeci_mjesec = sljedeci_mjesec + 1;
				}
				prethodni_dan = uneseni_dan - 1;
				prethodni_mjesec = uneseni_mjesec;
				prethodna_godina = unesena_godina;
				if (prethodni_dan == 0) {
					prethodni_dan = 29;
					prethodni_mjesec = prethodni_mjesec - 1;
				}
			}
			else {
				sljedeci_dan = uneseni_dan + 1;
				sljedeci_mjesec = uneseni_mjesec;
				sljedeca_godina = unesena_godina;
				if (sljedeci_dan > 31) {
					sljedeci_dan = 1;
					sljedeci_mjesec = sljedeci_mjesec + 1;
				}
				prethodni_dan = uneseni_dan - 1;
				prethodni_mjesec = uneseni_mjesec;
				prethodna_godina = unesena_godina;
				if (prethodni_dan == 0) {
					prethodni_dan = 28;
					prethodni_mjesec = prethodni_mjesec - 1;
				}
			}
			break;
		case 8:
			if (uneseni_dan > 31) {
				vazeci_datum = false;
			}
			else {
				sljedeci_dan = uneseni_dan + 1;
				sljedeci_mjesec = uneseni_mjesec;
				sljedeca_godina = unesena_godina;
				if (sljedeci_dan > 31) {
					sljedeci_dan = 1;
					sljedeci_mjesec = sljedeci_mjesec + 1;
					if (sljedeci_mjesec == 13) {
						sljedeci_mjesec = 1;
						sljedeca_godina = sljedeca_godina + 1;
					}
				}
				prethodni_dan = uneseni_dan - 1;
				prethodni_mjesec = uneseni_mjesec;
				prethodna_godina = unesena_godina;
				if (prethodni_dan == 0) {
					prethodni_dan = 31;
					prethodni_mjesec = prethodni_mjesec - 1;
					if (prethodni_mjesec == 0) {
						prethodni_mjesec = 12;
						prethodna_godina = prethodna_godina - 1;
					}
				}
			}
			break;
		default:
			vazeci_datum = false;
	}
	//
	// Ako je datum vazeci, ispisati sve datume, ako nije onda ispisati da je datum neispravan.
	if (vazeci_datum) {
		cout << "Datum: " << uneseni_dan << ". " << uneseni_mjesec << ". " << unesena_godina << ".";
		cout << " Prethodni: " << prethodni_dan << ". " << prethodni_mjesec << ". " << prethodna_godina << ".";
		cout << " Naredni: " << sljedeci_dan << ". " << sljedeci_mjesec << ". " << sljedeca_godina << ". god.";
	}
	else {
		cout << "Datum: " << uneseni_dan << ". " << uneseni_mjesec << ". " << unesena_godina << ". neispravan.";
	}
	//
	return 0;
}