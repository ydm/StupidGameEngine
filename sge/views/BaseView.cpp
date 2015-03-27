//
//  BaseView.cpp
//  StupidGameEngine
//
//  Created by Yordan on 3/20/15.
//
//

#include <functional>
#include <string>
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
    app->getEventManager()->addListener(EVENT_LOGIC_STATE_CHANGE, SGE_EM_LISTENER(&BaseView::handleStateChange_));
}


void BaseView::handleStateChange(const std::string& oldState, const std::string& newState)
{
    logi("BaseView::handleStateChange old=%s, new=%s", oldState.c_str(), newState.c_str());
}


void BaseView::handleStateChange_(const Event *e)
{
    const EventLogicStateChange *c = static_cast<const EventLogicStateChange *>(e);
    handleStateChange(c->getOldState(), c->getNewState());
}


SGE_NS_END;