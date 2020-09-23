#pragma once
#include"MoneyValidater.h"
#include<vector>

class VendingMachine {
public:
    VendingMachine(std::shared_ptr<MoneyValidater> mv);
    bool insertMoney(std::shared_ptr<Money> m);
    float totalInsertedMoney() const;
private:
    std::shared_ptr<MoneyValidater> m_moneyValider;
    std::vector<std::shared_ptr<Money>> m_moneys;
};