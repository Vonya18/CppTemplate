// string 1. feladat: a parancssor szamainak osszege
#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, char* argv[]) {
    double sum = 0;
    for (int i = 1; i < argc; i++) {
        istringstream in(argv[i]);
        double number;
        if (in >> number)
            sum += number;
    }
    cout << "Osszeg: " << sum << endl;
    return 0;
}