#pragma once
#include"SquarePeg.h"
#include"RoundPeg.h"
#include<memory>
#include<cmath>

class SqurePegAdapter: public RoundPeg {
public:
    SqurePegAdapter(std::shared_ptr<SquarePeg> sp):m_adaptee(sp) {

    }

    void setRadius(float r) override {
        if (m_adaptee != nullptr) {
            m_adaptee->setWidth(sqrtf(2 * r * r));
        }
    }

    float getRadius() const override {
        if (m_adaptee != nullptr) {
            return sqrtf(m_adaptee->getWidth() * m_adaptee->getWidth() * 0.5);
        }
        return 0;
    }
private:
    std::shared_ptr<SquarePeg> m_adaptee;
};