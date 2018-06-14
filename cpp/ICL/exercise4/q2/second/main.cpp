#include <iostream>
#include <fstream>

using namespace std;


int main(){
  cout << "Testing: " << 16/2 << " = " << 4*2 << ".\n\n";
  bool within_comment = false;
  /* Comment here */
  ifstream in_stream;
  ofstream out_stream;
  char character;
  char next_character;
  in_stream.open("main.cpp");
  out_stream.open("WithoutComment.cpp");
  in_stream.get(character);
  while(!in_stream.eof()){

    // Check if entering inside the comment
    if(character == '/'){
      in_stream.get(next_character);
      if(next_character == '*'){
        within_comment = true;
      }else{
        in_stream.putback(next_character);
      }
    }

    if(within_comment == false){
      cout << character;
      out_stream.put(character);
    }
    // Check if leaving from the comment
    if(within_comment == true && character == '*'){
      in_stream.get(next_character);
      if(next_character == '/'){
        within_comment = false;
      }else{
        in_stream.putback(next_character);
      }
    }


    in_stream.get(character);
  }
  /* Comment here as well */


  in_stream.close();
  out_stream.close();
  return 0;
}
