#include <iostream>
#include <string>

using namespace std;

class Item{
int location;
string title;
LibraryUser *bollowed_by;
public:
  Item(string t, int loc): location(loc), title(t){

  }

};

class LibraryUser{
string name;
int items_borrowed_count;
Item *items_borrowed[3];

public:
  LibraryUser(string n): name(n){
    items_borrowed_count = 0;
    for(int i = 0; i < 3; c++){
      items_borrowed[i] = NULL;
    }
  }
  book borrow(Item &target, int days){
    if(target.get_borrowed_by() != NULL){

    }
  }
};

class Book: public Item{
  int loan_period;
public:
  Book(string t, int loc, int loan): Item(t, loc), loan_period(loan) {}
};

class Periodical: public Item{
private:
  static int loan_period;
public:
  Periodical(string t, int loc): Item(t, loc){}
  int get_loan_period() const{
    return loan_period;
  }
};

int Periodical::loan_period = 5;

int main(){
  Book cpp("C++ without tears", 1, 10);
  Book guide("The Hitch", 2, 13);
  Periodical www("WWW in 80s", 3);
  Periodical queen("20m under", 4);
  LibraryUser georgia("Georgia");
  LibraryUser ali("Ali");
  return 0;
}
