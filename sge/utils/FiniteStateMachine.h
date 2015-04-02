//
//  FiniteStateMachine.h
//  StupidGameEngine
//
//  Created by Yordan on 3/21/15.
//
//

#ifndef __SGE_FINITE_STATE_MACHINE_H__
#define __SGE_FINITE_STATE_MACHINE_H__

#include <set>
#include <map>
#include <string>
#include "Bundle.h"
SGE_NS_BEGIN;


class FiniteStateMachine
{
public:
    FiniteStateMachine();
    virtual ~FiniteStateMachine();

    void addTransitionRule(const std::string& state, const std::string& next);
    const std::string& getCurrentState() const;
    bool isKnownState(const std::string& state);
    void transitionTo(const std::string& nextState, const Bundle *parameters = nullptr);

protected:
    virtual void onTransition(const std::string& oldState, const std::string& newState, const Bundle *parameters);

private:
    std::string state_;
    std::map<std::string, std::set<std::string> *> table_;
};


SGE_NS_END;
#endif // SGE_FINITE_STATE_MACHINE_H__
