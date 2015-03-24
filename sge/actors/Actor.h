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


class Actor : public HasID
{
public:
    Actor();
    virtual ~Actor();  // Deletes components
    void addComponent(const std::string& name, ActorComponent *component);
    ActorComponent *getComponent(const std::string& name) const;
    void update(const float dt);

private:
    std::map<std::string, ActorComponent *> components_;
};


SGE_NS_END;
#endif // __SGE_ACTORS_ACTOR_H__
