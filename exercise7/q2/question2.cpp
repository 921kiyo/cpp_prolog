#include <iostream>

using namespace std;


const int MAX = 80;

enum Logical {False, True};

Logical smaller_than(char first_string[], char second_string[]){
  int count = 0;
  while(first_string[count] != '\0' && second_string[count] != '\0'){
    if(first_string[count] < second_string[count]){
      return True;
    }
    else{
      return False;
    }
  }

  if(first_string[count] == '\0' && second_string[count]){
    return True;
  }
  else{
    return False;
  }
  count++;
}

int main(){
  char first_string[MAX], second_string[MAX];

  cout << "Type the first string\n";
  cin >> first_string;
  cout << "\n";
  cout << "Type the second string\n";
  cin >> second_string;

  if(smaler_than(first_string, second_string)){
    cout << "The first string is smaller than the second one\n";
  }
  else{
    cout << "The first string is NOT smaller than the second one\n";
  }
  
  return 0;
}
