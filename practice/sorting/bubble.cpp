#include <iostream>
#include <cstring>

#include "bubble.h"

using namespace std;

void swap(char &letter1, char &letter2){
  
  letter1 ^= letter2;
  letter2 ^= letter1;
  letter1 ^= letter2;
}

bool is_greater(char letter1, char letter2){
  return (letter1 > letter2);
}

void bubble_sort(char sentence[]){
  int length = strlen(sentence);

  for(int i = length; i>0; i--){
    for(int x = 0; x< i-1; x++){
      if(is_greater(sentence[x], sentence[x+1])){
	swap(sentence[x], sentence[x+1]);
      }
    }
  }

}
