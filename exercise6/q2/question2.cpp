#include <iostream>
#include <string>
using namespace std;

const int MAX = 80;



int min_form(char input[], int position);
void swap(char& a, char& b);

void string_sort(char input[]){
  int count = 0;
  while(input[count] != '\0'){
    swap(input[count], input[min_form(input, count)]);
    count++;
  }
}

void swap(char& a, char& b){
  char temp;
  temp = a;
  a = b;
  b = temp;
}

int min_form(char input[], int position){
  int min_index = position;
  int count = position + 1;
  while(input[count] != '\0'){
    if(input[count] < input[min_index]){
	min_index = count;
    }
    count++;
  }
 
  return min_index;
}

int main(){
  char input[MAX];
  string  output;
  cout << "Type in a string:\n";
  cin.getline(input, MAX);
  string_sort(input);
  cout << "Sorted string is " << input << "\n";
  
  //output = string_sort(input);
  //cout << "The sorted string is: " << output << "\n";

  return 0;
}
