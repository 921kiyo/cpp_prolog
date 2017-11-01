#ifndef DATE_H
#define DATE_H

class Date{
public:
  int year, month, day;
  Date(int d, int m, int y);
  void next();
  bool equal(Date);
  void print();
  void nextDate();
};

#endif
