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
    typedef std::list<EventListener> EventListenerList;
    typedef std::map<Event::EventType, EventListenerList *> TypeToList;

    EventManager();
    virtual ~EventManager();

    void addListener(const Event::EventType type, EventListener listener);
    // void removeListener(const Event::EventType type, EventListener listener);
    void notifyListeners(const Event& type) const;

private:
    EventListenerList *getListenersForType(const Event::EventType);
    TypeToList listenersForType_;
    EventListenerList globalListeners_;
};


SGE_NS_END;
#endif // SGE_EVENT_MANAGER_H__