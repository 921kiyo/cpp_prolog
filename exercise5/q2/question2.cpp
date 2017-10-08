#include <iostream>

using namespace std;

void print_pyramid(int height);

int main(){
  cout << "This program prints a 'pyramid' shape of a specified height on the screen.\n";
  int height;
  cout << "how hight would you like the pyramid?: \n";
  cin >> height;

  print_pyramid(height);
  
  return 0;
}

void print_pyramid(int height){
  int line;
  const int MARGIN = 10;

  cout << "\n\n";

  for(line = 1; line <= height; line++){
    int count;
    int total_space = MARGIN - height - line;
    for(count=1; count <= total_space; count++){
      cout << ' ';
    }
    for(count = 1; count <= line*2; count++){
      cout << '*';
    }
    cout << "\n";
  }
  cout << "\n\n";
  
}
