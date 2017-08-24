#include <iostream>

using namespace std;

int main() {
	//
	// Zadatak ne precizira koliko ce biti znakova uneseno sa tastature,
	// mi pretpostavljamo da uneseni tekst nece biti duzi od 1000 znakova.
	int N = 1000;
	char tekst[N];
	//
	// i je pomocna varijabla
	int i;
	//
	// Ovo su deklaracije brojaca
	int brojSamoglasnika = 0;
	int brojSuglasnika = 0;
	int brojPraznina = 0;
	//
	// Zadatak ne zahtijeva brojanje ostalih znakova, 
	// ali mi cemo dodati i tu opciju 
	int brojOstalih = 0;
	//
	// Unosimo tekst
	cout << "Unesite tekst: ";
	cin.getline(tekst, sizeof(tekst));
	//
	// Prolazimo kroz sve znakove teksta i odredjujemo kojoj grupi pripadaju
	// Znamo da zvjezdica oznacava kraj teksta tako da idemo kroz tekst sve dok ne dodjemo do *
	i = 0;
	while (tekst[i] != '*') {
		switch (tekst[i]) {
			//			
			// Provjera za prazninu
			case ' ':
				brojPraznina++;
				break;			
			//
			// Uzeli smo da su sva slova engleskog alfabeta validna
			// Prvo brojimo samoglasnike
			case 'a': case 'A': case 'e': case 'E': case 'i': case 'I': case 'o': case 'O': case 'u': case 'U':
				brojSamoglasnika++;
				break;
			//
			// Zatim brojimo suglasnike
			case 'b': case 'B':
			case 'c': case 'C':
			case 'd': case 'D':
			case 'f': case 'F':
			case 'g': case 'G':
			case 'h': case 'H':
			case 'j': case 'J':
			case 'k': case 'K':
			case 'l': case 'L':
			case 'm': case 'M':
			case 'n': case 'N':
			case 'p': case 'P':
			case 'q': case 'Q':
			case 'r': case 'R':
			case 's': case 'S':
			case 't': case 'T':
			case 'v': case 'V':
			case 'w': case 'W':
			case 'x': case 'X':
			case 'y': case 'Y':
			case 'z': case 'Z':
				brojSuglasnika++;
				break;
			//
			// Na kraju brojimo sve sto nije niti slovo niti praznina
			default:
				brojOstalih++;
		}
		i++;
	}
	//
	// Ispis rezultata
	cout << "Broj samoglasnika je: " << brojSamoglasnika << "\n";
	cout << "Broj suglasnika je: " << brojSuglasnika << "\n";
	cout << "Broj praznina je: " << brojPraznina << "\n";
	//cout << "Broj ostalih znakova je: " << brojOstalih << "\n";
	//
	// Izlaz bez greske
	return 0;
}