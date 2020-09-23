#pragma once
#include"shape.h"
#include"Point.h"
#include<iostream>

class Triangle: public Shape {
public:
    Triangle();
    Triangle(const Point& p1, const Point& p2, const Point& p3);
    Triangle(const Point* const points);
    Triangle(const Point& p1, const Point& p2, const Point& p3, RendererAPI* renderer);
    Triangle(const Point* const points, RendererAPI* renderer);

    bool operator == (const Triangle& other) const;
    bool operator != (const Triangle& other) const;

    float area() const override;
    void draw() override;

public:
    Point points[3];
};


std::ostream& operator << (std::ostream& o, const Triangle& t);