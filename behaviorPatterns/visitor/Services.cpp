#include"Services.h"
#include"Cards.h"


Service::Service(const std::string& name, float price, float discount):m_name(name)
, m_price(price)
, m_discount(discount) {

}


FoodService::FoodService(const std::string& name, float price, float discount):Service(name, price, discount) {

}

void FoodService::visit(BrazedCard* card) {
    setDiscount(0.95);
}

void FoodService::visit(SilverCard* card) {
    setDiscount(0.9);
}

void FoodService::visit(GoldCard* card) {
    setDiscount(0.8);
}


HotelService::HotelService(const std::string& name, float price, float discount):Service(name, price, discount) {

}


void HotelService::visit(BrazedCard* card) {
    setDiscount(0.99);
}

void HotelService::visit(SilverCard* card) {
    setDiscount(0.9);
}

void HotelService::visit(GoldCard* card) {
    setDiscount(0.85);
}

GasService::GasService(const std::string& name, float price, float discount):Service(name, price, discount) {

}

void GasService::visit(BrazedCard* card) {
    setDiscount(1.0);
}

void GasService::visit(SilverCard* card) {
    setDiscount(0.9);
}

void GasService::visit(GoldCard* card) {
    setDiscount(0.8);
}