#include"Triangle.h"
#include"Rect.h"
#include"Circle.h"
#include"ShapeFactory.h"
#include<memory>
#include<iostream>



using std::cout;
using std::endl;




int main() {
    auto triangleCreater = []() {
        return new Triangle();
    };

    auto rectCreater = []() {
        return new Rect();
    };

    auto circleCreater = []() {
        return new Circle();
    };

    ShapeFactory& factory = ShapeFactory::getInstance();
    factory.registerShapeCreater(triangleCreater, ShapeType::Triangle);
    factory.registerShapeCreater(rectCreater, ShapeType::Rect);
    factory.registerShapeCreater(circleCreater, ShapeType::Circle);

    auto t_ptr = factory.create(ShapeType::Triangle);
    auto r_ptr = factory.create(ShapeType::Rect);
    auto c_ptr = factory.create(ShapeType::Circle);

    auto p_trianle = dynamic_cast<Triangle*>(t_ptr);
    auto p_rect = dynamic_cast<Rect*>(r_ptr);
    auto p_circle = dynamic_cast<Circle*>(c_ptr);

    if (p_trianle != nullptr) {
        p_trianle->points[1] = Point(2,0);
        p_trianle->points[2] = Point(1, 0);
    }

    if (p_rect != nullptr) {
        p_rect->width = 4;
        p_rect->height = 2;
    }

    if (p_circle != nullptr) {
        p_circle->radius = 6;
    }

    cout << "t aera: " << t_ptr->area() << endl;
    cout << "p area: " << r_ptr->area() << endl;
    cout << "c area: " << c_ptr->area() << endl;

    delete t_ptr;
    delete r_ptr;
    delete c_ptr;

    return 0;
}