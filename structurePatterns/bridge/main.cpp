#include<iostream>
#include<memory>
#include<vector>
#include"Triangle.h"
#include"Rect.h"
#include"Circle.h"
#include"OpenglRenderer.h"
#include"DirectxRenderer.h"



int main() {
    std::shared_ptr<RendererAPI> glRenderer(new OpenglRenderer());
    std::shared_ptr<RendererAPI> dxRenderer(new DirectxRenderer());

    std::shared_ptr<Shape> trianle(new Triangle(Point(1,1), Point(3,1), Point(2,2)));
    std::shared_ptr<Shape> rect(new Rect(Point(5,5), 4, 3));
    std::shared_ptr<Shape> circle(new Circle(Point(8,8), 4));

    std::vector<std::shared_ptr<Shape>> shapes = {trianle, rect, circle};
    for (auto shape : shapes) {
        shape->setRenderer(glRenderer.get());
        shape->draw();
    }

    for (auto shape : shapes) {
        shape->setRenderer(dxRenderer.get());
        shape->draw();
    }

    return 0;
}