//
// Created by admin on 1/2/2017.
//

#ifndef RETROFUNK_TEST_COMPONENT_H
#define RETROFUNK_TEST_COMPONENT_H

#include "Component.h"

class TestComponent : public Component {

protected:
    std::vector<State> InternalSerialize() override;

public:
    bool saved = false;
};


#endif //RETROFUNK_TEST_COMPONENT_H
