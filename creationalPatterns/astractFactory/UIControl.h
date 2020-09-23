#pragma once
#include"Rect.h"
#include<vector>

enum class UIScheme {
    NoramlApperance,
    DrakApperance,
};


enum class ControlType {
    Button,
    Slider,
};

class UIControl {
    // ui control properties and operations
public:
    virtual ~UIControl() {};
public:
    Rect frame;
    virtual void draw() = 0;
};