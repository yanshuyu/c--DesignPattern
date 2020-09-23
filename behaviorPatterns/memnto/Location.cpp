#include"Location.h"
#include"LocationMemento.h"

LocationMemento Location::save() const {
    LocationMemento m;
    m.name = name;
    m.logitude = longitude;
    m.latitude = latitude;
    
    return m;
}
    
void Location::restore(const LocationMemento& m) {
    name = m.name;
    longitude = m.logitude;
    latitude = m.latitude;
}


std::ostream& operator << (std::ostream& o, const Location& l) {
    o << "location: " << l.name << ", log: " << l.longitude << ", lat: " << l.latitude; 
    return o;
}