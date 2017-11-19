#include <iostream>
#include <math.h>

int main(){
    double x1,y1,r1,x2,y2,r2;
    std::cout << "Unesite koordinate i poluprecnik prvog igralista >";
    std::cin >> x1 >> y1 >> r1;
    std::cout << "Unesite koordinate i poluprecnik drugog igralista >";
    std::cin >> x2 >> y2 >> r2;
    /*
        Kako biste razumjeli ovaj zadatak, uzmite list sveske sa kvadraticima i nacrtajte prvi kvadrant koordinatnog sistema,
        napravite veci razmak izmedju brojeva. Sada oznacite tacke O1(1,1), i O2(4,5). Oko tacke O1 ucrtajte kruznicu poluprecnika
        2, a oko tacke O2 kruznicu poluprecnika 3. Ako ste sve uradili kako treba, dobili ste dvije kruznice koje se dodiruju. Sada
        povezite tacke O1 i O2 i oznacite dobijenu duz sa "d". Na slici mozemo da uocimo da je dio duzi "d" od tacke O1 do tacke
        dodira krugova ustvari poluprecnik prvog kruga "r1". Istom logikom pronalazimo i poluprecnik drugog kruga "r2". Takodje
        uocavamo da je u ovom slucaju d = r1 + r2. Sada zamislite kako se krugovi udaljavaju jedan od drugoga(Ako vam je tesko
        zamisliti, nacrtajte drugi krug na x=5 y=6 i r=3). Dakle distanca izmedju njih(d) se povecava dok njihovi poluprecnici
        ostaju isti. Zakljucujemo da ukoliko je d > r1 + r2, krugovi se ne preklapaju. Istom logikom shvatamo da ukoliko je
        d < r1 + r2, krugovi se preklapaju
    */

    /*
        Sledeca linija sluzi za izracunavanje razdaljine izmedju centara(d). Koristimo opste poznatu formulu 
        d=sqrt((x1-x2)^2 + (y1-y2)^2)
    */
    double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2,2));
    if(d == r1 + r2){
        std::cout << "Krugovi se dodiruju" << std::endl;
    }else if(d < r1 + r2){
        std::cout << "Krugovi se preklapaju" << std::endl;
    }else{
        std::cout << "Krugovi se ne preklapaju" << std::endl;
    }
}
