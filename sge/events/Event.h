//
//  Event.h
//  StupidGameEngine
//
//  Created by Yordan on 3/24/15.
//
//

#ifndef __SGE_EVENT_H__
#define __SGE_EVENT_H__

#include <sstream>
#include "../utils/HasID.h"
SGE_NS_BEGIN;


class Event : private THasID<uint32_t>
{
public:
    typedef ID EventType;

    Event(const EventType ident);
    virtual ~Event();

    EventType getEventType() const;
    virtual void serialize(std::ostringstream& os) const;
    virtual void deserialize(std::istringstream& is);

protected:
    // static const char DELIMITER;
};


SGE_NS_END;
#endif // SGE_EVENT_H__
