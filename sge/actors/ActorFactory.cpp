//
//  Created by Yordan on 18/3/15.
//
//

#include "ActorFactory.h"
#include "TransformComponent.h"
SGE_NS_USING;


Actor::ID
ActorFactory::nextID = 0;


Actor *
ActorFactory::createActor()
{
    Actor *a = new Actor();

    TransformComponent *transform = new TransformComponent();
    Vec3 pos(0, 0, 0);
    transform->setPosition(pos);

    a->addComponent("transform", transform);
    return a;
}
