#include <iostream>

using namespace std;


bool check_smaller(const char string1[], const char string2[]){
  int count = 0;
  while(string1[count] != '\0' && string2[count] != '\0'){
    if(string1[count] <= string2[count]){
      return true;
    }
    else if (string1[count] <= string2[count]){
      return false;
    }
    count++;
  }
  
}

int main(){
  cout << check_smaller("hello", "helloa") << "\n";
  cout << check_smaller("hello", "hello") << "\n";
  cout << check_smaller("apple", "bear") << "\n";
  cout << check_smaller("www", "ddd") << "\n";
  cout << check_smaller("w", "ddd") << "\n";
  return 0;
}
