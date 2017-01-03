//
// Created by admin on 1/2/2017.
//

#include "TestComponent.h"

std::vector<State> TestComponent::InternalSerialize() {
    this->saved = true;
    return std::vector<State>({ State(StateType::bit, sizeof(saved), &saved) });
}
