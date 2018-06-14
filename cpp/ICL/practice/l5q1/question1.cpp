#include <iostream>

using namespace std;

int main(){
  int num;
  bool is_prime = true;
  cout << "Type a integer\n";
  cin >> num;

  for(int i = 2; i < num; i++){
    if(num % i == 0){
      is_prime = false;
    }
  }

  if(is_prime){
    cout << "The integer " << num << " is a prime number";
  }
  else{
    cout << "The integer " << num << " is not a prime number";
  }
  
  return 0;
}
