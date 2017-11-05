#include <iostream>
#include <cstring>

using namespace std;

bool is_appeared(char array[], char letter, int position){
  for(int i = 0; i< position; i++){
    if(array[i] == letter){
      return true;
    }
  }
  return false;
}

void position_back(char array[], int position){
  int count = position;
  while(array[count] != '\0'){
    array[count] = array[count+1];
    count++;
  }
}

void no_repetitions(char array[]){
  for(int i=strlen(array); i> 0; i--){
    if(is_appeared(array,array[i], i)){
      position_back(array, i);
    }
    
  }
}

int main(){
  const int MAX = 80;
  char array[MAX];
  cout << "Type in a string: \n";
  cin.getline(array, MAX);
  no_repetitions(array);
  cout << "The string without repetitions is: " << array << "\n";
  return 0;
}
