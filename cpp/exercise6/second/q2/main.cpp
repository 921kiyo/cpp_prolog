#include <iostream>

using namespace std;

void swap(char& x, char& y){
  char temp = x;
  x = y;
  y = temp;
}

int minimum_form(const char* word, int position){
  int min_index = position;
  for(int i = position+1; word[i] != '\0'; i++){
    if(word[min_index] > word[i]){
      min_index = i;
    }
  }
  return min_index;
}

void string_sort(char* word){
  for(int i = 0; word[i] != '\0'; i++){
    swap(word[i], word[minimum_form(word, i)]);
  }
}

int main(){
  char word[80];
  // char sorted[80];
  cout << "Type in a string: " << endl;
  cin.getline(word, 80);
  string_sort(word);
  cout << "The sorted string is: " << word << endl;
  return 0;
}
