#ifndef CONTESTANT_H
#define CONTESTANT_H

#include <string>
#include "University.h"

using namespace std;

class Contestant{
private:
  string name;
  University *uni;
  int age;
  bool captain;
  bool registered_student;
public:
  Contestant(string n, University& _uni, int a, bool cap, bool reg);
  bool is_valid(string team_uni);
  void change_university(University& _uni);
  void graduate();
  int get_age();
  bool get_captain();
  bool get_registered_student();
};

#endif
