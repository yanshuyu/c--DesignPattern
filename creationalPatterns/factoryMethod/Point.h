#pragma once
#include<iostream>

class Point {
public:
    static const Point zero;
    static float distanceBetween(const Point& p1, const Point& p2);

public:
    Point();
    Point(float x, float y);

    bool operator == (const Point& other) const;
    bool operator != (const Point& other) const;

    float distanceTo(const Point& other) const;
    
public:
    float x;
    float y;
};


std::ostream& operator << (std::ostream& o, const Point& p);


