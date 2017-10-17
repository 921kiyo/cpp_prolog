#include <iostream>
#include <cstring>
#include "piglatin.h"

using namespace std;

int findFirstVowel(const char* word){
  int length = strlen(word);
  for(int position =0; word[position] != '\0'; position++){
    if(check_vowels(word[position], position, length - 1)){
      return position;
    }
  }
  return -1;
}

bool check_vowels(char word, int position, int index){
  if(word == 'y' && (position == 0 || position == index)){
    return true;
  }
  switch(word){
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u': return true;
    break;
    default: return false;
  }
}

void translateWord(const char* english, char* piglatin){

  int length = strlen(english);
  while(english != '\0'){
    // Check if the word begins with a vowel
    if(findFirstVowel(english) == 0){
      strcpy(piglatin, english);
      strcat(piglatin, "way");
      break;
    }
    // When a vowel is found anywhere other than the index 0
    else if(findFirstVowel(english) > 0){
      break;
    }
    // When no vowel is found
    else{
      strcpy(piglatin, english);
      strcat(piglatin, "ay");
      break;
    }
    english++;
  }
}
