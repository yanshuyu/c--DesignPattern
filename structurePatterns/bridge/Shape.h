#pragma once
#include"RendererAPI.h"

enum class ShapeType {
    Triangle,
    Rect,
    Circle,
};


class Shape {
public:
    virtual ~Shape() {};
    virtual float area() const = 0;
    virtual void draw() = 0;

    void setRenderer(RendererAPI* render) {
        rendererImp = render;
    }

    RendererAPI* getRenderer() const {
        return rendererImp;
    }
protected:
    RendererAPI* rendererImp;
};