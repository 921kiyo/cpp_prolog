#include <iostream>

#include "IntegerArray.h"

using namespace std;

int main(){
  const int N = 6;
  float array1[N];
  float array2[N];
  input_array(array1, N);
  display_array(array1, N);
  copy_array(array1, array2, N);
  
  display_array(array2, N);

  float std = standard_deviation(array1, N);
  cout << "Std is " << std << "\n";
  return 0;
}
