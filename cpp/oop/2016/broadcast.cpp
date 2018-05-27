#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Ship{
  string callsign;
  int range;
  double lat;
  double lon;
  bool is_emergency;
public:
  Ship(string call, int r, double la, double lo): callsign(call), range(r), lat(la), lon(lo){
    is_emergency = false;
  }
  void update_position(double la, double lo){
    lat = la;
    lon = lo;
  }
  void emergency(){
    is_emergency = true;
  }
  void boardcast(){
    if(is_emergency){
      delta_lon = lon-lon2;;
      double bracket = sqrt(sin(pow(2, )));
      double distance = 2*3956* asin(bracket);
      // boardcase Mayday message
    }

  }
  double calculate_distance(Ship*ship){
    double delta_lat = abs(ship->getlat() - lat);
    double pi = 3;
    double temp;
    return 2*3956*asin(temp);
  }
  double getlat(){
    return lat;
  }
};
int main(){
  Ship endevour("2FBA7", 20, 36.158, -5.357);
  Ship seaswan("2CEU8", 10, 36.180, -5.390);
  seaswan.emergency();
  seaswan.boardcast();
  endevour.update_position(36.179, -5.391);
}
