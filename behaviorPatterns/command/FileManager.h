#pragma once
#include<string>
#include<vector>
#include<iostream>

class FileManager {
    friend std::ostream& operator << (std::ostream&, const FileManager&);

public:
    bool addItem(const std::string& item);
    bool removeItem(const std::string& item);
    bool renameItem(const std::string& item, const std::string& name);

private:
    std::vector<std::string> items;
};


std::ostream& operator << (std::ostream& o, const FileManager& f);