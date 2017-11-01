#include <iostream>

using namespace std;


int greatest_common_divisor(int a, int b){
  if(a == b){
    return a;
  }
  else if(b<a){
    return greatest_common_divisor(b, a-b);
  }
  else if(a<b)
    return greatest_common_divisor(a, b-a);
}

int main(){
  int a, b, answer;

  cout << "Type the first number\n";
  cin >> a;
  cout << "Type the second number\n";
  cin >> b;

  answer = greatest_common_divisor(a,b);

  cout << "Answer is " << answer << "\n";
  return 0;
}
