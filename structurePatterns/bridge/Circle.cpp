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

Circle::Circle(float r, RendererAPI* renderer):Circle(r) {
    rendererImp = renderer;
}

Circle::Circle(const Point& c, float r, RendererAPI* renderer):Circle(c, r) {
    rendererImp = renderer;
}

float Circle::area() const {
    return 2 * pi * radius * radius;
}


void Circle::draw() {
    if (rendererImp) {
        rendererImp->drawArc(center, radius, 0, 2*3.14159);
    }
}

float Circle::length() const {
    return 2 * pi * radius;
}


std::ostream& operator << (std::ostream& o, const Circle& c) {
    o << "[" << c.center << ", " << c.radius << "]";
    return o;
}

