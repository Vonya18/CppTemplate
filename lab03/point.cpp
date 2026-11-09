#include <cmath>
#include "Point.h"
using namespace std;

Point::Point(int x, int y) {
    if (x >= 0 && x <= M && y >= 0 && y <= M) {
        this->x = x;
        this->y = y;
    }
    else {
        this->x = 0;
        this->y = 0;
    }
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

double Point::distanceTo(const Point& point) const {
    double dx = x - point.x;
    double dy = y - point.y;
    return sqrt(dx * dx + dy * dy);
} 