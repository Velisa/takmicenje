# Шта треба знати за додатну наставу (основни концепти)
## Увод
Користимо стандарде C++14 (пожељно) или C++11 (ако C++14 није подржано).

Сва рјешења су урађена и тестирана у [https://www.cygwin.com/](Cygwin) окружењу са GCC компајлером.

Референтни извор информација је [https://en.cppreference.com](https://en.cppreference.com).
## Основни концепти
* Типови података: int, char, bool, float, string, double
* Кориштење `signed`, `unsigned`, `short`, `long`, `sizeof()`
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
* `round()`
    * [http://en.cppreference.com/w/cpp/numeric/math/round](http://en.cppreference.com/w/cpp/numeric/math/round)
* `sqrt()`
    * [http://en.cppreference.com/w/cpp/numeric/math/sqrt](http://en.cppreference.com/w/cpp/numeric/math/sqrt)
* `trunc()`
    * [http://en.cppreference.com/w/cpp/numeric/math/trunc](http://en.cppreference.com/w/cpp/numeric/math/trunc)
### Дефинисане у `<string>`
[http://en.cppreference.com/w/cpp/string/basic_string](http://en.cppreference.com/w/cpp/string/basic_string)
* `operator []`
    * [http://en.cppreference.com/w/cpp/string/basic_string/operator_at](http://en.cppreference.com/w/cpp/string/basic_string/operator_at)
* `empty()`
    * [http://en.cppreference.com/w/cpp/string/basic_string/empty](http://en.cppreference.com/w/cpp/string/basic_string/empty)
* `size` и `length`
    * [http://en.cppreference.com/w/cpp/string/basic_string/size](http://en.cppreference.com/w/cpp/string/basic_string/size)
* `operator +=`
    * [http://en.cppreference.com/w/cpp/string/basic_string/operator%2B%3D](http://en.cppreference.com/w/cpp/string/basic_string/operator%2B%3D)
* `substr()`
    * [http://en.cppreference.com/w/cpp/string/basic_string/substr](http://en.cppreference.com/w/cpp/string/basic_string/substr)
* `find()`
    * [http://en.cppreference.com/w/cpp/string/basic_string/find](http://en.cppreference.com/w/cpp/string/basic_string/find)
* `stoi()`
    * [http://en.cppreference.com/w/cpp/string/basic_string/stol](http://en.cppreference.com/w/cpp/string/basic_string/stol)
* `stof()`
    * [http://en.cppreference.com/w/cpp/string/basic_string/stof](http://en.cppreference.com/w/cpp/string/basic_string/stof)
* `to_string()`
    * [http://en.cppreference.com/w/cpp/string/basic_string/to_string](http://en.cppreference.com/w/cpp/string/basic_string/to_string)
### Дефинисане у `<iomanip>`
* `setprecision()`
    * [http://en.cppreference.com/w/cpp/io/manip/setprecision](http://en.cppreference.com/w/cpp/io/manip/setprecision)
### Дефинисане у `<ios>`
* `fixed`
    * [http://en.cppreference.com/w/cpp/io/manip/fixed](http://en.cppreference.com/w/cpp/io/manip/fixed)
### Остале функције за компатибилност са старијим С++ стандардима
* `аtoi()` из `<cstdlib>`
    * [http://en.cppreference.com/w/cpp/string/byte/atoi](http://en.cppreference.com/w/cpp/string/byte/atoi)
* `аtof()` из `<cstdlib>`
    * [http://en.cppreference.com/w/cpp/string/byte/atof](http://en.cppreference.com/w/cpp/string/byte/atof)
* `c_str()`
    * [http://en.cppreference.com/w/cpp/string/basic_string/c_str](http://en.cppreference.com/w/cpp/string/basic_string/c_str)
* `printf()` из `<cstdio>`
    * [http://en.cppreference.com/w/cpp/io/c/fprintf](http://en.cppreference.com/w/cpp/io/c/fprintf)
* `roundf()` из `<math.h>`
   * [http://en.cppreference.com/w/c/numeric/math/round](http://en.cppreference.com/w/c/numeric/math/round)
