//
//  Utils.h
//  StupidGameEngine
//
//  Created by Yordan on 3/22/15.
//
//

#ifndef __SGE_UTILS_H__
#define __SGE_UTILS_H__

#include <functional>
#include <list>
#include <map>
#include <set>
#include "../sge_base.h"
SGE_NS_BEGIN;

class Utils
{
public:
    // ----+
    // Map |
    // ----+
    template<typename K, typename V>
    static bool mapContainsKey(const std::map<K, V>& m, const K& key)
    {
        // ydm: http://stackoverflow.com/questions/1123080/why-do-we-need-typename-here
        typename std::map<K, V>::const_iterator it = m.find(key);
        return it != m.end();
    }

    /**
     * O(N)
     */
    template<typename K, typename V>
    static bool mapContainsValue(const std::map<K, V>& m, const V& val)
    {
        // for (auto& kv : m)
        for (typename std::map<K, V>::const_iterator it = m.begin(); it != m.end(); it++)
        {
            if (it->second == val)
            {
                return true;
            }
        }
        return false;
    }

    template<typename K, typename  V>
    static bool mapSetDefault(std::map<K, V>& m, const K& key, const V val)
    {
        if (!mapContainsKey(m, key))
        {
            m[key] = val;
            return true;
        }
        return false;
    }

    template<typename K, typename V>
    static bool mapSetDefault(std::map<K, V>& m, const K& key, const std::function<V ()> func)
    {
        if (!mapContainsKey(m, key))
        {
            m[key] = func();
            return true;
        }
        return false;
    }

    // -----+
    // List |
    // -----+
    template<typename T>
    static bool listContains(const std::list<T>& s, const T& element)
    {
        typename std::list<T>::const_iterator it = s.find(element);
        return it != s.end();
    }

    // ----+
    // Set |
    // ----+
    template<typename T>
    static bool setContains(const std::set<T>& s, const T& element)
    {
        typename std::set<T>::const_iterator it = s.find(element);
        return it != s.end();
    }
};

SGE_NS_END;
#endif // SGE_UTILS_H