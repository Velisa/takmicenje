#include <iostream>

typedef unsigned int uint;

bool jeMali(int64_t i){
    return i <= 1000000000;
}

int manjiOd(int i1, int i2){
    return (i1 > i2 ? i2 : i1);
}

int veciOd(int i1, int i2){
    return (i1 > i2 ? i1 : i2);
}

int main(){
    //Objasnjenje i pojednostavljenje dolaze uskoro
    int64_t x1, x2, x3, y1, y2, y3;
    std::cout << "Unesite koordinate triju tacaka >";
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if(!jeMali(x1)||!jeMali(x2)||!jeMali(x3)||!jeMali(y1)||!jeMali(y2)||!jeMali(y3)){
        std::cout << "Maksimalna vrijednost je 10^9" << std::endl;
        return 0;
    }
    if((x1 == x2 && x2 == x3) || (y1 == y2 && y2 == y3)){
        std::cout << 1 << std::endl;
    }else{
        uint slucaj1 = 0;
        uint slucaj2 = 0;

        /*
            1 = 1 i 2
            2 = 2 i 3
            3 = 1 i 3
        */

        if(x1 == x2) slucaj1 = 1;
        if(x2 == x3) slucaj1 = 2;
        if(x1 == x3) slucaj1 = 3;

        if(y1 == y2) slucaj2 = 1;
        if(y2 == y3) slucaj2 = 2;
        if(y1 == y3) slucaj2 = 3;
        if(slucaj1 > 0 && slucaj2 > 0){
            std::cout << 2 << std::endl;
            return 0;
        }

        if(slucaj1 == 1 && (y3 >= veciOd(y1,y2) || y3 <= manjiOd(y1,y2))){
            std::cout << 2 << std::endl;
            return 0;
        }
        
        if(slucaj1 == 2 && (y1 >= veciOd(y2,y3) || y1 <= manjiOd(y2,y3))){
            std::cout << 2 << std::endl;
            return 0;
        }
        
        if(slucaj1 == 3 && (y2 >= veciOd(y1,y3) || y2 <= manjiOd(y1,y3))){
            std::cout << 2 << std::endl;
            return 0;
        }

        //-----------------------------------------------------------------

        if(slucaj2 == 1 && (x3 >= veciOd(x1,x2) || x3 <= manjiOd(x1,x2))){
            std::cout << 2 << std::endl;
            return 0;
        }
        
        if(slucaj2 == 2 && (x1 >= veciOd(x2,x3) || x1 <= manjiOd(x2,x3))){
            std::cout << 2 << std::endl;
            return 0;
        }
        
        if(slucaj2 == 3 && (x2 >= veciOd(x1,x3) || x2 <= manjiOd(x1,x3))){
            std::cout << 2 << std::endl;
            return 0;
        }


        std::cout << 3 << std::endl;
    }
}
