//
//  HasID.cpp
//
//  Created by Yordan on 3/17/15.
//
//

#include "HasID.h"
SGE_NS_BEGIN;


const HasID::ID HasID::ID_INVALID = -1;


HasID::HasID(const ID ident)
: THasID(ident)
{
}


HasID::~HasID()
{
}


SGE_NS_END;