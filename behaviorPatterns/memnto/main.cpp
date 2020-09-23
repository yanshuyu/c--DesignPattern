#include<iostream>
#include"Location.h"
#include"LocationMementoPersister.h"

using std::cout;
using std::endl;


int main() {
    LocationMementoPersister persister("C:\\Users\\SY\\Documents\\c++DesignPattern\\behaviorPatterns\\memnto\\locmemn.txt");
    Location location;

    auto persistMemen = persister.load();

    if (persistMemen.first) {
        location.restore(persistMemen.second);
        cout << "persist location: " << location << endl;
    } else {
        cout << "no persist location!" << endl;
        location.longitude = 255.8;
        location.latitude = 20.4;
        location.name = "shenzhen-china";
        bool success = persister.save(location.save());
        cout << "save: " << location << "\nsuccess: " << success << endl;
    }


    return 0;
}