#include <iostream>
#include <cctype>

using namespace std;

int main(){
  // char character;
  // // int char_int;
  // cout << "Type a character" << endl;
  // cin >> character;
  // // char_int = character;
  // if(islower(character)){
  //   character = toupper(character);
  //   cout << "The upper case character corresponding is " << character << endl;
  // }
  // else if(isupper(character)){
  //   character = tolower(character);
  //   cout << "The lower case character corresponding is " << character << endl;
  // }
  // else{
  //   cout << character << " is not a letter" << endl;
  // }
  int number, posi;
  cout << "Type a number" << endl;
  cin >> number;
  cout << "positive power?" << endl;
  cin >> posi;
  int total = 1;
  for(int i = 0; i < posi; i++){
    total *= number;
  }

  cout << "result is " << total << endl;
  return 0;
}
