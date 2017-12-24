#include <iostream>
#include <cstdlib>

using namespace std;

void print_backwards();
int factorial(int number);

void quick_sort(int list[], int left, int right);
void display(int a[], int length);
void swap(int& first, int& second);

// int main(){
//   // print_backwards();
//   cout << factorial(10);
//   cout << endl;
//
//   return 0;
// }
const int MAX = 11;
int main()
{
	int list[MAX];
	int count;

	for (count = 0 ; count < MAX ; count++)
	{
		cout << "Enter value of element " << count << ": ";
		cin >> list[count];
	}

	cout << "\n\nBefore Quick Sort:\n\n";

	display(list,MAX);

	quick_sort(list, 0, MAX -1);

	cout << "\n\nAfter Quick Sort:\n\n";

	display(list,MAX);

	return 0;
}


void print_backwards(){
  char character;
  cout << "Enter a character ('.' to end program): ";
  cin >> character;
  if(character != '.'){
    print_backwards();
    cout << character;
  }
}

int factorial(int number){
  if(number < 0){
    cout << "\nError - negative argument to factorial \n";
    exit(1);
  }
  else if (number == 0){
    return 1;
  }else{
    return (number * factorial(number - 1));
  }
}

float raised_to_power(float number, int power){
  if(power < 0){
    cout << "Error - can't raise to a negative power" << endl;
    exit(1);
  }
  else if( power == 0){
    return (1.0);
  }
  else{
    return (number * raised_to_power(number, power - 1));
  }
}

int sum_of(int a[], int n){
  if(n == 1){
    return a[0];
  }
  else{
    return (a[n-1] + sum_of(a, n-1));
  }
}

void quick_sort(int list[], int left, int right){
  int pivot, left_arrow, right_arrow;

  left_arrow = left;
  right_arrow = right;

  pivot = list[(left + right)/2];

  do
  {
      while(list[right_arrow] > pivot)
        right_arrow--;
      while(list[left_arrow] < pivot)
        left_arrow++;
      if(left_arrow <= right_arrow){
        swap(list[left_arrow], list[right_arrow]);
        left_arrow++;
        right_arrow--;
      }
  }while(right_arrow >= left_arrow);

  if(left < right_arrow){
    quick_sort(list, left, right_arrow);
  }
  if(left_arrow < right){
    quick_sort(list, left_arrow, right);
  }
}

void swap(int& first, int& second){
  int temp = first;
  first = second;
  second = temp;
}

void display(int a[], int length){
  for(int i = 0; i< length; i++){
    cout << a[i] << " ";
  }
  cout << endl;
}
