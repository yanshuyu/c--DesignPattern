#include<iostream>
#include<memory>
#include"Cards.h"
#include"Services.h"
#include<vector>

using std::cout;
using std::endl;


int main() {
    std::vector<std::shared_ptr<CreditCard>> cards = { std::shared_ptr<CreditCard>(new BrazedCard(100)),
                    std::shared_ptr<CreditCard>(new SilverCard(100)),
                    std::shared_ptr<CreditCard>(new GoldCard(100))};


    auto foodService = std::shared_ptr<FoodService>(new FoodService("food services", 9.9));
    
    for (auto card : cards) {
        cout << "card befor pay: " << card->getBalance() << endl;
        card->accept(foodService.get());
        card->pay(foodService->getPrice() * foodService->getDiscount());
        cout << "card after pay: " << card->getBalance() << endl;
    }


    return 0;
}