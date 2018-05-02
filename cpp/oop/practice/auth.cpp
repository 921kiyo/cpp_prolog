#include <iostream>

#include <string>
#include <list>

using namespace std;

class User;
class Session;
class Authorisation;

class WorkStation{
  string hostname;
  list<Authorisation*> auths;
public:
  WorkStation(string t): hostname(t){}
  void add_authorisation(Authorisation *auth){
    auths.push_back(auth);
  }
  Authorisation *get_authorisation(User *target){
    for (auto iterator = auths.begin(); iterator != auths.end(); iterator++){
      if((*iterator)->matches_user(target)){
        return *iterator;
      }
    }
  }
  string get_hostname() const { return hostname; }
};

class User{
  string name;
  list<WorkStation*> is_authorised;
public:
  User(string n): name(n){}
  bool login(WorkStation &w){
    Authorisation *auth = w.get_authorisation(this);
    if(auth == NULL){
      return false;
    }
    return true;
  }
};

class Session{
  string root;
public:
  Session(string r): root(r){}
};

class Directory{
string name;
Directory* parent;
public:
  Directory(string n, Directory *p): name(n), parent(p){}
};

class Authorisation{
  int priority;
  User *user;
  WorkStation *workstation;
  Session sess;
  list<User*>auths;
  Directory* default_directory;
public:
  Authorisation(User *u, WorkStation *w, int p, Session &s, Directory *def): priority(p),
  user(u), sess(s), workstation(w), default_directory(def){
    w->add_authorisation(this);
  }
  bool matches_user(User *target){
    return user == target;
  }
};
