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
: listeners_()
{
}


EventManager::~EventManager()
{
    for (auto& kv : listeners_)
    {
        delete kv.second;
    }
    // listeners_.clear();
}


void EventManager::addListener(const Event::EventType type, EventListener listener)
{
    getListenersForType(type)->push_back(listener);
}


void EventManager::notifyListeners(const Event& e) const
{
    std::list<EventListener> *ls(nullptr);
    try
    {
        ls = listeners_.at(e.getEventType());
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


std::list<EventManager::EventListener> *EventManager::getListenersForType(const Event::EventType tp)
{
    if (!Utils::mapContainsKey(listeners_, tp))
    {
        listeners_[tp] = new std::list<EventListener>();
    }
    return listeners_[tp];
}


SGE_NS_END;