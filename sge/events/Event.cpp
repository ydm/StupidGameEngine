//
//  Event.cpp
//  StupidGameEngine
//
//  Created by Yordan on 3/24/15.
//
//

#include "Event.h"
SGE_NS_BEGIN;


// const char Event::DELIMITER(':');


Event::Event(const ID ident)
: THasID(ident)
{
}


Event::~Event()
{
}


Event::EventType Event::getEventType() const
{
    return getID();
}


void Event::serialize(std::ostrstream& os) const
{
    // TODO
}


void Event::deserialize(std::istrstream& is)
{
    // TODO
}


SGE_NS_END;