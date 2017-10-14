#ifndef LIST_H
#define LIST_H

struct Node;
typedef Node *Node_ptr;

const int MAX = 80;

struct Node{
  char word[MAX];
  Node_ptr ptr_next_word;
};


void assign_node(Node_ptr &node);
void assign_list(Node_ptr &a_list);
void print_list(Node_ptr a_node);
void add_after(Node_ptr &list, char a_word[], char word_after[]);

#endif
