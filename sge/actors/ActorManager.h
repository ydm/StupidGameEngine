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
#include <string>
#include "Actor.h"
SGE_NS_BEGIN;


class ActorManager
{
public:
    typedef std::map<Actor::ID, Actor *> ActorsMap;
    typedef std::map<std::string, ActorsMap *> StateActorsMap;

    ActorManager();
    virtual ~ActorManager();

    Actor *createGlobalActor(const Actor::ActorType actorType);
    Actor *createActorForState(const std::string& state, const Actor::ActorType actorType);

    Actor *getGlobalActor(const Actor::ID ident) const;
    Actor *getActorForState(const std::string& state, const Actor::ID ident) const;

    const ActorsMap *getGlobalActors() const;
    const ActorsMap *getActorsForState(const std::string& state);

protected:
    virtual Actor *createActor_(const Actor::ActorType actorType);

private:
    ActorsMap *getOrCreateActorsForState(const std::string& state);

    ActorsMap globalActors_;
    StateActorsMap actorsForState_;
    Actor::ID nextID_;
};


SGE_NS_END;
#endif // SGE_ACTOR_MANAGER_H
