#include <iostream>
#include <cstring>
#include <ostream>
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
  memset(piglatin, 0, strlen(piglatin)); // cleaning piglatin
  bool is_capital = isupper(english[0]);


  while(english != '\0'){
    int vowel_position = findFirstVowel(english);

    // if the first letter is a digit
    if(vowel_position == -1 && isdigit(english[0])){
      strcpy(piglatin, english);
      return;
    }
    // if the vowel is the first letter
    else if(vowel_position == 0 && !isdigit(english[0])){
      strcpy(piglatin, english);
      strcat(piglatin, "way");
      return;
    }
    // When a vowel is found anywhere other than the index 0
    else if(vowel_position > 0){
      move_character_before(english, piglatin, vowel_position, is_capital);
      return;
    }
    // When no vowel is found
    else{
      strcpy(piglatin, english);
      strcat(piglatin, "ay");

      return;
    }
    english++;
  }
}

void move_character_before(const char* english, char* piglatin, int position, bool is_capital){

  int x = 0;
  for(int i = position; english[i] != '\0'; i++){
    // if the first letter in english is upper case, make it lowercase
    if(x == 0 && is_capital){
      piglatin[x] = toupper(english[i]);
    }else{
      piglatin[x] = english[i];
    }
    x++;
  }

  for(int i = 0; i < position; i++){
    if(i == 0 && is_capital){
      piglatin[x] = tolower(english[i]);
    }
    else{
      piglatin[x] = english[i];
    }

    x++;
  }
  strcat(piglatin, "ay");
}

void translateStream(istream& inputStream, ostream& outputStream){
  char character;
  char word[64];
  char piglatin[64];
  inputStream.get(character);
  while(inputStream >> word){

    
    outputStream.put(character);
    // translateWord(character, piglatin);
    inputStream.get(character);
  }
  // inputStream >> outputStream;
}
