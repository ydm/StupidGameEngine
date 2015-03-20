//
//  HasID.h
//
//  Created by Yordan on 3/17/15.
//
//

#ifndef __SGE_HAS_ID_H__
#define __SGE_HAS_ID_H__

#include <cstddef>
#include "../sge_base.h"
SGE_NS_BEGIN;


class HasID
{
public:
    typedef size_t ID;
    static const ID ID_INVALID;

    HasID(ID ident = ID_INVALID);
    virtual ~HasID();

    ID getID() const;
    void setID(const ID ident);

private:
    ID id_;
};


SGE_NS_END;
#endif // __SGE_HAS_ID_H__
