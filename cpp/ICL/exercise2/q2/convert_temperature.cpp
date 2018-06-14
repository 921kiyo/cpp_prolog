#include <iostream>


using namespace std;

double convert_to_celcius(int temp){
  double result, temp1;
  temp1 = (double)temp;
  result = ((temp1 - 32) * 5)/9;
  return result;
}

double convert_to_absolute(double temp){
  double result;
  result = temp + 273.15;
  return result;
}

int main(){
  double celcius, absolute;
  int lower, upper, step;
  cout << "Type lower\n";
  cin >> lower;
  cout << "Type upper\n";
  cin >> upper;
  cout << "Type step size\n";
  cin >> step;
cout.width(15);
cout << "Fahrenheit";
cout.width(15);
cout << "Celsius";
cout.width(15);
cout << "Absolute Value\n";
  cout << fixed;
  cout.precision(2);
for (int v = lower; upper >= v; v=v+step){
  celcius = convert_to_celcius(v);
  absolute = convert_to_absolute(celcius);
cout.width(15);
cout << v;
cout.width(15);
cout << celcius;
cout.width(15);
cout << absolute << "\n";
}

  return 0;
}

