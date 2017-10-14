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
  for(int i = start; i< strlen(str); i++){
    if(str[i] < str[min_index]){
      min_index = i;
    }
  }
  return min_index;
}

void string_sort(char str[]){
  for(int i = 0; i < strlen(str); i++){
    swap(str[i], str[minimum_index(str, i)]);
  }
}

int main(){
  char str[MAX];
  cout << "Type in a string: " << endl;
  cin >> str;
  cout << "\n";
  void string_sort(char str[]);
  cout << "The sorted string is: " << str << "/n";
  return 0;
}
