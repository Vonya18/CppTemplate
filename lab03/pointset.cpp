#include <iostream>
#include <random>
#include <algorithm>
#include "PointSet.h"
using namespace std;

PointSet::PointSet(int n) {
    this->n = n;

    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, M);

    // addig sorsolunk, amig n kulonbozo pontunk nem lesz
    while (points.size() < n) {
        Point p(dist(mt), dist(mt));

        // megnezzuk, hogy volt-e mar ilyen pont
        bool volt = false;
        for (int i = 0; i < points.size(); i++) {
            if (points[i].getX() == p.getX() && points[i].getY() == p.getY()) {
                volt = true;
                break;
            }
        }
        if (!volt) {
            points.push_back(p);
        }
    }

    computeDistances();
}

void PointSet::computeDistances() {
    distances.clear();
    // minden parra egyszer (i < j)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            distances.push_back(points[i].distanceTo(points[j]));
        }
    }
}

double PointSet::maxDistance() const {
    if (distances.size() == 0) return 0;
    return *max_element(distances.begin(), distances.end());
}

double PointSet::minDistance() const {
    if (distances.size() == 0) return 0;
    return *min_element(distances.begin(), distances.end());
}

int PointSet::numDistances() const {
    return n * (n - 1) / 2;
}

void PointSet::printPoints() const {
    for (const Point& p : points) {
        cout << "(" << p.getX() << ", " << p.getY() << ")" << endl;
    }
}

void PointSet::printDistances() const {
    for (double d : distances) {
        cout << d << " ";
    }
    cout << endl;
}

// segedfuggvenyek a rendezeshez
bool compareX(const Point& a, const Point& b) {
    return a.getX() < b.getX();
}

bool compareY(const Point& a, const Point& b) {
    return a.getY() < b.getY();
}

void PointSet::sortPointsX() {
    sort(points.begin(), points.end(), compareX);
}

void PointSet::sortPointsY() {
    sort(points.begin(), points.end(), compareY);
}

void PointSet::sortDistances() {
    sort(distances.begin(), distances.end());
}

int PointSet::numDistinctDistances() {
    if (distances.size() == 0) return 0;
    // rendezes utan az egyenlok egymas mellett vannak
    sortDistances();
    int count = 1;
    for (int i = 1; i < distances.size(); i++) {
        if (distances[i] != distances[i - 1]) {
            count++;
        }
    }
    return count;
}