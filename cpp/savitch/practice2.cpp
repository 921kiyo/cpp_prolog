#include <iostream>

using namespace std;

double power(int x, int n){
  if(n > 0){
    return power(x, (n-1))*x;
  }
  if(n < 0){
    return (1/power(x, -n));
  }
  if(n == 0){
    return 1;
  }
}

int main(){
  // cout << "type a number" << endl;
  // int n;
  // cin >> n;
  // for(int n = 0; n < 4; n++){
  //   cout << "3 to the power " << n << " is " << power(3,n) << endl;
  // }
  for(int n = -4; n < 0; n++){
    cout << "3 to the power " << n << " is " << power(3,n) << endl;
  }
  // cout << "3 to the power 3"<< " is " << power(3,3) << endl;

  return 0;
}
