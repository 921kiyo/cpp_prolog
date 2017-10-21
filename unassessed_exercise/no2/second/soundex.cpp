#include <iostream>
#include <cctype>
#include <cstring>
#include "soundex.h"

using namespace std;

void encode(const char* surname, char* soundex){
  soundex[0] = toupper(surname[0]);

  int soundex_length = 1;
  char encode;
  for(int i = 1; surname[i] != '\0'; i++){
    encode = encode_table(surname[i]);

    if(encode == encode_table(surname[i-1])){
        continue;
    }
    else if(encode >= '1' && encode <= '6' && soundex_length <= 3){
      soundex[soundex_length] = encode;
      soundex_length++;
    }
  }


  for(; soundex_length<=3; soundex_length++){
    soundex[soundex_length] = '0';
  }
  if(soundex_length == 4){
    soundex[soundex_length] = '\0';
  }

}

int compare(const char* one, const char* two){
  if(*one == '\0' && *two == '\0'){
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
  char surnameSoundex[5];
  char sentenceSoundex[5];
  char surnames[80];
  char* tok;
  int counter = 0;
  strcpy(surnames, sentence);
  encode(surname, surnameSoundex);

  for(tok = strtok(surnames, ", ."); tok != NULL; tok = strtok(NULL, ", .")){
    encode(tok, sentenceSoundex);
    if(compare(surnameSoundex, sentenceSoundex)){
      counter++;
    }
  }
  return counter;
}

char encode_table(char letter){
  switch(letter){
    case 'b':
    case 'f':
    case 'p':
    case 'v':
    return '1'; break;

    case 'c':
    case 'g':
    case 'j':
    case 'k':
    case 'q':
    case 's':
    case 'x':
    case 'z':
    return '2'; break;

    case 'd':
    case 't':
    return '3'; break;

    case 'l':
    return '4'; break;

    case 'm':
    case 'n':
    return '5'; break;

    case 'r':
    return '6'; break;

    default:
    return '9';
  }
}
