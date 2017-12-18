#include "words.h"
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void reverse(const char* str1, char* str2){
  int length = strlen(str1);
  int counter = 0;
  for(int i = length-1; i >= 0; i--){
    str2[counter] = str1[i];
    counter++;
  }
  str2[counter] = '\0';
}



int compare(const char* one, const char* two){
  if(*one == '\0' && *two == '\0'){
    return 1;
  }
  char one_char;
  one_char = tolower(*one);
  if(!isalpha(one_char)){
    one++;
    return compare(one, two);
  }

  char two_char;
  two_char = tolower(*two);

  if(!isalpha(two_char)){
    two++;
    return compare(one, two);
  }

  if(one_char == two_char){
    one++;
    two++;
    return compare(one, two);
  }else{
    return 0;
  }

}

int palindrome(const char* sentence){
  char sentence_rev[512];
  reverse(sentence, sentence_rev);
  if(compare(sentence, sentence_rev)){
    return 1;
  }
  return 0;
}

void make_lower(char* sentence){
  int counter = 0;
  for(int i = 0; sentence[i] != '\0'; i++){
      sentence[counter] = toupper(sentence[i]);
      counter++;
  }
  sentence[counter] = '\0';
}

int anagram(const char* str1, const char* str2){
  char sentence1[512];
  strcpy(sentence1, str1);
  make_lower(sentence1);
  selection_sort(sentence1);

  char sentence2[512];
  strcpy(sentence2, str2);
  make_lower(sentence2);
  selection_sort(sentence2);
  if(compare(sentence1, sentence2)){
      return 1;
  }
  else{
    return 0;
  }
}

void selection_sort(char* a){
   int length = strlen(a);
  for(int i = 0; i < length; i++){
    swap(a[i], a[min_form(a, i, length)]);
  }
}

int min_form(char* a, int position, int length){
  int min_index = position;
  for(int count = position+1; count < length; count++){
    if(a[count] < a[min_index]){
      min_index = count;
    }
  }
  return min_index;
}

void swap(int& first, int& second){
  int temp = first;
  first = second;
  second = temp;
}
