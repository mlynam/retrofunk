//
// Created by admin on 1/2/2017.
//

#ifndef RETROFUNK_STATE_H
#define RETROFUNK_STATE_H

#include <unordered_map>

enum StateType : char {
    uninitialized,
    integer,
    floating_point,
    string,
    bit
};

struct State {
    State() {}
    State(StateType type, size_t size, void *value) : type(type), size(size), value(value) {}

    StateType type;
    size_t size;
    void* value;
};

#endif //RETROFUNK_STATE_H
