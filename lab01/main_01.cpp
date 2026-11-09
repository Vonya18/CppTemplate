#include <iostream>
#include <cmath>
#include "functions.h"
using namespace std;

int main() {
    // 1. feladat
    cout << "--- countBits ---" << endl;
    for (int i = 0; i <= 127; i++)
        cout << i << ": " << countBits(i) << endl;
    // Szabalyossag: countBits(2n) = countBits(n), countBits(2n+1) = countBits(n)+1,
    // a sorozat blokkonkent ismetlodik, a kovetkezo blokk = az elozo + 1.

    // 2. feladat
    cout << "\n--- setBit ---" << endl;
    for (int i = 0; i < 35; ++i) {
        int n = 0;
        if (setBit(n, i)) {
            cout << i << " ---> " << n << endl;
        } else {
            cout << "Impossible operation!" << endl;
        }
    }

    // 3-5. feladat
    cout << "\n--- mean, stddev, max2 ---" << endl;
    double t[] = {2, 4, 4, 4, 5, 5, 7, 9};
    cout << "atlag: " << mean(t, 8) << endl;      // 5
    cout << "szoras: " << stddev(t, 8) << endl;   // 2
    pair<double, double> p = max2(t, 8);
    cout << "ket legnagyobb: " << p.first << " " << p.second << endl;  // 7 9

    double egy[] = {3.5};
    p = max2(egy, 1);
    cout << "egy elem: " << p.first << " " << p.second << endl;

    p = max2(t, 0);
    cout << "ures: " << p.first << " " << p.second << endl;
    cout << "ures atlag: " << mean(t, 0) << endl;
    cout << "ures szoras: " << stddev(t, 0) << endl;

    // string 2. feladat
    cout << "\n--- countWords ---" << endl;
    cout << countWords("  alma   korte szilva ") << endl;   // 3

    // string 3. feladat
    cout << "\n--- code / decode ---" << endl;
    string s = "Hello Zebra, xyz!";
    string c = code(s);
    cout << c << endl;
    cout << decode(c) << endl;
    if (decode(c) == s)
        cout << "OK" << endl;
    else
        cout << "HIBA" << endl;

    return 0;
}