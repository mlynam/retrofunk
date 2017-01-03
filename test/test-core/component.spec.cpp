//
// Created by admin on 1/2/2017.
//

#include "gtest/gtest.h"
#include "Component.h"
#include "TestComponent.h"
#include "TestSerializer.h"

TEST(ComponentTests, ComponentTests_Serialize_Test) {
    auto serializer = new TestSerializer;
    auto component = TestComponent();

    component.Serialize(serializer);

    ASSERT_TRUE(*static_cast<bool*>(serializer->saved_state.value));

    delete serializer;
}
