#include <iostream>
#include <fstream>

using namespace std;

int count_letter(char character){
  ifstream in_stream;
  char c;
  int counter = 0;
  in_stream.open("q5.cpp");
  in_stream.get(c);
  while(!in_stream.eof()){
    if(character == c){
      counter++;
    }
    in_stream.get(c);
  }
  in_stream.close();

  return counter;
}

int main(){
  char character;
  cout << "CHARACTER";
  cout.width(20);
  cout << "OCCURANCES" << endl;
  for(int i = 'a'; i <= 'z'; i++){
    character = i;
    cout << character;
    cout.width(20);
    cout << count_letter(character);
    cout << endl;
  }

  return 0;
}
