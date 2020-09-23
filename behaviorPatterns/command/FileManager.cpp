#include"FileManager.h"
#include<algorithm>

bool FileManager::addItem(const std::string& item) {
    if(std::find(items.begin(), items.end(), item) == items.end()){
        items.push_back(item);
        return true;
    }
    return false;
}


bool FileManager::removeItem(const std::string& item) {
    auto newEnd = std::remove(items.begin(), items.end(), item);
    bool success = newEnd != items.end();
    items.erase(newEnd,items.end());
    return success;
}


bool FileManager::renameItem(const std::string& item, const std::string& name) {
    bool hasNew = false;
    auto pos = items.end();

    for (auto itr = items.begin(); itr != items.end(); itr++) {
        if (*itr == item) {
            pos = itr;
        }
        if (*itr == name) {
            hasNew = true;
            break;
        }
    }

    if (!hasNew && pos != items.end()) {
        *pos = name;
        return true;
    }

    return false;
}


std::ostream& operator << (std::ostream& o, const FileManager& f) {
    std::for_each(f.items.begin(), f.items.end(), [&](const std::string& item){
        o << item << "\n";
    });
    return o;
}