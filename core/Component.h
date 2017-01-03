//
// Created by admin on 1/2/2017.
//

#ifndef RETROFUNK_COMPONENT_H
#define RETROFUNK_COMPONENT_H

#define COMPONENT_ID(c) (std::type_index(typeid(c)))
#define ENSURE_VALID_COMPONENT_TYPE(c) static_assert(\
    std::is_base_of<Component,c>::value &&\
    std::is_default_constructible<c>::value\
    ,"The given type is not a component")

#include <vector>
#include "Serializer.h"
#include "State.h"

class Component {
public:
    void Serialize(Serializer *);

protected:
    virtual std::vector<State> InternalSerialize() = 0;

};

#endif //RETROFUNK_COMPONENT_H
