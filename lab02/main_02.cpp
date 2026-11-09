#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Point.h"
#include "util.h"
using namespace std;
 
int main() {
    srand(time(0));
 
    // 1. feladat
    Point p1(2, 3);
    cout << "p1( " << p1.getX() << "," << p1.getY() << ")" << endl;
    Point* pp1 = new Point(300, 400);
    cout << "pp1( " << pp1->getX() << "," << pp1->getY() << ")" << endl;
    delete pp1;
 
    // 2. feladat: print
    cout << "\nprint: ";
    p1.print();
    cout << endl;
 
    // 3. feladat: tavolsag
    Point a(0, 0), b(3, 4);
    cout << "\ntavolsag: " << distance(a, b) << endl;
 
    // 4. feladat: negyzet
    Point c(0, 4), d(3, 0);
    cout << "\nisSquare: " << isSquare(Point(10, 10), Point(10, 20), Point(20, 20), Point(20, 10)) << endl;
 
    // 5. feladat: fajlbol
    cout << "\ntestIsSquare:" << endl;
    testIsSquare("points.txt");
 
    // 6-7. feladat: tomb
    int n = 20;
    Point* arr = createArray(n);
    cout << "\ntomb:" << endl;
    printArray(arr, n);
 
    // 8. legkozelebbi
    pair<Point, Point> cl = closestPoints(arr, n);
    cout << "\nlegkozelebbi: ";
    cl.first.print();
    cout << " ";
    cl.second.print();
    cout << endl;
 
    // 9. legtavolabbi
    pair<Point, Point> fa = farthestPoints(arr, n);
    cout << "legtavolabbi: ";
    fa.first.print();
    cout << " ";
    fa.second.print();
    cout << endl;
 
    // 11. origotol legtavolabbi 10 (a rendezes elott, mert az atrendezi a tombot)
    Point* far10 = farthestPointsFromOrigin(arr, n);
    cout << "\norigotol legtavolabbi 10:" << endl;
    printArray(far10, 10);
    deletePoints(far10);
 
    // 10. rendezes
    cout << "\nrendezve x szerint:" << endl;
    sortPoints(arr, n);
 
    // 12. felszabaditas
    deletePoints(arr);
 
    return 0;
}