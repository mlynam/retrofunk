//
// Created by admin on 1/2/2017.
//

#ifndef RETROFUNK_TEST_ENTITY_H
#define RETROFUNK_TEST_ENTITY_H

#include "Entity.h"

class TestEntity : public Entity {
public:
    TestEntity(Serializer *);

    void Initialize();
};


#endif //RETROFUNK_TEST_ENTITY_H
