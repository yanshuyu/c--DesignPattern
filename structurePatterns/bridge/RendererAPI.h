#pragma once
#include"Point.h"

class RendererAPI {
public:
    virtual ~RendererAPI() {}

    virtual void drawLine(const Point& p1, const Point& p2) = 0;
    virtual void drawRect(const Point& original, float width, float height) = 0;
    virtual void drawArc(const Point& center, float radius, float fromAngle, float toAngle) = 0;
};