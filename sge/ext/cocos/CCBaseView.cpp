//
//  CCBaseView.cpp
//  StupidGameEngine: cocos2d-x extension
//
//  Created by Yordan on 3/28/15.
//
//

#include "CCBaseView.h"
#include "CCBaseLayer.h"
SGE_CC_NS_BEGIN;


CCBaseView::CCBaseView()
: currentLayer_(nullptr)
{
}


CCBaseView::~CCBaseView()
{
}


//void CCBaseView::update(const float dt)
//{
//    if (currentLayer_)
//    {
//        currentLayer_->sgeUpdate(dt);
//    }
//}


void CCBaseView::setCurrentLayer(CCBaseLayer *layer)
{
    currentLayer_ = layer;
    if (currentLayer_)
    {
        cocos2d::Scene *scene = cocos2d::Scene::create();
        scene->addChild(currentLayer_);
        cocos2d::Director::getInstance()->replaceScene(scene);
    }
}


CCBaseLayer *CCBaseView::getCurrentLayer() const
{
    return currentLayer_;
}

SGE_CC_NS_END;