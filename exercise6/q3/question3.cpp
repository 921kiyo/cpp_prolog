#include <iostream>

using namespace std;

const int MAX = 80;

void no_repetitions(char input[]);

bool is_appeared_before(char input[], char character, int stop);


void remove_char(char input[], int i);

int main(){
  char input[MAX];

  cout << "Type in a string: " << "\n";

  cin.getline(input, MAX);

  no_repetitions(input);
  
  return 0; 
}


void no_repetitions(char input[]){
  for(int i = 0; i< MAX; i++){
    if(is_appeared_before(input, input[i], i)){
      remove_char(input, i);
    } 
  }
  cout << "The string without repetitions is " << input << "\n";
}

bool is_appeared_before(char input[], char character, int stop){
  bool is_appeared = false;
  for(int i = 0; i<stop; i++){
    if(input[i] == character){
      is_appeared = true;
    }
  }
  return is_appeared;
}

void remove_char(char input[], int position){
  int i = position;
  while(input[i] != '\0'){
    input[i] = input[i+1];
    i++;
  }

}

