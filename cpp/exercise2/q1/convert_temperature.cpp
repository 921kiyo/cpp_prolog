#include <iostream>


using namespace std;

int LOWER;
int UPPER;
int STEP;

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
  
cout.width(15);
cout << "Fahrenheit";
cout.width(15);
cout << "Celsius";
cout.width(15);
cout << "Absolute Value\n";
  cout << fixed;
  cout.precision(2);
for (int v = LOWER; UPPER >= v; v=v+STEP){
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

