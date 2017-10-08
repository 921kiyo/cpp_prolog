#include <iostream>
#include <fstream>

using namespace std;

int main(){

  ifstream in_stream;

  char character;
  int counter = 0;

  in_stream.open("question3.cpp");
  in_stream.get(character);
  while(!in_stream.eof()){
    counter ++;
    in_stream.get(character);
  }
  in_stream.close();
  cout << "The number of character is " << counter << "\n";
  return 0;
}
