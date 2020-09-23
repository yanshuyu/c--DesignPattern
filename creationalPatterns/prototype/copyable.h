#pragma once

template<typename T> class Copyable {
public:
    T copy() {
        return T(*((T*)this));
    }
};