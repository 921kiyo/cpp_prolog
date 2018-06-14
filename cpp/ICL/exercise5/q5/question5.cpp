#include <iostream>
#include <fstream>

using namespace std;

int count_character(char letter);

int main(){
  char character;
  int counter;
  cout.setf(ios::left);
  cout.width(20);
  cout << "Character";
  cout.width(20);
  cout << "Occurences";
  cout << "\n\n";
  //int counter, b;
  
  for(character = 'a'; character <= 'z'; character++){
    counter = count_character(character);
    cout.width(20);
    cout << character;
    cout.width(20);
    cout << counter;
    cout << "\n";
  }
  
}

int count_character(char letter){
  ifstream in_stream;
  char character;
  int counter = 0;
  in_stream.open("question5.cpp");
  in_stream.get(character);

  while(!in_stream.eof()){
    if(character == letter){
      counter++;
    }
    in_stream.get(character);
  }
  in_stream.close();
  return counter;
}
