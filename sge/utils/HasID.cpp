//
//  HasID.cpp
//
//  Created by Yordan on 3/17/15.
//
//

#include "HasID.h"
SGE_NS_BEGIN;


const HasID::ID
HasID::ID_INVALID = -1;


HasID::HasID(const ID ident)
{
    setID(ident);
}


HasID::~HasID()
{
}


HasID::ID
HasID::getID() const
{
    return id_;
}


void HasID::setID(const ID ident)
{
    id_ = ident;
}


SGE_NS_END;