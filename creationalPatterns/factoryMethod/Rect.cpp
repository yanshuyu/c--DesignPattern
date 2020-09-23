#include"Rect.h"
#include<cmath>
#include<vector>
#include<set>
#include<algorithm>

const Rect Rect::zero;

Rect::Rect():Rect(0,0) {

}

Rect::Rect(float w, float h):Rect(Point::zero, w, h) {

}

Rect::Rect(const Point& o, float w, float h) {
    this->origin = o;
    this->width = w;
    this->height = h;
}

bool Rect::operator == (const Rect& other) const {
    return this->origin == other.origin 
        && this->width == other.width
        && this->height == other.height;
}


bool Rect::operator != (const Rect& other) const {
    return !(*this == other);
}


float Rect::area() const {
    return width * height;
}


Rect Rect::intersetRect(const Rect& other) const {
    if(!isInterset(other))
        return Rect::zero;
    if(other.width <= 0 && other.height <= 0 )
        return Rect::zero;
    
    float x_dis = other.origin.x - origin.x;
    float y_dis = other.origin.y - origin.y;
    return Rect(other.origin, width - x_dis, height - y_dis);
}


Rect Rect::unionRect(const Rect& other) const {
    auto selfPoints = _pointes();
    auto otherPoints = other._pointes();
    std::vector<Point> points;
    std::set<float> x_coords;
    std::set<float> y_coords;
    std::insert_iterator<decltype(x_coords)> x_insert_pos(x_coords, x_coords.end());
    std::insert_iterator<decltype(y_coords)> y_insert_pos(y_coords, y_coords.end());
    
    points.reserve(8);
    points.insert(points.end(), selfPoints.begin(), selfPoints.end());
    points.insert(points.end(), otherPoints.begin(), otherPoints.end());

    std::transform(points.begin(), points.end(), x_insert_pos, [](const Point& p) {
        return p.x;
    });
    std::transform(points.begin(), points.end(), y_insert_pos, [](const Point& p) {
        return p.y;
    });
    
    auto x_itr = x_coords.begin();
    auto y_itr = y_coords.begin();

    std::cout << __FUNCTION__ << std::endl << "x_coords: ";
    while (x_itr != x_coords.end())
    {
        std::cout << *x_itr << "\t";
        x_itr++;
    }
    std::cout << std::endl << "y_coords: ";

    while (y_itr != y_coords.end())
    {
        std::cout << *y_itr << "\t";
        y_itr++;
    }
    std::cout << std::endl;

    Point leftTop( std::min_element(x_coords.begin(), x_coords.end()).operator*(), 
                    std::max_element(y_coords.begin(), y_coords.end()).operator*());
    Point rightBottom( std::max_element(x_coords.begin(), x_coords.end()).operator*(), 
                        std::min_element(y_coords.begin(), y_coords.end()).operator*());
    return Rect(leftTop, rightBottom.x - leftTop.x, leftTop.y - rightBottom.y);
}


bool Rect::isInterset(const Rect& other) const {
    return isPointInside(other.origin);
}


bool Rect::isPointInside(const Point& p) const {
    float x_dis = p.x - origin.x;
    float y_dis = p.y - origin.y;
    return x_dis >= 0 && x_dis <= width && y_dis >= 0 && y_dis <= height;
}


std::array<Point, 4> Rect::_pointes() const {
    std::array<Point, 4> points;
    points[0] = origin;
    points[1] = Point(origin.x + width, origin.y);
    points[2] = Point(origin.x + width, origin.y - height);
    points[3] = Point(origin.x, origin.y - height);
    return points;
}




std::ostream& operator << (std::ostream& o, const Rect& r) {
    o << "[" << r.origin << ", " << r.width << ", " << r.height << "]";
    return o;
}