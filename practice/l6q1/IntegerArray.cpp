#include <iostream>
#include <cmath>

#include "IntegerArray.h"

using namespace std;

void input_array(float array[], int length){
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

void display_array(float array[], int length){
  cout << "Displaying an array...\n";
  for(int i = 0; i< length; i++){
    cout << array[i] << "\n";
  }
}

void copy_array(float array1[], float array2[], int length){
  for(int i = 0; i<length; i++){
    array2[i] = array1[i];
  }
}

float average(float array[], int length){
  float total = 0;
  for(int i = 0; i<length; i++){
    total += array[i];
  }
  return total/length;
}

float standard_deviation(float array[], int length){
  float av = average(array, length);
  float element[length];
  cout << "The average is " << av << "\n";
  
  for(int i = 0; i<length; i++){
    element[i] = (array[i]-av)*(array[i]-av);
  }

  return sqrt(average(element, length));
}
