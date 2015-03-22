//
//  Actor.cpp
//  StupidGameEngine
//
//  Created by Yordan on 3/20/15.
//
//

#include "Actor.h"
SGE_NS_USING;


Actor::Actor()
: components_()
{
}


Actor::~Actor()
{
    for (auto& kv : components_)
    {
        ActorComponent *c = kv.second;
        delete c;
    }
}


ActorComponent *
Actor::getComponent(const std::string& name)
{
    try {
        return components_.at(name);
    } catch (std::out_of_range _) {
        loge("Actor::getComponent: unknown component %s", name.c_str());
    }
    return nullptr;
}


void Actor::addComponent(const std::string &name, sge::ActorComponent *component)
{
    components_[name] = component;
    component->setOwner(this);
}