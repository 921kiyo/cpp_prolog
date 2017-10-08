#include <iostream>

using namespace std;

int main(){
  int number, power;
  cout << "Type a number\n" ;
  cin >> number;
  cout << "\n";

  cout << "Type a positive power\n";
  cin >> power;
  cout << "\n";

  int answer = 1;

  for (int count = 0; count < power; count++){
    answer *= number;
  }

  cout << "Answer is " << answer << "\n" ; 
  
  return 0;
}
