//
//  common_events.cpp
//  StupidGameEngine
//
//  Created by Yordan on 3/25/15.
//
//

#include "CommonEvents.h"
SGE_NS_BEGIN;

EventActor::EventActor(const EventType ident)
: Event(ident)                                                                  { }
EventActor::~EventActor()                                                       { }
Actor::ID EventActor::getActorID() const                                        { return actorID_; }

EventActorNew::EventActorNew()
: EventActor(EVENT_ACTOR_NEW)                                                   { }
EventActorNew::~EventActorNew()                                                 { }

EventActorMove::EventActorMove(const Vec3& pos)
: EventActor(EVENT_ACTOR_MOVE)                                                  { }
EventActorMove::~EventActorMove()                                               { }
Vec3 EventActorMove::getPosition() const                                        { return pos_; }

EventStateChange::EventStateChange(const std::string oldState, const std::string newState)
: Event(EVENT_STATE_CHANGE)
, oldState_(oldState)
, newState_(newState)                                                           { }
EventStateChange::~EventStateChange()                                           { }
const std::string& EventStateChange::getOldState() const                        { return oldState_; }
const std::string& EventStateChange::getNewState() const                        { return newState_; }

SGE_NS_END;