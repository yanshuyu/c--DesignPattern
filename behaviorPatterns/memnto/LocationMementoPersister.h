#pragma once
#include<fstream>
#include"LocationMemento.h"

class LocationMementoPersister {
public:
    LocationMementoPersister(const std::string& memenPath);
    ~LocationMementoPersister();
    bool save(const LocationMemento& m);
    std::pair<bool,LocationMemento> load();

private:
    //std::fstream fs;
    std::ifstream ifs;
    std::ofstream ofs;
    std::string memenPath;
};