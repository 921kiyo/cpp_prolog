#include <iostream>

#include "Team.h"
#include "Contestant.h"
#include "University.h"

using namespace std;

Team::Team(University& u){
  uni = &u;
  members=0;
  for(int i = 0; i < 4;i++){
    member[i] = NULL;
  }
}

bool Team::add_member(Contestant& c){
  if(members>=4){
      member[members] = &c;
      members++;
  };
}

double Team::average_age(){
  double total = 0;
  for(int i = 0; i< members; i++){
    total+= member[i]->get_age();
  }
  return total/members;
}

bool Team::is_valid(){
  int captain_count = 0;
  for(int i = 0; i< members; i++){
    if(member[i]->get_age() < 18 || member[i]->get_age() >40){
      cout << "Students age limit invalid... " << endl;
      return false;
    }
    if(member[i]->get_registered_student() == false){
      cout << "Non registered student..." << endl;
      return false;
    }
    if(member[i]->get_captain() == true){
      captain_count++;
    }
  }
  if(captain_count != 1){
    cout << "Each team needs exactly one captain" << endl;
    return false;
  }
  if(average_age() > 25.0){
    cout << "The average age of team members must be less than 25" << endl;
    return false;
  }
  return true;
}
