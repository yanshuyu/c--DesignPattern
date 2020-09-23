#include"LocationMementoPersister.h"
#include<iostream>

LocationMementoPersister::LocationMementoPersister(const std::string& memenPath):memenPath(memenPath) {
    
}


LocationMementoPersister::~LocationMementoPersister() {
    //fs.close();
    ofs.close();
    ifs.close();
}

bool LocationMementoPersister::save(const LocationMemento& m) {
    if (!ofs.is_open()) {
        ofs.open(memenPath, std::ios::out);
    }

    if (!ofs.is_open())
        return false;

    ofs.setf(std::ios_base::fixed, std::ios_base::floatfield);
    
    ofs.seekp(std::ios_base::beg);
    ofs << m.name << "\n";
    ofs << m.logitude << "\n";
    ofs << m.latitude;

    return ofs.good();
}

std::pair<bool, LocationMemento> LocationMementoPersister::load() {
    if (!ifs.is_open()) {
        ifs.open(memenPath, std::ios::in);
    }

    if (!ifs.is_open())
        return std::make_pair(false, LocationMemento());
    
    ifs.seekg(std::ios::end);
    if (ifs.tellg() <= 0)
        return std::make_pair(false, LocationMemento());

    LocationMemento m;
    ifs.seekg(std::ios::beg);
    ifs >> m.name;
    ifs >> m.logitude;
    ifs >> m.latitude;
    
    if (!ifs.good() && ifs.eof())
        ifs.clear(std::ios_base::goodbit);

    return std::make_pair(ifs.good(), m);
}