//
//  EventManager.h
//  StupidGameEngine
//
//  Created by Yordan on 3/24/15.
//
//

#ifndef __SGE_EVENT_MANAGER_H__
#define __SGE_EVENT_MANAGER_H__

#include <list>
#include <map>
#include <functional>
#include "Event.h"
SGE_NS_BEGIN;


#define SGE_EM_LISTENER(fn) std::bind(fn, this, std::placeholders::_1)


class EventManager
{
public:
    typedef std::function<void (const Event *)> EventListener;
    typedef std::list<EventListener> EventListenerList;
    typedef std::map<Event::EventType, EventListenerList *> TypeToList;

    EventManager();
    virtual ~EventManager();

    void addListener(const Event::EventType type, EventListener listener);
    // void removeListener(const Event::EventType type, ...);
    void notifyListeners(const Event *type) const;

private:
    EventListenerList *getListenersForType(const Event::EventType);
    
    EventListenerList globalListeners_;
    TypeToList listenersForType_;
};


SGE_NS_END;
#endif // SGE_EVENT_MANAGER_H__