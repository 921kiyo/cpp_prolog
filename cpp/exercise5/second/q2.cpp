#include <iostream>

using namespace std;


void print_pyramid(int height){
  int full_length = 0;
  int diff = height;
  for(int i = height; i > 0; i--){
    full_length += 2;
    diff--;
    for(int j = 0; j < diff; j++){
      cout << " ";
    }
    for(int j = 0; j < full_length; j++){
      cout << "*";
    }

    cout << endl;
  }
}

int main(){
  int height;
  cout << "This program prints a 'pyramid' shape of a specified height on the screen." << endl;
  cout << "how high would you like the pyramid?: " << endl;
  cin >> height;
  while(height < 1 && height > 30){
    cout << "Pick another height (must be between 1 and 30):" << endl;
    cin >> height;
  }

  print_pyramid(height);
  return 0;
}
