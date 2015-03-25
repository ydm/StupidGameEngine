//
//  EventManager.h
//  StupidGameEngine
//
//  Created by Yordan on 3/24/15.
//
//

#ifndef __SGE_EVENT_MANAGER_H__
#define __SGE_EVENT_MANAGER_H__

#include <functional>
#include "Event.h"
SGE_NS_BEGIN;


class EventManager
{
public:
    typedef std::function<void (const Event&)> EventListener;

    EventManager();
    virtual ~EventManager();

    void addListener(const Event::EventType type, EventListener listener);
    // void removeListener(const Event::EventType type, EventListener listener);
    void notifyListeners(const Event& type) const;

private:
    std::list<EventListener> *getListenersForType(const Event::EventType);
    std::map<Event::EventType, std::list<EventListener> *> listeners_;
};


SGE_NS_END;
#endif // SGE_EVENT_MANAGER_H__