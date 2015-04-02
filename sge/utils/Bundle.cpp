//
//  Bundle.cpp
//  StupidGameEngine
//
//  Created by Yordan on 4/2/15.
//
//

#include "Bundle.h"


Bundle::Bundle()
: bytes_()
, byteVectors_()
, floats_()
, floatVectors_()
, integers_()
, integerVectors_()
, strings_()
, stringVectors_()
{
}


Bundle::~Bundle()
{
}


void Bundle::clear()
{
    bytes_.clear();
    byteVectors_.clear();
    floats_.clear();
    floatVectors_.clear();
    integers_.clear();
    integerVectors_.clear();
    strings_.clear();
    stringVectors_.clear();
}


Bundle *Bundle::clone()
{
    // ydm: TODO
    return nullptr;
}


// ========================
// Byte
// ========================
int8_t Bundle::getByte(const std::string& key, const int8_t defaultValue) const
{
    try {
        return bytes_.at(key);
    } catch (std::out_of_range) {
        return defaultValue;
    }
}


void Bundle::putByte(const std::string& key, const int8_t value)
{
    bytes_[key] = value;
}


const std::vector<int8_t>& Bundle::getByteVector(const std::string& key) const
{
    return byteVectors_.at(key);
}


void Bundle::putByteVector(const std::string& key, const std::vector<int8_t>& vec)
{
    byteVectors_[key] = std::vector<int8_t>(vec);
}


// ========================
// Float
// ========================
float Bundle::getFloat(const std::string& key, const float defaultValue) const
{
    try {
        return floats_.at(key);
    } catch (std::out_of_range) {
        return defaultValue;
    }
}


void Bundle::putFloat(const std::string& key, const float value)
{
    floats_[key] = value;
}


const std::vector<float>& Bundle::getFloatVector(const std::string& key) const
{
    return floatVectors_.at(key);
}


void Bundle::putFloatVector(const std::string& key, const std::vector<float>& vec)
{
    floatVectors_[key] = std::vector<float>(vec);
}


// ========================
// Integer
// ========================
int Bundle::getInteger(const std::string& key, const int defaultValue) const
{
    try {
        return integers_.at(key);
    } catch (std::out_of_range) {
        return defaultValue;
    }
}


void Bundle::putInteger(const std::string& key, const int value)
{
    integers_[key] = value;
}


const std::vector<int>& Bundle::getIntegerVector(const std::string& key) const
{
    return integerVectors_.at(key);
}


void Bundle::putIntegerVector(const std::string& key, const std::vector<int>& vec)
{
    integerVectors_[key] = std::vector<int>(vec);
}


// ========================
// String
// ========================
const std::string& Bundle::getString(const std::string& key) const
{
    return strings_.at(key);
}


void Bundle::putString(const std::string& key, const std::string& value)
{
    strings_[key] = std::string(value);
}


const std::vector<std::string>& Bundle::getStringVector(const std::string& key) const
{
    return stringVectors_.at(key);
}


void Bundle::putStringVector(const std::string& key, const std::vector<std::string>& vec)
{
    stringVectors_[key] = std::vector<std::string>(vec);
}
