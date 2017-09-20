#include <iostream>
#include <math.h>
#include <iomanip>

double ciel(double d){
    if(floor(d) == d){
        return d;
    }else{
        return floor(d+1);
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
    std::cout << std::setprecision(15)<<ciel(n / 12)<< std::endl;
}
