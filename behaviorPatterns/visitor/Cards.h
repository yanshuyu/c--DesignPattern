#pragma once
#include"CreditCard.h"
#include"ServicesVisitor.h"



class BrazedCard: public CreditCard {
public:
    BrazedCard(float balance = 0);

    void accept(ServicesVisitor* visitor) override;
};




class SilverCard: public CreditCard {
public:
    SilverCard(float balance = 0);
    void accept(ServicesVisitor* visitor) override;
};



class GoldCard: public CreditCard {
public:
    GoldCard(float balance = 0);
    void accept(ServicesVisitor* visitor) override;
};