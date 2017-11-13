#include <iostream>

#include "Contestant.h"
#include "Team.h"
#include "University.h"

using namespace std;

int main(){
  University imperial("ICL");
  Team icl(imperial);
  Contestant ivor("Ivor Bigbrain", imperial, 20,false, true);
  Contestant prezza("Prezza Buzza", imperial, 18,false, true);
  Contestant ivonna("Ivonna Singh", imperial, 25,true, true);
  Contestant yuman("Yuman Google", imperial, 32, false, false);
  // prezza.graduate();
  return 0;
}
