#include <iostream>
#include <cctype>
#include <cstdio>
#include <cstring>

using namespace std;

/* Program ce se sastojati od najvise 200 malih i velikih slova engleske abecede, osim slova X. 
Slovom X oznacavamo NOP tako da bi i NOP bio jedan element u char nizu. Malo slovo x koristimo
da oznacimo neiskoristena mjesta u ulazu / izlazu. */
#define MAX 200

char ulaz[MAX];
int NOP;

void brojNOP() {
	int N = strlen (ulaz);
	/* Ovo je samo ukupan broj NOP elemenata */
	int NOP = 0;
	for (int i = 0; i < N; ++i) {
		if (!isupper(ulaz[i])) 
			continue;
		while ((i+NOP) %4 != 0) 
			++NOP;
	}
	// printf ("\nBroj potrebnih dodatnih NOP naredbi je: %d\n", NOP);
  cout << NOP << endl;
}
	
// Ovo je opcionalno

void novi_program() {
	char izlaz[MAX + NOP]; /* Izlaz mora da sadrzi extra NOP karaktere */
	for (int i = 0; i < MAX + NOP; ++i)
		izlaz[i] = 'x';
	int nop = 0; /* Paralelni indeks za izlaz */
	int malih = 0; /* Broj malih slova (argumenata) u komandi */
	int N = strlen (ulaz);
	izlaz[0] = ulaz[0]; /* Prvo slovo ce uvijek biti komanda */
	for (int i = 1; i < N; ++i) {
		if (islower(ulaz[i])) { /* Ako je malo slovo */
			++malih;
			izlaz[i+nop] = ulaz[i];
		}
		else {
			if ((malih + 1) % 4 == 0) {
				nop += 0;
			}
			if ((malih + 2) % 4 == 0) {
				izlaz[i+nop] = 'X';
				nop += 1;
			}
			if ((malih + 3) % 4 == 0) {
				izlaz[i+nop] = 'X';
				izlaz[i+nop+1] = 'X';
				nop += 2;
			}
			if ((malih + 4) % 4 == 0) {
				izlaz[i+nop] = 'X';
				izlaz[i+nop+1] = 'X';
				izlaz[i+nop+2] = 'X';
				nop += 3;
			}
			izlaz[i+nop] = ulaz[i];
			malih = 0;
		}
	}
	printf ("\nNovi program je: ");
	for (int i = 0; i < MAX + NOP; ++i)
		if (izlaz[i] != 'x')
			printf ("%c", izlaz[i]);
	printf ("\n");
}

int main(void) {
	for (int i = 0; i < MAX; ++i)
		ulaz[i] == 'x';
	//printf("\nUnesite program: ");
	//scanf("%s", ulaz);
  cin >> ulaz;
	brojNOP();
	// novi_program();
	return 0;
}