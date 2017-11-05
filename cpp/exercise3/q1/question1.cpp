#include <iostream>
#include "conversions.h"
using namespace std;


int lower = 0;
int upper = 0;
int step = 1;

void print_preliminary_message(){
  cout << "This program prints out a conversion table of temperatures.\n\n";
  cout << "Enter the minimum (whole number) temperature\n";
  cout << "you want in the table, in Fahrenheit: ";
  cin >> lower;
  cout << "Enter the maximum temperature you want in the table: ";
  cin >> upper;
  cout << "Enter the temperature difference you want between table entries: ";
  cin >> step;
  cout << "\n\n";
}

void input_table_specifications(){
  cout.width(15);
  cout << "Fahrenheit";
  cout.width(17);
  cout << "Celsius";
  cout.width(20);
  cout << "Absolute Value\n\n";

  cout.precision(2);
  cout.setf(ios::fixed);
}

void print_message_echoing_input(){
  cout << "Tempertature conversion table from " << lower << " Fahrenheit\n";
  cout << "to " << upper << " Fahrenheit, in steps of " << step << " Fahrenheit:\n\n";
}

void print_table(){
  int fahr = 0;
  double celsius = 0;
  for (fahr = lower ; fahr <= upper ; fahr += step) {
    cout << "   ";
    cout.width(15);
    cout << fahr;
    celsius = celsius_of(fahr);
    cout.width(15);
    cout << celsius;
    cout.width(15);
    cout << absolute_value_of(celsius) << endl;
  }
}

int main(){
  print_preliminary_message();
  input_table_specifications();
  print_message_echoing_input();
  print_table();
  
  return 0;
}
