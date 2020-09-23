#pragma once
#include"Money.h"

class MoneyValidater {
public:
    virtual ~MoneyValidater() {}

    virtual bool validateMoney(const Money* const m) = 0;

    std::shared_ptr<MoneyValidater> nextValidarer() const {
        return m_nextValidater;
    }

    void setNextValidater(MoneyValidater* v) {
        std::shared_ptr<MoneyValidater> sv(v);
        m_nextValidater.swap(sv);
    }
    
    void setNextValidater(std::shared_ptr<MoneyValidater> sv) {
        m_nextValidater.swap(sv);
    }
    
protected:
    std::shared_ptr<MoneyValidater> m_nextValidater;
};



class CashValidater: public MoneyValidater {
public:
    CashValidater(const std::pair<float, float>& devidation = std::make_pair(0.1, 0.1));
    bool validateMoney(const Money* const m) override;
private:
    std::pair<float, float> m_sizeDeviation;
};



class CoinValidater: public MoneyValidater {
public:
    CoinValidater(const std::pair<float, float>& deviation = std::make_pair(0.02, 0.02));
    bool validateMoney(const Money* const m) override;
private:
    float m_diameterDeviation;
    float m_weightDeviation;
};