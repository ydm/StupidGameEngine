//
//  Created by Yordan on 18/3/15.
//
//

#include "ActorComponentFactory.h"
SGE_USING_NS;


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
}


ActorComponentFactory::~ActorComponentFactory()
{
}


void ActorComponentFactory::registerComponentFactory(std::string &name, FactoryFunction func)
{
    factories_[name] = func;
}


ActorComponent *
ActorComponentFactory::createComponent(std::string& name)
{
    FactoryFunction func = nullptr;
    try
    {
        func = factories_.at(name);
    }
    catch (std::out_of_range _)
    {
        loge("ActorComponentFactory: unknown component '%s'", name.c_str());
        return nullptr;
    }
    return func();
}
