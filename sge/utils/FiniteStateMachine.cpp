//
//  FiniteStateMachine.cpp
//  StupidGameEngine
//
//  Created by Yordan on 3/21/15.
//
//
#include <functional>
#include <sstream>
#include <stdexcept>
#include "FiniteStateMachine.h"
#include "../utils/Utils.h"
SGE_NS_BEGIN;


FiniteStateMachine::FiniteStateMachine()
: state_("initial")
, table_()
{
}


FiniteStateMachine::~FiniteStateMachine()
{
    for (auto& pair : table_)
    {
        delete pair.second;
    }
}


void FiniteStateMachine::addTransitionRule(const std::string& state, const std::string& next)
{
    if (!Utils::mapContainsKey(table_, state))
    {
        table_[state] = new std::set<std::string>();
    }
    table_[state]->insert(next);
}


const std::string&
FiniteStateMachine::getCurrentState() const
{
    return state_;
}


bool FiniteStateMachine::isKnownState(const std::string& state)
{
    return Utils::mapContainsKey(table_, state);
}


void FiniteStateMachine::transitionTo(const std::string& nextState)
{
    // map::at() throws runtime exception in case of bad key
    std::set<std::string> *valid = table_.at(state_);
    if (!Utils::setContains(*valid, nextState))
    {
        std::ostringstream message;
        message << "FiniteStateMachine::transitionTo: unknown next state '" << nextState << "'";
        throw std::runtime_error(message.str());
    }
    else
    {
        const std::string old(state_);
        state_ = nextState;
        onTransition(old, state_);
    }
}


void FiniteStateMachine::onTransition(const std::string& oldState, const std::string& newState)
{
    // NOOP
}


SGE_NS_END;