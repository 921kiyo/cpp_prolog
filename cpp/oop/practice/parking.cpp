#include <iostream>

#include <string>

using namespace std;

class ParkingFine;

class ParkingAttendant{
protected:
  string name;
  double fines_issued;
  int badget_number;

public:
  ParkingAttendant(string n, int b): name(n), badget_number(b){
    fines_issued = 0;
  }

  void issue(ParkingFine &pf){
    fines_issued += pf.amount();
  }

  virtual double salary() = 0;
};

class SeniorParkingAttendant: public ParkingAttendant{

public:
  SeniorParkingAttendant(string n, int b): ParkingAttendant(n, b){}
  virtual double salary(){
    return 1200.0 + 0.1*fines_issued;
  }
};

class JuniorParkingAttendant: public ParkingAttendant{

public:
  JuniorParkingAttendant(string n, int b): ParkingAttendant(n, b){}
  virtual double salary(){
    return 900.0 + 0.05 * fines_issued;
  }
};

class ParkingFine{
protected:
  int offence_code;
  string offence_date;
  string offence_time;
  string registration_number;

public:
  ParkingFine(string date, string off_time,string reg,int oc){
    offence_date = date;
    offence_time = off_time;
    registration_number = reg;
    offence_code = oc;
  }

  virtual double amount() const = 0;
};

class FixedPenalty: public ParkingFine{
private:
static double fee;

public:
  FixedPenalty(string date, string off_time,string reg, int oc): ParkingFine(date, off_time, reg, oc){
  }
  virtual double amount() const{
    return fee;
  }
  void set_fee(double newfee){
    fee = newfee;
  }
  double get_fee(){
    return fee;
  }
};

class ExcessCharge: public ParkingFine{
int minutes;

public:
  ExcessCharge(string date, string off_time,string reg, int oc, int m): ParkingFine(date, off_time, reg, oc){
    minutes = m;
  }
  virtual double amount() const{
    return 20+5*minutes;
  }
};

FixedPenalty::fee = 100;

int main(){
  SeniorParkingAttendant charon("Charon", 66);
  FixedPenalty fp1("16/02/2006", "09h50", "LO52RNA", 26);
  charon.issue(fp1);
  FixedPenalty::set_fee(120);

  JuniorParkingAttendant nelson("Nelson", 111);
  ExcessCharge ec1("17/02/2006", "10h15", "B14NCA", 14, 15);
  nelson.issue(ec1);
  cout << "Nelson's salary is " << nelson.salary() << endl;

  return 0;
}
