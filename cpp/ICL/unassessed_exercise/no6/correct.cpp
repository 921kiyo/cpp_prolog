#include <iostream>
#include <cstring>
#include <cmath>

#include "correct.h"

using namespace std;

/* You are supplied with two helper functions */

/* converts a character into a binary string representation */
void ascii_to_binary(char ch, char *binary);

/* converts a binary string representation into a character */
char binary_to_ascii(const char *binary);

void ascii_to_binary(char ch, char *binary) {
  for (int n = 128; n; n >>= 1)
    *binary++ = (ch & n) ? '1' : '0';
  *binary = '\0';
}

char binary_to_ascii(const char *binary) {
  int ch = 0;
  for (int n=0, slide=128; n<8; n++, slide >>= 1) {
    if (binary[n] == '1')
      ch = ch | slide;
  }
  return ch;
}

/* now add your own functions here */

void text_to_binary(const char* str, char* binary){
  char res[10];

  if(*str == '\0'){
    strcat(binary, "\0");
    return;
  }
  ascii_to_binary(*str, res);
  // cout << *str << endl;
  // cout << res << endl;
  strcat(binary, res);
  // cout << binary << endl;
  text_to_binary(str+1, binary);
}

void binary_to_text(const char* binary, char* str){
  if(*binary == '\0'){
    *str = '\0';
    return;
  }
  char temp[512];
  strcpy(temp, binary);
  temp[8] = '\0';

  *str = binary_to_ascii(temp);

  binary_to_text(binary+8, (str+1));

}

void add_error_correction(const char* data, char* decoded){
  *decoded = '\0';

  char d[5];
  char partial_decoded[8];

  if(*data == '\0'){
    return;
  }

  // Clean decoded
  // strcpy(decoded, "");

  for(int i = 0; i < 4; i++){
    // cout << "hehe " << *(data+i) << endl;
    d[i] = *(data+i);
    // cout << "SSS " <<   << endl;
  }
  d[4] = '\0';

  create_error_corrected_data(d,partial_decoded);
  strcat(decoded, partial_decoded);
  add_error_correction(data+4, decoded+7);
}


char* create_error_corrected_data(char* d,char* decoded){
  char c1,c2,c3;
  c1 = parity(d[0], d[1], d[3]);
  c2 = parity(d[0], d[2], d[3]);
  c3 = parity(d[1], d[2], d[3]);

  decoded[0] = c1;
  decoded[1] = c2;
  decoded[2] = d[0];
  decoded[3] = c3;
  decoded[4] = d[1];
  decoded[5] = d[2];
  decoded[6] = d[3];
  decoded[7] = '\0';

  return decoded;
}

char parity(char first, char second, char third, char fourth){
  int total = first + second + third + fourth;
  if(total%2 == 0){
    return '0';
  }
  else{
    return '1';
  }
}


int decode(const char* received, char* decoded){
  *decoded = '\0';

  char p1,p2,p3;
  char b[8];
  int error_counter = 0;

  char error_binary[4];

  for(int i =0; i<8; i++){
    b[i] = received[i];
  }

  p1 = parity(b[3], b[4], b[5], b[6]);
  p2 = parity(b[1], b[2], b[5], b[6]);
  p3 = parity(b[0], b[2], b[4], b[6]);


  if(p1=='0' && p2== '0' && p3=='0'){
    // no errors
    decoded[0] = b[2];
    decoded[1] = b[4];
    decoded[2] = b[5];
    decoded[3] = b[6];
    decoded[4] = '\0';
    return 0;
  }

  if(p1=='1'||p2=='1'||p3=='1'){
    // There is an error
    // decimal value of p1p2p3 is the position of the error
    error_binary[0] = p1;
    error_binary[1] = p2;
    error_binary[2] = p3;
    error_binary[3] = '\0';


    // Find the decimal value of the error
    int sub, decimal=0;
    int i = 2;
    int x = 0;
    for(; i >= 0; i--, x++ ){
      if(error_binary[i] == '1'){
        sub = pow(2.0, x);
        decimal += sub;
        error_counter++;
      }
    }
    // cout << "decimal " << decimal << endl;
    
    // cout << "before " << b << endl;

    // Flip
    if(b[decimal-1] == '0'){
      // cout << ""
      b[decimal-1] = '1';
    }
    else{
      b[decimal-1] = '0';
    }

    // The original data bit stream can be recovered as b3,b5,b6,b7
    decoded[0] = b[2];
    decoded[1] = b[4];
    decoded[2] = b[5];
    decoded[3] = b[6];
    decoded[4] = '\0';
  }
  return error_counter;
}
