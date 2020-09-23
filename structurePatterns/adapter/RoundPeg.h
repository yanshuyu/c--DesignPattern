#pragma once


class RoundPeg {
public:
    RoundPeg(float r = 0):m_radius(r) {

    }

    virtual ~RoundPeg() {}

    virtual void setRadius(float r) {
        m_radius = r;
    }

    virtual float getRadius() const {
        return m_radius;
    }    
    
private:
    float m_radius;
};

