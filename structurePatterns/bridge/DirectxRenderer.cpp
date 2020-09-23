#include"DirectxRenderer.h"
#include<iostream>

void DirectxRenderer::drawLine(const Point& p1, const Point& p2) {
    std::cout << "dx draw line: " << p1 << " -> " << p2 << std::endl;
}

void DirectxRenderer::drawRect(const Point& original, float width, float height) {
    std::cout << "dx draw rect, orignal: " << original << " dimension: { " << width <<", " << height << " }" << std::endl;
}

void DirectxRenderer::drawArc(const Point& center, float radius, float fromAngle, float toAngle) {
    std::cout << "dx draw Arc, center: " << center << " radis: " << radius << " from angle: " << fromAngle << " to angle: " << toAngle << std::endl;
}