#include <iostream>
#include <stdlib.h>
#include <math.h>

/*
Objasnjenje:
Vidimo da je ovo poprilicno jednostavna funkcija jer se sastoji samo iz jedne
formule. Na kome principu ova formula radi?

Za pocetak cemo da predpostavimo da je "broj" stepen broja 10 (1, 10, 100, 1000)
taj broj mozemo da predstavimo na sledeci nacin:

10^x = broj

Ako uvrstimo neke brojeve umjesto x mozemo primjetiti da je x uvijek za 1 manje
od broja cifara trazenog broja (pokusajte sami). Posto je nama poznat broj, mi
mozemo jednostavnom algebrom da izvedemo x.

Znamo da je loga(b)=c i a^c=b jedno te isto. Dakle ako jednacinu 10^x=broj
predstavimo na prvi nacin, ona ce izgledati:

log10(broj) = x

Ne smijemo zaboraviti da je x broj cifara-1, te nasem izrazu treba dodati 1:
log10(broj) + 1 = brCifara

Ovo je pouzdan nacin da se pronadje broj cifara nekog stepena broja 10. Sada
kako bismo generalizovali izraz mozemo da se posluzimo logikom.

log10(100) ce nam dati vrijedonst 2, a log10(1000) ce nam dati vrijednost 3.
Dakle ako u ovu funkciju ubacimo neki broj izmedju 100 i 1000 (na primjer 159)
mozemo pretpostaviti da ce nam funkcija dati neku vrijednost izmedju 2 i 3
(u ovom slucaju log10(159) = 2.2013...), dakle broj prije zareza je onaj koji mi
trazimo, a da bismo dobili broj prije zareza koristimo matematicku funkciju
floor(double).

 Nas konacni izraz je: brojCifara = floor(log(broj)) + 1
 */
 
unsigned int broj_cifara (int broj) {
    return floor(log10(broj)) + 1;
}

int main() {
    std::cout << "Unesite broj cije cifre zelite da izbrojite >";
    int n;
    std::cin >> n;
    std::cout << "Broj cifara: " << broj_cifara(n) << std::endl;
    system("pause");
}
 
