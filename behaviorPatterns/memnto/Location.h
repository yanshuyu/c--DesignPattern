#pragma once
#include<string>
#include<iostream>
#include"LocationMemento.h"

struct Location {
    std::string name;
    float longitude;
    float latitude;

    LocationMemento save() const;
    void restore(const LocationMemento& m);
};


std::ostream& operator << (std::ostream& o, const Location& l);


