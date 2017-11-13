#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <string>

using namespace std;

class University{
private:
  string name;
public:
  University(string n);
  string get_name();
};

#endif
