//
//  common_events.h
//  StupidGameEngine
//
//  Created by Yordan on 3/25/15.
//
//

#ifndef __SGE_COMMON_EVENTS_H__
#define __SGE_COMMON_EVENTS_H__

#include <string>
#include <vector>
#include "Event.h"
#include "../actors/Actor.h"
SGE_NS_BEGIN;


// ========================
// Base event classes
// ========================

template <typename T>
class EventWithData : public Event
{
public:
    EventWithData(const Event::EventType ident)
    : Event(ident)
    , data_()
    {
    }

    EventWithData(const Event::EventType ident, const T& data)
    : Event(ident)
    , data_(data)
    {
    }

    virtual ~EventWithData()
    {
    }

    const T& getData() const
    {
        return data_;
    }

protected:
    T data_;
};


template <typename D, typename P>
class EventWithParameters : public EventWithData<D>
{
public:
    EventWithParameters(const Event::EventType ident, const D& data, const std::initializer_list<P> params)
    : EventWithData<D>(ident, data)
    , parameters_(params)
    {
    }

    virtual ~EventWithParameters()
    {
    }

    const std::vector<P>& getParameters() const
    {
        return parameters_;
    }

private:
    std::vector<P> parameters_;
};


// ========================
// Common events
// ========================
// 2**32 - 1 is the same as -1, and that's equal to INVALID_ID :)
// >>> def gen(): print(hex(randint(0, 2**32 - 2)))
static const Event::EventType EVENT_ACTOR_NEW           = 0x8bc09ac9;
static const Event::EventType EVENT_LOGIC_STATE_CHANGE  = 0x3f18527d;
static const Event::EventType EVENT_USER_COMMAND        = 0x8ddc6ad2;
static const Event::EventType EVENT_USER_COMMAND_INT    = 0x201874c2;

//static const Event::EventType EVENT_ACTOR_MOVE          = 0x297b6e01;
//static const Event::EventType EVENT_COMMAND             = 0xfa244899;
//static const Event::EventType EVENT_ACTOR_DESTROYED     = 0xDEAD;
//static const Event::EventType EVENT_ACTOR_COLLISION     = 0xDEAD;
//static const Event::EventType EVENT_PLAYER_DEATH        = 0xDEAD;
//static const Event::EventType EVENT_LEVEL_PRELOAD       = 0xdead;
//static const Event::EventType EVENT_LEVEL_LOADED        = 0xdead;


class EventActorNew : public EventWithData<Actor *>
{
public:
    EventActorNew(Actor *actor);
    virtual ~EventActorNew();
};


class EventLogicStateChange : public EventWithData<std::vector<std::string> >
{
public:
    EventLogicStateChange(const std::string& oldState, const std::string& newState);
    virtual ~EventLogicStateChange();
};


class EventUserCommand : public EventWithData<EventUserCommandType>
{
public:
    EventUserCommand(const EventUserCommandType cmd);
    virtual ~EventUserCommand();
};


class EventUserCommandInt : public EventWithParameters<EventUserCommandType, int>
{
public:
    EventUserCommandInt(const EventUserCommandType& data, const std::initializer_list<int> params);
    virtual ~EventUserCommandInt();
};


SGE_NS_END;
#endif // SGE_COMMON_EVENTS_H
