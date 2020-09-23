#include"Triangle.h"
#include<vector>
#include<algorithm>

Triangle::Triangle():Triangle(Point::zero, Point::zero, Point::zero) {

}

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3) {
    this->points[0] = p1;
    this->points[1] = p2;
    this->points[2] = p3;
}

Triangle::Triangle(const Point* const points) {
    this->points[0] = points[0];
    this->points[1] = points[1];
    this->points[2] = points[2];
}

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3, RendererAPI* renderer):Triangle(p1,p2,p3) {
    rendererImp = renderer;
}

Triangle::Triangle(const Point* const points, RendererAPI* renderer):Triangle(points) {
    rendererImp = renderer;
}

bool Triangle::operator == (const Triangle& other) const {
    std::vector<Point> selfPoints(points, points + 3);
    std::vector<Point> otherPoints(other.points, other.points + 3);
    return std::is_permutation(selfPoints.begin(), selfPoints.end(), otherPoints.begin());
}

bool Triangle::operator != (const Triangle& other) const {
    return !(*this == other);
}

float Triangle::area() const {
    float len = Point::distanceBetween(points[1], points[2]);
    Point mid((points[1].x + points[2].x) * 0.5f, (points[1].y + points[2].y) * 0.5f );
    float height = Point::distanceBetween(points[0], mid);
    
    return len * height * 0.5;
}


void Triangle::draw() {
    if (rendererImp != nullptr) {
        rendererImp->drawLine(points[0], points[1]);
        rendererImp->drawLine(points[1], points[2]);
        rendererImp->drawLine(points[2], points[0]);
    }
}



std::ostream& operator << (std::ostream& o, const Triangle& t) {
    o << "[" << t.points[0] << ", " << t.points[1] << ", " << t.points[2] << "]";
    return o;
}