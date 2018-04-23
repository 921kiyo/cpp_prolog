#include <iostream>
#include <string>
// #include <vector>
#include<list>

using namespace std;

class MotionDetector;
class Property;
class SecurityGuard{
private:
  bool deployed;
  Property* guarding;

public:
  SecurityGuard(){
    deployed = false;
    guarding = NULL;
  }
  bool assigned_to(Property* p){
    if(guarding){
      guarding->release(this);
    }
    guarding = p;
    guarding->acquire(this);
    deployed = true;
    return true;
  }

  void receive_alert(string message){
    cout << "The message is " << message << endl;
  }
};

class Property{
private:
  list<SecurityGuard*> guardians;
public:
  void acquire(SecurityGuard* g){
    guardians.push_back(g);
    // guards.append(g);
  }

  void release(SecurityGuard* g){
    guardians.remove(g);
  }

  void send_alert(string message){
    list<SecurityGuard *>::iterator it;
    // for (SecurityGuard **current = guardians.front(); *current; current = guardians.next()){
    for (it = guardians.begin(); it != guardians.end(); it++){
      (*it)->receive_alert(message);
    }
  }
};

class MotionDetector{
private:
  Property *prop;
  string name;
public:
  MotionDetector(const char *_name, Property *_prop){
    prop = _prop;
    name = _name;
  }
  void activate(){
    if(prop){
      prop->send_alert("Motion detected in " + name);
    }
  }
};

int main(){
  Property SK, IC;
  MotionDetector a = new MotionDetector("Hallway East", &SK);
  MotionDetector b = new MotionDetector("Hallway West", &SK);
  MotionDetector c = new MotionDetector("Crown Jewels", &SK);
  MotionDetector d = new MotionDetector("Rector's Office", &IC);

  SecurityGuard alice;
  SecurityGuard bob;
  alice.assigned_to(&SK);
  bob.assigned_to(&SK);
  a.activate();
  alice.assigned_to(&IC);
  c.activate();
  return 0;
}
