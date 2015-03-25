//
//  HasID.h
//
//  Created by Yordan on 3/17/15.
//
//

#ifndef __SGE_HAS_ID_H__
#define __SGE_HAS_ID_H__

#include <cinttypes>
#include "../sge_base.h"
SGE_NS_BEGIN;


template<typename T>
class THasID
{
public:
    typedef T ID;

    THasID(const ID ident)
    : id_(ident)
    {
    }

    virtual ~THasID()
    {
    }

    virtual ID getID() const
    {
        return id_;
    }

    virtual void setID(const ID ident)
    {
        id_ = ident;
    }

private:
    ID id_;
};


class HasID : public THasID<uint32_t>
{
public:
    static const ID ID_INVALID;

    HasID(const ID ident);
    virtual ~HasID();
};


SGE_NS_END;
#endif // __SGE_HAS_ID_H__
