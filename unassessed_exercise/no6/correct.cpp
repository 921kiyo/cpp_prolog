#include <iostream>
#include <cstring>
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

void text_to_binary(char* str, char* binary){
  char res[10];
  if(*str == '\0'){
    return;
  }
  ascii_to_binary(*str, res);
  strcat(binary, res);
  str++;
  binary++;
  text_to_binary(str, binary);
}

void binary_to_text(char* binary, char* str){
  char temp[10];
  if(*str == '\0'){
    return;
  }
  for(int i = 0; i < 8; i++){
    temp[i] = binary[i];
    cout << binary[i] << endl;
  }
  temp[8] = '\0';
  //
  // cout << temp << endl;
  //
  // strcat(binary_to_ascii())

}
