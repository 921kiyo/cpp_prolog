#include <iostream>
#include <cstring>


#include "correct.h"

using namespace std;

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

  char d[4];
  char partial_decoded[8];

  // Clean decoded
  strcpy(decoded, "");


  for(int i = 0; data[i] != '/0'; i++){

    int counter = 1;
    while(counter%4 == 0){
      d[counter] = data[counter];
      cout << "dss " << d[counter] << endl;
      counter++;
    }
    d[counter] = '\0';

  }


  create_error_corrected_data(d,partial_decoded);
  cout << "partial_decoded " << partial_decoded << endl;

  strcat(decoded, partial_decoded);
}

char* create_error_corrected_data(char* d,char* decoded){
  char c1,c2,c3;
  c1 = parity(d[0], d[1], d[3]);
  c2 = parity(d[0], d[2], d[3]);
  c3 = parity(d[1], d[2], d[3]);
  cout << "c2 " << c2 << endl;
  cout << "c3 " << c3 << endl;

  cout << "d " << d << endl;

  decoded[0] = c1;
  decoded[1] = c2;
  decoded[2] = d[0];
  decoded[3] = c3;
  decoded[4] = d[1];
  decoded[5] = d[2];
  decoded[6] = d[3];
  decoded[7] = '\0';

  cout << "decoded " << decoded << endl;

}

char parity(char first, char second, char third){
  int total = first + second + third;
  if(total%2 == 0){
    return '0';
  }
  else{
    return '1';
  }
}
