#include <iostream>
#include <math.h>

#define BROJ_SAMOGLASNIKA 5
#define BROJ_SUGLASNIKA 21
#define MAX_BOX_BROJ 100

typedef unsigned int uint;

bool jeUpitnik(char c){
  return c=='?';
}

bool jeSamoglasnik(char c){
  return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

uint prebrojFalse(bool* b, uint n){
  uint c = 0;
  for(uint i = 0; i < n; i++){
    if(b[i])c++;
  }
  return n - c;
}

void povecajZa1(bool* b, uint n){
  for(n-=1; n >= 0; n--){
    if(b[n]){
      b[n] = false;
    }else{
      b[n] = true;
      break;
    }
  }
}

void printajArray(bool* b, uint n){
  for(uint i = 0; i < n; i++){
    std::cout << b[i] << ',';
  }
  std::cout << std::endl;
}

bool suSviTrue(bool* b, uint n){
  for(uint i = 0; i < n; i++){
    if(!b[i]) return false;
  }
  return true;
}

uint64_t box_pow(uint b1, uint b2){
  uint64_t rezultat = 1;
  for(uint i = 0; i < b2; i++){
    rezultat *= b1;
  }
  return rezultat;
}

int main(){
  uint n, k;
  std::cout << "Unesite n i k > ";
  std::cin >> n >> k;
  std::cout << "Unesite rijec > ";
  char *rjec = new char[n+1];
  std::cin.ignore();
  std::cin.getline(rjec, n+1);
  unsigned int  sam = 0,
                sug = 0,
                upi = 0;
  //Prebroj samoglasnike, suglasnike i upitnike
  for(uint i = 0; i < n; i++){
    char slovo = rjec[i];
    if(jeUpitnik(slovo)){
      upi++;
      continue;
    }else if(jeSamoglasnik(slovo)){
      sam++;
      continue;
    }else{
      sug++;
      continue;
    }
  }
  uint64_t rezultat = 0;
  bool *upitnici = new bool[upi];//false - samoglasnik, true - suglasnik
  for(uint i = 0; i < upi; i++){
    upitnici[i] = false;
  }
  while(true){
    uint brojUpitSam = prebrojFalse(upitnici, upi);
    uint brojUpitSug = upi - brojUpitSam;
    if(abs((sam + brojUpitSam) - (sug + brojUpitSug)) <= k){
      rezultat += box_pow(BROJ_SAMOGLASNIKA, brojUpitSam) * box_pow(BROJ_SUGLASNIKA, brojUpitSug);//Promjeniti
    }
    if(suSviTrue(upitnici, upi)){
      break;
    }
    povecajZa1(upitnici, upi);
  }

  std::cout << "Rezultat: " << rezultat % (box_pow(10, 9) + 7) << std::endl;//Dodati modulo
  delete[] upitnici;
  delete[] rjec;
}
