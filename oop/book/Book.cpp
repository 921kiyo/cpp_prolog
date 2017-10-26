#include <iostream>
#include <cstring>
#include "Book.h"

using namespace std;


Book::Book(char* t){
  title = new char [strlen(t) + 1];
  strcpy(title, t);
  serialNumber = ++ bookCounter;
  cout << " constr " << title << " at " << serialNumber << endl;
}

Book::~Book(){
  cout << " del " << title << " form " << serialNumber << "; BC = " << --bookCounter << endl;
  delete [] title;
};
