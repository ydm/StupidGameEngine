//
//  BaseLogic.cpp
//  StupidGameEngine
//
//  Created by Yordan on 3/20/15.
//
//

#include "../app/Application.h" // Includes BaseLogic.h
#include "../events/CommonEvents.h"
#include "../utils/Utils.h"
SGE_NS_BEGIN;


BaseLogic::BaseLogic()
: actorManager_(nullptr)
, app_(nullptr)
, currentStateActors_(nullptr)
{
}


BaseLogic::~BaseLogic()
{
    currentStateActors_ = nullptr;
    delete actorManager_;
}


void BaseLogic::init(Application *app)
{
    if (app_)
    {
        logw("BaseLogic::init(): you can call init() only once");
        return;
    }
    if (!app)
    {
        logw("BaseLogic::init(): null APP argument");
        return;
    }
    app_ = app;

    // Init stages
    initStates();
    initActors();

    // Bind event handlers
    app_->getEventManager()->addListener(EVENT_USER_COMMAND, SGE_EM_LISTENER(&BaseLogic::handleCommand_));
    app_->getEventManager()->addListener(EVENT_USER_COMMAND_INT, SGE_EM_LISTENER(&BaseLogic::handleCommand_));
}


void BaseLogic::update(const float dt)
{
    if (actorManager_)
    {
        for (auto& p : *actorManager_->getGlobalActors())
        {
            p.second->update(dt);
        }
    }

    if (currentStateActors_)
    {
        for (auto& p : *currentStateActors_)
        {
            p.second->update(dt);
        }
    }
}


ActorManager *
BaseLogic::getActorManager() const
{
    return actorManager_;
}


void BaseLogic::setActorManager(ActorManager *actorManager)
{
    if (actorManager_)
    {
        logw("BaseLogic::setActionManager: actor manager is already set");
        return;
    }
    actorManager_ = actorManager;
}


// ----------+
// Protected |
// ----------+

Application *
BaseLogic::getApplication() const
{
    return app_;
}


void BaseLogic::handleCommand(const EventUserCommandType command)
{
    logi("BaseLogic::handleCommand: %zu", command);
}


void BaseLogic::handleCommand(const EventUserCommandType command, const std::vector<int>& params)
{
    logi("BaseLogic::handleCommand: %zu, %s", command, Utils::sequencePrettyString(params).c_str());
}


void BaseLogic::onTransition(const std::string& oldState, const std::string& newState, const Bundle *parameters)
{
    // We cache the current state actors for faster access in update()
    if (actorManager_)
    {
        currentStateActors_ = actorManager_->getActorsForState(newState);
    }

    // Now notify of the state change
    const EventLogicStateChange e(oldState, newState);
    getApplication()->getEventManager()->notifyListeners(&e);
}


void BaseLogic::handleCommand_(const Event *e)
{
    switch (e->getEventType())
    {
        case EVENT_USER_COMMAND:
        {
            const EventUserCommand *c = static_cast<const EventUserCommand *>(e);
            handleCommand(c->getData());
            break;
        }
        case EVENT_USER_COMMAND_INT:
        {
            const EventUserCommandInt *c = static_cast<const EventUserCommandInt *>(e);
            handleCommand(c->getData(), c->getParameters());
            break;
        }
        default:
            break;
    }
}


SGE_NS_END;