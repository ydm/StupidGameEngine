//
//  ActorManager.cpp
//  StupidGameEngine
//
//  Created by Yordan on 3/25/15.
//
//

#include "ActorManager.h"
SGE_NS_BEGIN;


ActorManager::ActorManager()
: actors_()
, actorsForState_()
, nextID_(0)
{
}


ActorManager::~ActorManager()
{
    for (auto& p : actors_)
    {
        delete p.second;
    }
    actors_.clear();

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
ActorManager::createActor()
{
    Actor *a = createActor_();
    return a;
}


Actor *
ActorManager::createActorForState(const std::string& state)
{
    Actor *a = createActor_();
    return a;
}


Actor *
ActorManager::getActor(const Actor::ID ident) const
{
    return actors_.at(ident);
}


Actor *
ActorManager::getActorForState(const std::string& state, const Actor::ID ident) const
{
    return actorsForState_.at(state)->at(ident);
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

SGE_NS_END;