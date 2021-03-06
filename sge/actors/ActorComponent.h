//
//  Created by Yordan on 19/3/15.
//
//

#ifndef __SGE_ACTORS_ACTOR_COMPONENT_H__
#define __SGE_ACTORS_ACTOR_COMPONENT_H__

#include "../sge_base.h"
SGE_NS_BEGIN;

class Actor;

class ActorComponent
{
    friend class Actor;

public:
    ActorComponent();
    virtual ~ActorComponent();
    virtual void update(const float dt);

protected:
    virtual void init(Actor *owner);
    Actor *getOwner();

private:
    Actor *owner_;
};

SGE_NS_END;
#endif // __SGE_ACTORS_ACTOR_COMPONENT_H__
