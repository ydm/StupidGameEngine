//
//  common_events.cpp
//  StupidGameEngine
//
//  Created by Yordan on 3/25/15.
//
//

#include "CommonEvents.h"
SGE_NS_BEGIN;


// ========================
// EventActorNew
// ========================
EventActorNew::EventActorNew(sge::Actor *actor)
: EventWithData<Actor *>(EVENT_ACTOR_NEW, actor)
{
}

EventActorNew::~EventActorNew()
{
}


// ========================
// EventLogicStateChange
// ========================
EventLogicStateChange::EventLogicStateChange(const std::string& oldState, const std::string& newState)
: EventWithData(EVENT_LOGIC_STATE_CHANGE)
{
    data_.push_back(oldState);
    data_.push_back(newState);
}

EventLogicStateChange::~EventLogicStateChange()
{
    data_.clear();
}


// ========================
// EventUserCommand
// ========================
EventUserCommand::EventUserCommand(const EventUserCommandType cmd)
: EventWithData(EVENT_USER_COMMAND, cmd)
{
}

EventUserCommand::~EventUserCommand()
{
}


// ========================
// EventUserCommandInt
// ========================
EventUserCommandInt::EventUserCommandInt(const EventUserCommandType& data, const std::initializer_list<int> params)
: EventWithParameters(EVENT_USER_COMMAND_INT, data, params)
{
}

EventUserCommandInt::~EventUserCommandInt()
{
}

/*
// ========================
// EventActor
// ========================
EventActor::EventActor(const EventType ident)
: Event(ident)                                                                  { }
EventActor::~EventActor()                                                       { }
Actor::ID EventActor::getActorID() const                                        { return actorID_; }

// ========================
// EventActorNew
// ========================
EventActorNew::EventActorNew()
: EventActor(EVENT_ACTOR_NEW)                                                   { }
EventActorNew::~EventActorNew()                                                 { }

// ========================
// EventActorMove
// ========================
EventActorMove::EventActorMove(const Vec3& pos)
: EventActor(EVENT_ACTOR_MOVE)                                                  { }
EventActorMove::~EventActorMove()                                               { }
Vec3 EventActorMove::getPosition() const                                        { return pos_; }

// ========================
// EventCommand
// ========================
EventCommand::EventCommand(const EventCommandType cmd)
: Event(EVENT_COMMAND)
, cmd_(cmd)                                                                     { }
EventCommand::~EventCommand()                                                   { }
EventCommandType EventCommand::getCommand() const                               { return  cmd_; }

// ========================
// EventStateChange
// ========================
EventLogicStateChange::EventLogicStateChange(const std::string oldState, const std::string newState)
: Event(EVENT_LOGIC_STATE_CHANGE)
, oldState_(oldState)
, newState_(newState)                                                           { }
EventLogicStateChange::~EventLogicStateChange()                                 { }
const std::string& EventLogicStateChange::getOldState() const                   { return oldState_; }
const std::string& EventLogicStateChange::getNewState() const                   { return newState_; }
*/


SGE_NS_END;