#include <iostream>

using namespace std;

void print_pyramid(int height){
  cout << "\n\n";
  const int MARGIN = 10;
  for(int row = 0; row < height; row++){
    int no_space = MARGIN + height - row;
    for(int i = 0; i<no_space; i++){
      cout << " ";
    }
    for(int column = 0; column<row*2; column++){
      cout << "*";
    }
    cout << "\n";
  }
  cout << "\n\n";
}

int main(){
  int height;
  cout << "This program prints a 'pyramid' shape of a specified height on the screen.\n";
  cout << "how high would you like the pyramid?: ";
  cin >> height;
  while(height >30 || height < 1){
    cout << "Pick another height (must be between 1 and 30): ";
    cin >> height;
  }

  print_pyramid(height);
  return 0;
}
