//
// Created by admin on 1/2/2017.
//

#ifndef RETROFUNK_SERIALIZER_H
#define RETROFUNK_SERIALIZER_H

#include "State.h"
#include <vector>

class Serializer {
public:
    virtual void Serialize(const std::vector<State> &) = 0;
};


#endif //RETROFUNK_SERIALIZER_H
