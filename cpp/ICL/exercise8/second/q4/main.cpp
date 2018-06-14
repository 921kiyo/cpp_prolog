#include <iostream>

using namespace std;

int binary_search(int value, int list[], int first, int last){
  int pivot = (first+last)/2;
  if(value == list[pivot]){
    return pivot;
  }
  if(value > list[pivot]){
    return binary_search(value, list, pivot,last);
  }
  else if(value < list[pivot]){
    return binary_search(value, list, first, pivot);
  }
}

int main(){
  int list[11] = {2,2,3,5,8,14,16,22,22,24,30};
  int num;
  cout << "Which number are you looking for?" << endl;
  cin >> num;
  cout << "index for " << num << " is: " << binary_search(num, list, 0,10) << endl;

  return 0;
}
