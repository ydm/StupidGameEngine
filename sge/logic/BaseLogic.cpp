//
//  BaseLogic.cpp
//  StupidGameEngine
//
//  Created by Yordan on 3/20/15.
//
//

#include "../app/Application.h" // Includes BaseLogic.h
#include "../events/CommonEvents.h"
#include "../utils/Utils.h"
SGE_NS_BEGIN;


BaseLogic::BaseLogic(ActorManager *actorManager)
: actorManager_(actorManager)
, currentStateActors_(nullptr)
{
    if (!actorManager)
    {
        throw new std::runtime_error("actorManager is null");
    }
}


BaseLogic::~BaseLogic()
{
    currentStateActors_ = nullptr;
    delete actorManager_;
}


void BaseLogic::ready()
{
}


void BaseLogic::update(const float dt)
{
    for (auto& p : *actorManager_->getGlobalActors())
    {
        p.second->update(dt);
    }

    if (currentStateActors_)
    {
        for (auto& p : *currentStateActors_)
        {
            p.second->update(dt);
        }
    }
}


// ----------+
// Protected |
// ----------+

Application *
BaseLogic::getApplication() const
{
    return app_;
}


ActorManager *
BaseLogic::getActorManager() const
{
    return actorManager_;
}


void BaseLogic::init()
{
    initStates();
    initActors();
}


void BaseLogic::onTransition(const std::string& oldState, const std::string& newState)
{
    // We cache the current state actors for faster access in update()
    currentStateActors_ = actorManager_->getActorsForState(newState);

    // Now notify of the state change
    const EventStateChange e(oldState, newState);
    getApplication()->getEventManager()->notifyListeners(&e);
}


SGE_NS_END;