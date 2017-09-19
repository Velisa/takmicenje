// Copyright (c) Novak Petrovic
// GNU General Public License v3.0
//
// Rjesenje 5. zadatka
// Regionalno takmicenje iz informatike, Republika Srpska, 2017.
//
// Za koristenje % za velike brojeve korisno je vidjeti
// http://www.geeksforgeeks.org/modulo-1097-1000000007/
//
// Koristimo:
// ( a + b) % c = ( ( a % c ) + ( b % c ) ) % c
// ( a * b) % c = ( ( a % c ) * ( b % c ) ) % c
// ( a - b) % c = ( ( a % c ) - ( b % c ) ) % c
//
// ali ne i:
// ( a / b ) % c != ( ( a % c ) / ( b % c ) ) % c

#include <math.h>
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
using namespace std;

// Generise niz binarnih brojeva (stringova) sa odredjenim brojem bitova n
// Binarni brojevi se koriste za predstavljanje mogucih kombinacija
// samoglasnik-suglasnik
// TODO: Promijeniti funkciju tako da ne koristi vektore
// (jer znamo koliko elementa ce biti za svaki broj bitova n)
vector<string> getBitStrings(unsigned int n) {
  vector<string> result;
  if (n <= 1) {
    result.push_back("0");
    result.push_back("1");
  }
  else {
    vector<string> sub = getBitStrings(n-1);
    for (vector<string>::const_iterator it = sub.cbegin();
      it != sub.cend(); ++it) {
	result.push_back(*it+'0');
        result.push_back(*it+'1');
      }
  }
  return result;
}

// Provjerava da li je karakter upitnik
bool jeUpitnik(char c) {
  return c=='?';	
}

// Provjerava da li je karakter samoglasnik
// Pazi:
//	* '0' se koristi za predstavljanje bilo kog samoglasnika
//	* '1' se koristi za predstavljanje bilo kog suglasnika
// (Zato se kompletna moguca kombinacija samoglasnika i suglasnika
// moze predstaviti kao binarni broj sa odredjenim brojem bitova)
bool jeSamoglasnik(char c) {
  return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='0';
}

// Da li izabrana kombinacija samoglasnika i suglasnika zadovoljava zadati uslov
bool zadovoljava(char *rijec, int n, int k) {
  int sagl=0;
  int sugl=0;
  for (int i=0; i<n; ++i) {
    if (jeSamoglasnik(rijec[i]))
      ++sagl;
    else
      ++sugl;
    }
  return abs(sagl-sugl)<=k;
}

int main() {
  // n i k su kao sto je zadato u zadatku
  int n,k;
  // Broj upitnika u zadatoj rijeci
  int upit=0; 
  // TODO: Treba provjeriti da li je stvarno potrebno da svi budu
  // deklarisani kao unsigned long int
  unsigned long int ukupno = 0;
  unsigned long int kombinacije;
  const unsigned long int djelilac = 1000000007;
  cin >> n >> k;
  // Rijec je rijec unesena na pocetku
  char *rijec = new char[n+1];
  cin >> rijec;
  // Prebrojavanje upitnika u unesenoj rijeci
  for (int i=0; i<n; ++i) {
    if (jeUpitnik(rijec[i]))
      ++upit;
  }
  // Na osnovu broja upitnika (bitova) generise se niz binarnih brojeva
  // koji predstavljaju sve moguce kombinacije samoglasnika i suglasnika
  // u zadatoj rijeci
  // Na primjer, ako imamo dva bita: 
  // binarni = {"00","01","10","11"}
  // A ako imamo tri bita:
  // binarni = {"000","001","010","011","100","101","110","111"}
  vector<string> binarni = getBitStrings(upit);
  int m;
  // Pomocna rijec sa odredjenim predlozenim rasporedom
  // samoglasnika i suglasnika. Kombinacija samoglasnika
  // i suglasnika se predstavlja odredjenim binarnim brojem
  char *pomocna = new char[n+1];  
  for (int i=0; i<pow(2,upit); ++i) {
    // m je brojac da znam dokle sam dosao u binarnom broju
    m = 0;
    // Generisemo pomocnu rijec tako sto kopiramo nule i jedinice na mjestima
    // gdje su upitnici. Prolazimo kroz sve moguce binarne brojeve sa zadatim
    for (int j=0; j<n; ++j) {
      if (jeUpitnik(rijec[j])) {
        pomocna[j]=binarni[i][m];
        ++m;
      }
      else {
        pomocna[j]=rijec[j];		
      }
    }	
    pomocna[n]='\0';
    // Provjeravamo da li predlozena kombinacija samoglasnika i suglasnika
    // zadovoljava jednacinu za k
    if (zadovoljava(pomocna,n,k)) {
      // Broj mogucih kombinacija slova za rijec koja zadovoljava uslov      
      kombinacije = 1;
      // Ovdje prolazimo kroz sva slova u rijeci koja zadovoljava uslov
      for (int i=0; i<n; ++i)
        // Ako je slovo samoglasnik (genericko 0) imamo 5 mogucih opcija
        // samoglasnika
        if (pomocna[i]=='0')
          kombinacije=((kombinacije%djelilac)*5)%djelilac;
        // Ako je slovo suglasnik (genericko 1) imamo 21 mogucu opciju
        // suglasnika
        else if (pomocna[i]=='1')
          kombinacije=((kombinacije%djelilac)*21)%djelilac;
        // Sabiremo kombinacije koje smo gore izracunali
        ukupno=((ukupno%djelilac)+(kombinacije%djelilac))%djelilac;
		    // TODO: Provjeriti da li je ovo najbolji nacin da se konacan rezultat
        // prikaze kao % djelilac (ovo radi ispravno)
        //if (ukupno > djelilac) ukupno = ukupno % djelilac;
    }
  }
  // Ispisi broj mogucih kombinacija (konacan odgovor)
  cout << ukupno << endl;
}
