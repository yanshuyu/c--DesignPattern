#include"UIButton.h"
#include<iostream>

UIButton::UIButton():UIButton("", Rect::zero) {

}

UIButton::UIButton(const Rect& f):UIButton("", f) {

}

UIButton::UIButton(const std::string& t, const Rect& f) {
    this->title = t;
    this->frame = f;
}

UIButton::~UIButton() {
    std::cout << __FUNCTION__ << std::endl;
}

void UIButton::draw() {
    std::cout << "[UIButton title: " << title << ", frame: " << frame << ", apperance: normal]" << std::endl;
}



void UIDarkButton::draw() {
    std::cout << "[UIButton title: " << title << ", frame: " << frame << ", apperance: dark]" << std::endl;
}

UIDarkButton::~UIDarkButton() {
    std::cout << __FUNCTION__ << std::endl;
}

