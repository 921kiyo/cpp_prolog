#include <iostream>
#include <string>

#include "Contestant.h"
#include "University.h"

using namespace std;

Contestant::Contestant(string n, University& _uni, int a, bool cap, bool reg): name(n), age(a), captain(cap), registered_student(reg){
  uni = &_uni;
}

bool Contestant::is_valid(string team_uni){
  if(uni->get_name() != team_uni || registered_student == false ){
    cout << "Contestant must a current studnet and represents for the uni" << endl;
    return false;
  }
  if(age < 18 || age > 40){
    cout << "Age limit..." << endl;
    return false;
  }
  cout << "This student is no problem! " << endl;
  return true;
}

void Contestant::change_university(University& _uni){
  uni = &_uni;
}

void Contestant::graduate(){
  cout << "This student is graduating..." << endl;
  registered_student = false;
}

int Contestant::get_age(){
  return age;
}
bool Contestant::get_captain(){
  return captain;
}
bool Contestant::get_registered_student(){
  return registered_student;
}
