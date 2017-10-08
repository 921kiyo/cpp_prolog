#include <iostream>

#include "IntegerArray.h"

using namespace std;

int main(){
  const int N = 6;
  int array1[N];
  int array2[N];
  input_array(array1, N);
  display_array(array1, N);
  copy_array(array1, array2, N);
  display_array(array2, N);

  return 0;
}
