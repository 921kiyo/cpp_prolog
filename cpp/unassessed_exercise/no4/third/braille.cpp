#include "braille.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

int encode_character(char ch, char* braille){
  int length = 6;
  if(isdigit(ch)){
    strcpy(braille, "..0000");
    strcat(braille, encode_digit(ch));
    length += 6;
  }
  // Lower case
  if(isalpha(ch) && islower(ch)){
    strcpy(braille, encode_letter(ch));
  }

  // Upper case
  if(isalpha(ch) && isupper(ch)){
    strcpy(braille, ".....0");
    ch = tolower(ch);
    strcat(braille, encode_letter(ch));
    length += 6;
  }
  // Punctuation
  if(ispunct(ch)){
    strcpy(braille, encode_punct(ch));
  }
  return length;
}

void encode(const char* plaintext, char* braille){
  int position;
  char newbraille[12];
  if(*plaintext == '\0'){
    return;
  }

  position = encode_character(*plaintext, newbraille);
  strcat(braille, newbraille);
  plaintext++;
  return encode(plaintext, braille);
}

const char* encode_letter(char ch){
  switch(ch){
    case('a'): return "0....."; break;
    case('b'): return "00...."; break;
    case('c'): return "0..0.."; break;
    case('d'): return "0..00."; break;
    case('e'): return "0...0."; break;
    case('f'): return "00.0.."; break;
    case('g'): return "00.00."; break;
    case('h'): return "00..0."; break;
    case('i'): return ".0.0.."; break;
    case('j'): return ".0.00."; break;
    case('k'): return "0.0..."; break;
    case('l'): return "000..."; break;
    case('m'): return "0.00.."; break;
    case('n'): return "0....."; break;
    case('o'): return "0.0.0."; break;
    case('p'): return "0000.."; break;
    case('q'): return "00000."; break;
    case('r'): return "000.0."; break;
    case('s'): return ".000.."; break;
    case('t'): return ".0000."; break;
    case('u'): return "0.0..0"; break;
    case('v'): return "000..0"; break;
    case('w'): return ".0.000"; break;
    case('x'): return "0.00.0"; break;
    case('y'): return "0.0000"; break;
    case('z'): return "0.0.00"; break;
  }
}

const char* encode_digit(char ch){
  switch(ch){
    case('1'): return "0....."; break;
    case('2'): return "00...."; break;
    case('3'): return "0..0.."; break;
    case('4'): return "0..00."; break;
    case('5'): return "0...0."; break;
    case('6'): return "00.0.."; break;
    case('7'): return "00.00."; break;
    case('8'): return "00..0."; break;
    case('9'): return ".0.0.."; break;
    case('0'): return ".0.00."; break;
  }
}


const char* encode_punct(char ch){
  switch(ch){
    case('.'): return ".0..00"; break;
    case(','): return ".0...."; break;
    case(';'): return ".00..."; break;
    case('-'): return "..0..0"; break;
    case('!'): return ".00.0."; break;
    case('?'): return ".00..0"; break;
    case('('):
    case(')'): return ".00.00"; break;
  }
}

void print_braille(const char* plaintext, ostream& output){
  char braille[512];
  braille[0]='\0';
  encode(plaintext, braille);
  // cout << braille << endl;
  for(int i = 0; braille[i] != '\0'; i++){
    if(i == 0){
      cout << braille[i];
    }
    if(i > 0 && i%3 == 0){
      cout << braille[i];
    }
  }
  cout << endl;
  for(int i = 0; braille[i] != '\0'; i++){
    if(i > 0 && i%3 == 1){
      cout << braille[i];
    }
  }
  cout << endl;
  for(int i = 0; braille[i] != '\0'; i++){
    if(i > 0 && i%3 == 2){
      cout << braille[i];
    }
  }
  cout << endl;

  for(int i = 0; plaintext[i] != '\0'; i++){
    if(isupper(plaintext[i]) || isdigit(plaintext[i])){
      cout << "  ";
    }
    cout << plaintext[i] << " ";
  }
  cout << endl;
}
