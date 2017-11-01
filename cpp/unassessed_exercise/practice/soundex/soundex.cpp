#include <iostream>
#include <cstring>
#include <cctype>

#include "soundex.h"

using namespace std;

void encode(const char* surname, char* soundex){
  soundex[0] = toupper(surname[0]); // Get the first letter
  
  int soundex_counter = 1;
  char letter;
  for(int i = 1; surname[i] != '\0'; i++){
    letter = encode_table(surname[i]);
    if(letter >='1' && letter <= '6'){ // if valid encode
      if(i > 1 && soundex[soundex_counter - 1] == letter){ // and no adjacent letters
        continue;
      }
      else if(soundex_counter < 4){
        soundex[soundex_counter] = letter; // then add the encode
        soundex_counter++;
      }
    }
  }

  for(int i = soundex_counter; i< 4; i++){
    soundex[i] = '0';
  }
  soundex[4] = '\0';
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
  
// int count(const char* surname, const char* sentence){
//   char surnames[80], soundex1[5], soundex2[5];
//   char* words;
//   encode(surname, soundex1);
//   strcpy(surnames, sentence);
//   words = strtok(surnames, ", .");

//   int count = 0;
//   int length = strlen(words);
//   for(int i = 0; i< length; i++){
//     encode(words[i], soundex2);
//     if(compare(soundex1, soundex2)){
//       count++;
//     }
//   }
//   return count;
// }

int count(const char* surname, const char* sentence) {
  
    char surnames[80], soundex1[5], soundex2[5];
    char *tok;
  
    int surname_count = 0;
  
    strcpy(surnames,sentence);
    encode(surname, soundex1);
    char *words = strtok(surnames, ", .");
    cout << "HELLO " << words << endl;
    
    for (tok = strtok(surnames, ", ."); tok != NULL; tok = strtok(NULL, ", .")) {
      cout << "\n";
      cout << "tok " << tok << endl;
      encode(tok, soundex2);
  
      if (compare(soundex1, soundex2))
        surname_count++;
    }
  return surname_count;
}

char encode_table(char letter){
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
    default:
      return '9';
  }
}
