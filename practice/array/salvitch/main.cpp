#include <iostream>

using namespace std;

const int MAX = 10;

int main(){
  char array[MAX];
 
  for(int i = 0; i<MAX; i++){
    cout << "Type nonnegative integers: ";
    cin >> array[i];
  }

  cout << "The array is: \n";
  for(int i = MAX; i>0; i--){
    cout << array[i] << endl;
  }
  return 0;
}
