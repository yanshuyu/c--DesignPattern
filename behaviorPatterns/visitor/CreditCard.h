#pragma once

class ServicesVisitor;

class CreditCard {
    friend class ServicesVisitor;
public:
    virtual ~CreditCard() {};

    virtual void accept(ServicesVisitor* visitor) = 0;

    void indraw(float money) {
        m_balance += money;
    }

    void pay(float money) {
        m_balance -= money; 
    }

    float getBalance() const {
        return m_balance;
    }

protected:
    float m_balance;
};