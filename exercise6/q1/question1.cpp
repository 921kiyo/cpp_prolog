#include <iostream>
#include "IntegerArray.h"

using namespace std;

int main(){

  const int NUM = 6;
  double array1[NUM];
  double array2[NUM];

  input_array(array1, NUM);
  display_array(array1, NUM);

  copy_array(array1, array2, NUM);
  display_array(array2, NUM);
  double ave = average(array1, NUM);
  cout << "Average: " << ave << "\n"; 
  return 0;
}
