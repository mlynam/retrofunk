//
// Created by admin on 1/2/2017.
//

#include "gtest/gtest.h"
#include "Entity.h"
#include "TestEntity.h"
#include "TestComponent.h"
#include "TestComponent2.h"
#include "TestSerializer.h"

class EntityTests : public ::testing::Test {
public:
    TestSerializer* serializer;

protected:
    virtual void TearDown() {
        delete serializer;
    }

    virtual void SetUp() {
        serializer = new TestSerializer;
    }
};


TEST_F(EntityTests, serialize_entity) {
    auto entity = TestEntity(this->serializer);
    entity.Initialize();
    entity.Serialize();

    for (auto &&item : entity.GetComponents()) {
        ASSERT_TRUE(static_cast<TestComponent*>(item)->saved);
    }
}

TEST_F(EntityTests, add_component_already_exists) {
    auto entity = TestEntity(this->serializer);
    entity.Initialize();

    ASSERT_THROW(entity.Add<TestComponent>(), std::logic_error);
}

TEST_F(EntityTests, add_component) {
    auto entity = Entity(this->serializer);
    auto component = entity.Add<TestComponent>();

    ASSERT_FALSE(component->saved);
}

TEST_F(EntityTests, get_component) {
    auto entity = TestEntity(this->serializer);
    entity.Initialize();

    ASSERT_TRUE(entity.GetComponent<TestComponent>());
}

TEST_F(EntityTests, add_multiple_components) {
    auto entity = TestEntity(this->serializer);
    entity.Initialize();
    auto component = entity.Add<TestComponent2>();

    ASSERT_TRUE(component);
    ASSERT_EQ(entity.GetComponents().size(), 2);
}

TEST_F(EntityTests, add_or_replace_component) {
    auto entity = TestEntity(this->serializer);
    entity.Initialize();

    auto component = entity.AddOrReplace<TestComponent>();

    ASSERT_TRUE(component);
}

TEST_F(EntityTests, remove_component) {
    auto entity = TestEntity(this->serializer);
    entity.Initialize();

    entity.RemoveComponent<TestComponent>();

    ASSERT_EQ(entity.GetComponents().size(), 0);
}

TEST_F(EntityTests, get_component_not_exists) {
    auto entity = TestEntity(this->serializer);
    entity.Initialize();

    ASSERT_FALSE(entity.GetComponent<TestComponent2>());
    ASSERT_EQ(entity.GetComponents().size(), 1);
}

// Dumb sanity check
TEST_F(EntityTests, create_entity) {
    auto entity = TestEntity(this->serializer);
    entity.Initialize();

    auto components = entity.GetComponents();
    ASSERT_EQ(components.size(), 1);
}


