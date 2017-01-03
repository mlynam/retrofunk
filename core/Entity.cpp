//
// Created by admin on 1/2/2017.
//

#include "Entity.h"

Entity::Entity(Serializer* ser) : serializer_(ser) {

}

void Entity::Serialize() {
    // Platform serialization
    for (auto &&component : components_) {
        component.second->Serialize(serializer_);
    }
}

Entity::~Entity() {
    for (auto &&item : components_) {
        delete item.second;
    }
    components_.clear();
}

std::vector<Component *> Entity::GetComponents() {
    auto components = std::vector<Component *>();
    for (auto &&component : components_) {
        components.push_back(component.second);
    }
    return components;
}
