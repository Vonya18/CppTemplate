#include <cmath>
#include "Polynomial.h"
using namespace std;

// Konstruktor: lemasolja az egyutthatokat.
// A felesleges, 0 egyutthato vezeto tagokat elhagyja (pl. 0x^2 + 3x + 1 -> 3x + 1)
Polynomial::Polynomial(int degree, const double coefficients[]) {
    int start = 0;
    while (start < degree && coefficients[start] == 0) {
        start++;
    }
    capacity = degree + 1 - start;
    this->coefficients = new double[capacity];
    for (int i = 0; i < capacity; i++) {
        this->coefficients[i] = coefficients[start + i];
    }
}

// Masolo konstruktor: melyen masol (uj tombot foglal)
Polynomial::Polynomial(const Polynomial &that) {
    capacity = that.capacity;
    coefficients = new double[capacity];
    for (int i = 0; i < capacity; i++) {
        coefficients[i] = that.coefficients[i];
    }
}

Polynomial::~Polynomial() {
    delete[] coefficients;
}

int Polynomial::degree() const {
    return capacity - 1;
}

// Horner-modszer: a0*x^n + ... + an = (...((a0*x + a1)*x + a2)*x ...) + an
double Polynomial::evaluate(double x) const {
    double result = coefficients[0];
    for (int i = 1; i < capacity; i++) {
        result = result * x + coefficients[i];
    }
    return result;
}

// Derivalt: az a_i * x^(n-i) tag derivaltja (n-i) * a_i * x^(n-i-1)
Polynomial Polynomial::derivative() const {
    int n = degree();
    if (n == 0) {
        double zero[1] = {0};
        return Polynomial(0, zero);
    }
    double* d = new double[n];
    for (int i = 0; i < n; i++) {
        d[i] = (n - i) * coefficients[i];
    }
    Polynomial result(n - 1, d);
    delete[] d;
    return result;
}

// a_index egyutthato (index = 0 a legnagyobb fokszamu tag)
double Polynomial::operator[](int index) const {
    if (index < 0 || index >= capacity) {
        return 0;
    }
    return coefficients[index];
}

// Egyoperandusu minusz: minden egyutthato elojelet megforditja
Polynomial operator -(const Polynomial &a) {
    int n = a.capacity;
    double* r = new double[n];
    for (int i = 0; i < n; i++) {
        r[i] = -a.coefficients[i];
    }
    Polynomial result(n - 1, r);
    delete[] r;
    return result;
}

// Osszeadas: az egyutthatokat a vegetol (alacsony fokszamtol) igazitjuk
Polynomial operator +(const Polynomial &a, const Polynomial &b) {
    int na = a.capacity;
    int nb = b.capacity;
    int n = na;
    if (nb > n) n = nb;

    double* r = new double[n];
    for (int i = 0; i < n; i++) {
        r[i] = 0;
    }
    for (int i = 0; i < na; i++) {
        r[n - na + i] += a.coefficients[i];
    }
    for (int i = 0; i < nb; i++) {
        r[n - nb + i] += b.coefficients[i];
    }
    Polynomial result(n - 1, r);
    delete[] r;
    return result;
}

Polynomial operator -(const Polynomial &a, const Polynomial &b) {
    return a + (-b);
}

// Szorzas: minden tag minden taggal, az i+j. helyre kerul
Polynomial operator *(const Polynomial &a, const Polynomial &b) {
    int na = a.capacity;
    int nb = b.capacity;
    int n = na + nb - 1;

    double* r = new double[n];
    for (int i = 0; i < n; i++) {
        r[i] = 0;
    }
    for (int i = 0; i < na; i++) {
        for (int j = 0; j < nb; j++) {
            r[i + j] += a.coefficients[i] * b.coefficients[j];
        }
    }
    Polynomial result(n - 1, r);
    delete[] r;
    return result;
}

// Kiiras: pl. 2x^2 + 3x - 1
ostream & operator <<(ostream& out, const Polynomial& what) {
    bool first = true;
    for (int i = 0; i < what.capacity; i++) {
        double c = what.coefficients[i];
        int power = what.capacity - 1 - i;
        if (c == 0) {
            continue;   // a 0 egyutthatos tagot nem irjuk ki
        }
        // elojel
        if (first) {
            if (c < 0) out << "-";
        } else {
            if (c < 0) out << " - ";
            else out << " + ";
        }
        first = false;
        // egyutthato (az 1-et nem irjuk ki x elott)
        double absC = fabs(c);
        if (absC != 1 || power == 0) {
            out << absC;
        }
        // x es kitevo
        if (power > 0) out << "x";
        if (power > 1) out << "^" << power;
    }
    if (first) {
        out << "0";   // csupa nulla egyutthato
    }
    return out;
}