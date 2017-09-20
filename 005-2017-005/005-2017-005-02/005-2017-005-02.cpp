#include <iostream>

int main(){
    std::cout << "Unesite duzinu niza, zatim clanove niza(Kontrolni broj je prvi clan) >";
    unsigned int n;
    std::cin >> n;
    int *niz = new int[n];
    for(unsigned int i = 0; i < n; i++){
        std::cin >> niz[i];
    }
    int kb = niz[0];
    for(unsigned int i = 1; i < n; i++){
        int cl = niz[i];
        if(cl <= kb) std::cout << cl << ' ';
    }
    std::cout << kb << ' ';
    for(unsigned int i = 1; i < n; i++){
        int cl = niz[i];
        if(cl > kb) std::cout << cl << ' ';
    }
    delete[] niz;
}
