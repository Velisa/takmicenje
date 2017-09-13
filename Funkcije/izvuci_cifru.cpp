#include <iostream>
#include <math.h>

/*
 * Cesto cete naici na problem koji od vas zahtjeva da "izvucete" odredjenu cifru iz broja.
 * Napomena: Funkcija nam vraca cifru sa desna na lijevo.
 * Funkcija je jednostavna i prati jednostavnu logiku. 
 * Prvi korak je uklanjanje svih cifara posle zeljene cifre. Recimo da moramo da uklonimo zadnje dvije cifre broja 123456, sjetimo se da prilikom
 * djeljenja broja nekim stepenom broja 10, zarez se pomjera za onoliko mjesta koliko taj stepen ima nula. Ako broj 123456 podjelimo sa 100 dobijamo
 * 1234,56. Kako bismo uklonili sve iza zareza koristimo funkciju floor(double). floor(1234,56) = 1234, i uspjesno smo uklonili zadnje dvije cifre.
 * Zakljucujemo da je algoritam za uklanjanje N zadnjih cifara broja: floor(broj / 10^N). Sada nam je samo preostalo da izdvojimo zadnju cifru
 * dobro poznatim postupkom broj % 10, medjutim nailazimo na problem. Operacija modulo se u c i c++ moze iskljucivo vrsiti izmedju cijelih brojeva, a
 * rezultat funkcije floor() je double. Rezultat floor() funkcije moramo da da pretvorimo (castujemo) u int.  
*/

unsigned int izvuci_cifru(int broj, unsigned int pozicija){
    return (int)floor(broj / pow(10, pozicija)) % 10;
}

int main(){
	int br;
	unsigned int poz;
	std::cout << "Unesite zeljeni broj i poziciju cifre >";
	std::cin >> br >> poz;
	std::cout << izvuci_cifru(br,poz) << std::endl;
}
