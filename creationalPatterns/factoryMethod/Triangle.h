#pragma once
#include"shape.h"
#include"Point.h"
#include<iostream>

class Triangle: public Shape {
public:
    Triangle();
    Triangle(const Point& p1, const Point& p2, const Point& p3);
    Triangle(const Point* const points);

    bool operator == (const Triangle& other) const;
    bool operator != (const Triangle& other) const;

    float area() const override;

public:
    Point points[3];
};


std::ostream& operator << (std::ostream& o, const Triangle& t);