#include <iostream>
#include "bubble.h"

using namespace std;
  
int main(){
  char sentence[MAX];
  cout << "Type in a string: \n";
  cin.getline(sentence, MAX);

  bubble_sort(sentence);

  cout << "The sorted string with bubble sort is: " << sentence << endl;
  return 0;
}
