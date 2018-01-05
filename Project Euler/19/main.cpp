#include <iostream>

bool shouldResetDay(const int &day, const int &month, const  int &year){
  if(month == 1){
    if(year % 4 == 0){
      if(year % 100 == 0){
        if(year % 400 == 0){
          return !(day < 29);
        }
        return !(day < 28);
      }
      return !(day < 29);
    }
    return !(day < 28);
  }
  bool condition2 = month == 3 || month == 5 || month == 8 || month == 10;
  if(condition2){
    return !(day < 30);
  }
  return !(day < 31);
}

int main(){
  long int dayOfTheWeek = 0;
  int dayOfTheMonth = 0;
  int month = 0;
  long int mondayCount = 0;
  int year = 1900;

  for(; true; ){
    dayOfTheWeek++;
    dayOfTheWeek %= 7;
    if(shouldResetDay(dayOfTheMonth, month, year)) {
      dayOfTheMonth = 0;
      month++;
    }
    if(month >= 12){
      month = 0;
      year++;
    }
    if(dayOfTheWeek == 6 && dayOfTheMonth == 0 && year > 1900) mondayCount ++;
    if(year > 2000) break;
    dayOfTheMonth++;
  }
  std::cout << mondayCount << std::endl;
}
