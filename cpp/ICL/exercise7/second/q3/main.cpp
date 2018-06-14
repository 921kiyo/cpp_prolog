#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAX_LENGTH = 80;

struct Node;
typedef Node *Node_ptr;

struct Node
{
  char word[MAX_LENGTH];
  Node_ptr ptr_to_next_node;
};

void assign_list(Node_ptr& a_list);

void assign_new_node(Node_ptr& a_node);

void print_list(Node_ptr a_node);

void add_after(Node_ptr& a_list, char a_word[], char word_after[]);
void delete_node(Node_ptr& a_list, char a_word[]);
void list_selection_sort(Node_ptr& a_list);

int main(){
  Node_ptr my_list = NULL;

  assign_list(my_list);

  cout << "The list is now: ";
  print_list(my_list);

  return 0;
}

void assign_list(Node_ptr& a_list){
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

void assign_new_node(Node_ptr& a_node){
  a_node = new (nothrow) Node;
  if(a_node == NULL){
    cout << "sorry - no more memory" << endl;
    exit(1);
  }
}

void print_list(Node_ptr a_node){
  while(a_node != NULL){
    cout << a_node->word << " ";
    a_node = a_node->ptr_to_next_node;
  }
}


// ---------------Answers below -----------------
void add_after(Node_ptr& a_list, char a_word[], char word_after[]){
  Node_ptr current_node_ptr = a_list, extra_node_ptr;
  assign_new_node(extra_node_ptr);
  strcpy(extra_node_ptr->word, word_after);

  while(current_node_ptr != NULL){
    if(!strcmp(a_word, current_node_ptr->word)){
      extra_node_ptr->ptr_to_next_node = current_node_ptr->ptr_to_next_node;
      current_node_ptr->ptr_to_next_node = extra_node_ptr;
      return;
    }
    current_node_ptr = current_node_ptr->ptr_to_next_node;
  }
  delete extra_node_ptr;
}

void delete_node(Node_ptr& a_list, char a_word[]){
  
}

void list_selection_sort(Node_ptr& a_list){

}
