#include <iostream>

using namespace std;

const int MAX = 80;

bool alpha_smaller(char first[], char second[]){
  int i = 0;
  while(first[i] != '\0' && second[i] != '\0'){
    if(first[i] < second[i]){
      return true;
    }
    else if(first[i] > second[i]){
      return false;
    }
    i++;
  }
  if(first[i] == '\0' && second[i] != '\0'){
    return true;
  }else{
    return false;
  }
  
}

bool alpha_smaller2(char* first, char* second){
  while(*first != '\0' && *second != '\0'){
    if(*first < *second){
      return true;
    }
    else if(*first > *second){
      return false;
    }
    first++;
    second++;
  }
  if(*first == '\0' && *second != '\0'){
    return true;
  }else{
    return false;
  }
  
}


int main(){
  char first[MAX];
  char second[MAX];
  cout << "The first string argument: \n";
  cin.getline(first, MAX);
  cout << "The second string argument: \n";
  cin.getline(second, MAX);

  cout << "The first string is ";
  if(!alpha_smaller(first, second)){
    cout << "NOT";
  }
  cout << " alphabetically smaller than the second string.\n";

  cout << "----------------------\n";
  cout << "With the pointer arithmetic, the first string is ";
  if(!alpha_smaller2(first, second)){
    cout << "NOT";
  }
  cout << " alphabetically smaller than the second string.\n";

  return 0;
}
