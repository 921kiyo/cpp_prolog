#include <iostream>

using namespace std;

<<<<<<< HEAD

int minimum_form(char array[], int position){
  int min_index = position;
  int count = position + 1;
  while(!array[count] == '\0'){
    if(array[count] < array[min_index]){
      min_index = count;
    }
    count++;
  }

  return min_index;
}

void swap(char& first, char& second){
  char temp = first;
  first = second;
  second = temp;
}

void string_sort(char array[]){
  int count = 0;
  while(!array[count] == '\0'){
    swap(array[count], array[minimum_form(array, count)]);
    count++;
  }
}

int main(){
  const int MAX = 80;
  char array[MAX];
  cout << "Type in a string:\n";
  cin.getline(array, MAX);
  string_sort(array);

  cout << "The sorted array is " << array << "\n";
=======
const int MAX = 80;

void string_sort(char array[]){
  
}

int main(){
  char array[MAX];
  cout << "Type in a string: \n";
  cin.getline(array, MAX);
  string_sort(array);
  cout << "The sorted string is " << array << "\n"
  
>>>>>>> 3fcd6881c963bdfe0ef7a46f469ea077ba19c842
  return 0;
}
