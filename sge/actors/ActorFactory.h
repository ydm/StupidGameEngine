//
//  Created by Yordan on 18/3/15.
//
//

#ifndef __SGE_ACTORS_ACTOR_FACTORY_H__
#define __SGE_ACTORS_ACTOR_FACTORY_H__

#include "Actor.h"
SGE_NS_BEGIN;

class ActorFactory
{
public:
    Actor *createActor();

private:
    static Actor::ID nextID;
};

SGE_NS_END;
#endif // SGE_ACTORS_ACTOR_FACTORY_H__
