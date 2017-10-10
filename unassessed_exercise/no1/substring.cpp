#include <iostream>

using namespace std;


const int MAX = 80;

bool is_prefix(char first_string[], char second_string[]){
  if(strlen(first_string) == 0){
    return true;
  }
  else if(strlen(second_string) == 0 && strlen(first_string) > 0){
    return false;
  }
  while()
  if(first_string != second_string){
    return false;
  }
  if(is_prefix(first_string[]))
}

int substring_position(char first[], char second[], int position){
  int i = 0;
  while(second[i] != '\0'){
    if(first[count] == second[i]){
      if(is_prefix(first, second, i)){
	return i;
      }
      else{
	return -1;
      }
    }
    else{
      return -1;
    }
    i++;
  }
}
