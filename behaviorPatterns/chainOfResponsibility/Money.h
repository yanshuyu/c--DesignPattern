#pragma once
#include<utility>
#include<memory>

class Money {
public:
    Money(float v, const std::pair<float, float>& sd, float sw, const std::pair<float, float>& s, float w):m_rmbValue(v)
    , m_standardDimension(sd)
    , m_standardWeight(sw)
    , m_dimension(s)
    , m_weight(w) {

    }

    std::pair<float, float> getStandardDimension() const {
        return m_standardDimension;
    }

    float getStandardWeight() const {
        return m_standardWeight;
    }

    float getRMBValue() const {
        return m_rmbValue;
    }

    std::pair<float, float> getDimension() const {
        return m_dimension;
    }

    float getWeight() const {
        return m_weight;
    }


protected:
    const float m_rmbValue;
    const std::pair<float, float> m_standardDimension;
    const std::pair<float, float> m_dimension;
    const float m_standardWeight;
    const float m_weight;
};


std::shared_ptr<Money> make_cash(float rmbValue, float w = 0, float h = 0);
std::shared_ptr<Money> make_coin(float rmbValue, float d = 0, float w = 0);

