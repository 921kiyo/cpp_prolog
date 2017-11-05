#include <iostream>
#include <cstdlib>

using namespace std;

int first = 1;
int total = 0;

int fibonacci(int num){
  if(num < 1){
    cout << "Error\n";
    exit(1);
  }
  else if(num == 1 || num == 2){
    return 1;
  }
  else{
    return (fibonacci(num - 1) + fibonacci(num-2));
  }
  
}

int main(){
  cout << fibonacci(7) << "\n";
  return 0;
}
