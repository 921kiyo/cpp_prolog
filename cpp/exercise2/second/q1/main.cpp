#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  int lowest, highest, step_size;
  cout << "What is the lowerst F temperature?" << endl;
  cin >> lowest;
  cout << "What is the highest F temperature?" << endl;
  cin >> highest;
  cout << "What is the desired step size?" << endl;
  cin >> step_size;
  cout << setiosflags(ios::left);
  cout.width(20);
  cout << "Fahrenheit";
  cout.width(20);
  cout << "Celsius";
  cout.width(20);
  cout << "Absolute Value" << endl;
  double fahrenheit, celsius, abs_value;
  for(int i = lowest; i < highest; i = i + step_size){
    cout.width(20);
    cout << i;
    fahrenheit = (double) i;
    celsius = (fahrenheit - 32) * 5 / 9;
    cout << fixed;
    cout.width(20);
    cout.precision(2);
    cout << celsius;
    cout.width(20);
    abs_value = celsius + 273.15;
    cout << abs_value;
    cout << endl;
  }
  cout << endl;

  return 0;
}
