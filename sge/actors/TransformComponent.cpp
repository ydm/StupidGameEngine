//
//  TransformComponent.cpp
//  StupidGameEngine
//
//  Created by Yordan on 3/20/15.
//
//

#include "TransformComponent.h"
SGE_NS_BEGIN;


TransformComponent::TransformComponent()
: position_(0, 0, 0)
, size_(0, 0, 0)
{
}


TransformComponent::~TransformComponent()
{
}


const Vec3&
TransformComponent::getPosition() const
{
    return position_;
}


void TransformComponent::setPosition(const Vec3& pos)
{
    position_ = pos;
}


const Vec3& TransformComponent::getSize() const
{
    return size_;
}


void TransformComponent::setSize(const Vec3& size)
{
    size_ = size;
}


SGE_NS_END;