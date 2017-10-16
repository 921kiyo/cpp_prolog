#include <iostream>
#include <cstring>
#include <cctype>

#include "soundex.h"

using namespace std;

void encode(const char* surname, char* soundex){
  soundex[0] = toupper(surname[0]); // Get the first letter
  int i = 1;
  int soundex_counter = 1;
  char letter;
  while(surname[i] != '\0'){
    letter = encode_table(surname[i]);
    if(letter >=1 || letter <= 6){ // if valid encode
      if(surname[soundex_counter - 1] != letter){ // and no adjacent letters
        surname[soundex_counter] = surname[i]; // then add the encode
        soundex_counter++;
      }
    }
    i++;
  }
}

int compare(const char* one, const char* two){
  int count = 0;
  if(one[count] == '\0' && two[count] == '\0'){
    return 1;
  }
  if(one[count] == two[count]){
    count++;
    return compare(one+1,two+1);
  }
  else{
    return 0;
  }
}

int count(char* surname, char* sentence){
  return 1;
}

char encode_table(char letter){
  switch(letter){
    case 'b':
    case 'f':
    case 'p':
    case 'v':
      return 1;
      break;
    case 'c':
    case 'g':
    case 'j':
    case 'k':
    case 'q':
    case 's':
    case 'x':
    case 'z':
      return 2;
      break;
    case 'd':
    case 't':
      return 3;
      break;
    case 'l':
      return 4;
      break;
    case 'm':
    case 'n':
      return 5;
      break;
    default:
      return 9;
  }
}
