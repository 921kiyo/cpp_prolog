#include <iostream>
#include <cstring>

using namespace std;

void reverse(const char* str1, char* str2){
  int count = 0;
  for(int i = 0; str1[i] != '\0'; i++){
    count++;
  }

  int x = 0;
  for(int i = count; i == 0; i--){
    str2[x] = str1[i];
    x++;
  }
}

int compare(char* one, char* two){
  
}

int palindrome(char* sentence){
  
}

int anagram(char* str1, char* str2){
  
}

void string_sort(){
}
