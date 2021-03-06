#include <iostream>

using namespace std;

const int MAX = 80;

void string_sort(char array[], int length);
int minimum(char array[], int position);

void swap(char& a, char&b);

int main(){
  char array[MAX];
  cout << "Type in a string: ";
  cin.getline(array, MAX);
  
  string_sort(array, MAX);
  cout << "The sorted string is: " << array << "\n";
  return 0; 
}

void string_sort(char array[], int length){
  int i = 0;
  while(array[i] != '\0'){
    swap(array[i], array[minimum(array, i)]);
    i++;
  }
  
}

int minimum(char array[], int position){
  int min = position;
  int count = position + 1;
  while(array[count] != '\0'){
    if(array[count] < array[min]){
      min = count;
    }
    count++;
  }

  return min;
}

/*
void swap(char& a, char&b){
  char temp = a;
  a = b;
  b = temp;
}
*/
void swap(char& a, char& b){
  
  a ^= b;
  b ^= a;
  a ^= b;
}
