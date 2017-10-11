#include <iostream>
#include <cstring>
#include "soundex.h"

using namespace std;


char* encode(const char* surname, char* soundex){
  soundex[0] = surname[0];
  int i = 1;
  while(soundex[i] != '\0'){
    soundex[i] = encode_translate(surname, i);
    i++;
  }
  return soundex;
}

char encode_translate(const char* surname, int num){
  char letter = surname[num];
  if(letter == 'b' || letter == 'f' || letter == 'p' || letter == 'v'){
    return '1';
  }
  else if(letter == 'c' || letter == 'g' || letter == 'j' || letter == 'k' || letter == 'q' || letter == 's' || letter == 'x' || letter == 'z'){
    return '2';
  }
  else if(letter == 'd' || letter == 't'){
    return '3';
  }
  else if(letter == 'l'){
    return '4';
  }
  else if(letter == 'm' || letter == 'n'){
    return '5';
  }
  else if(letter == 'r'){
    return '6';
  }
  else{
    return encode_translate(surname, num+1);
  }
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

/*
int count(const char surname[], const char sentence){
  
}

*/
