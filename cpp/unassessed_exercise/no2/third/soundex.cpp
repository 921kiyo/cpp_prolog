#include "soundex.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;


void encode(const char* surname, char* soundex){
  soundex[0] = surname[0];
  int soundex_int = 1;
  int encode_int;
  int length = strlen(surname);
  for(int i = 1; i < length; i++){
    if(!is_vowel(surname[i])){
      encode_int = convert(surname[i]);
      if(soundex[soundex_int-1] != encode_int && encode_int > 0){
        soundex[soundex_int] = encode_int;
        soundex_int++;
      }
    }
    if(soundex_int == 4){
      soundex[soundex_int] = '\0';
      break;
    }
  }
  // cout << soundex_int << endl;
  if(soundex_int < 4){
    for(int i = soundex_int; i < 4; i++){
      soundex[soundex_int] = '0';
      soundex_int++;
    }
  }
}

int compare(const char* one, const char* two){
  int one_length = strlen(one);
  int two_length = strlen(two);
  if(one_length != two_length){
    return 0;
  }
  if(one_length == 0 || two_length == 0){
    return 1;
  }
  if(*one == *two){
    one++;
    two++;
    return compare(one, two);
  }
  else{
    return 0;
  }

}


int count(const char* surname, const char* sentence){
  char soundex[5];
  encode(surname, soundex);
  char soundex2[5];

  char surnames[80];
  strcpy(surnames, sentence);
  int counter = 0;
  for(char* tok = strtok(surnames, ", ."); tok != NULL; tok = strtok(NULL, ", .")){
    cout << "tok " << tok << endl;
    encode(tok, soundex2);
    if(compare(soundex, soundex2)){
      counter++;
    }
  }
  return counter;
}

bool is_vowel(char letter){
  switch(letter){
    case('a'):
    case('e'):
    case('i'):
    case('o'):
    case('u'):
    case('w'):
    case('y'):
      return true; break;
  }
  return false;
}

char convert(char letter){
  switch(letter){
    case('b'):
    case('f'):
    case('p'):
    case('v'):
      return '1'; break;
    case('c'):
    case('g'):
    case('j'):
    case('k'):
    case('q'):
    case('s'):
    case('x'):
    case('z'):
      return '2'; break;
    case('d'):
    case('t'):
      return '3'; break;
    case('l'):
      return '4'; break;
    case('m'):
    case('n'):
      return '5'; break;
    case('r'):
      return '6'; break;
  }
}
