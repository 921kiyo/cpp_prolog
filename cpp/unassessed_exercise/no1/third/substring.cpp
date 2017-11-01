#include <iostream>
#include <cstring>
#include "substring.h"

using namespace std;

bool is_prefix(const char* first, const char* second){
  if(*first == '\0'){
    return true;
  }
  if(*first == *second){
    first++;
    second++;
    return is_prefix(first, second);
  }
  else{
    return false;
  }
}

int substring_position(const char* first, const char* second){
  if(strlen(first) == 0){
    return 0;
  }
  if(strlen(second) == 0){
    return -1;
  }
  if(!is_prefix(first, second)){
    second++;
    int no_error = substring_position(first, second);
    if(no_error >= 0){
      return no_error + 1;
    }
  }
  else{
    return 0  ;
  }

  return 1;
}
