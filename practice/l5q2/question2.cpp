#include <iostream>

using namespace std;


void print_pyramid(int height){
  const int MARGIN = 10;
  int line;

  cout << "\n\n";

  for(line = 1; line< height; line++){
    int count;
    int no_space = MARGIN + height - line;
    for(count = 1; count<=no_space; count++){
      cout << " "; 
    }
    for(count = 1; count<= line*2; count++){
      cout << "*";
    }
    cout << "\n";
  }


}

bool check_range(int height){
  return (height >=1 && height <=30);
}

int main(){
  int height;

  cout << "This program prints a 'pyramid' shape of a specified heigh on the screen\n";
  cout << "How high would you like the pyramid?\n";
  cin >> height;
  cout << "\n";

  while(!check_range(height)){
    cout << "Pick another height (must be between 1 and 30)\n";
    cin >> height;
  }

  print_pyramid(height);
  return 0;
}
