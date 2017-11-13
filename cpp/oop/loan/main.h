#ifndef MAIN_H
#define MAIN_H

#include <string>

using namespace std;

class Car{
private:
  string number_plate;
  double horsepower;
  double mileage;
public:
  double calculate_price();
};

class LegalEntity{
protected:
  string name;
  string address;
  // Is this correct?
  Car* car;
public:
  bool buy_car(LegalEntity buyer, Car c, double price);
  void take_ownership(Car c);
};

class Bank: public LegalEntity{
private:
  double interest_rate;
public:
  bool is_eligible_for_loan(Borrower b);
};

class Borrower: public LegalEntity{
public:
  virtual double get_disposable_income() = 0;
  bool apply_loan(Bank b, Car c);
  bool accept_loan(Bank b, Car c);
};

class Company: public Borrower{
private:
  double turnover;
public:
  double get_disposable_income();
};

class Person: public Borrower{
private:
  int age;
public:
  int get_age();
  double get_disposable_income();
};

class Loan{

};

class Employment{

};




#endif
