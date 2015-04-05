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


void BaseView::update(const float dt)
{
}


Application *
BaseView::getApplication()
{
    return app_;
}


void BaseView::handleStateChange(const std::string& oldState, const std::string& newState)
{
    logi("BaseView::handleStateChange old=%s, new=%s", oldState.c_str(), newState.c_str());
}


void BaseView::handleStateChange_(const Event *e)
{
    const EventLogicStateChange *c = static_cast<const EventLogicStateChange *>(e);
    auto data = c->getData();
    handleStateChange(data[0], data[1]);
}


void BaseView::sendCommand(const EventUserCommandType command)
{
    const EventUserCommand e(command);
    app_->getEventManager()->notifyListeners(&e);
}


void BaseView::sendCommand(const EventUserCommandType command, std::initializer_list<int> params)
{
    const EventUserCommandInt e(command, params);
    // FIXME ydm app_ is NULL
    app_->getEventManager()->notifyListeners(&e);
}


SGE_NS_END;