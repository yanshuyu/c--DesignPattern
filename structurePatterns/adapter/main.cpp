#include<iostream>
#include<memory>
#include"RoundPeg.h"
#include"RoundHold.h"
#include"SquarePeg.h"
#include"SquarePegAdapter.h"


using std::cout;
using std::endl;


int main() {
    auto hold = std::unique_ptr<RoundHold>(new RoundHold(6));
    auto rp_1 = std::unique_ptr<RoundPeg>(new RoundPeg(8));
    auto rp_2 = std::unique_ptr<RoundPeg>(new RoundPeg(4));

    auto sp_1 = std::shared_ptr<SquarePeg>(new SquarePeg(8));
    auto sp_2 = std::shared_ptr<SquarePeg>(new SquarePeg(16));
    auto sp_1_ad = std::unique_ptr<RoundPeg>(new SqurePegAdapter(sp_1));
    auto sp_2_ad = std::unique_ptr<RoundPeg>(new SqurePegAdapter(sp_2));

    cout << "rp_1(radius: " << rp_1->getRadius() << ") " << "can fit to hold(radius: " << hold->getRadius() << ")? " << hold->fitPeg(rp_1.get()) << endl; 
    cout << "rp_2(radius: " << rp_2->getRadius() << ") " << "can fit to hold(radius: " << hold->getRadius() << ")? " << hold->fitPeg(rp_2.get()) << endl;

    cout << "sp_1(width: " << sp_1->getWidth() << ", radius: " << sp_1_ad->getRadius()  << ") can fit to hold(radius: " << hold->getRadius() << ")? " << hold->fitPeg(sp_1_ad.get()) << endl;
    cout << "sp_2(width: " << sp_2->getWidth() << ", radius: " << sp_2_ad->getRadius()  << ") can fit to hold(radius: " << hold->getRadius() << ")? " << hold->fitPeg(sp_2_ad.get()) << endl; 

    sp_2_ad->setRadius(4);
    cout << "sp_1(width: " << sp_2->getWidth() << ", radius: " << sp_2_ad->getRadius()  << ") can fit to hold(radius: " << hold->getRadius() << ")? " << hold->fitPeg(sp_2_ad.get()) << endl;     
    return 0;
}