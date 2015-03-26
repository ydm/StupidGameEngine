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
{
    logi("CONSTRUCTOR: %lu", globalListeners_.size());
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
}


void EventManager::notifyListeners(const Event& e) const
{
    // 1. Notify global listeners
    /*
    logi("global listeners: %lu", globalListeners_.size());
    for (auto listener : globalListeners_)
    {
        listener(&e);
    }
    */

    // 2. Notify listeners bound for this type of event only
    EventListenerList *ls(nullptr);
    try
    {
        ls = listenersForType_.at(e.getEventType());
    }
    catch (std::out_of_range)
    {
    }

    if (ls)
    {
        for (EventListener func : *ls)
        {
            func(&e);
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