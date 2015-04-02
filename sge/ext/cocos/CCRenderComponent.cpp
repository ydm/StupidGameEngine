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
: node_(node)
{
    node->retain();
}


CCRenderComponent::~CCRenderComponent()
{
    node_->release();
}


void CCRenderComponent::update(const float dt)
{
    sge::TransformComponent *t = static_cast<sge::TransformComponent *>(getOwner()->getComponent("transform"));
    const sge::Vec3 pos(t->getPosition());

    cocos2d::Size size(cocos2d::Director::getInstance()->getWinSize());
    node_->setPosition(static_cast<float>(pos.getX() * size.width),
                       static_cast<float>(pos.getY() * size.height));
}


SGE_CC_NS_END;