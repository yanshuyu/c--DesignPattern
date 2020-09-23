#pragma once
#include"singleton.h"
#include"UIControl.h"
#include"UISlider.h"
#include"UIControlFactory.h"
#include<functional>

typedef std::function<UISlider*(void)> SliderCreater;

class UISliderFactory: public Singleton<UISliderFactory>, public ControlFactoryBase<SliderCreater> {
public: 
    UIControl* create(UIScheme s) override;
};