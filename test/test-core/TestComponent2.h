//
// Created by admin on 1/2/2017.
//

#ifndef RETROFUNK_TESTCOMPONENT2_H
#define RETROFUNK_TESTCOMPONENT2_H

#include "Component.h"

class TestComponent2 : public Component {
protected:
    std::vector<State> InternalSerialize() override;
};


#endif //RETROFUNK_TESTCOMPONENT2_H
