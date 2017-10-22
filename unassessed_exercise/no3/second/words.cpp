#include <iostream>
#include <cstring>
#include "words.h"

using namespace std;

void reverse(const char* str1, char* str2){
  int length = strlen(str1);
  str2[length] = '\0';
  int i = 0;

  while(str1[i] != '\0'){
      length--;
      str2[i] = str1[length];
      i++;
  }
}

int compare(const char* one, const char* two){
  char o = tolower(*one);
  char t = tolower(*two);

  if(strlen(one) == 0 && strlen(two)){
    return 1;
  }

  if(strlen(one) == 0){
    return compare(one, two+1);
  }

  if(strlen(two) == 0){
    return compare(one+1, two);
  }

  if(o == '\0' && t == '\0'){
    return 1;
  }

  if(!isalpha(o) && !isalpha(t)){
    one++;
    two++;
    return compare(one, two);
  }

  else if(!isalpha(o) && isalpha(t)){
    one++;
    return compare(one, two);
  }

  else if(isalpha(o) && !isalpha(t)){
    two++;
    return compare(one, two);
  }

  if(o == t){
    one++;
    two++;
    return compare(one, two);
  }
  if(o != t){
    return 0;
  }
  return 1;
}

int palindrome(const char* sentence){
  char reverseSentence[80];
  reverse(sentence, reverseSentence);
  if(compare(sentence, reverseSentence)){
    return 1;
  }
  else{
    return 0;
  }
}

int anagram(const char* str1, const char* str2){
  char string1[strlen(str1)];
  char string2[strlen(str2)];
  stringSort(str1, string1);
  stringSort(str2, string2);
  
  return compare(string1, string2);
}

// sorting
void stringSort(const char* string, char* sortedString){
  strcpy(sortedString, string);
  int length = strlen(sortedString);
  for(int i = 0; sortedString[i] != '\0'; i++){
    sortedString[i] = tolower(sortedString[i]);
  }
  for(int i = 0; i < length; i++){
    swap(sortedString[i], sortedString[minimum(sortedString, i, length)]);
  }
}

int minimum(char* string, int position, int length){
  int min_index = position;
  for(int i = position +1; i< length; i++){
    if(string[i] < string[min_index]){
      min_index = i;
    }
  }
  return min_index;
}

void swap(char& word1, char& word2){
  char temp;
  temp = word1;
  word1 = word2;
  word2 = temp;
}
