//
//  BaseView.cpp
//  StupidGameEngine
//
//  Created by Yordan on 3/20/15.
//
//

#include <functional>
#include "../app/Application.h" // includes BaseView.h
#include "../events/CommonEvents.h"
SGE_NS_BEGIN;


BaseView::BaseView()
{
}


BaseView::~BaseView()
{
}


void BaseView::init(Application *app)
{
    app_ = app;
    auto f = std::bind(&BaseView::handleStateChange, this, std::placeholders::_1);
    f(nullptr);
    // app->getEventManager()->addListener(EVENT_STATE_CHANGE, f);
}


void BaseView::handleStateChange(const Event *e)
{
    logi("e=%p", e);
    // const EventStateChange *c = static_cast<const EventStateChange *>(e);
    // logi("BaseView::handleStateChange old=%s, new=%s", c->getNewState().c_str(), c->getOldState().c_str());
}


SGE_NS_END;