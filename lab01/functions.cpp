#include <cmath>
#include <sstream>
#include "functions.h"
using namespace std;

// 1. feladat
int countBits(int number) {
    int count = 0;
    while (number != 0) {
        count += number & 1;
        number >>= 1;
    }
    return count;
}

// 2. feladat
bool setBit(int& number, int order) {
    if (order < 0 || order > 31)
        return false;
    number |= (1u << order);
    return true;
}

// 3. feladat
double mean(double array[], int numElements) {
    if (numElements == 0)
        return NAN;
    double sum = 0;
    for (int i = 0; i < numElements; i++)
        sum += array[i];
    return sum / numElements;
}

// 4. feladat
double stddev(double array[], int numElements) {
    if (numElements == 0)
        return NAN;
    double m = mean(array, numElements);
    double sum = 0;
    for (int i = 0; i < numElements; i++)
        sum += (array[i] - m) * (array[i] - m);
    return sqrt(sum / numElements);
}

// 5. feladat
pair<double, double> max2(double array[], int numElements) {
    if (numElements == 0)
        return pair<double, double>(NAN, NAN);
    if (numElements == 1)
        return pair<double, double>(array[0], array[0]);

    // a elso ketto kozul a kisebb az elso, a nagyobb a masodik
    double small = array[0];
    double big = array[1];
    if (small > big) {
        double tmp = small;
        small = big;
        big = tmp;
    }
    for (int i = 2; i < numElements; i++) {
        if (array[i] > big) {
            small = big;
            big = array[i];
        }
        else if (array[i] > small) {
            small = array[i];
        }
    }
    return pair<double, double>(small, big);
}

// string 2. feladat
int countWords(string text) {
    istringstream in(text);
    string word;
    int count = 0;
    while (in >> word)
        count++;
    return count;
}

// string 3. feladat
string code(string text) {
    for (int i = 0; i < text.size(); i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            if (text[i] == 'z') text[i] = 'a';
            else text[i]++;
        }
        else if (text[i] >= 'A' && text[i] <= 'Z') {
            if (text[i] == 'Z') text[i] = 'A';
            else text[i]++;
        }
    }
    return text;
}

string decode(string text) {
    for (int i = 0; i < text.size(); i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            if (text[i] == 'a') text[i] = 'z';
            else text[i]--;
        }
        else if (text[i] >= 'A' && text[i] <= 'Z') {
            if (text[i] == 'A') text[i] = 'Z';
            else text[i]--;
        }
    }
    return text;
}

// string 4. feladat
string capitalizeWords(string text) {
    bool newWord = true;   // most kezdodik-e uj szo
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == ' ' || text[i] == '\t') {
            newWord = true;
        }
        else {
            if (newWord)
                text[i] = toupper(text[i]);
            else
                text[i] = tolower(text[i]);
            newWord = false;
        }
    }
    return text;
}