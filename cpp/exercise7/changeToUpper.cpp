#include <iostream>

using namespace std;

const int MAX_LENGTH = 80;

void ChangeToUpperCase(char* phrase);

int LowerCase(char character);

void ChangeToUpperCase(char& character);


int main(){
  char a_string[MAX_LENGTH];

  cout << "Enter string (maximum length " << MAX_LENGTH - 1 << " characters): " << endl;
  cin.getline(a_string, MAX_LENGTH);

  ChangeToUpperCase(a_string);
  cout << a_string << endl;
  return 0;
}

void ChangeToUpperCase(char phrase[]){
  int index = 0;
  while(phrase[index] != '\0'){
    if(LowerCase(phrase[index])){
      ChangeToUpperCase(phrase[index]);
    }
    index++;
  }
}

int LowerCase(char character){
  return (character >= 'a' && character <= 'z');
}

void ChangeToUpperCase(char& character){
  character += 'A' - 'a';
}
