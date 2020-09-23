#pragma once


enum class ShapeType {
    Triangle,
    Rect,
    Circle,
};


class Shape {
public:
    virtual float area() const = 0;
    virtual ~Shape() {};

};