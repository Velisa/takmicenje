#include <iostream>
#include <math.h>

#define BROJ_SAMOGLASNIKA 5
#define BROJ_SUGLASNIKA 21
#define DJELILAC 1000000007

typedef unsigned int uint;

bool je_samoglasnik(const char& c){
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool su_svi_true(bool* niz, const int& n){
  for(uint i = 0; i < n; i++){
    if(!niz[i]) return false;
  }
  return true;
}

uint prebroj_true(bool* niz, const int& n){
  uint brojac = 0;
  for(uint i = 0; i < n; i++){
    if(niz[i]) brojac++;
  }
  return brojac;
}

/*
  Nizom boolean vrijednosti smo predstavili binarni broj. Nas cilj je da prodjemo kroz sve moguce kombinacije. To mozemo uraditi
  jednostavnim brojanjem u binarnom. Povecavanjem binarnog broja za 1 sve dok svi clanovi niza ne budu 1 osigurava da cemo proci
  kroz sve moguce kombinacije 1 i 0 u datom nizu(Pokusajte sami). Povecavamo broj tako sto pronadjemo 0 koja je najdalje u
  desno, promjenimo je u 1, sve vrijednosni desno od nje pretvorimo iz 1 u 0. To se najjednostavnije radi na sledeci nacin.
*/
void povecaj_za_1(bool* niz,const int& n){
  for(int i = n-1; i >= 0; i--){//Krecemo od zada
    if(niz[i]){
      niz[i] = false;//Sve true pretvaramo u false
    }else{
      niz[i] = true;//Cim naidjemo na false, pretvorimo ga u true i izadjemo iz funkcije
      return;
    }
  }
}

/*
  Zbog nepreciznosti funkcije pow(double, double), koristimo nasu sopstvenu funkciju za stepenovanje. Ona jednostavno
  pomnozi bazu(n1) samu sa sobom n1(stepen) puta, sto je u sustini za cijele stepene definicija stepenovanja.
*/
unsigned long long box_pow(uint n1, uint n2){
  unsigned long long rezultat = 1;
  for(uint i = 0; i < n2; i++){
    rezultat *= n1;
    rezultat = rezultat % DJELILAC;
    /*
      Matematicki je dokazano da je (a*b)%c=((a%b)*(b%c))%c. Kako nam ne bi doslo do overflowa* mi odma moduliramo sa 10^9 + 7
      kao sto je navedeno u zadatku.
    */
  }
  return rezultat;
}
/*
  *overflow
    Predpostavimo da koristimo "unsigned int" za neku varijablu. Nas kompajler treba da odvoji odredjen dio RAM-a kako bi
    mogao da sacuva nasu varijablu. U slucaju sa "unsignedint", kompajler odvaja 4 bajta memorije(Taj broj mozete dobiti funkcijom
    sizeof(tip)). 4 bajta = 32 bit-a. Tako da unsigned int moze da cuva vrijednosti izmedju 0 i 2^32. Kada su nam, kao na primjer
    u ovom zadatku, koristimo brojeve vece ili jednake 2^32, brojac u racunaru se vrati na pocetak(tako da je u "unsigned int" 
    2^32 = 0)  
  */

int main(){
  int n, k;
  std::cout << "Unesite n i k > ";
  std::cin >> n >> k;
  std::cin.ignore();
  char *rjec = new char[n + 1];
  std::cout << "Unesite rijec > ";
  std::cin.getline(rjec, n + 1);
  //Prebroj upitnike, samoglasnike i suglasnike
  uint upit = 0, samo = 0, sugl = 0;
  for(uint i = 0; i < n; i++){
    if(rjec[i] == '?'){
      upit++;
    }else if(je_samoglasnik(rjec[i])){
      samo++;
    }else{
      sugl++;
    }
  }
  //Prodji kroz sve varijacije
  bool * kombinacije = new bool[upit];
  /*
    U ovom slucaju moramo da provjerimo sve moguce kombinacije samoglasnik-suglasnik u nizu duzine "upit". Ovu informaciju
    mozemo predstaviti binarno (0-suglasnik, 1-samoglasnik).
  */
  for(uint i = 0; i < upit; i++){
    kombinacije[i] = false;
  }
  unsigned long long rezultat = 0;
  while(true){
    int uSamo = prebroj_true(kombinacije, upit);
    int uSug = upit - uSamo;
    if(abs((int)(uSamo + samo) - (int)(sugl + uSug)) <= k){
      rezultat += box_pow(BROJ_SAMOGLASNIKA, uSamo) * box_pow(BROJ_SUGLASNIKA, uSug);
      rezultat = rezultat % DJELILAC;//Pogledajte objasnjenje u opisu funkcije box_pow(int, int)
    }
    if(su_svi_true(kombinacije, upit)){//U sistemu koji smo napravili, kada su sve vrijednosti niza "kombinacije" true znaci da smo pregledali sve moguce kombinacije
      break;
    }
    povecaj_za_1(kombinacije, upit);//Pogledajte opis iznad
  }
  std::cout << rezultat << std::endl;
  delete[] rjec;
  delete[] varijacije;
}
