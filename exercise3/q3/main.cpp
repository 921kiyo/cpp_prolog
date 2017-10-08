#include <iostream>
#include "statistics.h"

using namespace std;

int first, second, third, fourth;

int get_command(){
  int command;
  cout << "Do you wish to test 1,2,3 or 4 numbers (enter 0 to end the program)\n";
  cin >> command;
  return command;
}

void get_first(){
  cout << "Enter first value:\n";
  cin >> first;
  cout << "\n";
}

void get_second(){
  cout << "Enter second value:\n";
  cin >> second;
  cout << "\n";
}

void get_third(){
  cout << "Enter third value:\n";
  cin >> third;
  cout << "\n";
}

void get_fourth(){
  cout << "Enter fourth value:\n";
  cin >> fourth;
  cout << "\n";
}

void end_program(){
}

void display_result(double a, double stan){
  cout << "Average: " << a << "\n";
  cout << "Standard deviation: " << stan << "\n";
}

int main(){  
  cout << "This program tests the functions in the 'statistics.h' header file\n";
  int command = get_command();
  double a, stan;
  switch(command){
  case 1:
    get_first();
    a = average(first);
    stan = standard_deviation(first);
    break;
  case 2:
    get_first();
    get_second();
    a = average(first, second);
    stan = standard_deviation(first, second, a);
    break;
  case 3:
    get_first();
    get_second();
    get_third();
    a = average(first, second, third);
    stan = standard_deviation(first, second, third, a);
    break;
  case 4:
    get_first();
    get_second();
    get_third();
    get_fourth();
    a = average(first, second, third, fourth);
    stan = standard_deviation(first, second, third, fourth, a);
    break;
  case 0: end_program();
  }
  display_result(a, stan);

  return 0;
}
