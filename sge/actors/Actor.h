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
    typedef size_t ActorType;

    Actor(const ActorType actorType);
    virtual ~Actor();  // Deletes components
    void update(const float dt);

    void addComponent(const std::string& name, ActorComponent *component);
    const ActorType getActorType() const;
    ActorComponent *getComponent(const std::string& name) const;
    //template<typename T> T *getComponent(const std::string& name) const;

private:
    std::map<std::string, ActorComponent *> components_;
    const ActorType actorType_;
};


SGE_NS_END;
#endif // __SGE_ACTORS_ACTOR_H__
