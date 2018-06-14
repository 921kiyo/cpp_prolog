#include <iostream>
#include <fstream>

using namespace std;

int count_word(){
  ifstream in_stream;
  int counter = 0;
  char character;
  in_stream.open("q4.cpp");
  in_stream.get(character);

  while(!in_stream.eof()){
    counter++;
    in_stream.get(character);
  }
  in_stream.close();

  return counter;
}

char get_word(int position){
  ifstream in_stream;
  char character;
  in_stream.open("q4.cpp");
  in_stream.get(character);
  for(int i = 0; i < position; i++){
    in_stream.get(character);
  }
  // while(position > counter){
  //   counter++;
  //   in_stream.get(character);
  // }
  in_stream.close();
  return character;
}

int main(){
  int count = count_word();
  for(int i = count; i >= 0 ; i--){
    cout << get_word(i);
  }
  return 0;
}
