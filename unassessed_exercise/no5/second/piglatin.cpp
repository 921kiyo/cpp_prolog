#include <iostream>
#include <cstring>
#include <fstream>
#include "piglatin.h"

using namespace std;

int findFirstVowel(const char* word){
  int last_position = strlen(word) -1;

  for(int i = 0; word[i] != '\0'; i++){
    if(isVowel(word[i])){
      return i;
    }
    else if((i != 0 && i != last_position) && word[i] == 'y'){
      return i;
    }
  }
  return -1;
}

void translateWord(const char* english, char* piglatin){
  // First clean piglatin
  int piglatin_length = strlen(piglatin);
  for(int i = 0; i< piglatin_length; i++){
    piglatin[i] = 0;
  }
  int vowel_position = findFirstVowel(english);
  // If the word begins with vowel, add 'way' to it
  if( vowel_position == 0){
    strcpy(piglatin, english);
    strcat(piglatin, "way");
  }
  // If the word begins with a digit, leave it as is
  else if(isdigit(english[0])){
    strcpy(piglatin, english);
  }
  // If there is a vowel somewhere other than the first letter,
  else if(vowel_position != -1){
    bool is_upper = false;
    if(isupper(english[0])){
      is_upper = true;
    }

    int english_length = strlen(english);
    int piglatin_index = 0;
    for(int i = vowel_position; i< english_length; i++){
        if(piglatin_index == 0 && is_upper){
          piglatin[piglatin_index] = toupper(english[i]);
        }else{
          piglatin[piglatin_index] = english[i];
        }
        piglatin_index++;
    }
    // Take the first half of the letters and append it
    for(int i = 0; i<vowel_position; i++){
      if(i == 0 && is_upper){
        piglatin[piglatin_index] = tolower(english[i]);
      }
      else{
        piglatin[piglatin_index] = english[i];
      }
      piglatin_index++;
    }
    strcat(piglatin, "ay");
  }
  else{
    strcpy(piglatin, english);
    strcat(piglatin, "ay");
  }
}

void translateStream(ifstream& inputStream, ostream& outputStream){

  char word[64];
  char translated[64];
  char punc;
  bool punct = false;

  // Get word by word
  while(inputStream >> word){

    if(ispunct(word[strlen(word)-1])){
      punct = true;
      punc = word[strlen(word)-1];
      cout << "punc " << punc << endl;

      // Replace the punctuation with \0
      word[strlen(word) - 1] = '\0';
    }

    if (ispunct(word[0])){
      punc = word[0];
      // Move all the letters by one letter
      for(int i = 1; i < strlen(word) -1; i++){
        word[i-1] = word[i];
      }
      word[strlen(word)-1] = '\0';
      outputStream << punc;
    }
    // cout << "word " << word << endl;
    translateWord(word, translated);

    if(punct){
      int len = strlen(translated);
      translated[len] = punc;
      translated[len+1] = '\0';
      punct = false;
    }

    outputStream << translated;

    if(inputStream.peek() == '\n'){
      outputStream << '\n';
    }else{
      outputStream << " ";
    }
  }

}

bool isVowel(char letter){
  switch(letter){
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    return true;
    break;
    default:
    return false;
  }
}
