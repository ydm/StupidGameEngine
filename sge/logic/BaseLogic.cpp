//
//  BaseLogic.cpp
//  StupidGameEngine
//
//  Created by Yordan on 3/20/15.
//
//

#include "BaseLogic.h"
#include "../utils/Utils.h"
SGE_NS_USING;


BaseLogic::BaseLogic()
{
}


BaseLogic::~BaseLogic()
{

}


void BaseLogic::update(const float dt)
{

}


void BaseLogic::addActorForState(size_t state, Actor *actor)
{
    
}


void BaseLogic::addGlobalActor(Actor *actor)
{

}


// ----------+
// Protected |
// ----------+

void BaseLogic::onTransition(const std::string& oldState, const std::string& newState)
{
}