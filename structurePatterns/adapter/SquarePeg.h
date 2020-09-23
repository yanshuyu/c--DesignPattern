#pragma once

class SquarePeg {
public:
    SquarePeg(float w = 0):m_width(w) {
        
    }
    
    void setWidth(float w) {
        m_width = w;
    }

    float getWidth() const {
        return m_width;
    }
private:
    float m_width;
};