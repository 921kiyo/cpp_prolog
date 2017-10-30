#include <iostream>

using namespace std;


bool is_appeared(char letter, int position, char* strings){
  for(int i = 0; i< position; i++){
    if(strings[i] == letter){
      return true;
    }
  }
  return false;
}

// void shift(int position, char* strings){
//   int i = position;
//   while(strings[i] != '\0'){
//     strings[i] = strings[i+1];
//     i++;
//   }
//   // strings[i] = '\0';
// }

void no_repetitions(char* strings, char* no_rep){
  int i = 0;
  int x = 0;
  while(strings[i] != '\0'){
    if(!is_appeared(strings[i], i, strings)){
      no_rep[x] = strings[i];
      x++;
    }
    i++;
  }
}

int main(){
  const int MAX = 40;
  char strings[MAX];
  char no_repeat[MAX];
  cout << "Type in a string: " << endl;
  cin.getline(strings, MAX);
  cout << strings << endl;
  no_repetitions(strings, no_repeat);

  cout << "The string without repetitions is: " << endl;
  cout << no_repeat << endl;

  return 0;
}
