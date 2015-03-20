//
//  Created by Yordan on 18/3/15.
//
//

#ifndef __SGE_ACTORS_ACTOR_H__
#define __SGE_ACTORS_ACTOR_H__

#include <map>
#include <string>
#include "ActorComponent.h"
#include "../utils/HasID.h"
SGE_NS_BEGIN;


class Actor : private HasID
{
    Actor();
    virtual ~Actor();
    ActorComponent *getComponent(const std::string& name);

    ID getActorID();

private:
    std::map<std::string, ActorComponent *> components_;
    void addComponent(const std::string& name, ActorComponent *component);
    friend class ActorFactory;
};


SGE_NS_END;
#endif // __SGE_ACTORS_ACTOR_H__
