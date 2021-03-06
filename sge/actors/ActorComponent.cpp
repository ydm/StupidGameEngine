//
//  Created by Yordan on 19/3/15.
//
//


#include <stdexcept>
#include "ActorComponent.h"
SGE_NS_BEGIN;


ActorComponent::ActorComponent() : owner_(nullptr)      {}
ActorComponent::~ActorComponent()                       {}
void ActorComponent::update(const float dt)             {}
Actor *ActorComponent::getOwner()                       {return owner_;}

void ActorComponent::init(Actor *owner)
{
    if (owner_)
    {
        throw std::runtime_error("ActorComponent's owner can be set only once");
    }
    owner_ = owner;
}

SGE_NS_END;