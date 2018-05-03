#include <iostream>
#include <string>
#include <math.h>
using namespace std;

const double center_x = 7.5;
const double center_y = 1.575;

class Player{
  double x, y;
  double skill_factor;
  bool has_ball;
  public:
  Player(double x_c, double y_c, double skill, bool ball): x(x_c), y(y_c), skill_factor(skill), has_ball(ball){}
  void pass_ball(Player *another){
    has_ball = false;
  }
  double shoot_ball(){
    double distance_x = x - center_x;
    double distance_y = y - center_y;
    double x = distance_x + distance_y;
    has_ball = false;

    double a = 0.62;
    double b = 6.84;
    double denominator = 1+exp(-a*(x-b*skill_factor));
    double prob = 1 - 1/denominator;

    if(is_inside_line(x)){
      cout << "drand48() " << drand48() << endl;
      return prob*2;
    }
    else{
      return prob*3;
    }
  }
  void move(double new_x, double new_y){
    x = new_x;
    y = new_y;
  }

  bool is_inside_line(double distance_total){
    if(distance_total<=6.6){
      return true;
    }
    else{
      return false;
    }
  }
};

int main(){
  Player* larry = new Player(4.5, 3.25, 0.9, false);
  Player* michael = new Player(10.5, 5.1, 0.95, true);
  larry->move(0.25,2.2);
  michael->pass_ball(larry);
  cout << "The number of points is " << larry->shoot_ball() << endl;
  delete larry;
  return 0;
}
