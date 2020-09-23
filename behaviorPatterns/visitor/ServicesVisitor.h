#pragma once


class BrazedCard;
class SilverCard;
class GoldCard;

class ServicesVisitor {
public:
    virtual ~ServicesVisitor() {};

    virtual void visit(BrazedCard* card) = 0;
    virtual void visit(SilverCard* card) = 0;
    virtual void visit(GoldCard* card) = 0;
};