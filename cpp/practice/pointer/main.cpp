#include <iostream>

using namespace std;

void manipulate(double *value){
  *value = 10.0;
}

int main(){
  double nValue = 8.0;

  double* pnValue = &nValue;

  cout << "nValue: " << nValue << endl;
  cout << "P nValue: " << pnValue << endl; // Getting the address
  cout << "P nValue: " <<* pnValue << endl; // Dereferencing
  manipulate(&nValue);
  cout << "After the change, nValue is " << nValue << "\n";


  string array[] = {"one", "two", "three"};

  string *pArray = array;
  cout << "Pointer Array \n";
  for(int i = 0; i< sizeof(array)/sizeof(string); i++){
    cout << *pArray << " ";

    pArray++;
  }
  cout << "\n";


  string *pStart = &array[0];
  string *pEnd = &array[2];

  while(true){
    cout << *pStart << " ";
   

    if(pStart == pEnd){
      break;
    }
    pStart++;
    
  }
  return 0;
}
