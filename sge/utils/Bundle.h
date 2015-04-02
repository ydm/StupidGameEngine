//
//  Bundle.h
//  StupidGameEngine
//
//  Created by Yordan on 4/2/15.
//
//

#ifndef __SGE_BUNDLE_H__
#define __SGE_BUNDLE_H__

#include <cinttypes>
#include <map>
#include <string>

#include "../sge_base.h"


// ========================
// Bundle: http://developer.android.com/reference/android/os/Bundle.html
// ========================

class Bundle
{
public:
    Bundle();
    virtual ~Bundle();

    void clear();
    Bundle *clone();

    // Byte
    int8_t getByte(const std::string& key, const int8_t defaultValue = 0) const;
    void putByte(const std::string& key, const int8_t value);

    const std::vector<int8_t>& getByteVector(const std::string& key) const; // throws out_of_range
    void putByteVector(const std::string& key, const std::vector<int8_t>& vec);

    // Float
    float getFloat(const std::string& key, const float defaultValue = 0) const;
    void putFloat(const std::string& key, const float value);

    const std::vector<float>& getFloatVector(const std::string& key) const; // throws out_of_range
    void putFloatVector(const std::string& key, const std::vector<float>& vec);

    // Integer
    int getInteger(const std::string& key, const int defaultValue = 0) const;
    void putInteger(const std::string& key, const int value);

    const std::vector<int>& getIntegerVector(const std::string& key) const; // throws out_of_range
    void putIntegerVector(const std::string& key, const std::vector<int>& vec);

    // String
    const std::string& getString(const std::string& key) const; // throws out_of_range
    void putString(const std::string& key, const std::string& value);

    const std::vector<std::string>& getStringVector(const std::string& key) const; // throws out_of_range
    void putStringVector(const std::string& key, const std::vector<std::string>& vec);

    // [ydm] TODO: string serialize(); Bundle& deserialize(string);

private:
    std::map<std::string, int8_t> bytes_;
    std::map<std::string, std::vector<int8_t> > byteVectors_;

    std::map<std::string, float> floats_;
    std::map<std::string, std::vector<float> > floatVectors_;

    std::map<std::string, int> integers_;
    std::map<std::string, std::vector<int> > integerVectors_;

    std::map<std::string, std::string> strings_;
    std::map<std::string, std::vector<std::string> > stringVectors_;
};

#endif // __SGE_BUNDLE_H__
