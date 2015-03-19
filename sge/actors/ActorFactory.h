//
//  Created by Yordan on 18/3/15.
//
//

#ifndef __SGE_FACTOR_FACTORY_H__
#define __SGE_FACTOR_FACTORY_H__

#include "sge_base.h"
#include "Actor.h"
SGE_NS_BEGIN;

class ActorFactory
{
public:
    Actor *createActor();
};

SGE_NS_END;
#endif // SGE_FACTOR_FACTORY_H__
