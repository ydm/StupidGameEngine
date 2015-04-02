//
//  BaseLogic.h
//  StupidGameEngine
//
//  Created by Yordan on 3/20/15.
//
//

#ifndef __SGE_BASE_LOGIC_H__
#define __SGE_BASE_LOGIC_H__

#include <list>
#include <vector>
#include "../actors/ActorManager.h"
#include "../utils/FiniteStateMachine.h"
SGE_NS_BEGIN;


class Application;


// A simple state machine
class BaseLogic : public FiniteStateMachine
{
public:
    BaseLogic();
    virtual ~BaseLogic();
    virtual void init(Application *app);
    virtual void update(const float dt);
    void setActorManager(ActorManager *actorManager);

protected:
    virtual void initStates() = 0;
    virtual void initActors() = 0;

    ActorManager *getActorManager() const;
    Application *getApplication() const;
    virtual void handleCommand(const EventUserCommandType command);
    virtual void handleCommand(const EventUserCommandType command, const std::vector<int>& params);
    // virtual void handleCommandWithStringParameters(const EventUserCommandType command, std::initializer_list<std::string>& params);
    virtual void onTransition(const std::string& oldState, const std::string& newState, const Bundle *parameters) override;

private:
    void handleCommand_(const Event *e);

    ActorManager                  *actorManager_;
    Application                   *app_;
    const ActorManager::ActorsMap *currentStateActors_;
};


SGE_NS_END;
#endif // GE_BASE_LOGIC_H__
