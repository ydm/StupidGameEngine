//
//  CCBaseView.h
//  StupidGameEngine: cocos2d-x extension
//
//  Created by Yordan on 3/28/15.
//
//

#ifndef __SGE_CC_BASE_VIEW_H__
#define __SGE_CC_BASE_VIEW_H__

#include "base.h"
#include "../../views/BaseView.h"
SGE_CC_NS_BEGIN;


class CCBaseLayer;


class CCBaseView : public BaseView
{
public:
    CCBaseView();
    virtual ~CCBaseView();
    // virtual void update(const float dt) override;
protected:
    void setCurrentLayer(CCBaseLayer *layer);
    CCBaseLayer *getCurrentLayer() const;
private:
    CCBaseLayer *currentLayer_;
};


SGE_CC_NS_END;
#endif // __SGE_CC_BASE_VIEW_H__
