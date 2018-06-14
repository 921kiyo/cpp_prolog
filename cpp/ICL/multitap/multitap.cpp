#include "multitap.h"

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int encode_character(char ch, char* multitap){
  int size = 0;
  int digit, dd;
  strcpy(multitap, "");
  if(ch == ' '){
    apply_multitap(multitap, 0,1);
  }
  if(ispunct(ch)){
    if(ch == '.'){
      apply_multitap(multitap, 1, 1);
    }
    else if(ch == ','){
      apply_multitap(multitap, 1, 2);
    }
    else if(ch == '!'){
      apply_multitap(multitap, 1, 3);
    }
    else if(ch == '?'){
      apply_multitap(multitap, 1, 4);
    }
  }

  if(isdigit(ch)){
    strcat(multitap, "*");
    digit = ch - '0';
    apply_multitap(multitap, digit, 1);
  }
  int times;

  if(isalpha(ch)){

    ch = tolower(ch);

    if(ch < 's'){
      dd = ch - 'a';
      // cout << "dd " << dd << endl;
      digit = dd / 3 + 2;
      times = dd % 3 + 1;
      // cout << "digit2 " << digit << endl;
      // cout << "times " << times << endl;
      apply_multitap(multitap, digit, times);
    }
    if(ch == 's'){
      apply_multitap(multitap, 7, 4);
    }
    if(ch == 't' || ch == 'u' || ch == 'v'){
      digit = ch - 'a' + 2;
      times = digit % 3 + 1;
      apply_multitap(multitap, 8, times);
    }

    if(ch == 'w' || ch == 'x' || ch == 'y' || ch == 'z'){
      digit = ch - 't' + 1;
      times = digit % 4 + 1;
      apply_multitap(multitap, 9, times);
    }
  }
  size = strlen(multitap);
  return size;
}

void apply_multitap(char* multitap, int digit, int times){
  char digit_char = digit + '0';
  int length = strlen(multitap);
  for(int i = 0; i < times; i++){
    multitap[length] = digit_char;
    length ++;
  }
  multitap[length] = '\0';
}

void encode(const char* plaintext, char* multitap){
  strcpy(multitap, "");
  char mul[10];
  bool is_upper = false;
  int length;
  char last_char;
  for(int i = 0; plaintext[i] != '\0'; i++){
    cout << plaintext[i] << endl;
    if(is_upper && islower(plaintext[i])){
      strcat(multitap, "#");
    }
    if(!is_upper && isupper(plaintext[i])){
      strcat(multitap, "#");
    }
    encode_character(plaintext[i], mul);

    if(isupper(plaintext[i])){
      is_upper = true;
    }
    if(islower(plaintext[i])){
      is_upper = false;
    }
    if(last_char == mul[0]){
      strcat(multitap, "|");
    }

    length = strlen(mul);
    last_char = mul[length-1];
    strcat(multitap, mul);
  }
}
