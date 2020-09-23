#include"OpenglRenderer.h"
#include<iostream>

void OpenglRenderer::drawLine(const Point& p1, const Point& p2) {
    std::cout << "gl draw line: " << p1 << " -> " << p2 << std::endl;
}

void OpenglRenderer::drawRect(const Point& original, float width, float height) {
    std::cout << "gl draw rect, orignal: " << original << " dimension: { " << width <<", " << height << " }" << std::endl;
}

void OpenglRenderer::drawArc(const Point& center, float radius, float fromAngle, float toAngle) {
    std::cout << "gl draw Arc, center: " << center << " radis: " << radius << " from angle: " << fromAngle << " to angle: " << toAngle << std::endl;
}