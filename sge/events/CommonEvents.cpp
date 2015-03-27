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
// EventStateChange
// ========================
EventLogicStateChange::EventLogicStateChange(const std::string oldState, const std::string newState)
: Event(EVENT_LOGIC_STATE_CHANGE)
, oldState_(oldState)
, newState_(newState)                                                           { }
EventLogicStateChange::~EventLogicStateChange()                                 { }
const std::string& EventLogicStateChange::getOldState() const                   { return oldState_; }
const std::string& EventLogicStateChange::getNewState() const                   { return newState_; }


SGE_NS_END;