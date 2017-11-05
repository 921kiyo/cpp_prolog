#include <iostream>
#include <cstring>

using namespace std;


bool is_appeared(int position, char letter, char sentence[]){
  for(int i = 0; i<position; i++){
    if(sentence[i] == letter){
      return true;
    }
  }
  return false;
}

void shift_back(char sentence[], int position){
  //for(int i = position; i< strlen(sentence); i++){
  int start = position;
  while(sentence[start] != '\0'){
    sentence[start] = sentence[start+1];
    start++;
  }
  //  sentence[i] = sentence[i+1];
    //}
}

// change to * later
void no_repetition(char* sentence){
  int start = strlen(sentence);
  for(int i = start; i>0; i--){
    if(is_appeared(i, sentence[i], sentence)){
      shift_back(sentence, i);
    }
  }
}


int main(){
  const int MAX = 80;
  char sentence[MAX];
  cout << "Type in a string: ";
  cin.getline(sentence, MAX);

  no_repetition(sentence);

  cout << "The string without repetition is: " << sentence << endl;
}
