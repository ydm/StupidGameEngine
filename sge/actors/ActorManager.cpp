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
ActorManager::createGlobalActor()
{
    Actor *a = createActor_();
    globalActors_[a->getID()] = a;
    return a;
}


Actor *
ActorManager::createActorForState(const std::string& state)
{
    ActorsMap *m = getOrCreateActorsForState(state);
    Actor *a = createActor_();
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
    return actorsForState_.at(state);
}


// ========================
// Private
// ========================

Actor *
ActorManager::createActor_()
{
    Actor *a = new Actor();
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