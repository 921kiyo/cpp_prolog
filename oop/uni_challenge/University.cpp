#include <iostream>
#include "University.h"
#include "Team.h"
#include "Contestant.h"

using namespace std;

University::University(string n){
  name = n;
}

string University::get_name(){
  return name;
}
