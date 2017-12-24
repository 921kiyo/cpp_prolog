#include <iostream>

using namespace std;

int fibonacci(int num){
  if(num == 1 || num == 2){
    return 1;
  }
  else{
    return (fibonacci(num-1) + fibonacci(num-2));
  }
}

int main(){
  int num, answer;
  cout << "type a number" << endl;
  cin >> num;
  answer = fibonacci(num);
  cout << "answer is " << answer << endl;
  return 0;
}
