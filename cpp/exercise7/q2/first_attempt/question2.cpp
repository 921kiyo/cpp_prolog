#include <iostream>

using namespace std;


bool check_argument(char first, char second);

bool pointer_arithmetic(char first, char second);


int main(){
  char first, second;
  cout << "Type the first string\n";
  cin >> first;
  cout << "Type the second string\n";
  cin >> second;

  /*
  if(check_argument(first, second)){
    cout << "The first string is alphabetically smaller than its second string argument\n";
  }
  else{
    cout << "The first string is alphabetically bigger than or equal to its second string argument\n";
  }
  */

  if(pointer_arithmetic(first, second)){
    cout << "The first string is alphabetically smaller than its second string argument\n";
  }
  else{
    cout << "The first string is alphabetically bigger than or equal to its second string argument\n";
  }

  return 0; 
}

bool check_argument(char first, char second){
  int a, b;
  a = first;
  b = second;
  return (a < b);
}

bool pointer_arithmetic(char first, char second){
  return (first < second);
}
