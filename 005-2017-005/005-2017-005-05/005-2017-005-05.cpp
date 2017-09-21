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

void povecaj_za_1(bool* niz,const int& n){
  for(int i = n-1; i >= 0; i--){
    if(!niz[i]){
      niz[i] = true;
      return;
    }else{
      niz[i] = false;
    }
  }
}

unsigned long long box_pow(uint n1, uint n2){
  unsigned long long rezultat = 1;
  for(uint i = 0; i < n2; i++){
    rezultat *= n1;
    rezultat = rezultat % DJELILAC;
  }
  return rezultat;
}

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
  bool * varijacije = new bool[upit];
  for(uint i = 0; i < upit; i++){
    varijacije[i] = false;
  }
  unsigned long long rezultat = 0;
  while(true){
    /**
    for(uint i = 0; i < upit; i++){
      std::cout << varijacije[i] << ',';
    }
    std::cout << std::endl;
    /**/
    int uSamo = prebroj_true(varijacije, upit);
    int uSug = upit - uSamo;
    if(abs((int)(uSamo + samo) - (int)(sugl + uSug)) <= k){
      rezultat += box_pow(BROJ_SAMOGLASNIKA, uSamo) * box_pow(BROJ_SUGLASNIKA, uSug);
      rezultat = rezultat % DJELILAC;
    }
    if(su_svi_true(varijacije, upit)){
      break;
    }
    povecaj_za_1(varijacije, upit);
  }
  std::cout << DJELILAC << std::endl;
  std::cout << rezultat << std::endl;
  delete[] rjec;
  delete[] varijacije;
}
