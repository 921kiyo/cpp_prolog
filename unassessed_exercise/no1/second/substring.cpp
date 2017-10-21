#include <iostream>
#include <cstring>
#include "substring.h"

using namespace std;


int substring_position( const char* first, const char* second){
  if(strlen(first) == 0){
    return 0;
  }

  if(strlen(second) == 0){
    return -1;
  }
  if(!is_prefix(first, second)){

    cout << second << endl;
    int no_error = substring_position(first, second+ 1);
    cout << "no error " << no_error << endl;
    if(no_error >=0){
      return no_error+1;
    }
  }
  else if(is_prefix(first, second)){
    return 0;
  }

}

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
