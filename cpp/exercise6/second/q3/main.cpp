#include <iostream>

using namespace std;

bool appear_before(const char* sentence, int position, char letter){
  for(int i = 0; i < position; i++){
    if(sentence[i] == letter){
      return true;
    }
  }
  return false;
}

void no_repetitions(const char* sentence, char* sentence_no_rep){
  int j = 0;
  for(int i = 0; sentence[i] != '\0'; i++){
    if(appear_before(sentence, i, sentence[i])){
      continue;
    }else{
      sentence_no_rep[j] = sentence[i];
      j++;
    }
  }
  sentence_no_rep[j] = '\0';
}

int main(){
  char sentence[80], sentence_no_rep[80];
  cout << "Type in a string: " << endl;
  cin.getline(sentence, 80);
  no_repetitions(sentence, sentence_no_rep);
  cout << "The string without repetitions is: " << sentence_no_rep << endl;
  return 0;
}
