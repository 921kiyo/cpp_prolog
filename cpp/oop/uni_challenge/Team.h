#ifndef TEAM_H
#define TEAM_H

#include "Contestant.h"
#include "University.h"

class Team{
private:
  int members;
  University* uni;
  Contestant* member[4];
public:
  Team(University& u);
  bool add_member(Contestant& c);
  double average_age();
  bool is_valid();
};

#endif
