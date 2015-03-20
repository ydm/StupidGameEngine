//
//  Created by Yordan on 18/3/15.
//
//

#include "ActorFactory.h"
#include "ActorComponentFactory.h"
SGE_NS_USING;


Actor::ID
ActorFactory::nextID = 0;


Actor *
ActorFactory::createActor()
{
    Actor *a = new Actor();
    // a->addComponent("Transform", ActorComponentFactory::getInstance()->createComponent("Transform"));
    return a;
}
