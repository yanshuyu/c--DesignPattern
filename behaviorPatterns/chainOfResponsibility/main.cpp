#include<iostream>
#include"VendingMachine.h"
#include"MoneyValidater.h"



int main() {

    auto cashValidater = std::shared_ptr<MoneyValidater>(new CashValidater());
    auto coinValidater = std::shared_ptr<MoneyValidater>(new CoinValidater());
    cashValidater->setNextValidater(coinValidater);

    auto vendingMachine = std::shared_ptr<VendingMachine>(new VendingMachine(cashValidater));

    auto coin_point_five_rmb = make_coin(0.5);
    auto cash_ten_rmb = make_cash(10);
    auto coin_one_rmb_invailded = make_coin(1, 100, 1000);
    auto cash_five_rmb_invailed = make_cash(5, 100, 100);
    auto cash_five_rmb = make_cash(5);

    vendingMachine->insertMoney(coin_point_five_rmb);
    vendingMachine->insertMoney(cash_ten_rmb);
    vendingMachine->insertMoney(coin_one_rmb_invailded);
    vendingMachine->insertMoney(cash_five_rmb_invailed);
    vendingMachine->insertMoney(cash_five_rmb);

    std::cout << "total accpeted: " << vendingMachine->totalInsertedMoney() << std::endl;

    return 0;
}