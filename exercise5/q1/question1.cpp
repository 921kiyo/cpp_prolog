#include <iostream>

using namespace std;

int main(){
  int number;
  bool isPrime = true;

  cout << "Type a number\n";
  cin >> number;

  for(int i = 2; i < number / 2; i++){
    if(number % i == 0){
      isPrime = false;
    }
  }

  if(isPrime){
    cout << "The number " << number << " is a prime number\n"; 
  }
  else{
    cout << "The number " << number << " is not a prime number\n";
  }
  /*
  if(1 <= number && number <= 1000){
    
  }
  else{
    cout << "The number has to be between 1 and 1000\n";
    }
  */
  return 0;
}
