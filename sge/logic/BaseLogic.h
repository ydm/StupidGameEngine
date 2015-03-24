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
#include "../actors/Actor.h"
#include "../utils/FiniteStateMachine.h"
SGE_NS_BEGIN;


// A simple state machine
class BaseLogic : public FiniteStateMachine
{
public:
    BaseLogic();
    virtual ~BaseLogic();
    virtual void update(const float dt);

    void addActorForState(std::string& state, Actor *actor);
    void addGlobalActor(Actor *actor);

protected:
    void onTransition(const std::string& oldState, const std::string& newState) override;

private:
    std::list<Actor *> *getActorsForState(const std::string& state);

    std::map<std::string, std::list<Actor *> *>  actors_;
    std::list<Actor *>                          *currentStateActors_;
    std::list<Actor *>                           globalActors_;
};


SGE_NS_END;
#endif // GE_BASE_LOGIC_H__
