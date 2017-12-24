#include <iostream>

using namespace std;

int greatest_common_divisor(int small, int large){
  if(small == large){
    return large;
  }else if(small < large){
    return greatest_common_divisor(small, large-small);
  }
  else{
    return greatest_common_divisor(large, small-large);
  }

}

int main(){
  int small, large;
  cout << "Type the first integer" << endl;
  cin >> small;
  cout << "Type the second integer" << endl;
  cin >> large;
  cout << "GCD is " << greatest_common_divisor(small, large) << endl;
  return 0;
}
