//
//  BaseLogic.h
//  StupidGameEngine
//
//  Created by Yordan on 3/20/15.
//
//

#ifndef __SGE_BASE_LOGIC_H__
#define __SGE_BASE_LOGIC_H__

#include <list>
#include "../actors/ActorManager.h"
#include "../utils/FiniteStateMachine.h"
SGE_NS_BEGIN;


// A simple state machine
class BaseLogic : public FiniteStateMachine
{
public:
    BaseLogic(ActorManager *actorManager);
    virtual ~BaseLogic();
    virtual void update(const float dt);

protected:
    // Init stages
    virtual void init();
    virtual void initStates() = 0;
    virtual void initActors() = 0;
    virtual void postInit()  = 0;

    ActorManager *getActorManager() const;
    void onTransition(const std::string& oldState, const std::string& newState) override;

private:
    ActorManager            *actorManager_;
    ActorManager::ActorsMap *currentStateActors_;
};


SGE_NS_END;
#endif // GE_BASE_LOGIC_H__
