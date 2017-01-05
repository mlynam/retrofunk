//
// Created by admin on 1/2/2017.
//

#ifndef RETROFUNK_ENTITY_H
#define RETROFUNK_ENTITY_H

#include <unordered_map>
#include <type_traits>
#include <typeindex>
#include "Component.h"
#include "Serializer.h"

class Entity {
public:
    /// Construct a new entity. Entities serve as component factories and the base game object
    /// \param serializer The serializer used to persist the components.
    Entity(Serializer* serializer);

    virtual ~Entity();
    virtual void Serialize();

    Entity(Entity&) = delete;
    Entity(Entity&&);

    std::vector<Component*> GetComponents();

    /// Adds a new component to the entity.
    /// \throws std::logic_error if the component already exists
    /// \tparam ComponentType The component type.
    /// \return A pointer to the component.
    template<typename ComponentType>
    ComponentType* Add() {
        ENSURE_VALID_COMPONENT_TYPE(ComponentType);
        auto id = COMPONENT_ID(ComponentType);
        if (components_.count(id)) {
            throw std::logic_error("ComponentExists: use AddOrReplace to replace the existing Component of this type.");
        }
        auto component = new ComponentType;
        components_[id] = component;
        return component;
    }

    /// Add (or replace an existing) a new component to the entity.  An existing component will be deleted.
    /// \tparam ComponentType The compnent type.
    /// \return A pointer to the component.
    template<typename ComponentType>
    ComponentType* AddOrReplace() {
        ENSURE_VALID_COMPONENT_TYPE(ComponentType);
        auto id = COMPONENT_ID(ComponentType);
        if (components_.count(id)) {
            delete components_[id];
        }
        auto component = new ComponentType;
        components_[id] = component;
        return component;
    }

    /// Get the component of the given type.
    /// \tparam ComponentType The component type.
    /// \return A pointer to the component or nullptr if this entity does not have the requested component type.
    template<typename ComponentType>
    ComponentType* GetComponent() {
        auto id = COMPONENT_ID(ComponentType);
        return components_.count(id) ? static_cast<ComponentType*>(components_[id]) : nullptr;
    }

    /// Removes the component matching the given type.
    /// \tparam ComponentType The component type.
    template<typename ComponentType>
    void RemoveComponent() {
        auto id = COMPONENT_ID(ComponentType);
        if (components_.count(id)) {
            delete components_[id];
        }
        components_.erase(id);
    }


private:
    Serializer* serializer_;
    std::unordered_map<std::type_index, Component*> components_;
};


#endif //RETROFUNK_ENTITY_H
