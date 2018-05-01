#include <iostream>
#include <string>

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
    double distance_total = distance_x + distance_y;
    has_ball = false;

    double prob = 0.5;

    if(is_inside_line(distance_total)){
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

// class Court{
//  static int point_A, point_B;
// public:
//   Court(){
//     point_A = 0;
//     point_B = 0;
//   }
// };

int main(){
  Player* larry = new Player(4.5, 3.25, 0.9, false);
  Player* michael = new Player(10.5, 5.1, 0.95, true);
  larry->move(0.25,2.2);
  michael->pass_ball(larry);
  cout << "The number of points is " << larry->shoot_ball() << endl;
  return 0;
}
