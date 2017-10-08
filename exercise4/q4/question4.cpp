#include <iostream>
#include <fstream>

using namespace std;

int count_file();
char get_character(int number);

int main(){

  int counter;

  counter = count_file();
  cout << counter << "\n";

  for(int num = counter; num > 0; num--){
    //cout << num;
    cout << get_character(num);
     }
  return 0;
}


int count_file(){
  ifstream in_stream;
  char character;
  int counter = 0;

  in_stream.open("question4.cpp");

  in_stream.get(character);
  while(!in_stream.eof()){
    counter++;
    in_stream.get(character);
  }

  in_stream.close();

  return counter;
}

char get_character(int number){
  char ch;
  ifstream in_stream;
  in_stream.open("question4.cpp");
  //in_stream.get(ch);

  for(int v=0; v<number; v++){
    //cout << v << "\n";
    in_stream.get(ch);
  }

  in_stream.close();
  return ch;
}
