#include <iostream>
#include <math.h>

int main(){
    double x1,y1,r1,x2,y2,r2;
    std::cout << "Unesite koordinate i poluprecnik prvog igralista >";
    std::cin >> x1 >> y1 >> r1;
    std::cout << "Unesite koordinate i poluprecnik drugog igralista >";
    std::cin >> x2 >> y2 >> r2;
    double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2,2));
    double tr = r1+r2;
    std::cout << d << ' ' << tr << std::endl;
    if(d == tr){
        std::cout << "Krugovi se dodiruju" << std::endl;
    }else if(d < tr){
        std::cout << "Krugovi se preklapaju" << std::endl;
    }else{
        std::cout << "Krugovi se ne preklapaju" << std::endl;
    }
}
