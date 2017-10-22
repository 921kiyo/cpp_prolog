#include <iostream>
#include <cstring>
#include "braille.h"

using namespace std;

int encode_character(char ch, char* braille){
  // int i = 0;
  // while(braille[i] != '\0'){
  //   braille[i] = 0;
  //   i++;
  // }
  strcpy(braille, "");

  int size = 6;

  if(isupper(ch)){
    size += 6;
    strcat(braille, ".....0");
    encode_table(tolower(ch), braille);
  }
  else if(isdigit(ch)){
    size += 6;
    strcat(braille, "..0000");
    encode_table(ch, braille);
  }
  else{
    encode_table(ch, braille);
  }
  return size;
}

void encode(const char* plaintext, char* braille){
  if(*plaintext == '\0'){
    return ;
  }
  else{
    int length = encode_character(*plaintext, braille);
    return encode(plaintext+1, braille+length);
  }
}

void print_braille(const char* plaintext, ostream& output){
  char braille[512];
  encode(plaintext, braille);

  int length = strlen(braille);

  for(int i = 0; i < length; i++){
      if(i%3== 0){
        cout << braille[i];
      }
  }
  cout << endl;

  for(int i = 0; i < length; i++){
      if(i>0 && i%3== 1){
        cout << braille[i];
      }
  }
  cout << endl;

  for(int i = 0; i < length; i++){
      if(i>0 && i%3== 2){
        cout << braille[i];
      }
  }
  cout << endl;

  int text_length = strlen(plaintext);
  for(int i = 0; i<text_length; i++){
    if(isupper(plaintext[i]) || isdigit(plaintext[i])){
      cout << "  ";
    }
    cout << plaintext[i] << " ";
  }
  cout << endl;
}

void encode_table(const char letter, char* braille){
    switch(letter){
        case '.': strcat(braille, ".0..00");
        break;
        case ',': strcat(braille, ".0....");
        break;
        case ';': strcat(braille, ".00...");
        break;
        case '-': strcat(braille, "..0..0");
        break;
        case '!': strcat(braille, ".00.0.");
        break;
        case '?': strcat(braille, ".00..0");
        break;
        case '(':
        case ')': strcat(braille, ".0..00");
        break;
        case '1':
        case 'a': strcat(braille, "0.....");
        break;
        case '2':
        case 'b': strcat(braille, "00....");
        break;
        case '3':
        case 'c': strcat(braille, "0..0..");
        break;
        case '4':
        case 'd': strcat(braille, "0..00.");
        break;
        case '5':
        case 'e': strcat(braille, "0...0.");
        break;
        case '6':
        case 'f': strcat(braille, "00.0..");
        break;
        case '7':
        case 'g': strcat(braille, "00.00.");
        break;
        case '8':
        case 'h': strcat(braille, "00..0.");
        break;
        case '9':
        case 'i': strcat(braille, ".0.0..");
        break;
        case 'j': strcat(braille, ".0.00.");
        break;
        case 'k': strcat(braille, "0.0...");
        break;
        case 'l': strcat(braille, "000...");
        break;
        case 'm': strcat(braille, "0.00..");
        break;
        case 'n': strcat(braille, "0.000.");
        break;
        case 'o': strcat(braille, "0.0.0.");
        break;
        case 'p': strcat(braille, "0000..");
        break;
        case 'q': strcat(braille, "00000.");
        break;
        case 'r': strcat(braille, "000.0.");
        break;
        case 's': strcat(braille, ".000..");
        break;
        case 't': strcat(braille, ".0000.");
        break;
        case 'u': strcat(braille, "0.0..0");
        break;
        case 'v': strcat(braille, "000..0");
        break;
        case 'w': strcat(braille, ".0.000");
        break;
        case 'x': strcat(braille, "0.00.0");
        break;
        case 'y': strcat(braille, "0.0000");
        break;
        case 'z': strcat(braille, "0.0.00");
    }
}
