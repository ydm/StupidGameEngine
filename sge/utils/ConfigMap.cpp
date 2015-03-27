//
//  ConfigMap.cpp
//  StupidGameEngine
//
//  Created by Yordan on 3/27/15.
//
//

#include <cstdint>
#include <stdexcept>
#include "ConfigMap.h"
SGE_NS_BEGIN;


static void *int2p(const int i)
{
    intptr_t iptr = static_cast<intptr_t>(i);
    return reinterpret_cast<void *>(iptr);
}


static int p2int(void *const p)
{
    intptr_t iptr = reinterpret_cast<intptr_t>(p);
    return static_cast<int>(iptr);
}


Node_::Node_()
: type_(NodeType::MAP)
, data_(new std::map<std::string, Node_*>())
{
}


Node_::Node_(const std::string& s)
: type_(NodeType::STRING)
, data_(new std::string(s))
{
}


Node_::Node_(const int value)
: type_(NodeType::INT)
, data_(int2p(value))
{
}


std::map<std::string, Node_ *> *
Node_::getAsMap()
{
    if (type_ != NodeType::MAP)
    {
        throw std::runtime_error("Node_::getAsMap() is viable only when node is of type MAP");
    }
    return static_cast<std::map<std::string, Node_ *> *>(data_);
}


int Node_::getAsInt()
{
    if (type_ != NodeType::INT)
    {
        throw std::runtime_error("Node_::getAsInt() is viable only when node is of type INT");
    }
    return p2int(data_);
}


const std::string *
Node_::getAsString()
{
    if (type_ != NodeType::STRING)
    {
        throw std::runtime_error("Node_::getAsString() is viable only when node is of type STRING");
    }
    return static_cast<std::string *>(data_);
}


SGE_NS_END;