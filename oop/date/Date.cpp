#include <iostream>
#include "Date.h"

using namespace std;

// Constructor
Date::Date(int d, int m, int y){
  if(d<1 || d>31){
    cout << d << " illegal day \n";
    d=1;
  }
  if(m<1 || m>12){
    cout << m << " illegal month \n";
    m=1;
  }
  if(y<1900 || y>3000){
    cout << y << " illegal year\n";
    y=2000;
  }

  day = d;
  month = m;
  year = y;
}


void Date::next(){
  day++;
  if(this->day==32){
    day=1;
    month++;
  };
  if(this->month==13){
    month=1;
    year++;
  };
}

bool Date::equal(Date aDate){
  return ((day == aDate.day) && (month==aDate.month)) && (year==aDate.year);
}

void Date::print(){
  cout << day << " / " << month << " / " << year << endl;
}

void Date::nextDate(){
  cout << day +1 << " / " << month << " / " << year << endl;
}
