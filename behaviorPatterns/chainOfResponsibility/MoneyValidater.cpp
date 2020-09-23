#include"MoneyValidater.h"
#include<iostream>


CashValidater::CashValidater(const std::pair<float, float>& devidation):m_sizeDeviation(devidation) {

}

bool CashValidater::validateMoney(const Money* const m) {
    if (m == nullptr)
        return false;

    auto stdDimension = m->getStandardDimension();
    if (stdDimension.first == stdDimension.second) { // this is a coin, not cash
        if (m_nextValidater)
            return m_nextValidater->validateMoney(m);
        else 
            return false;
    }
    
    auto dimension = m->getDimension();
    auto minDimension = std::make_pair(stdDimension.first * (1 - m_sizeDeviation.first), stdDimension.second * (1 - m_sizeDeviation.second));
    auto maxDimension = std::make_pair(stdDimension.first * (1 + m_sizeDeviation.first), stdDimension.second * (1 + m_sizeDeviation.second));

    if (dimension.first >= minDimension.first 
        && dimension.first <= maxDimension.first
        && dimension.second >= minDimension.second
        && dimension.second <= maxDimension.second) {
            std::cout << "accept cash " << m->getRMBValue() << " RMB" << std::endl;
            return true;
    }
    
    if (m_nextValidater) 
        return m_nextValidater->validateMoney(m);
    else 
        return false;
}




CoinValidater::CoinValidater(const std::pair<float, float>& deviation):m_diameterDeviation(deviation.first)
, m_weightDeviation(deviation.second) {

}

bool CoinValidater::validateMoney(const Money* const m) {
    if (m == nullptr)
        return false;
        
    auto stdDimension = m->getStandardDimension();
    if (stdDimension.first != stdDimension.second) { // this is cash, not coin
        if (m_nextValidater)
            return m_nextValidater->validateMoney(m);
        else
            return false;
    }
    
    auto diameter = m->getDimension().first;
    auto minDiametr = stdDimension.first * (1 - m_diameterDeviation);
    auto maxDiameter = stdDimension.first * (1 + m_diameterDeviation);

    if (diameter < minDiametr || diameter > maxDiameter) {
        if (m_nextValidater)
            return m_nextValidater->validateMoney(m);
        else
            return false;
    }

    auto stdWeight = m->getStandardWeight();
    auto weight = m->getWeight();
    auto minWeight = stdWeight * (1 - m_weightDeviation);
    auto maxWeight = stdWeight * (1 + m_weightDeviation);

    if (weight < minWeight || weight > maxWeight) {
        if (m_nextValidater)
            return m_nextValidater->validateMoney(m);
        else
            return false;
    }

    std::cout << "accept coin " << m->getRMBValue() << " RMB" << std::endl;
    return true;
}