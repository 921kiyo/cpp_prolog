#include <iostream>

#include <string>
#include <chrono>
#include <ctime>

using namespace std;

class Date{

public:
  Date(){

  }
};


class Flight{
int codeNumber;
double price;
Date takeoff;

public:
  Flight(Date d, int c, double p): takeoff(d), codeNumber(c), price(p){

  }
  void print_info(){
    cout << "Code number is " << codeNumber << " and price is " << price << endl;
  }
  Date getDate() const { return takeoff;}
  double getPrice() const { return price;}
};

class Passenger{
string name;
string address;

public:
  Passenger(string n, string a): name(n), address(a){}
};

class Booking{
protected:
  string seat;
  Passenger *passenger;
  Flight *flight;

  virtual int days_before() = 0;
  virtual double cancel_amount() = 0;

public:
  Booking(string s, Passenger *p, Flight *f): seat(s), passenger(p), flight(f){}

  bool cancel(){
    return true;
  }
};

class FirmBooking: public Booking{
double amount_paid;
public:
  virtual int days_before(){
    return 20;
  }

  virtual double cancel_amount(){
    // only deposit repaid.
    return flight->getPrice();
  }
};

class Flexible: public Booking{
double amount_paid;
public:
  virtual int days_before(){
    return 10;
  }

  virtual double cancel_amount(){
    if(days_before() >= 10){
      return amount_paid*0.8;
    }
  }
};

int main(){
  return 0;
}
