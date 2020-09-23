#pragma once
#include"singleton.h"
#include"Shape.h"
#include<functional>
#include<memory>
#include<map>


class ShapeFactory: public Singleton<ShapeFactory> {
    typedef std::function<Shape*(void)> ShapeCreater;
public:
    void registerShapeCreater(ShapeCreater creater, ShapeType type);
    void removeShapeCreater(ShapeType type);
    bool hasShapeCreater(ShapeType type) const;
    ShapeCreater::result_type create(ShapeType type);

private:
    std::map<ShapeType, ShapeCreater> creaters;
}; 