#include <iostream>
#include <cmath>
#include "statistics.h"

using namespace std;

double average(int first){
  cout << "Average: " << first << "\n";
  return static_cast<double>(first);
};

double average(int first, int second){
  double avg_result = static_cast<double>(first+second)/2;
  return avg_result;
};

double average(int first, int second, int third){
  double avg_result = static_cast<double>(first+second+third)/3;
  return avg_result;
};

double average(int first, int second, int third, int fourth){
  double avg_result = static_cast<double>(first+second+third+fourth)/4;
  return avg_result;
};

double standard_deviation(int first){
  return 0;
};

double standard_deviation(int first, int second, double avg_result){
  double arg_1 = (first - avg_result)*(first - avg_result);
  double arg_2 = (second - avg_result)*(second - avg_result);

  return sqrt(average(arg_1, arg_2));
};
double standard_deviation(int first, int second, int third, double avg_result){
  double arg_1 = (first - avg_result)*(first - avg_result);
  double arg_2 = (second - avg_result)*(second - avg_result);
  double arg_3 = (third - avg_result)*(third - avg_result);
  return sqrt(average(arg_1, arg_2, arg_3));
};
double standard_deviation(int first, int second, int third, int fourth, double avg_result){
  double arg_1 = (first - avg_result)*(first - avg_result);
  double arg_2 = (second - avg_result)*(second - avg_result);
  double arg_3 = (third - avg_result)*(third - avg_result);
  double arg_4 = (fourth - avg_result)*(fourth - avg_result);
  return sqrt(average(arg_1, arg_2, arg_3, arg_4));

};
