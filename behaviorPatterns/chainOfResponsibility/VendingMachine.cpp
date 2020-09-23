#include"VendingMachine.h"
#include<algorithm>
#include<iostream>

VendingMachine::VendingMachine(std::shared_ptr<MoneyValidater> mv):m_moneyValider(mv) {

}

bool VendingMachine::insertMoney(std::shared_ptr<Money> m) {
    if (!m_moneyValider)
        return false;
    bool isValided = m_moneyValider->validateMoney(m.get());

    if (isValided) {
        m_moneys.push_back(m);
    } else {
        std::cout << "failed to validate money!" << std::endl;
    }

    return isValided;
}

float VendingMachine::totalInsertedMoney() const {
    float total = 0;
    std::for_each(m_moneys.begin(), m_moneys.end(), [&](decltype(m_moneys)::value_type m) {
        total += m->getRMBValue();
    });

    return total;
}