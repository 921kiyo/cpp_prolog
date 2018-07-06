#include <iostream>

using namespace std;


class list_element{
public:
  int d;
  list_element* next;
  list_element(int n = 0, list_element* ptr = 0): d(n), next(ptr){}
};

class list{
private:
  list_element* head;
  list_element* cursor;
public:
  list():head(0), cursor(0){}

  // copy constructor
  list(const list& lst){
    if(lst.head == 0){
      head = 0;
      cursor = 0;
    }else{
      cursor = lst.head;
      list_element* h = new list_element();
      list_element* previous;
      head = h;
      h->d = lst.head->d;
      previous = h;

      while(cursor!=0){
        h = new list_element();
        h->d = cursor->d;
        previous->next = h;
        cursor = cursor->next;
        previous = h;
      }
      cursor=head;
    }
  }

  ~list(){
    cursor = head;
    while(cursor!=0){
      cursor = head->next;
      delete head;
      head = cursor;
    }
  }

  void prepend(int n){
    if(head == 0){
      head = cursor = new list_element(n, head);
    }else{
      head = new list_element(n, head);
    }

  }
  int get_element(){return cursor->d;}
  void advance(){cursor=cursor->next;}
  void print(){
    list_element* h = head;
    while(h != 0){
      cout << h->d << ", ";
      h = h->next;
    }
    cout << "###" << endl;
  }
};

int main(){
  list a, b;
  int data[10] = {3,4,6,7,-3,5};
  list d(data, 6);
  list e(data, 10);
  a.prepend(9);
  a.prepend(8);
  a.print();
  return 0;
}
