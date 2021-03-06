#include <iostream>
#include <cstring>
#include "braille.h"

using namespace std;

int encode_character(char ch, char* braille){
    strcpy(braille, "");
    int braille_size = 6;
    char character = ch;
    if(ispunct(ch)){
        encode_punctuation(ch, braille);
    }
    else{
        if(isdigit(ch)){
            braille_size += 6;
            strcat(braille,"..0000");
            character = convert_num_to_alpha(ch);

        }
        if(isupper(ch)){
            braille_size += 6;
            strcat(braille,".....0");
            character = tolower(ch);
        }
        encode_alphabet(character, braille);
    }
    return braille_size;
}

char* encode(const char* plaintext, char* braille){
  if(*plaintext == '\0'){
    return braille;
  }
  else{
    int length = encode_character(*plaintext, braille);
    return encode((plaintext+1), (braille+length));
  }
}


void print_braille(const char* plaintext, ostream& output){
  char braille[512];
  braille[0] = '\0';

  encode(plaintext, braille);
  output << plaintext << endl;

  int length = strlen(braille);

  cout << endl;

  for(int i = 0; i< length; i++){
    if(i%3 == 0){
      cout << braille[i];
    }
  }

  cout << endl;
  for(int i = 0; i< length; i++){
    if( i > 0 && (i-1)%3 == 0){
      cout << braille[i];
    }
  }

  cout << endl;

  for(int i = 0; i< length; i++){
    if(i>0 && (i+1)%3 == 0){
      cout << braille[i];
    }
  }
  cout << endl;

  //int text_length = strlen(plaintext);
  for(int i = 0; plaintext[i] != '\0'; i++){
    if(isupper(plaintext[i]) || isdigit(plaintext[i])){
      cout << "  ";
    }
    cout << plaintext[i] << " ";
  }
  cout << endl;

}

void encode_punctuation(char letter, char* braille){
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
    }
}

char convert_num_to_alpha(const char num){
    switch(num){
        case '1': return 'a';
        break;
        case '2': return 'b';
        break;
        case '3': return 'c';
        break;
        case '4': return 'd';
        break;
        case '5': return 'e';
        break;
        case '6': return 'f';
        break;
        case '7': return 'g';
        break;
        case '8': return 'h';
        break;
        case '9': return 'i';
        break;
        default: return num;
    }
}

void encode_alphabet(const char letter, char* braille){
    switch(letter){
        case 'a': strcat(braille, "0.....");
        break;
        case 'b': strcat(braille, "00....");
        break;
        case 'c': strcat(braille, "0..0..");
        break;
        case 'd': strcat(braille, "0..00.");
        break;
        case 'e': strcat(braille, "0...0.");
        break;
        case 'f': strcat(braille, "00.0..");
        break;
        case 'g': strcat(braille, "00.00.");
        break;
        case 'h': strcat(braille, "00..0.");
        break;
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
