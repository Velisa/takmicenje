# Шта треба знати за додатну наставу (основни концепти)
## Увод
Користимо стандарде C++14 (пожељно) или C++11 (ако C++14 није подржано).

Референтни извор информација је [https://en.cppreference.com](https://en.cppreference.com).
## Основни концепти
* Типови података: int, char, bool, float, string, double
* Кориштење `signed`, `unsigned`, `short`, `long`, `sizeof`
* Кориштење библиотека
* Декларација: промјенљивих, константи, функција, низова, стрингова
* Иницијализација: промјенљивих, низова, стрингова
* Аритметички и логички оператори
* Улаз и излаз (`cin` и `cout`)
## Гранање
* `if-else` исказ
* `switch` исказ
## Петље
* `for` петља
* `while` петља
* `do-while` петља
* Наредба `break`
* Наредба `continue`
## Кориштење функција и оператора
### Дефинисане у `<cmath>`
* `round`
    * [http://en.cppreference.com/w/cpp/numeric/math/round](http://en.cppreference.com/w/cpp/numeric/math/round)
* `sqrt`
    * [http://en.cppreference.com/w/cpp/numeric/math/sqrt](http://en.cppreference.com/w/cpp/numeric/math/sqrt)
* `trunc`
    * [http://en.cppreference.com/w/cpp/numeric/math/trunc](http://en.cppreference.com/w/cpp/numeric/math/trunc)
### Дефинисане у `<string>`
[http://en.cppreference.com/w/cpp/string/basic_string](http://en.cppreference.com/w/cpp/string/basic_string)
* `operator []`
    * [http://en.cppreference.com/w/cpp/string/basic_string/operator_at](http://en.cppreference.com/w/cpp/string/basic_string/operator_at)
* `empty`
    * [http://en.cppreference.com/w/cpp/string/basic_string/empty](http://en.cppreference.com/w/cpp/string/basic_string/empty)
* `size` и `length`
    * [http://en.cppreference.com/w/cpp/string/basic_string/size](http://en.cppreference.com/w/cpp/string/basic_string/size)
* `operator +=`
    * [http://en.cppreference.com/w/cpp/string/basic_string/operator%2B%3D](http://en.cppreference.com/w/cpp/string/basic_string/operator%2B%3D)
* `substr`
    * [http://en.cppreference.com/w/cpp/string/basic_string/substr](http://en.cppreference.com/w/cpp/string/basic_string/substr)
* `find`
    * [http://en.cppreference.com/w/cpp/string/basic_string/find](http://en.cppreference.com/w/cpp/string/basic_string/find)
* `stoi`
    * [http://en.cppreference.com/w/cpp/string/basic_string/stol](http://en.cppreference.com/w/cpp/string/basic_string/stol)
* `stof`
    * [http://en.cppreference.com/w/cpp/string/basic_string/stof](http://en.cppreference.com/w/cpp/string/basic_string/stof)
* `to_string`
    * [http://en.cppreference.com/w/cpp/string/basic_string/to_string](http://en.cppreference.com/w/cpp/string/basic_string/to_string)
# Задаци
## Основни концепти
### Улаз и излаз
## Гранање
## Петље
### Наредба `break`
#### Задатак 1
Шта ће исписати сљедећи програм?
````
#include <iostream>
using namespace std; 
int main() {
    for (int i=0; i < 2; ++i) {
        for (int j=0; j < 5; ++j) {
            if (j == 2) 
                break;
            cout << i << j << " ";
        }
    }
    return 0;    
}
````
### Наредба `continue`
#### Задатак 1
Шта ће исписати сљедећи програм?
````
#include <iostream>
using namespace std; 
int main() {
    for (int i=0; i < 10; ++i) {
        if (i != 5)
            continue;
        cout << i << " ";
    }
    return 0;
}
````
#### Задатак 2
Шта ће исписати сљедећи програм?
````
#include <iostream>
using namespace std; 
int main() {
    for (int i=0; i < 2; ++i) {
        for (int j=0; j < 5; ++j) {
            if (j == 3)
                continue;
            cout << i << j << " ";
        }
    }
    return 0;
}
````
## Кориштење функција и оператора
### Дефинисане у `<cmath>`
#### `round`
##### Задатак 1
Шта ће исписати сљедећи програм?
````
#include <iostream>
#include <cmath>
using namespace std; 
int main() {
  cout  << "round(+2.3) = " << round(2.3) << endl
        << "round(+2.5) = " << round(2.5) << endl
        << "round(+2.7) = " << round(2.7)  << endl
        << "round(-2.3) = " << round(-2.3) << endl
        << "round(-2.5) = " << round(-2.5) << endl
        << "round(-2.7) = " << round(-2.7) << endl
        << "round(-0.0) = " << round(-0.0) << endl
        << "round(-Inf) = " << round(-INFINITY) << endl;
  return 0;
}
````
##### Задатак 2
Корисник уноси сљедеће бројеве: 3.14159265359, 1.61803398875, 2.71828. Напиши програм који исписује први број заокружен на 1 децимално мјесто, други број заокружен на 2 децимална мјеста, и трећи број заокружен на 3 децимална мјеста.
### Дефинисане у `<string>`
#### Задатак 1
Корисник уноси неки износ користећи децимални зарез. Испиши на којој позицији се налази зарез.
#### Задатак 2
Корисник уноси неки износ користећи децимални зарез. Испиши све унесене цифре прије децималног зареза.
#### Задатак 3
Корисник уноси неки износ користећи децимални зарез. Испиши све унесене цифре послије децималног зареза.
#### Задатак 4
Корисник уноси неки износ користећи децимални зарез. Испиши тај износ користећи децималну тачку.
#### Задатак 5
Корисник уноси неку ријеч, користећи само мала слова. Испиши колико има самогласника у унесеној ријечи. Уради задатак користећи if-else исказ, па затим користећи switch исказ.
## Низови - Један низ
1. Учитати низ А од М чланова, затим исписати чланове низа. (ЖГ)
1. Учитати низ и исписати само позитивне чланове низа. (ЖГ)
1. Учитати низ и израчунати суму свих чланова низа. (ЖГ)
1. Учитати низ и израчунати производ свих чланова низа. (ЖГ)
1. Учитати низ и исписати само парне чланове низа. (ЖГ)
1. Учитати низ и исписати чланове низа са парним индексима. (ЖГ)
1. Учитати низ и исписати прво чланове низа са парним индексима, па затим чланове низа са непарним индексима. (ЖГ)
1. Учитати низ и исписати прво негативне чланове, па нуле, па затим позитивне чланове низа. (ЖГ)
1. Учитати низ А од М чланова и наћи највећи члан низа. (ЖГ)
1. Учитати низ А од М чланова и наћи најмањи члан низа. (ЖГ) 
1. Учитати низ А од М чланова, сортирати низ и исписати чланове низа од најмањег до највећег члана.
1. Учитати низ А од М чланова, сортирати низ и исписати чланове низа од највећег до најмањег члана.
