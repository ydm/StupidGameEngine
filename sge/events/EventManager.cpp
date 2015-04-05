//
//  EventManager.cpp
//  StupidGameEngine
//
//  Created by Yordan on 3/24/15.
//
//

#include "EventManager.h"
#include "../utils/Utils.h"
SGE_NS_BEGIN;


EventManager::EventManager()
: globalListeners_()
, listenersForType_()
, nextID_(0)
{
}


EventManager::~EventManager()
{
    globalListeners_.clear();
    for (auto& kv : listenersForType_)
    {
        kv.second->clear();
        delete kv.second;
    }
    listenersForType_.clear();
}


void EventManager::addListener(const Event::EventType type, EventListener listener)
{
    getListenersForType(type)->push_back(listener);
    logi("EventManager::addListener: added event listener for type %zu", type);
}


void EventManager::removeListener(const Event::EventType type, EventListener listener)
{
    void (*const *remove) (const Event *) = listener.target<void (*) (const Event *)>();

    EventListenerList *listeners = getListenersForType(type);
    for (EventListenerList::iterator it = listeners->begin();
         it != listeners->end();
         it++)
    {
        EventListener e(*it);
        void (*const *target) (const Event *) = e.target<void (*) (const Event *)>();

        if (*target == *remove)
        {
            listeners->erase(it);
            logi("EventManager::removeListener: removed event listener for type %zu", type);
            break;
        }
    }
}


void EventManager::notifyListeners(const Event *e) const
{
    // 1. Notify global listeners
    for (auto func : globalListeners_)
    {
        func(e);
    }

    // 2. Notify listeners bound for this type of event only
    EventListenerList *ls(nullptr);
    try
    {
        ls = listenersForType_.at(e->getEventType());
    }
    catch (std::out_of_range)
    {
    }

    if (ls)
    {
        for (EventListener func : *ls)
        {
            func(e);
        }
    }
}


EventManager::EventListenerList *
EventManager::getListenersForType(const Event::EventType tp)
{
    if (!Utils::mapContainsKey(listenersForType_, tp))
    {
        listenersForType_[tp] = new EventListenerList();
    }
    return listenersForType_[tp];
}


SGE_NS_END;