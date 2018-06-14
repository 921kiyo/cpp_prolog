#include <iostream>
#include <fstream>

using namespace std;


int count_character(char letter){
    ifstream in_stream;
    char character;
    int counter = 0;

    in_stream.open("main.cpp");
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

int main(){
  cout.setf(ios::left);
  cout.width(10);
  cout << "Character";
  cout.width(10);
  cout << "Occurrences";
  cout << "\n";
  for(char character = 'a'; character <= 'z'; character++){
   
    cout.width(10);
    cout << character;
    cout.width(10);
    cout << count_character(character) << "\n";
  }
  
  return 0;
}
