#include "q1.h"
#include <iostream>

using namespace std;

int main(){

  int array[4];
  int array2[8];

  input_array(array, 4);
  display_array(array, 4);
  input_array(array2, 8);
  display_array(array2, 8);
  copy_array(array, array2, 2);
  cout << "after copy" << endl;
  display_array(array , 4);
  return 0;
}
