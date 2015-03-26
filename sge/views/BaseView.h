//
//  BaseView.h
//  StupidGameEngine
//
//  Created by Yordan on 3/20/15.
//
//

#ifndef __SGE_BASE_VIEW_H__
#define __SGE_BASE_VIEW_H__

#include "../logic/BaseLogic.h"
#include "../events/Event.h"
SGE_NS_BEGIN;


class Application;


class BaseView
{
public:
    BaseView();
    virtual ~BaseView();
    virtual void init(Application *app);

    virtual void handleStateChange(const Event *e);

private:
    Application *app_;
    // BaseLogic *logic_;
};


SGE_NS_END;
#endif // SGE_BASE_VIEW_H__
