#pragma once
#include"UIButton.h"
#include"singleton.h"
#include"UIControlFactory.h"
#include<functional>

typedef std::function<UIButton*(void)> ButtonCreater;

class UIButtonFactory: public Singleton<UIButtonFactory>, public ControlFactoryBase<ButtonCreater> {
public:
    ~UIButtonFactory() {};
    UIControl* create(UIScheme s) override;
};