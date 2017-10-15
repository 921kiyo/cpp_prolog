#include <iostream>
#include <cstring>
#include "two_d.h"

using namespace std;

int main(){
  int array1[M][N];
  int array2[N][R];
  
  cout << "INPUT FIRST 2*2 MATRIX: " << endl;
  insert_n(array1, M);
  cout << "INPUT SECOND 2*2 MATRIX: " << endl;
  insert_r(array2, N);

  cout << "\n\n";
  
  display_n(array1, M);
  cout << "\n";
  display_r(array2, N);
  cout << "\n";
  return 0; 
}
