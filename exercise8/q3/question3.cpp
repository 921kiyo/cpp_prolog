#include <iostream>

using namespace std;

bool check_input(int m, int n){
  return (m<n);
}

int greatest_common_divisor(int big, int small){
  int a = big/small;
  int remainder = big%small;
  if(remainder !=0){
    greatest_common_divisor(small, remainder);
  }
  else{
    return small;
  }
}


int main(){
  int big;
  int small;
  cout << "Type a number BIG\n";
  cin >> big;
  cout << "Type a number SMALL\n";
  cin >> small;
  cout << "\n\n";
  cout << "The greatest common divisor is " << greatest_common_divisor(big, small) << "\n";

  return 0;
}
