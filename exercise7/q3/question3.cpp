
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX_WORD_LENGTH = 80;

struct Node;

typedef Node *Node_ptr;

struct Node
{
  char word[MAX_WORD_LENGTH];
  Node_ptr ptr_to_next_node;
};

void assign_list(Node_ptr &a_list);

void assign_new_node(Node_ptr &a_node);

void print_list(Node_ptr a_node);

void add_after(Node_ptr &a_list, char a_word[], char word_after[]);

void delete_node(node_ptr &a_list, char a_word[]);

void list_selection_sort(node_ptr &a_list);

int main(){
  Node_ptr my_list = NULL;
  assign_list(my_list);
  cout << "\nTHE LIST IS NOW:\n";
  print_list(my_list);

  char a_word[MAX_WORD_LENGTH];
  char new_word[MAX_WORD_LENGTH];

  cout << "\nAfter which world you like to add an extra word?\n";
  cin >> a_word;
  cout << "Which word would you like to add?\n";
  cin >> new_word;
  add_after(my_list, a_word, new_word);
  cout << "\nTHE LIST IS NOW:\n";
  print_list(my_list);
  
  return 0;
}

void add_after(Node_ptr &a_list, char a_word[], char word_after[]){
  Node_ptr current_node_ptr = a_list, extra_node_ptr;
  assign_new_node(extra_node_ptr);
  strcpy(extra_node_ptr->word,word_after); // Copy from word_after into extra_node_ptr->word

  while(current_node_ptr != NULL){
    if(!strcmp(a_word, current_node_ptr->word)){
      extra_node_ptr->ptr_to_next_node = current_node_ptr->ptr_to_next_node;
      current_node_ptr->ptr_to_next_node = extra_node_ptr;
      return;
    }
    current_node_ptr = current_node_ptr->ptr_to_next_node;
  }
}

void delete_node(node_ptr &a_list, char a_word[]){
  
}

void list_selection_sort(node_ptr &a_list){
  
}

void assign_list(Node_ptr &a_list){
  Node_ptr current_node, last_node;

  assign_new_node(a_list);
  cout << "Enter first word (or '.' to end list): ";
  cin >> a_list->word;
  if(!strcmp(".", a_list->word)){
    delete a_list;
    a_list = NULL;
  }
  current_node = a_list;

  while(current_node != NULL){
    assign_new_node(last_node);
    cout << "Enter next word (or '.' to end list): ";
    cin >> last_node->word;
    if(!strcmp(".", last_node->word)){
      delete last_node;
      last_node = NULL;
    }
    current_node->ptr_to_next_node = last_node;
    current_node = last_node;				       
  }
}

void assign_new_node(Node_ptr &a_node){
  a_node = new (nothrow) Node;
  if(a_node == NULL){
    cout << "sorry - no more memory\n";
    exit(1);
  }
}

void print_list(Node_ptr a_node){
  while(a_node != NULL){
    cout << a_node->word << " ";
    a_node = a_node->ptr_to_next_node;
  }
}
