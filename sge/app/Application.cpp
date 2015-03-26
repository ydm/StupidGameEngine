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
, started_(false)
, views_()
{
}


Application::~Application()
{
    delete logic_;
    for (auto v : views_)
    {
        delete v;
    }
    views_.clear();
}


void Application::update(const float dt)
{
    return;
    static bool printed = false;
    if (!printed)
    {
        printed = true;
        logi("App::update(%f)", dt);
    }
    // logic_->update(dt);
}


void Application::addView(BaseView *view)
{
    if (view)
    {
        view->init(this);
        views_.push_back(view);
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


void Application::ready()
{
    logic_->ready();
}


SGE_NS_END;