#pragma once
#include"shape.h"
#include"Point.h"
#include<array>
#include<iostream>


class Rect: public Shape {
public:
    static const Rect zero;

public:
    Rect();
    Rect(float w, float h);
    Rect(const Point& o, float w, float h);
    Rect(float w, float h, RendererAPI* renderer);
    Rect(const Point& o, float w, float h, RendererAPI* renderer);

    bool operator == (const Rect& other) const;
    bool operator != (const Rect& other) const;
    
    float area() const override;
    void draw() override;
    Rect intersetRect(const Rect& other) const;
    Rect unionRect(const Rect& other) const;
    bool isInterset(const Rect& other) const;
    bool isPointInside(const Point& p) const;
    
public:
    Point origin;
    float width;
    float height;

private: 
    std::array<Point, 4> _pointes() const;
};



std::ostream& operator << (std::ostream& o, const Rect& r);