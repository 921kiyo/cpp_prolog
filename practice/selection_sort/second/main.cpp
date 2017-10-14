#include <iostream>
#include <cstring>

using namespace std;


const int MAX = 80;

void swap(char &letter1, char &letter2){
  char temp = letter1;
  letter1 = letter2;
  letter2 = temp;
}

int minimum_index(char str[], int position){
  int start = position + 1;
  int min_index = position;
  while(str[start] != '\0'){
    if(str[start] < str[min_index]){
      min_index = start;
    }
    start++;
  }
  return min_index;
}

void string_sort(char str[]){
  int i = 0;
  while(str[i] != '\0'){
    swap(str[i], str[minimum_index(str, i)]);
    i++;
  }
}

int main(){
  char str[MAX];
  cout << "Type in a string: " << endl;
  cin.getline(str, MAX);
  cout << str;
  cout << "\n";
  string_sort(str);
  cout << "The sorted string is: " << str << "\n";
  return 0;
}
