#include <iostream>
#include "Date.h"

using namespace std;

int main(){
  Date today(31,1,2008);
  Date aDay(78, 10, 1986);
  today.print();
  aDay.print();

  Date* tomorrow = new Date(11,21,1996);
  cout << "tomorrow is ";
  tomorrow->print();

  // aDay = today;

  // if(aDay.equal(today)){
  //   cout << "Today and aDay are equal" << endl;
  // }
  //
  // aDay.next();
  // aDay.next();
  // aDay.print();
  //
  // if(aDay.equal(today)){
  //   cout << "aDay and tomorrow are equal \n";
  // }
  //
  // cout << "Next date is ";
  // aDay.nextDate();
  // aDay.print();



}
