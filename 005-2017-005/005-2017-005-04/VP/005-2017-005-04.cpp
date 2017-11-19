#include <iostream>
#include <math.h>

/*
    Ciel funkcija je u sustini jednostavna. Vrijednost dobijemo tako sto na broj dodamo 1 i pozovemo floor().
    Ali ne zaboravimo da postoji poseban slucaj kada je nas broj cijeli. U tom slucaju spomenuta formula ce nam
    dati broj za jedan veci, sto mi ne zelimo. Ciel funkcija, ukoliko na ulazu ima cijeli broj, treba da vrati
    taj isti broj.
*/

int ciel(double d){
    if(floor(d) == d){
        return d;
    }else{
        return (int)floor(d+1);
    }
}

int main(){
    double n;
    std::cout << "Unesite broj n > ";
    std::cin >> n;
    if(n > 1000000000000000){
        std::cout << "Broj je prevelik" << std::endl;
        return 0;
    }
    /*
        Posto trazimo najmanji broj bacanja, mozemo da predpostavimo da se na svakom bacanju dobiju dvije sestice. Dakle za
        svakih 12 n mi povecavamo broj bacanja. Djeljenjem n sa 12 dobicemo broj malo manji od trazenog(0 - 0.999) osim ako je
        n djeljivo sa 12, kada dobijamo tacan rezultat. Posto broj bacanja mora da bude prirodan broj, rjesenje djeljenja moramo
        da zaokruzimo. U ovom slucaju zaokruzujemo na vise jer djeljenjem dobijamo broj manji od zeljenog. Za zaokruzivanje
        broja na gore koristimo funkciju ciel koja na zalost nije definisana u standardnoj c++ biblioteci, te mi sami moramo
        da je napisemo(Pogledajte gore).
    */
    std::cout << ciel(n / 12) << std::endl;
}
