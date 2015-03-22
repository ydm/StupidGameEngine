//
//  Application.h
//  StupidGameEngine
//
//  Created by Yordan on 3/20/15.
//
//

#ifndef __SGE_APPLICATION_H__
#define __SGE_APPLICATION_H__

#include <list>
#include "../logic/BaseLogic.h"
#include "../views/BaseView.h"
SGE_NS_BEGIN;


class Application
{
public:
    Application();
    virtual ~Application();
    void update(const float dt);

    void setLogic(BaseLogic *logic);
    void addView(BaseView *view);

private:
    BaseLogic *logic_;
    std::list<BaseView *> views_;
};


SGE_NS_END;
#endif // SGE_APPLICATION_H__