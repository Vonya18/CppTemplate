#ifndef POINT_H
#define POINT_H

const int M = 2000;

class Point{
private:
    int x, y;
public:
    Point(int x = 0, int y = 0);
    int getX() const;
    int getY() const;
    double distanceTo(const Point& point) const;
};

#endif /* POINT_H */