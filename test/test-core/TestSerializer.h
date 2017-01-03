//
// Created by admin on 1/2/2017.
//

#ifndef RETROFUNK_TEST_SERIALIZER_H
#define RETROFUNK_TEST_SERIALIZER_H

#include "Serializer.h"

class TestSerializer : public Serializer {

public:
    void Serialize(const std::vector<State> &vector) override;

public:
    State saved_state;
    TestSerializer() {}
};


#endif //RETROFUNK_TEST_SERIALIZER_H
