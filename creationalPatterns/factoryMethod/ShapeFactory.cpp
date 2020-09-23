#include"ShapeFactory.h"


void ShapeFactory::registerShapeCreater(ShapeCreater creater, ShapeType type) {
    this->creaters[type] = creater;
}

void ShapeFactory::removeShapeCreater(ShapeType type) {
    auto pos = this->creaters.find(type);
    if (pos != this->creaters.end()) {
        this->creaters.erase(pos);
    }
}

bool ShapeFactory::hasShapeCreater(ShapeType type) const {
    return this->creaters.find(type) != this->creaters.end();
}

ShapeFactory::ShapeCreater::result_type ShapeFactory::create(ShapeType type) {
    return this->creaters[type]();
}