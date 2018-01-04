#include <iostream>
#include <cmath>
using namespace std;

int squares(int n){
  if(n == 1){
    return 1;
  }
  else{
    return squares(n-1)+n*n;
  }
}

int main(){
  cout << "Type a number" << endl;
  int n;
  cin >> n;
  cout << "answer is " << squares(n) << endl;
  return 0;
}
