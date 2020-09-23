#include"UISlider.h"
#include<iostream>


UISlider::UISlider():UISlider(Rect::zero) {

}


UISlider::UISlider(const Rect& f):UISlider(f,0,1,0) {

}

UISlider::UISlider(float min, float max):UISlider(Rect::zero, min, max, min) {

}

UISlider::UISlider(const Rect& f, float min, float max, float cur) {
    this->frame = f;
    this->minValue = min;
    this->maxValue = max;
    this->currentValue = cur;
}

UISlider::~UISlider() {
  std::cout << __FUNCTION__ << std::endl;   
}

void UISlider::draw() {
    std::cout << "[UISlider frame: " << frame << ", min: " << minValue << ", max: " << maxValue << ", current: " << currentValue << ", apperance: normal]" << std::endl; 
}


void UIDrakSlider::draw() {
    std::cout << "[UISlider frame: " << frame << ", min: " << minValue << ", max: " << maxValue << ", current: " << currentValue << ", apperance: dark]" << std::endl; 
}


UIDrakSlider::~UIDrakSlider() {
    std::cout << __FUNCTION__ << std::endl; 
}