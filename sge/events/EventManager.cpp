//
//  EventManager.cpp
//  StupidGameEngine
//
//  Created by Yordan on 3/24/15.
//
//
#include <iostream>
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


static void hehe(const Event *)
{
}


void EventManager::removeListener(const Event::EventType type, EventListener listener)
{
    // ydm: Bind expressions yield NULL when asked for target().  Thus if
    // target() yields NULL for this kind of EventListener, I presume it's a
    // bind expression and use type_info matching instead.  WARNING: this may
    // be problematic as I expect the std::bind() routine to return the one and
    // same unique type for each specific function bound.

    EventListenerList *listeners = getListenersForType(type);

    void (*const *removeTarget) (const Event *) = listener.target<void (*) (const Event *)>();
    if (removeTarget)
    {
        // Normal function, compare pointers
        for (EventListenerList::iterator it = listeners->begin(); it != listeners->end(); it++)
        {
            const EventListener& fn(*it);
            void (*const *fnTarget) (const Event *) = fn.target<void (*) (const Event *)>();
            if (fnTarget == removeTarget)
            {
                listeners->erase(it);
                logi("EventManager::removeListener: removed function listener for type %zu", type);
                break;
            }
        }
    }
    else
    {
        // Bind expression, compare types
        const std::type_info& removeType(listener.target_type());
        for (EventListenerList::iterator it = listeners->begin(); it != listeners->end(); it++)
        {
            const EventListener& fn(*it);
            const std::type_info& fnType(fn.target_type());
            if (fnType == removeType)
            {
                listeners->erase(it);
                logi("EventManager::removeListener: removed bound function listener for type %zu", type);
                break;
            }
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