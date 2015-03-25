//
//  ActorManager.h
//  StupidGameEngine
//
//  Created by Yordan on 3/25/15.
//
//

#ifndef __SGE_ACTOR_MANAGER_H__
#define __SGE_ACTOR_MANAGER_H__

#include <map>
#include "Actor.h"
SGE_NS_BEGIN;


class ActorManager
{
public:
    ActorManager();
    virtual ~ActorManager();

    Actor *createActor();
    Actor *createActorForState(const std::string& state);

    Actor *getActor(const Actor::ID ident) const;
    Actor *getActorForState(const std::string& state, const Actor::ID ident) const;

private:
    Actor *createActor_();

    std::map<Actor::ID, Actor *> actors_;
    std::map<std::string, std::map<Actor::ID, Actor *> *> actorsForState_;
    Actor::ID nextID_;
};


SGE_NS_END;
#endif // SGE_ACTOR_MANAGER_H
