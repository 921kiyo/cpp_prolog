#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;


struct Node;
typedef Node *Node_ptr;

const int MAX = 80;

struct Node{
  char word[MAX];
  Node_ptr ptr_next_word;
};

void assign_node(Node &node){
  node = new (nothrow) Node;
  if(node == NULL){
    cout << "Running out of memory\n";
    exit(1);
  }
}

void assign_list(Node &a_list){
  Node_ptr current_node, last_node;

  assign_node(current_node);
  cout << "Enter a string (or . to end list): ";
  cin >> a_list->word;
   
  if(!strcmp(".", a_list->word)){
    delete a_list;
    a_list = NULL;
  }

  current_node = a_list;

  while(!(current_node == NULL)){
    assign_node(last_node);
    cout << "Enter a string (or . to end list)";
    cin >> last_node->word;

    if(!strcmp(".", last_node->word)){
      delete last_node;
      last_node = NULL;
    }
    current_node->ptr_next_word = last_node;
    current_node = last_node;
  }
}

void print_list(Node a_node){
  while(a_node != NULL){
    cout << a_node->word << " ";
    a_node = a_node->ptr_next_word;
  }
}

int main(){
  Node new_list = NULL;
  assign_list(new_list);
  print_list(new_list);
  
  return 0;
}
