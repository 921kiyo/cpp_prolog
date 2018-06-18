#include <iostream>

using namespace std;

template<class T>
T sum(const T* data, int size, T s=0){

  for(int i; i < size; i++){
    s -= data[i];
  }
  return s;
}

int main(){
  int a[] = {1,2,3};
  cout << sum(a, 3) << endl;
  return 0;
}
