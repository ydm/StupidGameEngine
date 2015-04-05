//
//  ActorManager.cpp
//  StupidGameEngine
//
//  Created by Yordan on 3/25/15.
//
//

#include "ActorManager.h"
#include "Utils.h"
SGE_NS_BEGIN;


ActorManager::ActorManager()
: actorsForState_()
, globalActors_()
, nextID_(0)
{
}


ActorManager::~ActorManager()
{
    for (auto& p : globalActors_)
    {
        delete p.second;
    }
    // globalActors_.clear();

    for (auto& m : actorsForState_)
    {
        for (auto &p : *m.second)
        {
            delete p.second;
        }
        delete m.second;
    }
    actorsForState_.clear();
}


Actor *
ActorManager::createGlobalActor(Actor::ActorType actorType)
{
    Actor *a = createActor_(actorType);
    globalActors_[a->getID()] = a;
    return a;
}


Actor *
ActorManager::createActorForState(const std::string& state, Actor::ActorType actorType)
{
    ActorsMap *m = getOrCreateActorsForState(state);
    Actor *a = createActor_(actorType);
    (*m)[a->getID()] = a;
    return a;
}


Actor *
ActorManager::getGlobalActor(const Actor::ID ident) const
{
    return globalActors_.at(ident);
}


Actor *
ActorManager::getActorForState(const std::string& state, const Actor::ID ident) const
{
    return actorsForState_.at(state)->at(ident);
}


const ActorManager::ActorsMap *
ActorManager::getGlobalActors() const
{
    return &globalActors_;
}


const ActorManager::ActorsMap *
ActorManager::getActorsForState(const std::string& state) const
{
    try {
        return actorsForState_.at(state);
    } catch (std::out_of_range) {
        return nullptr;
    }
}


// ========================
// Private
// ========================

Actor *
ActorManager::createActor_(const Actor::ActorType actorType)
{
    Actor *a = new Actor(actorType);
    a->setID(nextID_++);
    return a;
}


ActorManager::ActorsMap *
ActorManager::getOrCreateActorsForState(const std::string& state)
{
    if (!Utils::mapContainsKey(actorsForState_, state))
    {
        actorsForState_[state] = new ActorsMap();
    }
    return actorsForState_[state];
}

SGE_NS_END;