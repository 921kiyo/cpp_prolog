#include <iostream>
#include "IntegerArray.h"

using namespace std;

void input_array(double array[], int length){
  cout << "You can add " << length << " elements in the array\n";
  for(int i=0; i<length; i++){
    cout << "Type an integer\n";
    cin >> array[i];
    cout << "\n";
  }
}

void display_array(double array[], int length){
  cout << "Array displaying\n"; 
  for(int i=0; i<length; i++){
    cout << array[i] << "\n";
  }
}

void copy_array(double array1[], double array2[], int length){
  for(int i = 0; i<length; i++){
    array2[i] = array1[i];
  }
}

double average(double array[], int length){
  int sum = 0;
  for(int i = 0; i<length; i++){
    sum += array[i];
  }
  return static_cast<double>(sum)/static_cast<double>(length);
}

double standard_deviation(double array[], int length){
  double av = average(array, length);
  double element[length];
  for(int i = 0; i<length; i++){
    element[i] = (array[i] - av)*(array[i]-av);
  }
  return average(element, length);
}
