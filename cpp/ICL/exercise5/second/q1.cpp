#include <iostream>

using namespace std;

bool is_divisible(int i, int num){
  if(num % i == 0){
    return true;
  }else{
    return false;
  }
}

bool is_prime(int num){
  if(num == 2 || num == 3){
    return true;
  }
  else if (num > 3){

    for(int i = 2; i < num ; i++){
      if(is_divisible(i, num)){
        cout << "hi" << num << endl;
        return false;
      }
    }
  }
  else{
    return true;
  }
}

int main(){
  cout << is_prime(7) << endl;
  cout << is_prime(2) << endl;
  cout << is_prime(3) << endl;
  cout << is_prime(31) << endl;
  cout << is_prime(17) << endl;
  cout << "-------------" << endl;
  cout << is_prime(8) << endl;
  cout << is_prime(1002) << endl;
  return 0;
}
