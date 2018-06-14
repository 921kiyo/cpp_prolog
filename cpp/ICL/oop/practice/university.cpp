#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Contestant;

class University{
string name;

public:
  University(string n): name(n){}
  string get_name(){ return name;}
};

class Contestant{
string name;
University *university;
int age;
bool captain;
bool registered_student;
public:
  Contestant(string _name, University &_uni, int _age, bool _reg, bool _captain = false){
    name = _name;
    university = &_uni;
    age = _age;
    captain = _captain;
    registered_student = _reg;
  }

  bool is_valid(string team_uni) const{
    if(age < 18 || age > 40){
      return false;
    }
    if (!registered_student){
      return false;
    }
    if (team_uni != university->get_name()){
      return false;
    }
    return true;
  }

  int get_age() const { return age;}
  bool get_captain() const { return captain;}
};

class Team{
University *university;
int members;
Contestant *member[4];
public:
  Team(University &uni): university(&uni){
    members = 0;
    for(int n = 0; n<4; n++){
      member[n] = NULL;
    }
  }
  bool add_member(Contestant &contestant){
    if(members >= 4){
      return false;
    }
    member[members] = &contestant;
    members++;
    return true;
  }

  double average_age() const {
    assert(members > 0);
    double total = 0;
    for(int n = 0; n < members; n++){
      total += member[n]->get_age();
    }
    return total/members;
  }

  bool is_valid() const{
    // cout << "mem " << members << endl;
    if(members != 4) return false;
    int captains = 0;
    for(int n=0; n<4; n++){
      cout << member[n]->is_valid(university->get_name()) << endl;
      if(!member[n]->is_valid(university->get_name())) return false;
      if(member[n]->get_captain()){
        captains ++;
      }
      // cout << "captains " << captains << endl;
    }
    return (captains == 1) && average_age() < 25.0;
  }
};

int main(){
  University imperial("Imperial");
  Team icteam(imperial);
  Contestant ib("Ivor Bigbrain", imperial, 20, true);
  icteam.add_member(ib);
  Contestant pb("Prezza Buzza", imperial, 18, true);
  icteam.add_member(pb);
  Contestant is("Ivonna Singh", imperial, 25, true, true);
  icteam.add_member(is);
  Contestant yg("Yuman Google", imperial, 32, true);
  icteam.add_member(yg);
  cout << "Imperial team is ";
  if(!icteam.is_valid()){
    cout << "NOT ";
  }
  cout << "valid." << endl;
  return 0;
}
