//
//  ActorComponentFactory.h
//
//  Created by Yordan on 18/3/15.
//
//

#ifndef __SGE_ACTOR_COMPONENT_FACTORY_H__
#define __SGE_ACTOR_COMPONENT_FACTORY_H__

#include "actors_base.h"
#include <functional>
#include <map>
#include <string>
#include "ActorComponent.h"
SGE_ACTORS_NS_BEGIN;

class ActorComponentFactory
{
public:
    typedef std::function<ActorComponent *()> FactoryFunction;

    static ActorComponentFactory *getInstance();
    virtual ~ActorComponentFactory();

    void registerComponentFactory(std::string& name, FactoryFunction);
    ActorComponent *createComponent(std::string& name);

private:
    ActorComponentFactory();
    static ActorComponentFactory *instance_;
    std::map<std::string, FactoryFunction> factories_;
};

SGE_ACTORS_NS_END;
#endif // __SGE_ACTOR_COMPONENT_FACTORY_H__
