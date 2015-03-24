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
: logic_(nullptr)
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
}


void Application::update(const float dt)
{
    logic_->update(dt);
}


void Application::setLogic(BaseLogic *logic)
{
    // ydm: I like simple things, so logic_ can be set only once.
    if (logic_)
    {
        loge("%s: logic object is already set", __func__);
        return;
    }

    if (logic)
    {
        logic_ = logic;
    }
    else
    {
        loge("%s: bad LOGIC argument", __func__);
    }
}


void Application::addView(BaseView *view)
{
    if (view)
    {
        views_.push_back(view);
    }
}


SGE_NS_END;