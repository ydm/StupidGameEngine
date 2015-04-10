//
//  CCRenderComponent.cpp
//  StupidGameEngine: cocos2d-x extension
//
//  Created by Yordan on 3/25/15.
//
//

#include "CCRenderComponent.h"
#include "../../actors/Actor.h"
#include "../../actors/TransformComponent.h"
SGE_CC_NS_BEGIN;


CCRenderComponent::CCRenderComponent(cocos2d::Node *node)
: sge::ActorComponent()
, node_(node)
{
    node->retain();
}


CCRenderComponent::~CCRenderComponent()
{
    node_->release();
}


void CCRenderComponent::init(sge::Actor *a)
{
    sge::ActorComponent::init(a);

    const sge::TransformComponent *t = static_cast<const sge::TransformComponent *>(getOwner()->getComponent("transform"));
    double width = t->getSize().getX();
    double height = t->getSize().getY();
    sge::logi("INIT RENDER COMPONENT: x=%f, y=%f", width, height);
}


void CCRenderComponent::update(const float dt)
{
    sge::TransformComponent *t = static_cast<sge::TransformComponent *>(getOwner()->getComponent("transform"));
    const sge::Vec3& pos = t->getPosition();

    const cocos2d::Size& size = cocos2d::Director::getInstance()->getWinSize();
    const float x = static_cast<float>(pos.getX()) * size.width;
    const float y = static_cast<float>(pos.getY()) * size.height;
    node_->setPosition(x, y);
}


cocos2d::Node *CCRenderComponent::getNode() const
{
    return node_;
}


SGE_CC_NS_END;