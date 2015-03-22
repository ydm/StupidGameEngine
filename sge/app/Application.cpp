//
//  Application.cpp
//  StupidGameEngine
//
//  Created by Yordan on 3/20/15.
//
//

#include "Application.h"
SGE_NS_USING;


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
    for (auto v : views_)
    {
        v->update(dt);
    }
}


void Application::setLogic(BaseLogic *logic)
{
    if (logic_)
    {
        delete logic_;
    }
    logic_ = logic;
}


void Application::addView(BaseView *view)
{
    if (view)
    {
        views_.push_back(view);
    }
}
