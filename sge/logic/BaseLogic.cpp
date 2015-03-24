//
//  BaseLogic.cpp
//  StupidGameEngine
//
//  Created by Yordan on 3/20/15.
//
//

#include "BaseLogic.h"
#include "../utils/Utils.h"
SGE_NS_BEGIN;


BaseLogic::BaseLogic()
: actors_()
, currentStateActors_(nullptr)
, globalActors_()
{
}


BaseLogic::~BaseLogic()
{
    for (std::pair<std::string, std::list<Actor *> *> p : actors_)
    {
        std::list<Actor *> *seq = p.second;
        for (Actor *actor : *seq)
        {
            delete actor;
        }
        delete seq;
    }
}


void BaseLogic::update(const float dt)
{
    for (auto a : globalActors_)
    {
        a->update(dt);
    }

    if (currentStateActors_)
    {
        for (auto a : *currentStateActors_)
        {
            a->update(dt);
        }
    }
}


void BaseLogic::addActorForState(std::string& state, Actor *actor)
{
    if (actor)
    {
        auto actors = getActorsForState(state);
        if (actors)
        {
            actors->push_back(actor);
        }
    }
    else
    {
        loge("%s: actor is null", __func__);
    }
    actors_[state]->push_back(actor);
}


void BaseLogic::addGlobalActor(Actor *actor)
{
    globalActors_.push_back(actor);
}


// ----------+
// Protected |
// ----------+

void BaseLogic::onTransition(const std::string& oldState, const std::string& newState)
{
    currentStateActors_ = getActorsForState(newState);
}


// --------+
// Private |
// --------+

std::list<Actor *> *
BaseLogic::getActorsForState(const std::string& state)
{
    if (isKnownState(state))
    {
        if (!Utils::mapContainsKey(actors_, state))
        {
            actors_[state] = new std::list<Actor *>();
        }
        return actors_[state];
    }
    loge("BaseLogic::getActorsForState: unknown state %s", state.c_str());
    return nullptr;
}


SGE_NS_END;