//
//  CCBaseLayer.h
//  StupidGameEngine
//
//  Created by Yordan on 3/28/15.
//
//

#ifndef __SGE_CC_BASE_LAYER_H__
#define __SGE_CC_BASE_LAYER_H__

#include "base.h"
#include "CCBaseView.h"
SGE_CC_NS_BEGIN;


#define SGE_CC_LAYER_CREATE(Type)                                               \
static Type *createLayer(sge::cc::CCBaseView *view)                             \
{                                                                               \
    Type *ret = new Type();                                                     \
    ret->view_ = view;                                                          \
    if (ret->init())                                                            \
    {                                                                           \
        ret->autorelease();                                                     \
        return ret;                                                             \
    }                                                                           \
    else                                                                        \
    {                                                                           \
        delete ret;                                                             \
    }                                                                           \
    return nullptr;                                                             \
}


#define SGE_CC_LAYER_CREATE_SCENE(Type)                                         \
static cocos2d::Scene *createScene(sge::cc::CCBaseView *view)                   \
{                                                                               \
    cocos2d::Scene *scene = cocos2d::Scene::create();                           \
    scene->addChild(Type::createLayer(view));                                   \
    return scene;                                                               \
}


class CCBaseLayer : public cocos2d::Layer
{
public:
    CCBaseLayer();
    virtual ~CCBaseLayer();

protected:
    CCBaseView *view_;
};

SGE_CC_NS_END;
#endif // SGE_CC_BASE_LAYER_H
