#include <iostream>
#include <cctype>
#include "soundex.h"

using namespace std;

void encode(const char* surname, char* soundex){
  soundex[0] = toupper(surname[0]);
  
  int length_count = 1;
  
  for(int counter = 1; surname[counter] != '\0'; counter++){
    if(encode_table(surname[counter]) >= '1' && encode_table(surname[counter]) <= '6'){
      if(counter>1 && encode_table(surname[counter]) == encode_table(surname[counter-1])){
	continue;
      }
      else if(length_count < 4){
	soundex[length_count] = encode_table(surname[counter]);
	length_count++;
      }
    }
  }
  for(int i = length_count; i< 4; i++){
    soundex[i] = '0';
  }
  soundex[4] = '\0';
}

int compare(const char one[], const char two[]){
  int counter = 0;
  if(one[counter] == '\0' && two[counter] == '\0'){
    return 1;
  }
  else if(one[counter] != two[counter]){
    return 0;
  }
  else{
    counter++; 
    return compare(one + 1, two + 1);
  }
}

int count(const char surname[],  const char sentence[]){
  char soundex[5];

  char* word;
  int counter = 0;
  for(int i = 0; sentence[i] != '\0'; i++){
    word[i] = sentence[i];
  }
  return 1;
}


char encode_table(const char letter){
  switch(letter){
  case 'b':
  case 'f':
  case 'p':
  case 'v':
    return '1';
    break;
  case 'c':
  case 'g':
  case 'j':
  case 'k':
  case 'q':
  case 's':
  case 'x':
  case 'z':
    return '2';
    break;
  case 'd':
  case 't':
    return '3';
    break;
  case 'l':
    return '4';
    break;
  case 'm':
  case 'n':
    return '5';
    break;
  case 'r':
    return '6';
    break;
  default:
    return '9';
    break;
  }
}


