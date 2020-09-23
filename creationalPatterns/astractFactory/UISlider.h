#pragma once
#include"UIControl.h"


class UISlider: public UIControl {
public:
    UISlider();
    UISlider(const Rect& f);
    UISlider(float min, float max);
    UISlider(const Rect& f, float min, float max, float cur);
    virtual ~UISlider();

    virtual void draw() override;
public:
    float minValue;
    float maxValue;
    float currentValue;
}; 


class UIDrakSlider: public UISlider {
public:
    void draw() override;
    ~UIDrakSlider();
};