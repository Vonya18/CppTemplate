#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include "util.h"
using namespace std;
 
// segedfuggveny: tavolsag negyzete (egesz szam, nincs kerekitesi hiba)
int sqDist(const Point& a, const Point& b) {
    int dx = a.getX() - b.getX();
    int dy = a.getY() - b.getY();
    return dx * dx + dy * dy;
}
 
double distance(const Point& a, const Point& b) {
    return sqrt((double)sqDist(a, b));
}
 
bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d) {
    // mind a 6 tavolsag negyzete
    int t[6];
    t[0] = sqDist(a, b);
    t[1] = sqDist(a, c);
    t[2] = sqDist(a, d);
    t[3] = sqDist(b, c);
    t[4] = sqDist(b, d);
    t[5] = sqDist(c, d);
    sort(t, t + 6);
    // negyzet: 4 egyenlo oldal, 2 egyenlo atlo, atlo^2 = 2 * oldal^2
    if (t[0] == 0) return false;
    if (t[0] == t[1] && t[1] == t[2] && t[2] == t[3] &&
        t[4] == t[5] && t[4] == 2 * t[0]) {
        return true;
    }
    return false;
}
 
void testIsSquare(const char* filename) {
    ifstream f(filename);
    if (!f) {
        cout << "Nem sikerult megnyitni: " << filename << endl;
        return;
    }
    int x[4], y[4];
    while (f >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2] >> x[3] >> y[3]) {
        Point p[4];
        for (int i = 0; i < 4; i++) {
            p[i] = Point(x[i], y[i]);
            p[i].print();
            cout << " ";
        }
        if (isSquare(p[0], p[1], p[2], p[3]))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    f.close();
}
 
Point* createArray(int numPoints) {
    Point* arr = new Point[numPoints];
    for (int i = 0; i < numPoints; i++) {
        arr[i] = Point(rand() % 2001, rand() % 2001);
    }
    return arr;
}
 
void printArray(Point* points, int numPoints) {
    for (int i = 0; i < numPoints; i++) {
        points[i].print();
        cout << endl;
    }
}
 
pair<Point, Point> closestPoints(Point* points, int numPoints) {
    pair<Point, Point> best(points[0], points[1]);
    int bestDist = sqDist(points[0], points[1]);
    for (int i = 0; i < numPoints; i++) {
        for (int j = i + 1; j < numPoints; j++) {
            int d = sqDist(points[i], points[j]);
            if (d < bestDist) {
                bestDist = d;
                best = pair<Point, Point>(points[i], points[j]);
            }
        }
    }
    return best;
}
 
pair<Point, Point> farthestPoints(Point* points, int numPoints) {
    pair<Point, Point> best(points[0], points[1]);
    int bestDist = sqDist(points[0], points[1]);
    for (int i = 0; i < numPoints; i++) {
        for (int j = i + 1; j < numPoints; j++) {
            int d = sqDist(points[i], points[j]);
            if (d > bestDist) {
                bestDist = d;
                best = pair<Point, Point>(points[i], points[j]);
            }
        }
    }
    return best;
}
 
bool compareX(const Point& a, const Point& b) {
    return a.getX() < b.getX();
}
 
void sortPoints(Point* points, int numPoints) {
    sort(points, points + numPoints, compareX);
    printArray(points, numPoints);
}
 
// az origotol legtavolabbi 10 pont, egyetlen bejarassal
Point* farthestPointsFromOrigin(Point* points, int numPoints) {
    Point origin(0, 0);
    Point* result = new Point[10];
    int count = 0;
    for (int i = 0; i < numPoints; i++) {
        if (count < 10) {
            result[count] = points[i];
            count++;
        }
        else {
            // megkeressuk az eredmenyben a legkozelebbit az origohoz
            int minIndex = 0;
            for (int j = 1; j < 10; j++) {
                if (sqDist(result[j], origin) < sqDist(result[minIndex], origin))
                    minIndex = j;
            }
            // ha az uj pont messzebb van, kicsereljuk
            if (sqDist(points[i], origin) > sqDist(result[minIndex], origin))
                result[minIndex] = points[i];
        }
    }
    return result;
}
 
void deletePoints(Point* points) {
    delete[] points;
}