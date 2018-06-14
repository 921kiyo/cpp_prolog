#include <iostream>
#include <cmath>

using namespace std;

int main(){
  const int a_f = 77617;
  const int b_f = 33096;

  /*
  float first_f = 333.75*pow(b_f, 6) + pow(a_f,2) * (11*pow(a_f,2)*pow(b_f,2) - 121 * pow(b_f, 4) - 2);
  float second_f = first_f + 5.5*pow(b_f,8);
  float third_f = second_f - pow(a_f,2)*pow(b_f,6);
  float answer_f = third_f + a_f/2*b_f;
  cout << "The answer in float is " << answer_f << "\n";
  */
  
  float answer_f2 = (((333.75*pow(b_f, 6) + pow(a_f,2) * (11*pow(a_f,2)*pow(b_f,2) - 121 * pow(b_f, 4) - 2)) + 5.5*pow(b_f,8)) - pow(a_f,2)*pow(b_f,6)) + a_f/(2*b_f);
  cout << "The answer in float2 is " << answer_f2 << "\n";



  /*
  double first_d = 333.75*pow(b_d, 6) + pow(a_d,2) * (11*pow(a_d,2)*pow(b_d,2) - 121 * pow(b_d, 4) - 2);
  double second_d = first_d + 5.5*pow(b_d,8);
  double third_d = second_d - pow(a_d,2)*pow(b_d,6);
  double answer_d = third_d + a_d/2*b_d;
  cout << "The answer in double is " << answer_d << "\n";
  */
  double answer_d2 = (((333.75*pow(b_f, 6) + pow(a_f,2) * (11*pow(a_f,2)*pow(b_f,2) - 121 * pow(b_f, 4) - 2)) + 5.5*pow(b_f,8)) - pow(a_f,2)*pow(b_f,6)) + a_f/2*b_f;
  cout << "The answer in double2 is " << answer_d2 << "\n";


  /*
  long double first_ld = 333.75*pow(b_ld, 6) + pow(a_ld,2) * (11*pow(a_ld,2)*pow(b_ld,2) - 121 * pow(b_ld, 4) - 2);
  
  
  long double second_ld = first_ld + 5.5*pow(b_ld,8);
  long double third_ld = second_ld - pow(a_ld,2)*pow(b_ld,6);
  long double answer_ld = third_ld + a_ld/2*b_ld;
  cout << "The answer in long double is " << answer_ld << "\n";
  */

  long double answer_ld2 = (((333.75*pow(b_f, 6) + pow(a_f,2) * (11*pow(a_f,2)*pow(b_f,2) - 121 * pow(b_f, 4) - 2)) + 5.5*pow(b_f,8)) - pow(a_f,2)*pow(b_f,6)) + a_f/2*b_f;
  cout << "The answer in long double2 is " << answer_ld2 << "\n";


  return 0;
}
