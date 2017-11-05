#include <iostream>
#include <cstdlib>

using namespace std;


int fibonacci(int num){
  if(num < 1){
    cout << "No fibonacci\n";
    exit(1);
  }
  else if(num == 1 || num == 2){
    return 1;
  }
  else{
    return (fibonacci(num-1) + fibonacci(num-2));
  }
}

int main(){
  int num;
  cout << "Type the number\n";
  cin >> num;
  int answer;
  answer = fibonacci(num);
  cout << "The answer is " << answer << "\n";
  return 0;
}
