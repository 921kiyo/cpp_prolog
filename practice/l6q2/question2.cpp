#include <iostream>

using namespace std;

const int MAX = 80;

void string_sort(char array[]){
  
}

int main(){
  char array[MAX];
  cout << "Type in a string: \n";
  cin.getline(array, MAX);
  string_sort(array);
  cout << "The sorted string is " << array << "\n"
  
  return 0;
}
