#include <iostream>
#include <cstdlib>
#include <cstring>

#include "list.h"

using namespace std;

void add_after(Node_ptr &list, char a_word[], char word_after[]){
  
  assign_node(list);
  while(list != NULL){
    if(list->word == a_word){
      list->ptr_next_word = word_after;
    }
    list = list->ptr_next_word;
  }

}

void assign_node(Node_ptr &node){
  node = new (nothrow) Node;
  if(node == NULL){
    cout << "Running out of memory\n";
    exit(1);
  }
}

void assign_list(Node_ptr &a_list){
  Node_ptr current_node, last_node;

  assign_node(a_list);
  cout << "Enter a string (or . to end list): \n";
  cin >> a_list->word;
  
  
  if(!strcmp(".", a_list->word)){
    delete a_list;
    a_list = NULL;
  }

  current_node = a_list;

  while(!(current_node == NULL)){
    assign_node(last_node);
    cout << "Enter a string (or . to end list): \n";
    cin >> last_node->word;

    if(!strcmp(".", last_node->word)){
      delete last_node;
      last_node = NULL;
    }
    current_node->ptr_next_word = last_node;
    current_node = last_node;
  }
}

void print_list(Node_ptr a_node){
  while(a_node != NULL){
    cout << a_node->word << " ";
    a_node = a_node->ptr_next_word;
  }
}
