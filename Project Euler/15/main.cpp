#include <iostream>

long long getTriangle(int nth){
  long long sum = 0;
  for(int i = 0; i < nth; i++){
    sum += i;
  }
  return sum;
}

int main(){
  long long counter = 0;
  //Ispisi sve dvocifrene brojeve u bazi 3 kod kojih je cifra sa desne strane uvijek veca od one sa lijeve
  for(int c1 = 0; c1 < 10; c1++){
    for(int c2 = 0; c2 < 10; c2++){
      //for(int c3 = 0; c3 < 10; c3++){
        if(c1 > c2 /*|| c1 > c3 || c2 > c3*/) counter++;
      //}
    }
  }
  std::cout << counter << "\t" << getTriangle(1000/10) << std::endl;
}
