#include "playfair.h"

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void prepare(const char* input, char* output){
  int input_length = strlen(input);
  strcpy(output, "");
  int counter = 0;
  for(int i = 0; i < input_length; i++){
    if(isalnum(input[i])){
      output[counter] = toupper(input[i]);
      counter++;
    }
  }
  if(counter%2 == 1){
    output[counter] = 'X';
    counter++;
    output[input_length+1] = '\0';
  }else{
    output[input_length] = '\0';
  }
}

void grid(const char* codeword, char square[][6]){
  // check if codeword only contains uppercase letters and digits
  if(!is_codeword_valid(codeword)){
    cerr << "codeword is not valid" << endl;
  }
  char temp[36];
  remove_dup(codeword, temp);
  int temp_length = strlen(temp);
  int codeword_length = strlen(codeword);
  int temp_counter = 0;
  char alpha = 'A';
  char number = '0';
  for(int row = 0; row < 6; row++){
    for(int col = 0; col < 6; col++){
      if(temp_counter < temp_length){
        square[row][col] = temp[temp_counter];
        temp_counter++;
      }else if(alpha <= 'Z'){
        while(appear_before(codeword, alpha, codeword_length)){
          alpha++;
        }
        square[row][col] = alpha;
        alpha++;
      }else{
        while(appear_before(codeword, number, codeword_length)){
          number++;
        }
        square[row][col] = number;
        number++;
      }
    }
  }
}

void remove_dup(const char* codeword, char* temp){
  int counter = 0;
  for(int i = 0; codeword[i] != '\0'; i++){
    if(!appear_before(codeword, codeword[i], i)){
      temp[counter] = codeword[i];
      counter++;
    }
  }
}

bool appear_before(const char* codeword, char letter, int position){
  for(int i = 0; i < position; i++){
    if(letter == codeword[i]){
      return true;
    }
  }
  return false;
}

bool is_codeword_valid(const char* codeword){
  for(int i = 0; codeword[i] != '\0'; i++){
    if(isalnum(codeword[i]) && isupper(codeword[i])){
      continue;
    }else{
      return false;
    }
  }
  return true;
}

void bigram(char square[][6], char inchar1, char inchar2, char& outchar1, char& outchar2){
  int inchar1_row, inchar1_col, inchar2_row, inchar2_col;
  get_position(square, inchar1, inchar1_row, inchar1_col);
  get_position(square, inchar2, inchar2_row, inchar2_col);

  if(inchar1_row == -1 || inchar2_row == -1){
    cerr << "inchar not found on square" << endl;
    return;
  }

  outchar1 = square[inchar1_row][inchar2_col];
  outchar2 = square[inchar2_row][inchar1_col];
}

void get_position(char square[][6], char inchar, int& row, int& col){
  for(int r = 0; r < 6; r++){
    for(int c = 0; c < 6; c++){
      if(square[r][c] == inchar){
        row=r;
        col=c;
        return;
      }
    }
  }
  row=-1;
  col=-1;
}

void encode(char square[][6], const char* prepared, char* encoded){
  strcpy(encoded, "");
  encode_recursive(square, prepared, encoded);

}

void encode_recursive(char square[][6], const char* prepared, char* encoded){
  if(*prepared == '\0'){
    *encoded = '\0';
    return;
  }
  char inchar1 = *prepared;
  prepared++;
  char inchar2 = *prepared;
  prepared++;
  char outchar1, outchar2;
  bigram(square, inchar1, inchar2, outchar1, outchar2);
  *encoded = outchar1;
  encoded++;
  *encoded = outchar2;
  encoded++;
  return encode_recursive(square, prepared, encoded);
}

void decode(char square[][6], const char* prepared, char* decoded){
  strcpy(decoded, "");
  encode_recursive(square, prepared, decoded);
  int length = strlen(decoded);
  if(decoded[length-1] == 'X'){
    decoded[length-1] = '\0';
  }
}
