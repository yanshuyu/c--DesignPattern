#include"Money.h"



std::shared_ptr<Money> make_cash(float rmbValue, float w, float h) {
    auto _d = std::make_pair(w,h);
    float _w = 0;
    auto sd = std::make_pair(0, 0);
    auto sw = 0;

    if (rmbValue == 0.5) {
        sd = std::make_pair(10, 6);
        sw = 1;
        _w = sw;
        if (w == 0 && h == 0)
            _d = sd;

    } else if (rmbValue == 1) {
        sd = std::make_pair(15, 9);
        sw = 1.5;
        _w = sw;
        if (w == 0 && h == 0)
            _d = sd;
    } else if (rmbValue == 5) {
        sd = std::make_pair(18, 10);
        sw = 2;
        _w = sw;
        if (w == 0 && h == 0)
            _d = sd;
    } else if (rmbValue == 10) {
        sd = std::make_pair(22, 14);
        sw = 2.8;
        _w = sw;
        if (w == 0 && h == 0)
            _d = sd;
    } else if (rmbValue == 20) {
        sd = std::make_pair(28, 17);
        sw = 3.6;
        _w = sw;
        if (w == 0 && h == 0)
            _d = sd;
    } else {
        return nullptr;
    }

    return std::shared_ptr<Money>(new Money(rmbValue, sd, sw, _d, _w));

}

std::shared_ptr<Money> make_coin(float rmbValue, float d, float w) {
    auto _d = std::make_pair(d,d);
    float _w = w;
    auto sd = std::make_pair(0, 0);
    auto sw = 0;

    if (rmbValue == 0.1) {
        sd = std::make_pair(2, 2);
        sw = 5;
        if (d == 0)
            _d = sd;
        if (w == 0)
            _w = sw;

    } else if (rmbValue == 0.2) {
        sd = std::make_pair(3.5, 3.5);
        sw = 7;
        if (d == 0)
            _d = sd;
        if (w == 0)
            _w = sw;

    } else if (rmbValue == 0.5) {
        sd = std::make_pair(4.5, 4.5);
        sw = 8;
        if (d == 0)
            _d = sd;
        if (w == 0)
            _w = sw;

    } else if (rmbValue == 1) {
        sd = std::make_pair(6, 6);
        sw = 10;
        if (d == 0)
            _d = sd;
        if (w == 0)
            _w = sw;
    } else {
        return nullptr;
    }

    return std::shared_ptr<Money>(new Money(rmbValue, sd, sw, _d, _w));
}

