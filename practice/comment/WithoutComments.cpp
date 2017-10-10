#include<iostream>
#include<fstream>

using namespace std;

int main(){
  bool is_comment = false;
  char character, next_character;
  / COMMENT HERE 
  cout << "Testing: " << 16/2 << " = " << 4 << ".\n\n";

  ifstream in_stream;
  ofstream out_stream;
  in_stream.open("main.cpp");
  out_stream.open("WithoutComments.cpp");

  in_stream.get(character);
  while(!in_stream.eof()){
    cout << character;

    if(is_comment == false && character == '/'){
      in_stream.get(next_character);
      if(next_character == '){
	is_comment = true;
      }
      else{
	in_stream.putback(next_character);
      }
    }

    if(is_comment = true && character == '){
      in_stream.get(next_character);
      if(next_character == '/'){
	is_comment = false;
	in_stream.get(character);
      }
    }

    if(is_comment == false){
      out_stream.put(character);
    }
    
    in_stream.get(character);

  }

  in_stream.close();
  out_stream.close();
  
  return 0;
}
