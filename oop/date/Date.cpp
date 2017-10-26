#include <iostream>
#include "Date.h"

using namespace std;

void Date::next(){
  day++;
  if(this->day==32){
    day=1;
    month++;
  }
  if(this->month==13){
    month=1;
    year++;
  }
}
