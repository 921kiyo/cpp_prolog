#include <iostream>

#include "IntegerArray.h"

using namespace std;

void input_array(int array[], int length){
  for(int i =0; i<length; i++){
    cout << "Type an integer\n";
    cin >> array[i];
    cout << "\n";
  }
}


/*
string numbering(int i){
  if()
  
}
*/

void display_array(int array[], int length){
  cout << "Displaying an array...\n";
  for(int i = 0; i< length; i++){
    cout << array[i] << "\n";
  }
}

void copy_array(int array1[], int array2[], int length){
  for(int i = 0; i<length; i++){
    array2[i] = array1[i];
  }
}
