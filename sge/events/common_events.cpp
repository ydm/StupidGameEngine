//
//  common_events.cpp
//  StupidGameEngine
//
//  Created by Yordan on 3/25/15.
//
//

#include "common_events.h"
SGE_NS_BEGIN;

EventActor::EventActor(const EventType ident) : Event(ident)                    { }
EventActor::~EventActor()                                                       { }
Actor::ID EventActor::getActorID() const                                        { return actorID_; }

EventActorNew::EventActorNew() : EventActor(EVENT_ACTOR_NEW)                    { }
EventActorNew::~EventActorNew()                                                 { }

EventActorMove::EventActorMove(const Vec3& pos) : EventActor(EVENT_ACTOR_MOVE)  { }
EventActorMove::~EventActorMove()                                               { }
Vec3 EventActorMove::getPosition() const                                        { return pos_; }

SGE_NS_END;