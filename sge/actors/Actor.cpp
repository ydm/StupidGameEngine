//
//  Actor.cpp
//  StupidGameEngine
//
//  Created by Yordan on 3/20/15.
//
//

#include "Actor.h"
SGE_NS_BEGIN;


Actor::Actor()
: HasID()
, components_()
{
}


Actor::~Actor()
{
    for (auto& kv : components_)
    {
        delete kv.second;
    }
    components_.clear();
}


void Actor::addComponent(const std::string &name, sge::ActorComponent *component)
{
    if (component)
    {
        components_[name] = component;
        component->setOwner(this);
    }
    else
    {
        loge("Actor::addComponent: unable to add null component");
    }
}


ActorComponent *
Actor::getComponent(const std::string& name) const
{
    try {
        return components_.at(name);
    } catch (std::out_of_range _) {
        loge("Actor::getComponent: unknown component %s", name.c_str());
    }
    return nullptr;
}


void Actor::update(const float dt)
{
    for (auto kv : components_)
    {
        kv.second->update(dt);
    }
}

SGE_NS_END;