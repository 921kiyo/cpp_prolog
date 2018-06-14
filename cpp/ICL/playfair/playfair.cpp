#include <iostream>
#include <cctype>
#include <cstring>
#include "playfair.h"

using namespace std;

void prepare(const char* input, char* output){
  // Cpy alphanum characters
  int counter = 0;
  for(int i = 0; input[i] != '\0'; i++){
    if(isalnum(input[i])){
      output[counter] = toupper(input[i]);
      counter++;
    }
  }
  // Check if number of character is odd
  if(counter % 2 == 1){
    output[counter] = 'X';
    counter++;
  }
  output[counter] = '\0';
}

void grid(const char* codeword, char square[][SQ_SIZE]){
  int code_length = strlen(codeword);
  int counter = 0;
  char letter = 'A';
  int foo = letter;
  cout << foo << endl;
  for(int row = 0; row < 6; row++){
    for(int column = 0; column < 6; column++){
      if(counter < code_length){
        while(occurs_before(codeword, codeword[counter], counter)){
          counter++;
        }
        square[row][column] = codeword[counter];
        counter++;

      }else{
        while(occurs_before(codeword, letter, counter)){
          letter++;
          if(letter == 91){
            letter = '0';
          }
        }
        square[row][column] = letter;
        letter++;
        if(letter == 91){
          letter = '0';
        }
      }
    }
  }
}

bool occurs_before(const char str[], char letter, int pos){
  for(int i = 0; i < pos ;i++){
    if(str[i] == letter){
      return true;
    }
  }
  return false;
}

void bigram(char square[][SQ_SIZE], char inchar1, char inchar2, char& outchar1, char& outchar2){
  int inchar1_row, inchar1_column,inchar2_row, inchar2_column;
  find_position(square, inchar1, inchar1_row, inchar1_column);
  find_position(square, inchar2, inchar2_row, inchar2_column);
  if(inchar1_row == -1 || inchar2_row == -1){
    cerr << "Could not find input char in the square" << endl;
    return;
  }

  outchar1 = square[inchar1_row][inchar2_column];
  outchar2 = square[inchar2_row][inchar1_column];
}

void find_position(char square[][SQ_SIZE], char inchar, int& inchar_row, int& inchar_column){
  for(int row = 0; row < SQ_SIZE; row++){
    for(int column = 0; column < SQ_SIZE; column++){
      if(square[row][column] == inchar){
        inchar_row = row;
        inchar_column = column;
        return;
      }
    }
  }
  inchar_row = -1;
  inchar_column = -1;
}

void encode(char square[][SQ_SIZE], const char* prepared, char* encoded){
  if(*prepared == '\0'){
    return;
  }
  char inchar1 = *prepared;
  prepared++;
  char inchar2 = *prepared;
  prepared++;
  char out1, out2;
  bigram(square, inchar1, inchar2, out1, out2);
  *encoded = out1;
  encoded++;
  *encoded = out2;
  encoded++;
  encode(square, prepared, encoded);
}

void decode(char square[][SQ_SIZE], const char* encoded, char* decoded){

  if(*encoded == '\0'){
    encoded--;
    if(islower(*encoded)){
      encoded = '\0';
    }
    return;
  }
  char inchar1 = *encoded;
  encoded++;
  char inchar2 = *encoded;
  encoded++;
  // Getting two letters of the original message
  char out1, out2;
  bigram(square, inchar1, inchar2, out1, out2);
  *decoded = out1;
  decoded++;
  *decoded = out2;
  decoded++;

  decode(square, encoded, decoded);
}
