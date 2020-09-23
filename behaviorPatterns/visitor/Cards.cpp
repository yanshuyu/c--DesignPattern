#include"Cards.h"

BrazedCard::BrazedCard(float balance) {
    m_balance = balance;
}

void BrazedCard::accept(ServicesVisitor* visitor) {
    visitor->visit(this);
}




SilverCard::SilverCard(float balance) {
    m_balance = balance;
}

void SilverCard::accept(ServicesVisitor* visitor) {
    visitor->visit(this);
}



GoldCard::GoldCard(float balance) {
    m_balance = balance;
}

void GoldCard::accept(ServicesVisitor* visitor) {
    visitor->visit(this);
}


