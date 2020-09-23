#pragma once    
#include"UIControl.h"
#include<string>


class UIButton: public UIControl {
public:
    UIButton();
    UIButton(const Rect& f);
    UIButton(const std::string& t, const Rect& f);
    virtual ~UIButton();

    virtual void draw() override;
public:
    std::string title;
}; 




class UIDarkButton: public UIButton {
public:
    void draw() override;
    ~UIDarkButton();
};