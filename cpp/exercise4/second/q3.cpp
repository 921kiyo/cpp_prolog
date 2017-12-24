#include <iostream>
#include <fstream>
using namespace std;

int main(){
  ifstream in_stream;
  in_stream.open("WithoutComments.cpp");
  int counter = 0;
  char character;

  in_stream.get(character);
  while(!in_stream.eof()){
    counter++;
    in_stream.get(character);
  }

  for(int i = counter; i > 0 ; i--){
    cout << 
  }

  cout << "total is " << counter << endl;
  in_stream.close();
  return 0;
}
