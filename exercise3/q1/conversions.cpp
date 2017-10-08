#include <iostream>
#include "conversions.h"

using namespace std;

double celsius_of(int fahr){
  double result;
  result = (static_cast<double>(5)/9) * (fahr - 32);
  return result;
}

double absolute_value_of(double celsius){
  double result; 
  result = celsius + 273.15;
  return result;
}
