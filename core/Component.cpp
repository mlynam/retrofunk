//
// Created by admin on 1/2/2017.
//

#include "Component.h"

void Component::Serialize(Serializer *serializer) {
    auto states = InternalSerialize();
    serializer->Serialize(states);
}
