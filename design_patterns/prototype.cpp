#include <iostream>

using namespace std;

struct Point {
    int x{0}, y{0};

    Point() {}
    Point(const Point& other)
        : x(other.x)
        , y(other.y)
    {
    }
    // Point operator=(const Point& other) {
    //     x = other.x;
    //     y = other.y;
    //     return *this;
    // }

    Point(const int x, const int y)
        : x{x}
        , y{y}
    {
    }
};

struct Line {
    Point *start, *end;

    Line(Point* const start, Point* const end)
        : start(start)
        , end(end)
    {
    }

    Line(const Line& other) {
        start = new Point(*other.start);
        end = new Point(*other.end);
    }


    ~Line()
    {
        delete start;
        delete end;
    }

    Line deep_copy() const { return Line(*this); }
};

int main(void)
{
    Point p = Point{1, 2};
    Point p2 = Point{2, 4};
    Line l = Line(&p, &p2);
    Line l2 = l.deep_copy();
    l2.start->x = 10;
    cout << l.start->x << " " << l2.start->x << endl;
    return 0;
}

// Prototype Coding Exercise
// Given the provided code, you are asked to implement Line::deep_copy() to perform a deep copy of the current Line
// object.
//
// Beware memory leaks!
