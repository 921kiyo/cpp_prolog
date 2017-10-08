#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(){
  char character;
  ifstream in_stream;
  ofstream out_stream;
  in_stream.open("question1.cpp");

  if(in_stream.fail()){
    cout << "Unsuccessful\n";
    exit(1);
  } 
  
  while(!in_stream.eof()){
    cout << character;
    in_stream.get(character);
    
  }
  in_stream.close();
  return 0;
}
