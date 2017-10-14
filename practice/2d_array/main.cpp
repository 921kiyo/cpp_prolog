#include <iostream>
#include <cstring>
#include "2d.h"

using namespace std;

int main(){
  int array1[M][N];
  int array2[N][R];
  
  cout << "INPUT FIRST 2*2 MATRIX: " << endl;
  insert_value(array1, M, N);
  cout << "INPUT SECOND 2*2 MATRIX: " << endl;
  insert_value(array2, N, R);
  return 0; 
}
