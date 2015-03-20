//
//  Created by Yordan on 18/3/15.
//
//

#ifndef __SGE_ACTORS_ACTOR_COMPONENT_FACTORY_H__
#define __SGE_ACTORS_ACTOR_COMPONENT_FACTORY_H__

#include <functional>
#include <map>
#include <string>
#include "ActorComponent.h"
SGE_NS_BEGIN;


class ActorComponentFactory
{
public:
    typedef std::function<ActorComponent *()> ComponentFactoryFunction;

    static ActorComponentFactory *getInstance();
    virtual ~ActorComponentFactory();

    void registerComponentFactory(const std::string& name, ComponentFactoryFunction);
    ActorComponent *createComponent(const std::string& name) const;

private:
    ActorComponentFactory();
    static ActorComponentFactory *instance_;
    std::map<std::string, ComponentFactoryFunction> factories_;
};


SGE_NS_END;
#endif // __SGE_ACTORS_ACTOR_COMPONENT_FACTORY_H__
