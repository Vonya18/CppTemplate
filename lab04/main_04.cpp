#include <iostream>
#include "Polynomial.h"
using namespace std;

int main() {
    double ca[] = {2, 3, 1};    // 2x^2 + 3x + 1
    double cb[] = {1, -4};      // x - 4
    Polynomial a(2, ca);
    Polynomial b(1, cb);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    // degree
    cout << "\ndegree(a) = " << a.degree() << "  (varhato: 2)" << endl;
    cout << "degree(b) = " << b.degree() << "  (varhato: 1)" << endl;

    // evaluate
    cout << "\na(2) = " << a.evaluate(2) << "  (varhato: 15)" << endl;
    cout << "b(4) = " << b.evaluate(4) << "  (varhato: 0)" << endl;

    // derivative
    cout << "\na' = " << a.derivative() << "  (varhato: 4x + 3)" << endl;
    cout << "b' = " << b.derivative() << "  (varhato: 1)" << endl;
    cout << "(b')' = " << b.derivative().derivative() << "  (varhato: 0)" << endl;

    // index operator
    cout << "\na[0] = " << a[0] << ", a[1] = " << a[1] << ", a[2] = " << a[2]
         << ", a[5] = " << a[5] << "  (varhato: 2 3 1 0)" << endl;

    // operatorok
    cout << "\n-a    = " << -a << "  (varhato: -2x^2 - 3x - 1)" << endl;
    cout << "a + b = " << a + b << "  (varhato: 2x^2 + 4x - 3)" << endl;
    cout << "a - b = " << a - b << "  (varhato: 2x^2 + 2x + 5)" << endl;
    cout << "a * b = " << a * b << "  (varhato: 2x^3 - 5x^2 - 11x - 4)" << endl;
    cout << "a - a = " << a - a << "  (varhato: 0)" << endl;

    // masolo konstruktor: a masolat a torles utan is mukodik
    cout << "\nmasolo konstruktor:" << endl;
    double cc[] = {5, 0, -1};
    Polynomial* p = new Polynomial(2, cc);
    Polynomial q(*p);
    delete p;
    cout << "q = " << q << "  (varhato: 5x^2 - 1)" << endl;

    // vezeto nullak
    double cd[] = {0, 0, 3, 1};
    Polynomial d(3, cd);
    cout << "\nd = " << d << ", foka: " << d.degree() << "  (varhato: 3x + 1, fok 1)" << endl;

    return 0;
}