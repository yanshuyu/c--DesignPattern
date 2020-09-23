#pragma once
#include"RendererAPI.h"



class DirectxRenderer: public RendererAPI {
public:
    void drawLine(const Point& p1, const Point& p2) override;
    void drawRect(const Point& original, float width, float height)override;
    void drawArc(const Point& center, float radius, float fromAngle, float toAngle)override; 
};