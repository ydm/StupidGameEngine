//
//  BaseView.h
//  StupidGameEngine
//
//  Created by Yordan on 3/20/15.
//
//

#ifndef __SGE_BASE_VIEW_H__
#define __SGE_BASE_VIEW_H__

#include <initializer_list>
#include "../events/Event.h"
SGE_NS_BEGIN;


class Application;


class BaseView
{
public:
    BaseView();
    virtual ~BaseView();
    virtual void init(Application *app);
    virtual void update(const float dt);

    Application *getApplication();

    virtual void handleStateChange(const std::string& oldState, const std::string& newState);
    void sendCommand(const EventUserCommandType command);
    void sendCommand(const EventUserCommandType command, std::initializer_list<int> params);

private:
    void handleStateChange_(const Event *e);
    Application *app_;
};


SGE_NS_END;
#endif // SGE_BASE_VIEW_H__
