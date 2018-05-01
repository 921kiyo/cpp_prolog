#include <iostream>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;

class AF{
protected:
  string name;
  int year_birth;
  double os_mark;
public:
  AF(string n, int y, double os): name(n), year_birth(y), os_mark(os){}
  virtual double calculate_score() = 0;
};

class NAF: public AF{
private:
  double net_mark;
public:
  NAF(string n, int y, double os, double net): AF(n, y, os), net_mark(net){}

  double calculate_score(){
    return (os_mark+net_mark)/2;
  }
};

class PAF: public AF{
private:
  double prog_mark;
public:
  PAF(string n, int y, double os, double prog): AF(n, y, os), prog_mark(prog){}

  double calculate_score(){
    return (os_mark+prog_mark)/2;
  }
};

class HR{
private:
  string name;
  int dob;
  stack<AF*> trays;
  int limit;
public:
  HR(string n, int d, int lim): name(n), dob(d), limit(lim){}
  void receive_applicant(AF* applicant){
    if(trays.size() <= 50){
      trays.push(applicant);
    }
  }
  int count(){
    return trays.size();
  }
  void remove(){
    for(int i = 0; i < trays.size(); i++){
      AF* temp = trays.top();
      if(temp->calculate_score() < 66){
        trays.pop();
      }
      // temp.push()
    }
  }
};


int main(){
  HR helen("Helen", 1975, 50);
  NAF peter("Peter", 1986, 65, 75);
  helen.receive_applicant(&peter);
  NAF susan1("Susan", 1989, 70, 60);
  PAF susan2("Susan", 1989, 70, 80);
  helen.receive_applicant(&susan1);
  helen.receive_applicant(&susan2);
  helen.remove();
  cout << "The number of applicant left is" << helen.count() << endl;
  return 0;
}
