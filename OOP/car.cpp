#include <iostream>
#include <string>

using namespace std;

class Car;

class Passenger{
  private:
  double weight;
  string name;

  public:
  Passenger(string n, double w){
    name = n;
    weight = w;
  }

  void print_details(ostream &out){
    out << name << " (" << weight << "kg)" << endl;
  }

  void diet(); //??

  void eat(double food_weight){
    cout << "Passenger(" << this << ") eat called." << endl;
    weight += food_weight;
  }

  bool get_into(Car &c);

  double get_weight() const { return weight;}

  friend ostream &operator<< (ostream &out, const Passenger &p);
};

ostream &operator<< (ostream &out, const Passenger &p){
  // Why &p here??
  cout << "p " << p << endl;
  out << "Passenger(" << &p << ") with name " << p.name << " and weight " << p.weight;
  return out; // Why bother return out?
}

void Passenger::diet()
{
  if(weight > 40){
    weight -= 1.0;
  }
}
