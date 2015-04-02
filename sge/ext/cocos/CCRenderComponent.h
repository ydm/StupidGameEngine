//
//  CCRenderComponent.h
//  StupidGameEngine: cocos2d-x extension
//
//  Created by Yordan on 3/25/15.
//
//

#ifndef __SGE_CC_RENDER_COMPONENT_H__
#define __SGE_CC_RENDER_COMPONENT_H__

#include "base.h"
#include "../../actors/ActorComponent.h"
SGE_CC_NS_BEGIN;


class CCRenderComponent : public sge::ActorComponent
{
public:
    CCRenderComponent(cocos2d::Node *node);
    virtual ~CCRenderComponent();
    virtual void update(const float dt) override;

private:
    cocos2d::Node *node_;
};


SGE_CC_NS_END;
#endif // __SGE_CC_RENDER_COMPONENT_H__