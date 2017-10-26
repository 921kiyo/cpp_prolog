#include <iostream>
#include "Book.h"

using namespace std;

int main(){
  Book b1("Seagull");
  Book *b2, *b3;

  Book b4("Iron Mask");

  b2 = new Book("Moonstone");

  Book *b5 = new Book("Tom Sawyer");

  b2 = new Book("Polyanna");

  b2 = new Book("Shogun");

  b3 = b2;

  delete b3;

  cout << "Now " << bookCounter << " books left \n";

  return 0;
}
