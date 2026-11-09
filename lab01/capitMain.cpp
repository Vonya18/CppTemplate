// string 4. feladat: sorok beolvasasa vegjelig (Ctrl+D)
#include <iostream>
#include <string>
#include "functions.h"
using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        cout << capitalizeWords(line) << endl;
    }
    return 0;
}