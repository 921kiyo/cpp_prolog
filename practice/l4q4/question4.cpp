#include <iostream>
#include <fstream>

using namespace std;

int count(){
  ifstream in_stream;
  char character;
  int counter = 0;
  in_stream.open("question4.cpp");
  in_stream.get(character);
  while(!in_stream.eof()){
    in_stream.get(character);
    counter++;
  }
  in_stream.close();
  return counter;
}

char string_position(int position){
  ifstream in_stream;
  char character;
  in_stream.open("question4.cpp");
  in_stream.get(character);
  for(int i = 0; i<position; i++){
    in_stream.get(character);
  }
  return character;
}

int main(){
  int counter;
  counter = count();

  for(int i = counter; i>0; i--){
    cout << string_position(i);
  }
  
  return 0; 
}
