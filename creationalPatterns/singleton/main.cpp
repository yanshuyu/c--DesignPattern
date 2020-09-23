#include<iostream>
#include<string>
#include"singleton.h"

using namespace std;


class FileSystem: public Singleton<FileSystem> {
public:
    string currentWorkingDirectry() const {
        return __FILE__;
    }


    ~FileSystem() {
        cout << __FUNCTION__ << endl;
    }
};




int main() {
    cout << FileSystem::getInstance().currentWorkingDirectry()  << endl;

    FileSystem* f1 = &FileSystem::getInstance();
    FileSystem* f2 = &FileSystem::getInstance();

    cout << f1 << "\t" << f2 << endl;

    return 0;
}
