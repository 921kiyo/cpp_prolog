#include <iostream>
#include <fstream>
using namespace std;

int main(){
  cout << "Testing: " << 16/2 << " = " << 4*2 << ".\n\n";
  /* *** ///Comment here */
  ifstream in_stream;
  ofstream out_stream;
  char character;
  char next_char;
  bool is_comment = false;
  in_stream.open("q2.cpp");
  out_stream.open("WithoutComments.cpp");

  in_stream.get(character);
  while(!in_stream.eof()){
    if(character == '/'){
      in_stream.get(next_char);
      if(next_char == '*'){
        is_comment = true;
      }else{
        in_stream.putback(next_char);
      }

    }
    if(!is_comment){
      cout << character;
      out_stream.put(character);
    }


    if(is_comment && character == '*'){
      in_stream.get(next_char);
      if(next_char == '/'){
        is_comment = false;
      }else{
          in_stream.putback(next_char);
      }

    }

    in_stream.get(character);
  }
  in_stream.close();
  out_stream.close();
  /* Comment here */
  /* Comment here */
  return 0;
}
