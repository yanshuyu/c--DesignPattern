#include<iostream>
#include"UIButtonFactory.h"
#include"UISliderFactory.h"
#include<memory>

using std::cout;
using std::endl;


int main() {

    auto buttonFactory = &UIButtonFactory::getInstance();
    auto sliderFactory = &UISliderFactory::getInstance();

    ButtonCreater normalBC = []() {
        return new UIButton();
    };

    ButtonCreater darkBC = []() {
        return new UIDarkButton();
    };

    SliderCreater normalSC = []() {
        return new UISlider();
    };

    SliderCreater darkSC = [] {
        return new UIDrakSlider();
    };

    buttonFactory->registerCreater(UIScheme::NoramlApperance, normalBC);
    buttonFactory->registerCreater(UIScheme::DrakApperance, darkBC);
    sliderFactory->registerCreater(UIScheme::NoramlApperance, normalSC);
    sliderFactory->registerCreater(UIScheme::DrakApperance, darkSC);

    auto& controlFactory = UIControlFactory::getInstance();
    controlFactory.registerFactory(ControlType::Button, buttonFactory);
    controlFactory.registerFactory(ControlType::Slider, sliderFactory);

    std::vector<UIControl*> ctls;
    ctls.push_back(controlFactory.create(ControlType::Button, UIScheme::NoramlApperance));
    ctls.push_back(controlFactory.create(ControlType::Button, UIScheme::DrakApperance));
    ctls.push_back(controlFactory.create(ControlType::Slider, UIScheme::NoramlApperance));
    ctls.push_back(controlFactory.create(ControlType::Slider, UIScheme::DrakApperance));

    for(auto ctrl : ctls) {
        ctrl->draw();
        delete ctrl;
    }


    return 0;
}