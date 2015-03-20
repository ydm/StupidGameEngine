//
//  Created by Yordan on 18/3/15.
//
//

#include "ActorComponentFactory.h"
#include "TransformComponent.h"
SGE_NS_USING;


// ========================
// Static
// ========================

ActorComponentFactory *
ActorComponentFactory::instance_ = new ActorComponentFactory();


ActorComponentFactory *
ActorComponentFactory::getInstance()
{
    return instance_;
}


// ========================
// Non-static
// ========================

ActorComponentFactory::ActorComponentFactory()
: factories_()
{
    // Register default components
    registerComponentFactory("Transform", [] () {return new TransformComponent();});
}


ActorComponentFactory::~ActorComponentFactory()
{
}


void ActorComponentFactory::registerComponentFactory(const std::string &name, ComponentFactoryFunction func)
{
    factories_[name] = func;
}


ActorComponent *
ActorComponentFactory::createComponent(const std::string& name) const
{
    ComponentFactoryFunction func = nullptr;
    try
    {
        func = factories_.at(name);
    }
    catch (std::out_of_range _)
    {
        loge("ActorComponentFactory: unknown component '%s'", name.c_str());
        return nullptr;
    }
    ActorComponent *component = func();
    if (component->init())
    {
        return component;
    }
    delete component;
    return nullptr;
}
