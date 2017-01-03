//
// Created by admin on 1/2/2017.
//

#include "TestEntity.h"
#include "TestComponent.h"

TestEntity::TestEntity(Serializer *serializer) : Entity(serializer) {

}

void TestEntity::Initialize() {
    this->Add<TestComponent>();
}
