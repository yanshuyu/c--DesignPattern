#pragma once
#include"RoundPeg.h"


class RoundHold {
public:
    RoundHold(float r = 0):m_radius(r) {

    }

    bool fitPeg(const RoundPeg* rp) const {
        return m_radius >= rp->getRadius();
    }

    void setRadius(float r) {
        m_radius = r;
    }

    float getRadius() const {
        return m_radius;
    }

private:
    float m_radius;
};