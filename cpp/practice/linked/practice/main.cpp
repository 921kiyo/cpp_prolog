#include <iostream>
#include <cstdlib>
#include <cstring>
#include "list.h"

using namespace std;

int main(){
  Node_ptr new_list = NULL;
  assign_list(new_list);

  cout << "THE LIST IS NOW: " << "\n";
  print_list(new_list);

  char a_word[MAX], word_after[MAX];

  cout << "After which word would you like to add an extra word?: ";
  cin >> word_after;
  cout << "\n";
  cout << "Which word would you like to add? ";
  cin >> a_word;
  add_after(new_list, a_word, word_after);
  return 0;
}
