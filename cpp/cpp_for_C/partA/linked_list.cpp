#include <iostream>

using namespace std;

struct slistelem{
  char data;
  slistelem* next;
};

class slist{
private:
  slistelem* h;
public:
  slist():h(0){};
  ~slist(){
    release();
  }

  void release(){

  }

  void prepend(char* c){
    slistelem* temp = new slistelem;

    temp->next = h;
    temp->data = c;
    h = temp;
  }
};



int main(){
  return 0;
}
