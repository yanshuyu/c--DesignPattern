#pragma once

template<typename T> class Singleton {
public:
    static T& getInstance() {
        static T share;
        return share;
    }

    virtual ~Singleton() {}

protected:
    Singleton() {};
    Singleton(const Singleton&) = delete;
    Singleton& operator = (const Singleton&) = delete;
};