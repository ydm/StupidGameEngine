//
//  common_events.h
//  StupidGameEngine
//
//  Created by Yordan on 3/25/15.
//
//

#ifndef __SGE_COMMON_EVENTS_H__
#define __SGE_COMMON_EVENTS_H__

#include "../actors/Actor.h"
#include "../sge_base.h"
#include "Event.h"


SGE_NS_BEGIN;

// 2**32 - 1 is the same as -1, and that's INVALID_ID :)
// >>> from random import randint
// >>> def gen(): print(hex(randint(0, 2**32 - 2)))
static const Event::EventType EVENT_ACTOR_NEW  = 0x8bc09ac9;
static const Event::EventType EVENT_ACTOR_MOVE = 0x297b6e01;


class EventActor : public Event
{
public:
    EventActor(const EventType ident);
    virtual ~EventActor();
    Actor::ID getActorID() const;
private:
    Actor::ID actorID_;
};


class EventActorNew : public EventActor
{
public:
    EventActorNew();
    virtual ~EventActorNew();
};


class EventActorMove : public EventActor
{
public:
    EventActorMove(const Vec3& pos);
    virtual ~EventActorMove();
    Vec3 getPosition() const;
private:
    Vec3 pos_;
};


SGE_NS_END;
#endif // SGE_COMMON_EVENTS_H
