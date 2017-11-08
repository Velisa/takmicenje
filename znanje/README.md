# Шта треба знати за додатну наставу (основни концепти)
## Теорија
* Типови података
  * int
  * char
  * bool
  * float
  * string
  * double
* Кориштење `signed`, `unsigned`, `short`, `long`  
## Синтакса
### Уопште
* Кориштење библиотека
* Декларација промјенљивих
* Декларација константи
* Декларација функција
* Декларација једнодимензионалних низова
* Кориштење `cin` и `cout`
* Аритметички оператори
* Логички оператори
* `if-else` наредба
* `for` петља
* Наредбе `break` и `continue`
### Вајл петља
```
while (uslov) {
  iskaz(i);
}
```
Да би се изрази унутар петље извршиле, услов мора бити тачан.
### Ду-вајл петља
```
do {
  iskaz(i);
} while (uslov);
```
Тијело петље се извршава најмање једном. Да би се петља извршила више него једном, услов мора бити тачан.
### Свич исказ
```
switch (izraz) {
  case konstantni-izraz:
    iskaz(i);
    break; // opcionalno
  case konstantni-izraz:
    iskaz(i);
    break; // opcionalno
  ...
  // Moze postojati bilo koji broj kejs (case) iskaza
  ...
  default: // opcionalno
    iskaz(i);
}

```
Сљедећа правила важе за свич исказе:
* Израз у `switch (izraz)` мора бити цјелобројног или набројивог типа, или бити типа такве класе која има једну функцију за претварање у цјелобројни или набројиви тип.
* `konstantni-izraz` мора бити истог типа као и промјенљива (израз) унутар `switch (izraz)`, и мора бити или константа или литерал.
* When the variable being switched on is equal to a case, the statements following that case will execute until a break statement is reached.
* When a break statement is reached, the switch terminates, and the flow of control jumps to the next line following the switch statement.
* Not every case needs to contain a break. If no break appears, the flow of control will fall through to subsequent cases until a break is reached.
* A switch statement can have an optional default case, which must appear at the end of the switch. The default case can be used for performing a task when none of the cases is true. No break is needed in the default case.

## Кориштење функција
* `sizeof()`
* `sqrt()`
## Задаци
### Низови - Један низ
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
