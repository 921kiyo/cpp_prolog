#include <iostream>

using namespace std;

int binary_search(int value, int list[], int first, int last);

int main(){
  const int MAX = 11;
  int num, position;
  int list[MAX] = {2,2,3,5,8,14,16,22,22,24,30};
  cout << "Which number are you looking for?\n";
  cin >> num;
  position = binary_search(num, list, 0, MAX-1);
  if(position >= 0){
    cout << "The position of the number is " << position +1 << "\n";
  }
  else{
    cout << "We could not find the number from the list\n";
  }
  
  return 0; 
}

int binary_search(int value, int list[], int first, int last){
  int midpoint;

  if(first > last){
    return -1;
  }
  else{
    midpoint = (first + last)/2;
    if(list[midpoint] == value){
      return midpoint;
    }
    else if(list[midpoint] < value){
      return binary_search(value, list, midpoint+1, last);
    }
    else{
      return binary_search(value, list, first, midpoint-1);
    }
  }

}
