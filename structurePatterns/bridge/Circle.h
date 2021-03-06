#pragma once
#include"Shape.h"
#include"Point.h"
#include<iostream>


class Circle: public Shape {
public:
    static const float pi;

public:
    Circle();
    Circle(float r);
    Circle(const Point& c, float r);
    Circle(float r, RendererAPI* renderer);
    Circle(const Point& c, float r, RendererAPI* renderer);

    float area() const override;
    void draw() override;
    float length() const;
   
public:
    Point center;    
    float radius;
};


std::ostream& operator << (std::ostream& o, const Circle& c);

