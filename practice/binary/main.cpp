#include <iostream>

using namespace std;

// int binary_search(int value, int list[], int first, int last){
//   int middle = (last+first)/2;


//   if(value == list[middle]){
//     return middle;
//   }
//   else if(value < list[middle]){
//     return binary_search(value, list, first, middle-1);
//   }
//   else{
//     return binary_search(value, list, middle+1, last);
//   }

// }


int binary_search(int value, int list[], int first, int last){
  int middle;
  if(first>last){
    return -1;
  }
  else{
    middle = (last+first)/2;
    if(value == list[middle]){
      return middle;
    }
    else if(value < list[middle]){
      return binary_search(value, list, first, middle-1);
    }
    else{
      return binary_search(value, list, middle+1, last);
    }
  }
}


int main(){
  const int MAX = 11;
  int sorted_array[MAX] = {2,2,3,5,8,14,16,22,22,24,30};
  /*
  for(int i = 0; i<MAX; i++){
    cout << "Type an integer \n";
    cin >> sorted_array[i];
    }*/

  int target;
  cout << "Type an integer you are looking for \n";
  cin >> target;
  cout << "\n";
  
  int index;
  index = binary_search(target, sorted_array, 0, MAX-1);
  
  if(index == -1){
    cout << "Sorry, we could not find it in the array \n";
  }
  else{
    cout << "The position is " << index << endl;
  }
  
  return 0;
}
