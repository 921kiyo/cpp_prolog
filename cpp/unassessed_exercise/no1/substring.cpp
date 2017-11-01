#include <iostream>
#include <cstring>

using namespace std;


bool is_prefix(char first_string[], char second_string[]){
  //cout << "A" << strlen(first_string);
  if(strlen(first_string) == 0){
    return true;
  }
  else if(strlen(second_string) == 0 && strlen(first_string) > 0){
    return false;
  }

  if(is_prefix((first_string + 1),(second_string + 1))){
    return true;
  }
  else{
    for(int i = 0; first_string[i] != '\0'; i++ ){
      if(second_string[i] != first_string[i]){
	return false;
      }
    }
  }

}

int substring_position(char first[], char second[]){
  //cout << "AA" << first;
  //cout << "BB" << second + 1;
  if(strlen(first) == 0){
    return 0;
  }
  if(strlen(second) == 0){
    return -1;
  }

  else{
  
    for (int i = 0; second[i] != '\0'; i++){
      if(is_prefix(first, second+1)){
	return i;
      }
    }
  }
}
