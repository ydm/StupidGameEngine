//
//  Created by Yordan on 19/3/15.
//
//


#include "ActorComponent.h"
SGE_NS_USING;


ActorComponent::ActorComponent() : owner_(nullptr)      {}
ActorComponent::~ActorComponent()                       {}
bool ActorComponent::init()                             {return true;}
// void ActorComponent::postInit()                         {}
void ActorComponent::update(const float dt)             {}
Actor *ActorComponent::getOwner()                       {return owner_;}
void ActorComponent::setOwner(Actor *owner)             {owner_ = owner;}
