#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <utility>
using namespace std;

int countBits(int number);
bool setBit(int& number, int order);
double mean(double array[], int numElements);
double stddev(double array[], int numElements);
pair<double, double> max2(double array[], int numElements);

int countWords(string text);
string code(string text);
string decode(string text);
string capitalizeWords(string text);

#endif