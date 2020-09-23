#include"Point.h"
#include<cmath>

const Point Point::zero(0,0);

Point::Point():Point(0,0) {

}   

Point::Point(float x, float y) {
    this->x = x;
    this->y = y;
}

bool Point::operator == (const Point& other) const {
    return this->x == other.x && this->y == other.y;
}

bool Point::operator != (const Point& other) const {
    return !(*this == other);
}

float Point::distanceBetween(const Point& p1, const Point& p2) {
    return sqrtf( powf(p1.x - p2.x, 2) + powf(p1.y - p2.y, 2) );
}

float Point::distanceTo(const Point& other) const {
    return sqrtf( powf(this->x - other.x, 2) + powf(this->y - other.y, 2) );
} 



std::ostream& operator << (std::ostream& o, const Point& p) {
    o << "{" << p.x << ", " << p.y << "}";
    return o;
}