#include "piglatin.h"

#include <iostream>
#include <fstream>
#include <ostream>
#include <cstring>

using namespace std;

int findFirstVowel(const char* word){
  int length = strlen(word);
  for(int i = 0; word[i] != '\0'; i++){
    if(isVowel(word[i], i, length)){
      return i;
    }
  }
  return -1;
}

bool isVowel(char letter, int position, int length){
  switch(letter){
    case('a'): return true; break;
    case('e'): return true; break;
    case('i'): return true; break;
    case('o'): return true; break;
    case('u'): return true; break;
  }

  if(position != 0 && position != length -1 && letter == 'y'){
    return true;
  }

  return false;
}

void translateWord(const char* english, char* piglatin){
  strcpy(piglatin, "");
  int length = strlen(english);
  char first_half[80];
  char second_half[80];
  bool begin_vowel = false;
  char first_letter;
  if(isupper(english[0])){
    first_letter = tolower(english[0]);
    begin_vowel = true;
  }else{
    first_letter = english[0];
  }
  // Check if the word begins with a vowel
  if(isVowel(first_letter, 0, length)){
    strcpy(piglatin, english);
    strcat(piglatin, "way");
  }
  // If no vowel
  int vowel_position = findFirstVowel(english);
  if(vowel_position == -1){
    strcpy(piglatin, english);
    strcat(piglatin, "ay");
  }
  if(vowel_position > 0){
    getFirstHalf(english, vowel_position, first_half, begin_vowel);
    getSecondHalf(english, vowel_position, second_half, begin_vowel);
    strcpy(piglatin, second_half);
    strcat(piglatin, first_half);
    strcat(piglatin, "ay");
  }
}

void getFirstHalf(const char* english, int position, char* first_half, bool begin_vowel){
  int i = 0;
  while(i < position){
    if(i == 0 && begin_vowel){
      first_half[i] = tolower(english[i]);
    }else{
      first_half[i] = english[i];
    }
    i++;
  }
  first_half[i] = '\0';
}

void getSecondHalf(const char* english, int position, char* second_half, bool begin_vowel){
  int counter = 0;
  int i = position;
  while(english[i] != '\0'){
    if(i == position && begin_vowel){
        second_half[counter] = toupper(english[i]);
    }else{
      second_half[counter] = english[i];
    }
    i++;
    counter++;
  }
  second_half[counter] = '\0';
}

void translateStream(istream& inputStream, ostream& outputStream){
  char word[64];
  char translated[64];
  char punc;
  bool is_punc = false;
  while(inputStream >> word){
      if(ispunct(word[strlen(word)-1])){
        is_punc = true;
        punc = word[strlen(word)-1];
        word[strlen(word)-1] = '\0';
      }

      if(ispunct(word[0])){
        punc = word[0];
      }
  }

  // inputStream.get(character);
  // while(inputStream >> word){
  //   cout << word << endl;
  // }
  inputStream >> word;
  // cout << word << endl;
  translateWord(word, piglatin);
  outputStream << piglatin << " ";
  return translateStream(inputStream, outputStream);
}
