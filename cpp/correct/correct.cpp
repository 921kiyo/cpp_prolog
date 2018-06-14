#include <iostream>
#include <cstring>
using namespace std;

#include "correct.h"
/* You are supplied with two helper functions */

/* converts a character into a binary string representation */
void ascii_to_binary(char ch, char *binary);

/* converts a binary string representation into a character */
char binary_to_ascii(char *binary);

void ascii_to_binary(char ch, char *binary) {
  for (int n = 128; n; n >>= 1)
    *binary++ = (ch & n) ? '1' : '0';
  *binary = '\0';
}

char binary_to_ascii(char *binary) {
  int ch = 0;
  for (int n=0, slide=128; n<8; n++, slide >>= 1) {
    if (binary[n] == '1')
      ch = ch | slide;
  }
  return ch;
}

/* now add your own functions here */

void text_to_binary(const char* str, char* binary){
  strcpy(binary, "");
  recursive(str, binary);
}

void recursive(const char* str, char* binary){
  if(*str == '\0'){
    return;
  }
  char temp[10];
  ascii_to_binary(*str, temp);
  strcat(binary, temp);
  str++;
  return recursive(str, binary);
}

void binary_to_text(const char* binary, char* text){
  strcpy(text, "");
  recursive2(binary, text);
}

void recursive2(const char* binary, char* text){
  if(*binary == '\0'){
    *text = '\0';
    return;
  }
  char temp[9];
  for(int i = 0; i < 8; i++){
    temp[i] = *binary;
    binary++;
  }
  temp[9] = '\0';
  char letter = binary_to_ascii(temp);
  *text = letter;
  text++;
  return recursive2(binary, text);
}

void add_error_correction(const char* data, char* corrected){
  strcpy(corrected, "");
  recursive3(data, corrected);
}

void recursive3(const char* data, char* corrected){
  if(*data == '\0'){
    *corrected = '\0';
    return;
  }
  char c_1, c_2, c_3;
  char d_1, d_2, d_3, d_4;

  d_1 = *data;
  data++;
  d_2 = *data;
  data++;
  d_3 = *data;
  data++;
  d_4 = *data;
  data++;

  c_1 = parity(d_1, d_2, d_4);
  c_2 = parity(d_1, d_3, d_4);
  c_3 = parity(d_2, d_3, d_4);

  *corrected = c_1;
  corrected++;
  *corrected = c_2;
  corrected++;
  *corrected = d_1;
  corrected++;
  *corrected = c_3;
  corrected++;
  *corrected = d_2;
  corrected++;
  *corrected = d_3;
  corrected++;
  *corrected = d_4;
  corrected++;

  return recursive3(data, corrected);
}

char parity(char a, char b, char c, char d){
  int a_int = a - '0';
  int b_int = b - '0';
  int c_int = c - '0';
  int d_int = d - '0';
  if((a_int + b_int + c_int + d_int) % 2 == 0){
    return '0';
  }else{
    return '1';
  }
}

int decode(char* received, char* decoded){
  int errors = 0;
  strcpy(decoded, "");
  recursive4(received, decoded, errors);
  return errors;
}

void recursive4(char* received, char* decoded, int& errors){
  if(*received == '\0'){
    *decoded = '\0';
    return;
  }
  char b_1 = *received;
  received++;
  char b_2 = *received;
  received++;
  char b_3 = *received;
  received++;
  char b_4 = *received;
  received++;
  char b_5 = *received;
  received++;
  char b_6 = *received;
  received++;
  char b_7 = *received;
  received++;
  // cout << "b_1: " << b_1 << " ";
  // cout << "b_2: " << b_2 << " ";
  // cout << "b_3: " << b_3 << " ";
  // cout << "b_4: " << b_4 << " ";
  // cout << "b_5: " << b_5 << " ";
  // cout << "b_6: " << b_6 << " ";
  // cout << "b_7: " << b_7 << " ";
  char p_1, p_2, p_3;
  p_1 = parity(b_4, b_5, b_6, b_7);
  p_2 = parity(b_2, b_3, b_6, b_7);
  p_3 = parity(b_1, b_3, b_5, b_7);
  // cout << "p_1 " << p_1 << endl;
  // cout << "p_2 " << p_2 << endl;
  // cout << "p_3 " << p_3 << endl;

  int p_1_int = p_1 - '0';
  int p_2_int = p_2 - '0';
  int p_3_int = p_3 - '0';
  int error_counter = p_1_int + p_2_int + p_3_int;
  if(error_counter > 0){
    errors++;
  }
  char total[4];
  total[0] = p_1;
  total[1] = p_2;
  total[2] = p_3;
  total[3] = '\0';
  int decimal = get_decimal(total);
  // cout << "decimal " << decimal << endl;
  if(decimal > 0){
    switch(decimal){
      case(1): flip(b_1); break;
      case(2): flip(b_2); break;
      case(3): flip(b_3); break;
      case(4): flip(b_4); break;
      case(5): flip(b_5); break;
      case(6): flip(b_6); break;
      case(7): flip(b_7); break;
    }
  }

  *decoded = b_3;
  decoded++;
  *decoded = b_5;
  decoded++;
  *decoded = b_6;
  decoded++;
  *decoded = b_7;
  decoded++;

  return recursive4(received,decoded,errors);

}

void flip(char& binary){
  (binary == '1')? binary = '0': binary = '1';
}

int get_decimal(char* binary){
  int total = 0;
  if(binary[0] == '1'){
    total += 2*2;
  }
  if(binary[1] == '1'){
    total += 2;
  }
  if(binary[2] == '1'){
    total += 1;
  }

  return total;
}
