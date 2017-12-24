#include "q1.h"

#include <iostream>

using namespace std;

void input_array(int* a, int n){
  for(int i = 0; i < n; i++){
    a[i] = n;
  }
}

void display_array(int* a, int n){
  for(int i = 0; i < n; i++){
    cout << i <<"th element " << a[i] << endl;
  }
}

void copy_array(int* a1, int* a2, int n){
  for(int i = 0; i < n; i++){
    a1[i] = a2[i];
  }
}
