#include <iostream>
#include <cstdlib>

using namespace std;

int greatest_common_divisor(int first, int second){
  if(first < 1 || second < 1){
    cout << "Error\n";
    exit(1);
  }
  else if(first == second){
    return first;
  }
  else if(first < second){
    return greatest_common_divisor(first, (second-first));
  }
  else{
    return greatest_common_divisor(second, (first-second));
  }
}


int main(){
  int first;
  int second;
  cout << "Type the first positive number\n";
  cin >> first;
  cout << "Type the second positive number\n";
  cin >> second;
  cout << "\n\n";
  cout << "The greatest common divisor is " << greatest_common_divisor(first, second) << "\n";

  return 0;
}
