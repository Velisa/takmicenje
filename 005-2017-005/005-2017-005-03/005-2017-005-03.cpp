#include <iostream>

bool jeMali(int64_t i){
    return i <= 1000000000;
}

int main(){
    int64_t x1, x2, x3, y1, y2, y3;
    std::cout << "Unesite koordinate triju tacaka >";
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if(!jeMali(x1)||!jeMali(x2)||!jeMali(x3)||!jeMali(y1)||!jeMali(y2)||!jeMali(y3)){
        std::cout << "Maksimalna vrijednost je 10^9" << std::endl;
        return 0;
    }
    if((x1 == x2 && x2 == x3) || (y1 == y2 && y2 == y3)){
        std::cout << 1 << std::endl;
    }else if(
            (x1 == x2 && (y2 == y3 || y1 == y3)) ||
            (x2 == x3 && (y1 == y2 || y1 == y3)) ||
            (x1 == x3 && (y1 == y2 || y2 == y3))){
        std::cout << 2 << std::endl;
    }else{
        std::cout << 3 << std::endl;
    }
}
