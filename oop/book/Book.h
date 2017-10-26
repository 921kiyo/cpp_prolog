#ifndef BOOK_H
#define BOOK_H

class Book{
public:
  char* title;
  int serialNumber;
  Book(char*);
  ~Book();

};

extern int bookCounter;

#endif
