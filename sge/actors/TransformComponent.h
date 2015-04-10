//
//  TransformComponent.h
//  StupidGameEngine
//
//  Created by Yordan on 3/20/15.
//
//

#ifndef __SGE_TRANSFORM_COMPONENT_H__
#define __SGE_TRANSFORM_COMPONENT_H__

#include "ActorComponent.h"
SGE_NS_BEGIN;


class TransformComponent : public ActorComponent
{
public:
    TransformComponent();
    virtual ~TransformComponent();

    const Vec3& getPosition() const;
    void setPosition(const Vec3& pos);

    const Vec3& getSize() const;
    void setSize(const Vec3& size);

private:
    Vec3 position_;
    Vec3 size_;
    // ydm: TODO scale, rotation, etc.
};


SGE_NS_END;
#endif /* defined(__StupidGameEngine__TransformComponent__) */
