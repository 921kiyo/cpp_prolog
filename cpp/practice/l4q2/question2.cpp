#include <iostream>
#include <fstream>

using namespace std;

int main(){
  ifstream in_stream;
  ofstream out_stream;

  const int False = 0;
  const int True = 1;
  int is_comment = False;

  
  char character, next_character;
  /* Here is a comment */
  cout << "Testing: " << 16/2 << " = " << 4*2 << ".\n\n";

  in_stream.open("question2.cpp");
  out_stream.open("WithoutComments.cpp");
  in_stream.get(character);
  while(!in_stream.eof()){
    if(is_comment == False && character == '/'){
      in_stream.get(next_character);
      if(next_character == '*'){
	is_comment = True;
      }
      else{
	in_stream.putback(next_character);
      } 
    }
    
    if(is_comment == True && character == '*'){
      in_stream.get(next_character);
      if(next_character == '/'){
	is_comment = False;
	in_stream.get(character);
      }
    }

    if(is_comment == False){
      out_stream.put(character);
      cout << character;
    }
    in_stream.get(character);


  }

  in_stream.close();
  out_stream.close();
  return 0;
}

/* Here is a comment 2 */
