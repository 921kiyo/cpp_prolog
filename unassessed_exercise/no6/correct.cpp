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

void text_to_binary(const char* str, char* binary){
  char res[100];
  if(*str == '\0'){
    strcat(binary, "\0");
    return;
  }
  ascii_to_binary(*str, res);
  cout << *str << endl;
  cout << res << endl;
  strcat(binary, res);
  cout << binary << endl;
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

char* add_error_correction(const char* data, char* decoded){
  while(data* != '\0'){
    if(){
      
    }
  }
  get_check_digit


}
