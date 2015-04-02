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


void FiniteStateMachine::transitionTo(const std::string& nextState, const Bundle *parameters)
{
    std::set<std::string> *valid(nullptr);
    try
    {
        valid = table_.at(state_);
    }
    catch (std::out_of_range)
    {
        logw("FiniteStateMachine::transitionTo: No rules for state '%s'.  Rules table: %s", state_.c_str(), Utils::mapPrettyString(table_).c_str());
        return;
    }

    if (Utils::setContains(*valid, nextState))
    {
        const std::string old(state_);
        state_ = nextState;
        onTransition(old, state_, parameters);
    }
    else
    {
        loge("FiniteStateMachine::transitionTo: unknown next state '%s', current = '%s'", nextState.c_str(), state_.c_str());
    }
}


void FiniteStateMachine::onTransition(const std::string& oldState, const std::string& newState, const Bundle *parameters)
{
    // NOOP
}


SGE_NS_END;