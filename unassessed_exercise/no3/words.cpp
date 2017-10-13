#include <iostream>
#include <cstring>
#include <cctype>

#include "words.h"

using namespace std;

void reverse(const char* str1, char* str2){
  int count = 0;
  for(int i = 0; str1[i] != '\0'; i++){
    count++;
  }
  
  int x = 0;
  for(int i = count-1; i >= 0; i--){

    str2[x] = str1[i];
    x++;
  }
  str2[count] = '\0';
}

int compare(const char* one, const char* two){
  if(strlen(one) == 0 && strlen(two) == 0){
    return 1;
  }

  if(strlen(one) == 0){
    return compare(one, two+1);
  }

  if(strlen(two) == 0){
    return compare(one+1, two);
  }

  int first = static_cast<int>(*one);
  int second = static_cast<int>(*two);

  // Converting all uppercase to lowercase characters
  if(first >= 65 && first <= 90){
    first+=32;
  }
  if(second >= 65 && second <= 90){
    second+=32;
  }

  // If other than alphabet, skip it
  if(!(first >= 97 && first <= 122)){
    return compare(one+1, two);
  }
  if(!(second >= 97 && second <= 122)){
    return compare(one, two+1);
  }

  if(first != second){
    return 0;
  }

  if(first == second){
    return compare(one+1, two+1);
  }
  
  return 1;
}

int palindrome(const char* sentence){
  char reversed[strlen(sentence)];
  reverse(sentence, reversed);
  return compare(sentence, reversed); 
}

void clean_string(char* string)
{
  for(int i = 0; i < strlen(string); i++){
    int chr = static_cast<int>(string[i]);
    // Converting lowercase to uppercase
    if(chr >= 65 && chr <= 90){
      chr += 32;
      string[i] =  static_cast<char>(chr);
    }
    // Remove anything other than alphabet
    else if(!( chr >= 97 && chr <= 122)){
      string[i] = ' ';
    }
  }
}

int minimum(char* string, int start){
  int position = start;
  for(int i = start + 1; i < strlen(string); i++){
    if(string[i] > string[position]){
      position = i;
    }
  }
  swap(string[start], string[position]);
    return position;
}

int anagram(const char* str1, const char* str2){
  char string1[strlen(str1)];
  char string2[strlen(str2)];
  strcpy(string1, str1);
  strcpy(string2, str2);
  
  clean_string(string1);
  clean_string(string2);

  for(int i=0; i<strlen(str1); i++){
    minimum(string1, i);
  }

  for(int i=0; i<strlen(str2); i++){
    minimum(string2, i);
  }

  if(compare(string1, string2)){
    return 1;
  }

  return 0;
}
