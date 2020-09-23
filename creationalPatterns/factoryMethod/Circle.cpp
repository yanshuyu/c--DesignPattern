#include"Circle.h"

const float Circle::pi(3.14159f);

Circle::Circle():Circle(0) {

}

Circle::Circle(float r):Circle(Point::zero, r) {

}

Circle::Circle(const Point& c, float r) {
    this->center = c;
    this->radius = r;
}

float Circle::area() const {
    return 2 * pi * radius * radius;
}

float Circle::length() const {
    return 2 * pi * radius;
}


std::ostream& operator << (std::ostream& o, const Circle& c) {
    o << "[" << c.center << ", " << c.radius << "]";
    return o;
}

