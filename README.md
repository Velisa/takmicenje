# Распоред такмичења у школској години 2017/2018.

| Дисциплина  | Школско          | Општинско       | Регионално    |
|-------------|------------------|-----------------|---------------|
| Информатика | до 28. 02. 2018. | није предвиђено | 10. 03. 2018. |

# Задаци и рјешења са такмичења из информатике за средње школе
## Формат имена задатака
Сваки појединачни задатак мора бити јединствено и логички означен. Формат за име сваког задатка се састоји од четири групе бројева, раздвојене средњом цртицом:

**KKK-YYYY-LLL-MM{-A}**

Свака од група бројева има сљедеће значење:

* KKK
  * Земља гдје је такмичење одржано
    * 005 = Република Српска
    * 010 = Србија
    * 015 = Босна и Херцеговина
    * 020 = Хрватска

* YYYY
  * Година такмичења (четири цифре)

* LLL
  * Врста такмичења:
    * 003 = **Општинско** такмичење из информатике за средње школе
    * 005 = **Регионално** такмичење из информатике за средње школе
    * 010 = **Кантонално** такмичење из информатике за средње школе
    * 015 = **Жупанијско** такмичење из информатике за средње школе
    * 020 = **Републичко** такмичење из информатике за средње школе
    * 025 = **Државно** такмичење из информатике за средње школе   

* MM
  * Редни број задатка у оквиру појединачног такмичења.
  
* {-A}
  * Опционално слово или број које може да се користи ако је било више група задатака на такмичењу.
 
На примјер, задатак означен као **005-2013-005-02** значи:
* 005 = Такмичење одржано у Републици Српској
* 2013 = Такмичење одржано 2013. године
* 005 = Регионално такмичење из информатике за средње школе
* 02 = 2. задатак на такмичењу.

Цијели скуп задатака (фолдер) са једног такмичења може да се означи као  005-2013-005 (без навођења редног броја задатка). У случају да је било двије различите групе исте врсте задатака, рецимо групе 1 и 2, онда се сви задаци из групе 1 означавају као 005-2013-005-1, а сви задаци из групе 2 као 005-2013-005-2.

Задатке чувамо у сљедећим форматима:
* PDF = Portable Document Format
* ODT = Open Document Text.

Често сам задатак дефинише потребно име изворног фајла рјешења. То захтијевано име често буде веома кратко и може се додати у име задатка на сљедећи начин:

**KKK-YYYY-LLL-MM-{A}-SSS...**

гдје **SSS...** представља захтијевано име (наравно без празних размака). Три тачке су стављене јер је дужина имена непозната.

## Имена изворних фајлова рјешења
Имена рјешења такође морају бити у одговарајућем формату. Иако можда сам задатак дефинише потребно име изворног фајла рјешења, ми то захтијевано име не користимо (ради каснијег лакшег тестирања). Имена рјешења су дакле у сљедећем формату:

**KKK-YYYY-LLL-MM-{A}.cpp**

Као екстензију увијек користимо .cpp јер за рјешавање задатака користимо програмски језик C++.

Уколико постоји неколико верзија рјешења, алтернативна рјешења ставити у посебне директорије, назване:

**_altNN**

гдје почетна доња црта обавезна, а **NN** је редни број алтернативног рјешења написан са свије цифре (на примјер 01, 02, 03, итд).

За посебна рјешења корисника, креирати посебну директорију за сваког корисника, користећи (кратко) име директорије које једнозначно одређује корисника. За истог корисника, користити исто име директорије у свим задацима.

Уколико постоје алтернативна рјешења унутар посебне резервисане директорије за рјешења, користити сљедећи формат за име директорије алтернативног рјешења:

**_I..._altNN**

гдје су двије доње црте обавезне, а:

* I...
    * (кратко) име директорије које једнозначно одређује корисника
* NN
    * редни број исписан са свије цифре (на примјер 01, 02, 03, итд).

## Тренутно кориштена имена за посебне директорије рјешења

| Име посебне директорије | Власник           |
|-------------------------|-------------------|
| NP                      | Новак Петровић    |
|-------------------------|-------------------|
| VP                      | Велиша Петричевић |
## Имена тест фајлова

Сви фајлови за тестирање се налазе у поддиректорији **tests** и то у сљедећим форматима:

Улаз:
**KKK-YYYY-LLL-MM-{A}.test.ZZ.in.txt**

Излаз:
**KKK-YYYY-LLL-MM-{A}.test.ZZ.out.txt**

Рјешење:
**KKK-YYYY-LLL-MM-{A}.test.ZZ.sol.txt**

гдје **ZZ** представља редни број теста (01, 02, ... 10, 11, ... 16, ... 87, ...).

У самој директорији гдје је задатак и рјешење налази се само тест извјештај који садржи информације да ли је сваки тест прошао или не. Име тог фајла је:
**KKK-YYYY-LLL-MM-{A}.tests.report.txt**

## Контакт
Сва питања и приједлоге упутити на:
Новак Петровић (Novak Petrovic) npetrovic@gmail.com
