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

void BaseLogic::onTransition(const std::string& oldState, const std::string& newState)
{
    // ydm: We won't be changing it, of course, but since the
    // currentStateActors_ handle can't be const, we need to cast.
    currentStateActors_ = const_cast<ActorManager::ActorsMap *>(
        actorManager_->getActorsForState(newState)
    );
}


SGE_NS_END;