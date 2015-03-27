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
#include "../events/EventManager.h"
#include "../logic/BaseLogic.h"
#include "../views/BaseView.h"
SGE_NS_BEGIN;


class Application
{
public:
    Application();
    virtual ~Application();
    void init();
    void update(const float dt);

    void addView(BaseView *view);
    EventManager *getEventManager() const;
    BaseLogic *getLogic() const;
    void setLogic(BaseLogic *logic);

private:
    EventManager eventManager_;
    BaseLogic *logic_;
    bool started_;
    std::list<BaseView *> views_;
};


SGE_NS_END;
#endif // SGE_APPLICATION_H__
