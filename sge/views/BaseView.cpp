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
    app->getEventManager()->addListener(EVENT_LOGIC_STATE_CHANGE, SGE_EM_LISTENER(&BaseView::handleStateChange));
}


void BaseView::handleStateChange(const Event *e)
{
    const EventLogicStateChange *c = static_cast<const EventLogicStateChange *>(e);
    logi("BaseView::handleStateChange old=%s, new=%s", c->getOldState().c_str(), c->getNewState().c_str());
}


SGE_NS_END;