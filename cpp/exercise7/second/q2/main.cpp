#include <iostream>

using namespace std;

bool is_smaller(const char* string1, const char* string2){
  if(string1[0] < string2[0]){
    return true;
  }

  if(string1[0] > string2[0]){
    return false;
  }

  if(string1[0] == string2[0]){
    string1++;
    string2++;
    return is_smaller(string1, string2);
  }
  return true;
}

int main(){
  char string1[80];
  char string2[80];
  cout << "Type the first string" << endl;
  cin >> string1;
  cout << "Type the second string" << endl;
  cin >> string2;
  if(is_smaller(string1, string2)){
    cout << "The first string is smaller " << endl;
  }
  else{
    cout << "The first string is NOT smaller" << endl;
  }
  return 0;
}
