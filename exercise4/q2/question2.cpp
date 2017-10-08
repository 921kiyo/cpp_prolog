#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

/* This part should not be shown 111 */

int main(){
  bool is_inside = false;
  
  cout << "Testing: " << 16/2 << " = " << 4*2 << ".\n\n";
  char character;
  char next_char;
  ifstream in_stream;
  ofstream out_stream;

  in_stream.open("question2.cpp");
  out_stream.open("WithoutComments.cpp");
  
  in_stream.get(character);
  while(!in_stream.eof()){

    /* Checking if we are inside of a comment or not */
    if(is_inside == false && character == '/'){
      in_stream.get(next_char);
      if(next_char == '*'){
	is_inside = true;
      }
      else{
	in_stream.putback(next_char);
      }
    }

    /* Checking if we are finishing the comment */
    if(is_inside == true && character == '*'){
      in_stream.get(next_char);
      if(next_char == '/'){
	is_inside = false;
	in_stream.get(character);
      }
    }

    if(is_inside == false){
      out_stream.put(character);
      cout << character;
    }

    in_stream.get(character);
  }

  out_stream.close();
  in_stream.close();
  return 0;
}

/* This part should not be shown too 222 */
