//
//  ConfigMap.h
//  StupidGameEngine
//
//  Created by Yordan on 3/27/15.
//
//

#ifndef __SGE_CONFIG_MAP_H__
#define __SGE_CONFIG_MAP_H__

#include <map>
#include "../sge_base.h"
SGE_NS_BEGIN;


class ConfigMap;


class Node_
{
public:
    typedef enum {INT, MAP, STRING} NodeType;
    Node_();                     // MAP node constructor
    Node_(const std::string& s); // STRING constructor
    Node_(const int value);      // INT constructor

    std::map<std::string, Node_ *> *getAsMap();
    int getAsInt();
    const std::string *getAsString();

    /*
    Node_ *operator[](const std::string& key)
    {
        if (type_ != NodeType::MAP)
        {
            throw std::runtime_error("Node should be of type MAP in order to support the subscript operator");
        }
        std::map<std::string, Node_ *> *m = getAsMap();
        return (*m)[key];
    }
    */

private:
    void *data_;
    const NodeType type_;
};


class ConfigMap
{
private:
    Node_ root_;
};


SGE_NS_END;
#endif // __SGE_CONFIG_MAP_H__
