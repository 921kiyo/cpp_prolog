#include <iostream>

using namespace std;

void write_verticle(int n){
  if(n < 10){
    cout << n << endl;
  }
  else{
    write_verticle(n/10);
    cout << n%10 << endl;
  }
}

void write_astarisks(int n){
  if(n < 0){
    cout << "number has to be positive" << endl;
    return;
  }
  if(n == 0){
    cout << endl;
    return;
  }
  if(n > 0){
    cout << "*";
    write_astarisks(n-1);
  }
}

void integer_backward(int n){
  if(n < 0){
    cout << "number has to be positive" << endl;
    return;
  }
  if(n < 10){
    cout << n << endl;
    return;
  }

  if(n >= 10){
    cout << n%10 << endl;
    integer_backward(n/10);
  }
}

void integer_count(int n){
  if(n >= 1){
    integer_count(n-1);
    cout << n << " ";
  }
}

void integer_increment(int n){
  if(n >=1){
    cout << n << " ";
    integer_increment(n-1);
  }
}

int main(){
  cout << "type a number" << endl;
  int n;
  cin >> n;
  // write_verticle(n);
  // write_astarisks(n);
  // integer_backward(n);
  // integer_count(n);
  integer_increment(n);
  return 0;
}
