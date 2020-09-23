#pragma once
#include"UIControl.h"
#include"singleton.h"
#include<unordered_map>
#include<stdexcept>
#include<string>

class IControlFactory {
public:
    virtual ~IControlFactory() {};
    virtual UIControl* create(UIScheme s) = 0;
};



template<typename T> class ControlFactoryBase: public IControlFactory {
    typedef T ControlCreater;
public:
    virtual ~ControlFactoryBase() {};

    virtual UIControl* create(UIScheme s) override {
        std::string msg("this method must impl in subclass");
        throw std::logic_error(msg.c_str());
        return nullptr;
    }

    void registerCreater(UIScheme s, ControlCreater c) {
        this->m_creaters[s] = c;
    }

    void removeCreater(UIScheme s) {
        auto pos = this->m_creaters.find(s);
        if (pos != this->m_creaters.end()) {
            this->m_creaters.erase(pos);
        }
    }

    bool hasCreater(UIScheme s) {
        return this->m_creaters.find(s) != this->m_creaters.end();
    }

protected:
    std::unordered_map<UIScheme, ControlCreater> m_creaters;
};



class UIControlFactory: public Singleton<UIControlFactory> {
public:
    void registerFactory(ControlType ct, IControlFactory* f);
    void removeFactory(ControlType ct);
    bool hasFactory(ControlType ct) const;

    UIControl* create(ControlType ct, UIScheme s);
private:
    std::unordered_map<ControlType, IControlFactory*> m_factorys;
};
