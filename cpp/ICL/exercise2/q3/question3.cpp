#include <iostream>

using namespace std;

int main(){
  char character, new_char;
  int number;
  cout << "Type a charactetr\n";
  cin >> character;
  number = character;

  if(97 <= number || number <= 122){
    number = number - 32;
    new_char = char(number);
    cout << "The upper case character corresponding to " << character << " is " << new_char << "\n";
  }

  else if(65 <= number || number <= 90){
    number = number + 32;
    new_char = char(number);
    cout << "The lower case character corresponding to " << character << " is " << new_char << "\n";
  }

  

  
  return 0;
}
