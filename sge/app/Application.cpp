//
//  Application.cpp
//  StupidGameEngine
//
//  Created by Yordan on 3/20/15.
//
//

#include "Application.h"
SGE_NS_BEGIN;


Application::Application()
: eventManager_()
, logic_(nullptr)
, localViews_()
{
}


Application::~Application()
{
    delete logic_;
    for (auto v : localViews_)
    {
        delete v;
    }
    localViews_.clear();
}


void Application::update(const float dt)
{
    logic_->update(dt);
    for (auto v : localViews_)
    {
        v->update(dt);
    }
}


void Application::addLocalView(BaseView *view)
{
    if (view)
    {
        localViews_.push_back(view);
    }
    else
    {
        logw("Application::addView: invalid view");
    }
}


EventManager *
Application::getEventManager() const
{
    return const_cast<EventManager *>(&eventManager_);
}


BaseLogic *
Application::getLogic() const
{
    return logic_;
}


void Application::setLogic(BaseLogic *logic)
{
    // ydm: I like simple things, so logic_ can be set only once.
    if (logic_)
    {
        logw("Application::setLogic: logic object is already set");
        return;
    }

    if (logic)
    {
        logic_ = logic;
    }
    else
    {
        logw("Application::setLogic: bad LOGIC argument");
    }
}


void Application::init()
{
    // It's important to init views first as they depend on logic and not the other way around.
    // For example they may subscribe to state change events, produced in Logic::init()
    for (auto v : localViews_)
    {
        v->init(this);
    }
    logic_->init(this);
}


SGE_NS_END;