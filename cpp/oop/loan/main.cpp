#include "main.h"
#include <iostream>
#include <string>

using namespace std;

double Car::calculate_price(){
  return (horsepower*10000)/mileage;
}

bool LegalEntity::buy_car(LegalEntity buyer, Car c, double price){
  // TODO
  return true;
}

void LegalEntity::take_ownership(Car c){
}

bool Bank::is_eligible_for_loan(Borrower b){
  // TODO
    return true;
}

bool Borrower::apply_loan(Bank b, Car c){
  return true;
}
bool Borrower::accept_loan(Bank b, Car c){
  return true;
}

int Person::get_age(){
  return age;
}

double Company::get_disposable_income(){
  return 10;
}


double Person::get_disposable_income(){
  return 10;
}

int main(){
  return 0;
}
