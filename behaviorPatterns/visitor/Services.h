#pragma once
#include"ServicesVisitor.h"
#include<string>

class Service {
public:
    Service(const std::string& name, float price, float discount = 1);
    virtual ~Service() {};

    std::string getName() const {
        return m_name;
    }

    float getPrice() const {
        return m_price;
    }

    float getDiscount() const {
        return m_discount;
    }

    void setDiscount(float discount) {
        m_discount = discount;
    }

protected:
    float m_price;
    float m_discount;
    std::string m_name;

};


class FoodService: public Service, public ServicesVisitor {
public:
    FoodService(const std::string& name, float price, float discount = 1);
    void visit(BrazedCard* card) override;
    void visit(SilverCard* card) override;
    void visit(GoldCard* card) override;
};



class HotelService: public Service, public ServicesVisitor {
public:
    HotelService(const std::string& name, float price, float discount = 1);
    void visit(BrazedCard* card) override;
    void visit(SilverCard* card) override;
    void visit(GoldCard* card) override;
};



class GasService: public Service, public ServicesVisitor {
public:
    GasService(const std::string& name, float price, float discount = 1);
    void visit(BrazedCard* card) override;
    void visit(SilverCard* card) override;
    void visit(GoldCard* card) override;
};

