#ifndef STATISTICS_H
#define STATISTICS_H

double average(int first);
double average(int first, int second);
double average(int first, int second, int third);
double average(int first, int second, int third, int fourth);

double standard_deviation(int first);
double standard_deviation(int first, int second, double avg_result);
double standard_deviation(int first, int second, int third, double avg_result);
double standard_deviation(int first, int second, int third, int fourth, double avg_result);

#endif
