//
//  Created by Yordan on 19/3/15.
//
//

#ifndef __SGE_ACTORS_ACTOR_COMPONENT_H__
#define __SGE_ACTORS_ACTOR_COMPONENT_H__

#include "../sge_base.h"
SGE_NS_BEGIN;

class Actor;
class ActorFactory;

class ActorComponent
{
public:
    ActorComponent();
    virtual ~ActorComponent();

    virtual bool init();
    // virtual void postInit();
    virtual void update(const float dt);
    // virtual void onChange();

protected:
    Actor *getOwner();

private:
    Actor *owner_;
    void setOwner(Actor *owner);
    friend class ActorFactory;
};

SGE_NS_END;
#endif // __SGE_ACTORS_ACTOR_COMPONENT_H__
