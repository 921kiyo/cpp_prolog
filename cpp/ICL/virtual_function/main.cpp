#include<iostream>
#include"expression.cpp"

using namespace std;

int main() {
	Number n2(2), n3(3), n_1(-1);
	cout << n_1 << endl;
	// SIMPLE OUTPUT : -1 = -1
	// MINIMUM OUTPUT: -1 = -1

	Addition a1(n2, n_1);
	cout << a1 << endl;
	// // SIMPLE OUTPUT : (2)+(-1) = 1
	// // MINIMUM OUTPUT: 2+(-1) = 1
  //
	Addition a2(n_1, n3);
	cout << a2 << endl;
	// // SIMPLE OUTPUT : (-1)+(3) = 2
	// // MINIMUM OUTPUT: -1+3 = 2
  //
	Multiplication m1(n3, a1);
	cout << m1 << endl;
	// // SIMPLE OUTPUT : (3)*((2)+(-1)) = 3
	// // MINIMUM OUTPUT: 3*(2+(-1)) = 3
  //
	Addition a3(m1, a1);
	cout << a3 << endl;
	// // SIMPLE OUTPUT : ((3)*(2+(-1)))+(2+(-1)) = 4
	// // MINIMUM OUTPUT: 3*(2+(-1))+(2+(-1)) = 4
  //
	Addition a4(a1, m1);
	cout << a4 << endl;
	// SIMPLE OUTPUT : ((2)+(-1))+((3)*(2+(-1))) = 4
	// MINIMUM OUTPUT: 2+(-1)+3*(2+(-1)) = 4
	return 0;
}
